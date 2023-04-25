#pragma once
#include <IO/ReadBufferFromFileBase.h>
#include <Core/Block.h>
#include "ParquetMetaData.h"
#include "NativeColumnReader.h"
#include "ParquetTypeInfo.h"
#include <DataTypes/DataTypeNested.h>

namespace DB
{

class ReadBufferFromFileBase;

class NativeParquetReader
{
public:
    static BlockPtr createHeader(std::vector<ParquetTypeInfoPtr> cols);
    static DataTypePtr createRowType(
        std::vector<std::shared_ptr<ParquetTypeInfo>>
            children);

    explicit NativeParquetReader(std::shared_ptr<ReadBufferFromFileBase> file);

private:
    // Reads and parses file footer.
    void loadFileMetaData();
    void initializeSchema();
    std::unique_ptr<NativeColumnReader> createReader();
    std::shared_ptr<ParquetTypeInfo> getParquetColumnInfo(
        size_t maxSchemaElementIdx,
        size_t maxRepeat,
        size_t maxDefine,
        size_t schemaIdx,
        size_t columnIdx) const;

    DataTypePtr convertType(const SchemaElement& schemaElement) const;

    std::shared_ptr<ReadBufferFromFileBase> file;
    size_t file_length;
    ParquetTypeInfoPtr schema_info;
    BlockPtr header;
    std::unique_ptr<FileMetaData> metaData;
};

} // DB

