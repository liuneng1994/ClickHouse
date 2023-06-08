#pragma once

#include <Columns/ColumnNullable.h>
#include <Columns/ColumnString.h>
#include <Columns/ColumnVector.h>
#include <Columns/ColumnsCommon.h>
#include <DataTypes/DataTypeString.h>
#include <DataTypes/IDataType.h>
#include <generated/parquet_types.h>
#include <Common/PODArray.h>
#include "RleEncoding.h"
#include "Utils.h"
#include "type.h"

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

    virtual void nextBatch(size_t /*count*/, uint8_t * /*dst*/) { throw Exception(ErrorCodes::LOGICAL_ERROR, "nextBatch not supported"); }
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
            nullable_col.getNullMapData().resize_fill(dst->size() + count);
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

template <>
class PlainDecoder<DB::String> final : public Decoder
{
public:
    PlainDecoder() = default;
    ~PlainDecoder() override = default;

    //    static void decode(const std::string & buffer, DB::String * value)
    //    {
    //        int byte_size = sizeof(T);
    //        memcpy(value, buffer.c_str(), byte_size);
    //    }

    void setData(const Slice & data_) override
    {
        data.data = data_.data;
        data.size = data_.size;
        offset = 0;
        row_offset = 0;
        size_list.clear();
        size_list.reserve(8192 * 4);
        char * pointer = data.data + offset;
        while (pointer < data_.data + data.size)
        {
            auto length = decode_fixed32_le(pointer);
            pointer = pointer + sizeof(uint32_t) + length;
            size_list.emplace_back(length);
        }
    }

    void nextBatch(size_t count, MutableColumnPtr & dst) override
    {
        chassert(count + row_offset <= size_list.size());
        size_t total_size = count;
        for (size_t i = row_offset; i < row_offset + count; i++)
        {
            total_size += size_list[i];
        }
        if (dst->isNullable())
        {
            auto & nullable_col = static_cast<ColumnNullable &>(*dst);
            nullable_col.getNullMapColumn().insertMany(0, count);
            chassert(checkColumn<ColumnString>(nullable_col.getNestedColumn()));
            auto & string_col = static_cast<ColumnString &>(nullable_col.getNestedColumn());
            insertDataToStringColumn(string_col, total_size, count);
        }
        else
        {
            chassert(checkColumn<ColumnString>(*dst));
            auto & string_col = static_cast<ColumnString &>(*dst);
            insertDataToStringColumn(string_col, total_size, count);
        }
        row_offset += count;
    }

    void nextBatch(size_t, uint8_t *) override { }

private:
    void insertDataToStringColumn(ColumnString & col, size_t mem_size, size_t row_count)
    {
        PaddedPODArray<UInt8> & column_chars_t = col.getChars();
        PaddedPODArray<UInt64> & column_offsets = col.getOffsets();

        auto initial_size = column_chars_t.size();
        column_chars_t.reserve(initial_size + mem_size);
        column_offsets.reserve(initial_size + row_count);

        for (size_t i = 0; i < row_count; ++i)
        {
            const auto * raw_data = data.data + offset + sizeof(uint32_t);
            column_chars_t.insert_assume_reserved(raw_data, raw_data + size_list[row_offset + i]);
            column_chars_t.emplace_back('\0');
            column_offsets.emplace_back(column_chars_t.size());
            offset = offset + size_list[row_offset + i] + sizeof(uint32_t);
        }
        chassert(initial_size + mem_size == column_offsets.back());
    }

    Slice data;
    size_t offset = 0;
    size_t row_offset = 0;
    std::vector<size_t> size_list;
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
        dict = ColumnVector<T>::create();
        indexes = ColumnVector<UInt32>::create();
        dict->insertManyDefaults(num_values);
        indexes->reserve(chunk_size);
        decoder.nextBatch(num_values, reinterpret_cast<uint8_t *>(static_cast<ColumnVector<T>&>(*dict).getData().data()));
    }

    void setData(const Slice & data) override
    {
        if (data.size > 0)
        {
            uint8_t bit_width = *data.data;
            indexBatchDecoder
                = RleBatchDecoder<uint32_t>(reinterpret_cast<uint8_t *>(data.data) + 1, static_cast<int>(data.size) - 1, bit_width);
        }
        else
        {
            throw Exception(ErrorCodes::LOGICAL_ERROR, "input encoded data size is 0");
        }
    }

    void nextBatch(size_t count, MutableColumnPtr & dst) override
    {
        auto & indexes_vector = static_cast<ColumnVector<UInt32>&>(*indexes);
        dst->reserve(count);
        indexes_vector.getData().resize_fill(count);
        indexBatchDecoder.GetBatch(indexes_vector.getData().data(), static_cast<int32_t>(count));

        if (dst->isNullable())
        {
            auto & nullable_col = static_cast<ColumnNullable &>(*dst);
            nullable_col.getNullMapData().resize_fill(dst->size() + count);
            auto & column_data = static_cast<ColumnVector<T> &>(nullable_col.getNestedColumn());
            auto values = dict->index(*indexes, count);
            column_data.insertRangeFrom(*values, 0, count);
            //            for (size_t i = 0; i < count; i++)
            //            {
            //                column_data.getData().insert_assume_reserved(&dict[indexes[i]], &dict[indexes[i]] + 1);
            //            }
        }
        else
        {
            auto values = dict->index(*indexes, count);
            auto & column_data = static_cast<ColumnVector<T> &>(*dst);
            column_data.insertRangeFrom(*values, 0, count);
            //            for (size_t i = 0; i < count; i++)
            //            {
            //                column_data.getData().insert_assume_reserved(&dict[indexes[i]], &dict[indexes[i]] + 1);
            //            }
        }
    }

private:
    RleBatchDecoder<uint32_t> indexBatchDecoder;
    MutableColumnPtr dict;
    MutableColumnPtr indexes;
};


template <>
class DictDecoder<DB::String> final : public Decoder
{
public:
    DictDecoder() = default;
    ~DictDecoder() override = default;

    void setDict(size_t chunk_size, size_t num_values, Decoder & decoder) override
    {
        indexes = ColumnVector<UInt32>::create();
        indexes->reserve(chunk_size);
        slices.resize(chunk_size);
        auto type = std::make_shared<DataTypeString>();
        dict = type->createColumn();
        dict->reserve(num_values);
        decoder.nextBatch(num_values, dict);
    }

    void getDictValues(MutableColumnPtr & column) override { column->insertRangeFrom(*dict, 0, dict->size()); }

    void getDictValues(const std::vector<int32_t> & dict_codes, MutableColumnPtr & column) override
    {
        for (size_t i = 0; i < dict_codes.size(); i++)
        {
            column->insertFrom(*dict, i);
        }
    }

    void setData(const Slice & data) override
    {
        if (data.size > 0)
        {
            uint8_t bit_width = *data.data;
            index_batch_decoder
                = RleBatchDecoder<uint32_t>(reinterpret_cast<uint8_t *>(data.data) + 1, static_cast<int>(data.size) - 1, bit_width);
        }
        else
        {
            throw Exception(ErrorCodes::LOGICAL_ERROR, "input encoded data size is 0");
        }
    }

    void nextBatch(size_t count, MutableColumnPtr & dst) override
    {
        auto & indexes_vector = static_cast<ColumnVector<UInt32>&>(*indexes);
        dst->reserve(count);
        indexes_vector.getData().resize_fill(count);
        index_batch_decoder.GetBatch(indexes_vector.getData().data(), static_cast<int32_t>(count));
        if (dst->isNullable())
        {
            auto & nullable_col = static_cast<ColumnNullable &>(*dst);
            nullable_col.getNullMapData().resize_fill(dst->size() + count);
            auto & column_data = static_cast<ColumnString &>(nullable_col.getNestedColumn());
            auto values = dict->index(*indexes, count);
            column_data.insertRangeFrom(*values, 0, count);
        }
        else
        {
            auto values = dict->index(*indexes, count);
            auto & column_data = static_cast<ColumnString &>(*dst);
            column_data.insertRangeFrom(*values, 0, count);
        }
    }

private:
    RleBatchDecoder<uint32_t> index_batch_decoder;
    MutableColumnPtr dict;
    MutableColumnPtr indexes;
    std::vector<Slice> slices;
};

class LevelDecoder
{
public:
    void parse(parquet::format::Encoding::type encoding, size_t max_level, uint32_t num_levels, Slice * slice);

    // Try to decode n levels into levels;
    size_t decode_batch(size_t n, level_t * levels);

    size_t nextRepeatedCount() { return rle_decoder->repeatedCount(); }

    size_t get_repeated_value(size_t count);

private:
    parquet::format::Encoding::type encoding;
    size_t bit_width = 0;
    [[maybe_unused]] size_t max_level = 0;
    uint32_t num_levels = 0;
    std::shared_ptr<RleDecoder<level_t>> rle_decoder;
};

class EncodingInfo
{
public:
    static EncodingInfo get(parquet::format::Type::type type, parquet::format::Encoding::type encoding);
    template <typename TypeEncodingTraits>
    explicit EncodingInfo(TypeEncodingTraits traits);

    std::unique_ptr<Decoder> createDecoder() const { return create_decoder_func(); }


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
