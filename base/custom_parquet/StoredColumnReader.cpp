#include "StoredColumnReader.h"
#include "ParquetColumnChunkReader.h"

namespace DB
{
size_t RequiredStoredColumnReader::readRecords(size_t num_rows, MutableColumnPtr & dst)
{
    if (end) [[unlikely]]
    {
        return 0;
    }
    size_t records_read = 0;
    while (records_read < num_rows)
    {
        if (num_values_left_in_cur_page == 0)
        {
            try
            {
                next_page();
            }
            catch (EndOfFile &)
            {
                end = true;
                break;
            }
            if (num_values_left_in_cur_page == 0) [[unlikely]]
            {
                break;
            }
        }

        size_t records_to_read = std::min(num_rows - records_read, num_values_left_in_cur_page);
        if (records_to_read == 0) [[unlikely]]
        {
            break;
        }
        reader->decode_values(records_to_read, dst);
        records_read += records_to_read;
        num_values_left_in_cur_page -= records_to_read;
    }
    return records_read;
}


void RequiredStoredColumnReader::init(const ParquetField * field_, const parquet::format::ColumnChunk * chunk_metadata_)
{
    field = field_;
    reader = std::make_shared<ParquetColumnChunkReader>(field->max_def_level(), field->max_rep_level(), chunk_metadata_, opts);
    reader->init(opts.chunk_size);
}

std::unique_ptr<StoredColumnReader> StoredColumnReader::create(
    const ColumnReaderOptions & opts, const ParquetField * field, const parquet::format::ColumnChunk * chunk_metadata)
{
    if (field->max_rep_level() > 0)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "RepeatedStoredColumnReader not supported");
    }
    else if (field->max_def_level() > 0)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "OptionalStoredColumnReader not supported");
    }
    else
    {
        auto reader = std::make_unique<RequiredStoredColumnReader>(opts);
        reader->init(field, chunk_metadata);
        return reader;
    }
}

size_t StoredColumnReader::next_page()
{
    chassert(num_values_left_in_cur_page == 0);
    reader->loadHeader();
    if (reader->currentPageIsDict())
    {
        reader->loadPage();
        reader->skipPage();
        reader->loadHeader();
    }

    reader->loadPage();
    num_values_left_in_cur_page = reader->numValues();
    return num_values_left_in_cur_page;
}

}
