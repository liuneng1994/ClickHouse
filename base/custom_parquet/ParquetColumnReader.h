#pragma once

#include <Columns/IColumn.h>
#include <DataTypes/IDataType.h>
#include <IO/SeekableReadBuffer.h>
#include <generated/parquet_types.h>
#include "StoredColumnReader.h"
#include "Utils.h"
#include "param.h"
#include "schema.h"
#include "type.h"


namespace DB
{
class StoredColumnReader;

class ParquetColumnReader
{
public:
    static std::unique_ptr<ParquetColumnReader> create(const ColumnReaderOptions & opts, const ParquetField * field);

    virtual ~ParquetColumnReader() = default;

    virtual void prepare_batch(size_t num_records, MutableColumnPtr & column) = 0;
    virtual void finish_batch() = 0;

    void next_batch(size_t num_records, MutableColumnPtr & column)
    {
        prepare_batch(num_records, column);
        finish_batch();
    }

    virtual bool canUseMinMaxStatics() { return reader->canUseMinMaxStatics(); }

    std::pair<ColumnPtr, ColumnPtr> readMinMaxColumn() {return reader->readMinMaxColumn();}

    size_t nextPage() {return reader->nextPage();}

    size_t skipPage() {return reader->skipPage();}

    void skipRows(size_t rows) {return reader->skipRows(rows);}

    virtual DataTypePtr getStatsType() = 0;

    virtual void get_levels(level_t ** def_levels, level_t ** rep_levels, size_t * num_levels) = 0;

    virtual void get_dict_values(MutableColumnPtr & /*column*/)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "getDictCodes not supported");
    }

    virtual void get_dict_values(const std::vector<int32_t> & /*dict_codes*/, MutableColumnPtr & /*column*/)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "getDictCodes not supported");
    }

    virtual void get_dict_codes(const std::vector<Slice> & /*dict_values*/, std::vector<int32_t> * /*dict_codes*/)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "getDictCodes not supported");
    }

protected:
    std::unique_ptr<StoredColumnReader> reader;
};

class ScalarColumnReader : public ParquetColumnReader
{
public:
    explicit ScalarColumnReader(const ColumnReaderOptions & opts_) : opts(opts_) { }
    ~ScalarColumnReader() override = default;

    void init(const ParquetField * field, const parquet::format::ColumnChunk * chunk_metadata)
    {
        reader = StoredColumnReader::create(opts, field, chunk_metadata);
    }

    void prepare_batch(size_t num_records, MutableColumnPtr & dst) override { reader->readRecords(num_records, dst); }

    void finish_batch() override { }

    void get_levels(level_t ** def_levels, level_t ** rep_levels, size_t * num_levels) override
    {
        reader->getLevels(def_levels, rep_levels, num_levels);
    }

    bool canUseMinMaxStatics() override { return reader->canUseMinMaxStatics(); }

    DataTypePtr getStatsType() override { return opts.stats_type; }

private:
    const ColumnReaderOptions & opts;
};

class ListColumnReader : public ParquetColumnReader
{
};

class MapColumnReader : public ParquetColumnReader
{
};

class StructColumnReader : public ParquetColumnReader
{
};

}
