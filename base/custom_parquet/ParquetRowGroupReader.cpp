#include "ParquetRowGroupReader.h"

namespace DB
{
ParquetGroupReader::ParquetGroupReader(ParquetGroupReaderParam & param_, int row_group_number) : param(param_)
{
    row_group_metadata = std::make_shared<parquet::format::RowGroup>(param.file_metadata->parquetMetaData().row_groups[row_group_number]);
}

void ParquetGroupReader::init()
{
    initColumnReaders();
    for (int read_col_idx = 0; (size_t)read_col_idx < param.read_cols.size(); read_col_idx++)
    {
        active_column_indices.emplace_back(read_col_idx);
    }
}

Chunk ParquetGroupReader::getNext()
{
    return read(active_column_indices, param.chunk_size);
}

void ParquetGroupReader::close()
{
    column_readers.clear();
}

void ParquetGroupReader::initColumnReaders()
{
    ColumnReaderOptions & opts = column_reader_opts;
    opts.timezone = param.timezone;
    opts.case_sensitive = param.case_sensitive;
    opts.chunk_size = param.chunk_size;
    opts.stream = param.file_read_buffer;
    opts.row_group_meta = row_group_metadata.get();

    for (const auto & column : param.read_cols)
    {
        createColumnReader(column);
    }
}

void ParquetGroupReader::createColumnReader(const ParquetGroupReaderParam::Column & column)
{
    const auto * schema_node = param.file_metadata->schema().getStoredColumnByIdx(column.col_idx_in_parquet);
    std::unique_ptr<ParquetColumnReader> column_reader = ParquetColumnReader::create(column_reader_opts, schema_node);
    column_readers[column.col_idx_in_chunk] = std::move(column_reader);
}

Chunk ParquetGroupReader::read(const std::vector<int> & read_columns, size_t row_count)
{
    if (read_columns.empty())
    {
        return {};
    }
    MutableColumns columns;
    for (int col_idx : read_columns)
    {
        auto & column = param.read_cols[col_idx];
        auto col = column.col_type_in_chunk->createColumn();
        col->reserve(row_count);
        column_readers[column.col_idx_in_chunk]->next_batch(row_count, col);
        columns.emplace_back(std::move(col));
    }
    size_t rows_read = columns.begin()->get()->size();
    return Chunk(std::move(columns), rows_read);
}
}
