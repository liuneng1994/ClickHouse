#pragma once
#include <Core/Block.h>
#include <Processors/Chunk.h>
#include <DataTypes/DataTypeNested.h>
#include <IO/ReadBufferFromFileBase.h>
#include "metadata.h"
#include "param.h"

namespace parquet
{
namespace format
{
    class FileMetaData;
    class SchemaElement;
}
}


namespace DB
{

class ReadBufferFromFileBase;
class ParquetGroupReader;
struct ParquetGroupReaderParam;

struct ScanParam
{
    Block header;
    std::set<size_t> skip_row_groups;
    bool case_sensitive = false;
};

class ParquetFileReader
{
public:
    ParquetFileReader(std::shared_ptr<ReadBufferFromFileBase> file, ScanParam context, size_t chunk_size = 8192);
    void init();
    Chunk getNext();

private:
    // Reads and parses file footer.
    void loadFileMetaData();
    void prepareReadColumns();
    void initGroupReaders();


    std::shared_ptr<ReadBufferFromFileBase> file;
    size_t file_length;
    FileMetaData metadata;
    std::vector<std::shared_ptr<ParquetGroupReader>> row_group_readers;
    ParquetGroupReaderParam group_reader_param;
    size_t chunk_size;
    ScanParam param;
    std::vector<ParquetGroupReaderParam::Column> read_cols;
    size_t total_row_count = 0;
    size_t scan_row_count = 0;
    size_t row_group_size = 0;
    size_t cur_row_group_idx = 0;
};

} // DB
