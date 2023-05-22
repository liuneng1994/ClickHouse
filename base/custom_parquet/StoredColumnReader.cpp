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
        auto reader = std::make_unique<OptionalStoredColumnReader>(opts);
        reader->init(field, chunk_metadata);
        return reader;
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

void OptionalStoredColumnReader::init(const ParquetField * field, const parquet::format::ColumnChunk * chunk_metadata)
{
    _field = field;
    reader = std::make_shared<ParquetColumnChunkReader>(_field->max_def_level(), _field->max_rep_level(), chunk_metadata, opts);
    reader->init(opts.chunk_size);
}
size_t OptionalStoredColumnReader::_read_records_only(size_t num_rows, MutableColumnPtr & dst)
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
        size_t repeated_count = reader->getDefLevelDecoder().nextRepeatedCount();
        if (repeated_count > 0)
        {
            records_to_read = std::min(records_to_read, repeated_count);
            level_t def_level = 0;
            def_level = reader->getDefLevelDecoder().get_repeated_value(records_to_read);
            if (def_level >= _field->max_def_level())
            {
                reader->decode_values(records_to_read, dst);
            }
            else
            {
                dst->insertManyDefaults(records_to_read);
            }
        }
        else
        {
            {
                size_t new_capacity = records_to_read;
                if (new_capacity > levels_capacity)
                {
                    def_levels.reserve(new_capacity);

                    levels_capacity = new_capacity;
                }
                reader->decode_def_levels(records_to_read, def_levels.data());
            }

            size_t i = 0;
            while (i < records_to_read)
            {
                size_t j = i;
                bool is_null = def_levels[j] < _field->max_def_level();
                j++;
                while (j < records_to_read && is_null == (def_levels[j] < _field->max_def_level()))
                {
                    j++;
                }
                if (is_null)
                {
                    dst->insertManyDefaults(j - i);
                }
                else
                {
                    reader->decode_values(j - i, dst);
                }
                i = j;
            }
        }
        num_values_left_in_cur_page -= records_to_read;
        records_read += records_to_read;
    }

    return records_read;
}
void OptionalStoredColumnReader::reset()
{
    def_levels.resize_fill(def_levels.size());
}
//size_t OptionalStoredColumnReader::_read_records_and_levels(size_t , MutableColumnPtr & )
//{
//    return 0;
//}
}
