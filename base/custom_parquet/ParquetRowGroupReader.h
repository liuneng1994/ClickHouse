#pragma once
#include <Core/Block.h>
#include <DataTypes/IDataType.h>
#include <generated/parquet_types.h>
#include <Processors/Chunk.h>
#include "ParquetColumnReader.h"
#include "metadata.h"
#include "param.h"

namespace DB
{


class ParquetGroupReader {
public:
    ParquetGroupReader(ParquetGroupReaderParam& param, int row_group_number);
    ~ParquetGroupReader() = default;

    void init();
    Chunk getNext();
    void close();

private:
    void initColumnReaders();
    void createColumnReader(const ParquetGroupReaderParam::Column& column);

    Chunk read(const std::vector<int>& read_columns, size_t row_count);

    std::shared_ptr<parquet::format::RowGroup> row_group_metadata;
    std::unordered_map<size_t, std::unique_ptr<ParquetColumnReader>> column_readers;
    std::vector<ParquetGroupReaderParam::Column> direct_read_columns;
    std::vector<int> active_column_indices;
    ParquetGroupReaderParam& param;
    ColumnReaderOptions column_reader_opts;
};
}


