#pragma once
#include <IO/ReadBufferFromFileBase.h>
#include <Core/Block.h>

namespace DB
{

class ReadBufferFromFileBase;

class NativeParquetReader
{
public:
    explicit NativeParquetReader(const std::shared_ptr<ReadBufferFromFileBase> file);

private:
    // Reads and parses file footer.
    void loadFileMetaData();

    void initializeSchema();


    std::shared_ptr<ReadBufferFromFileBase> file;
    size_t file_length;
    BlockPtr schema;
};

} // DB

