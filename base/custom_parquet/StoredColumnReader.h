#pragma once

#include <generated/parquet_types.h>
#include "schema.h"
#include "type.h"
#include <Common/PODArray.h>


namespace DB
{

struct ColumnReaderOptions;
class ParquetColumnChunkReader;

class StoredColumnReader
{
public:
    static std::unique_ptr<StoredColumnReader>
    create(const ColumnReaderOptions & opts, const ParquetField * field, const parquet::format::ColumnChunk * chunk_metadata);
    explicit StoredColumnReader(const ColumnReaderOptions & opts_) : opts(opts_) { }

    virtual ~StoredColumnReader() = default;

    virtual void reset() = 0;

    virtual size_t readRecords(size_t num_rows, MutableColumnPtr & dst) = 0;

    virtual void get_levels(level_t ** def_levels, level_t ** rep_levels, size_t * num_levels) = 0;

protected:
    size_t next_page();

    std::shared_ptr<ParquetColumnChunkReader> reader;
    size_t num_values_left_in_cur_page = 0;
    const ColumnReaderOptions & opts;
    bool end = false;
};


class RequiredStoredColumnReader : public StoredColumnReader
{
public:
    explicit RequiredStoredColumnReader(const ColumnReaderOptions & opts_) : StoredColumnReader(opts_) { }
    ~RequiredStoredColumnReader() override = default;

    void init(const ParquetField * field_, const parquet::format::ColumnChunk * chunk_metadata_);

    void reset() override { }

    size_t readRecords(size_t num_rows, MutableColumnPtr & dst) override;

    void get_levels(level_t ** def_levels, level_t ** rep_levels, size_t * num_levels) override
    {
        *def_levels = nullptr;
        *rep_levels = nullptr;
        *num_levels = 0;
    }

private:
    const parquet::format::ColumnChunk chunk_metadata;
    const ParquetField * field = nullptr;
};

class OptionalStoredColumnReader : public StoredColumnReader
{
public:
    OptionalStoredColumnReader(const ColumnReaderOptions& opts_) : StoredColumnReader(opts_) {}
    ~OptionalStoredColumnReader() override = default;

    void init(const ParquetField* field, const parquet::format::ColumnChunk* chunk_metadata);

    // Reset internal state and ready for next read_values
    void reset() override;

    size_t readRecords(size_t num_records, MutableColumnPtr & dst) override {
//        if (_needs_levels) {
//            return _read_records_and_levels(num_records, dst);
//        } else {
            return _read_records_only(num_records, dst);
//        }
    }

//    void set_needs_levels(bool needs_levels) override { _needs_levels = needs_levels; }

    void get_levels(level_t** def_levels_, level_t** rep_levels, size_t* num_levels) override {
        // _needs_levels must be true
//        DCHECK(_needs_levels);

        *def_levels_ = nullptr;
        *rep_levels = nullptr;
        *num_levels = 0;
    }

private:
//    void _decode_levels(size_t num_levels);
    size_t _read_records_only(size_t num_records, MutableColumnPtr & dst);
//    size_t _read_records_and_levels(size_t num_records, MutableColumnPtr&  dst);

    const ParquetField* _field = nullptr;

    // When the flag is false, the information of levels does not need to be materialized,
    // so that the advantages of RLE encoding can be fully utilized and a lot of overhead
    // can be saved in decoding.
//    bool _needs_levels = false;

    size_t levels_capacity = 0;
    PaddedPODArray<uint8_t> is_nulls;
    PaddedPODArray<level_t> def_levels;
};
}
