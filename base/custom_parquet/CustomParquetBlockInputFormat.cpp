#include "CustomParquetBlockInputFormat.h"

namespace DB
{

Chunk CustomParquetBlockInputFormat::generate()
{
    initializeIfNeeded();

    return file_reader->getNext();
}
CustomParquetBlockInputFormat::CustomParquetBlockInputFormat(ReadBufferFromFileBase * buf, const Block & header_, const FormatSettings & format_settings_)
    : IInputFormat(header_, buf)
    , format_settings(format_settings_)
{
}

void CustomParquetBlockInputFormat::resetParser()
{
    file_reader.reset();
    is_stopped = false;
    is_initialized = false;
    IInputFormat::resetParser();
}
void CustomParquetBlockInputFormat::initializeIfNeeded()
{
    if (std::exchange(is_initialized, true))
        return;
    ScanParam param;
    param.header = getOutputs().begin()->getHeader();
    param.case_sensitive = false;
    param.skip_row_groups.insert(format_settings.parquet.skip_row_groups.begin(), format_settings.parquet.skip_row_groups.end());
    file_reader = std::make_shared<ParquetFileReader>(reinterpret_cast<ReadBufferFromFileBase *>(in), param, 8192);
    file_reader->init();
}
}
