#pragma once

#include <Columns/ColumnNullable.h>
#include <Columns/ColumnVector.h>
#include <Columns/ColumnsCommon.h>
#include <DataTypes/IDataType.h>
#include <generated/parquet_types.h>
#include <Common/PODArray.h>
#include "RleEncoding.h"
#include "Utils.h"

namespace DB
{
namespace ErrorCodes
{
    extern const int LOGICAL_ERROR;
}

template <typename T>
class RleDecoder;
template <typename T>
class RleBatchDecoder;

class Decoder
{
public:
    Decoder() = default;
    virtual ~Decoder() = default;

    virtual void setDict(size_t /*chunk_size*/, size_t /*num_values*/, Decoder & /*decoder*/)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "setDict not supported");
    }

    virtual ColumnPtr getDictValues() { throw Exception(ErrorCodes::LOGICAL_ERROR, "getDictValues not supported"); }

    virtual void getDictValues(MutableColumnPtr & /*column*/) { throw Exception(ErrorCodes::LOGICAL_ERROR, "getDictValues not supported"); }

    virtual void getDictValues(const std::vector<int32_t> & /*dict_codes*/, MutableColumnPtr &)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "getDictValues not supported");
    }

    virtual void getDictCodes(const std::vector<Slice> & /*dict_values*/, std::vector<int32_t> & /*dict_codes*/)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "getDictCodes not supported");
    }

    // used to set fixed length
    virtual void setTypeLength(int32_t /*type_length*/) { }

    // Set a new page to decoded.
    virtual void setData(const Slice & data) = 0;

    // For history reason, decoder don't known how many elements encoded in one page.
    // Caller must assure that no out-of-bounds access.
    // It will return ERROR if caller wants to read out-of-bound data.
    virtual void nextBatch(size_t count, MutableColumnPtr & dst) = 0;

    virtual void nextBatch(size_t /*count*/, uint8_t *  /*dst*/) { throw Exception(ErrorCodes::LOGICAL_ERROR, "nextBatch not supported"); }
};

template <typename T>
class PlainDecoder final : public Decoder
{
public:
    PlainDecoder() = default;
    ~PlainDecoder() override = default;

    static void decode(const std::string & buffer, T * value)
    {
        int byte_size = sizeof(T);
        memcpy(value, buffer.c_str(), byte_size);
    }

    void setData(const Slice & data_) override
    {
        data.data = data_.data;
        data.size = data_.size;
        offset = 0;
    }

    void nextBatch(size_t count, MutableColumnPtr & dst) override
    {
        chassert((count + offset) * SIZE_OF_TYPE <= data.size);
        const auto * data_start = reinterpret_cast<const T *>(data.data) + offset;
        if (dst->isNullable())
        {
            auto & nullable_col = static_cast<ColumnNullable &>(*dst);
            nullable_col.getNullMapColumn().insertMany(0, count);
            auto & column_data = static_cast<ColumnVector<T> &>(nullable_col.getNestedColumn()).getData();
            column_data.insert_assume_reserved(data_start, data_start + count);
        }
        else
        {
            auto & column_data = static_cast<ColumnVector<T> &>(*dst).getData();
            column_data.insert_assume_reserved(data_start, data_start + count);
        }
        offset += count;
    }

    void nextBatch(size_t count, uint8_t * dst) override
    {
        if ((count + offset) * SIZE_OF_TYPE > data.size) [[unlikely]]
        {
            throw Exception(
                ErrorCodes::LOGICAL_ERROR, "going to read out-of-bounds data, offset={},count={},size={}", offset, count, data.size);
        }
        memcpy(dst, data.data + offset * SIZE_OF_TYPE, count * SIZE_OF_TYPE);
        offset += count;
    }

private:
    enum
    {
        SIZE_OF_TYPE = sizeof(T)
    };

    Slice data;
    // row number
    size_t offset = 0;
};

template <typename T>
class DictDecoder final : public Decoder
{
public:
    DictDecoder() = default;
    ~DictDecoder() override = default;

    // initialize dictionary
    void setDict(size_t chunk_size, size_t num_values, Decoder & decoder) override
    {
        _dict.resize(num_values);
        _indexes.resize(chunk_size);
        decoder.nextBatch(num_values, reinterpret_cast<uint8_t *>(_dict.data()));
    }

    void setData(const Slice & data) override
    {
        if (data.size > 0)
        {
            uint8_t bit_width = *data.data;
            _index_batch_decoder
                = RleBatchDecoder<uint32_t>(reinterpret_cast<uint8_t *>(data.data) + 1, static_cast<int>(data.size) - 1, bit_width);
        }
        else
        {
            throw Exception(ErrorCodes::LOGICAL_ERROR, "input encoded data size is 0");
        }
    }

    void nextBatch(size_t count, MutableColumnPtr &dst) override
    {
        _indexes.reserve(count);
        _index_batch_decoder.GetBatch(_indexes.data(), static_cast<int32_t>(count));

        if (dst->isNullable())
        {
            auto & nullable_col = static_cast<ColumnNullable &>(*dst);
            nullable_col.getNullMapColumn().insertMany(0, count);
            auto &column_data = static_cast<ColumnVector<T> &>(nullable_col.getNestedColumn());
            for (size_t i = 0; i < count; i++)
            {
                column_data.insertData(reinterpret_cast<char *>(&_dict[_indexes[i]]), SIZE_OF_TYPE);
            }
        }
        else
        {
            auto &column_data = static_cast<ColumnVector<T> &>(*dst);
            for (size_t i = 0; i < count; i++)
            {
                column_data.insertData(reinterpret_cast<char *>(&_dict[_indexes[i]]), SIZE_OF_TYPE);
            }
        }

    }

private:
    enum
    {
        SIZE_OF_TYPE = sizeof(T)
    };

    RleBatchDecoder<uint32_t> _index_batch_decoder;
    std::vector<T> _dict;
    std::vector<uint32_t> _indexes;
};

class LevelDecoder
{
public:
    void parse(parquet::format::Encoding::type encoding, size_t max_level, uint32_t num_levels, Slice * slice);

    // Try to decode n levels into levels;
    size_t decode_batch(size_t n, size_t * levels);


    size_t get_repeated_value(size_t count);

private:
    parquet::format::Encoding::type encoding;
    size_t bit_width = 0;
    [[maybe_unused]] size_t max_level = 0;
    uint32_t num_levels = 0;
    std::shared_ptr<RleDecoder<size_t>> rle_decoder;
};

class EncodingInfo
{
public:
    static EncodingInfo get(parquet::format::Type::type type, parquet::format::Encoding::type encoding);
    template <typename TypeEncodingTraits>
    explicit EncodingInfo(TypeEncodingTraits traits);

    std::unique_ptr<Decoder> create_decoder() const { return create_decoder_func(); }


    parquet::format::Type::type getType() const { return type; }
    parquet::format::Encoding::type getEncoding() const { return encoding; }

private:
    friend class EncodingInfoResolver;


    using CreateDecoderFunc = std::function<std::unique_ptr<Decoder>()>;
    CreateDecoderFunc create_decoder_func;

    parquet::format::Type::type type;
    parquet::format::Encoding::type encoding;
};
}
