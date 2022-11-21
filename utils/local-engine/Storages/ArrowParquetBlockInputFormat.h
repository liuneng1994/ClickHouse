#pragma once

#include <Common/ChunkBuffer.h>
#include <Common/SourceStatistics.h>
#include "ch_parquet/OptimizedParquetBlockInputFormat.h"
#include "ch_parquet/OptimizedArrowColumnToCHColumn.h"
#include "ch_parquet/arrow/reader.h"

namespace arrow
{
class RecordBatchReader;
class Table;
}

namespace local_engine
{
class ArrowParquetBlockInputFormat : public DB::OptimizedParquetBlockInputFormat , public SourceStatistics
{
public:
    ArrowParquetBlockInputFormat(DB::ReadBuffer & in, const DB::Block & header, const DB::FormatSettings & formatSettings, const std::vector<int> & row_group_indices_ = {});
    //virtual ~ArrowParquetBlockInputFormat();
    virtual long getReadBufferTime()
    {
        return in->time_micro_seconds;
    }

    virtual long getReadBufferDataSize()
    {
        return in->data_size;
    }

    ~ArrowParquetBlockInputFormat() override;

private:
    DB::Chunk generate() override;

    int64_t convert_time = 0;
    int64_t non_convert_time = 0;
    std::shared_ptr<arrow::RecordBatchReader> current_record_batch_reader;
    std::vector<int> row_group_indices;
};

}
