#pragma once

#include <generated/parquet_types.h>
#include "schema.h"
#include "type.h"


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
    bool end = false;
};
}
