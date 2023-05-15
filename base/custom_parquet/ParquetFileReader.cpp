#include "ParquetFileReader.h"
#include <DataTypes/DataTypeArray.h>
#include <DataTypes/DataTypeFactory.h>
#include <DataTypes/DataTypeMap.h>
#include <IO/ReadBufferFromFileBase.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/protocol/TProtocol.h>
#include <Common/Exception.h>
#include <Common/PODArray.h>
#include "thrift/ThriftFileTransport.h"
#include <generated/parquet_types.h>
#include "ParquetRowGroupReader.h"


namespace DB
{

namespace ErrorCodes
{
    extern const int LOGICAL_ERROR;
}


void check(bool condition, String msg)
{
    if (!condition)
    {
        throw Exception::createRuntime(ErrorCodes::LOGICAL_ERROR, msg);
    }
}

ParquetFileReader::ParquetFileReader(const std::shared_ptr<ReadBufferFromFileBase> file_, ScanParam param_, size_t chunk_size_)
    : file(file_), chunk_size(chunk_size_), param(param_)
{
    file_length = file->getFileSize();
}

std::unique_ptr<apache::thrift::protocol::TProtocol> createThriftProtocol(std::shared_ptr<ReadBufferFromFileBase> file)
{
    auto transport = std::make_shared<ThriftFileTransport>(file);
    return std::make_unique<apache::thrift::protocol::TCompactProtocolT<ThriftFileTransport>>(transport);
}

void ParquetFileReader::loadFileMetaData()
{
    auto file_size = file->getFileSize();
    auto proto = createThriftProtocol(file);
    auto & transport = *reinterpret_cast<ThriftFileTransport *>(proto->getTransport().get());
    PODArray<uint8_t> buf(8);
    transport.setLocation(file_length - 8);
    transport.read(buf.data(), 8);
    if (strncmp(reinterpret_cast<char *>(buf.data()) + 4, "PAR1", 4) != 0)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "No magic bytes found at end of file '{}'", file->getFileName());
    }
    auto footer_len = *reinterpret_cast<uint32_t *>(buf.data());
    if (footer_len <= 0 || file_size < 12 + footer_len)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Footer length error in file '{}'", file->getFileName());
    }
    auto metadata_pos = file_size - (footer_len + 8);
    transport.setLocation(metadata_pos);
    parquet::format::FileMetaData meta;
    meta.read(proto.get());
    metadata.init(meta);
}

void ParquetFileReader::init()
{
    if (file_length == 0)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Parquet file is empty");
    if (file_length < 12)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Parquet file is too small");
    loadFileMetaData();
    prepareReadColumns();
    initGroupReaders();
}


void ParquetFileReader::prepareReadColumns()
{
    size_t col_idx = 0;
    for (const auto & column : param.header.getColumnsWithTypeAndName())
    {
        size_t field_index = metadata.schema().get_column_index(column.name, param.case_sensitive);

        auto parquet_type = metadata.schema().getStoredColumnByIdx(field_index)->physical_type;
        metadata.schema_._fields[field_index].type = column.type;
        ParquetGroupReaderParam::Column read_col{};
        read_col.col_idx_in_parquet = field_index;
        read_col.col_type_in_parquet = parquet_type;
        read_col.col_idx_in_chunk = col_idx;
        read_col.col_type_in_chunk = column.type;
        read_cols.emplace_back(read_col);
        col_idx++;
    }
}

void ParquetFileReader::initGroupReaders()
{
    group_reader_param.read_cols = read_cols;
    group_reader_param.chunk_size = chunk_size;
    group_reader_param.file_metadata = &metadata;
    group_reader_param.case_sensitive = param.case_sensitive;
    group_reader_param.file_read_buffer = file;

    // select and create row group readers.
    for (size_t i = 0; i < metadata.parquetMetaData().row_groups.size(); i++)
    {
        if (param.skip_row_groups.contains(i)) continue;
        auto row_group_reader = std::make_shared<ParquetGroupReader>(group_reader_param, i);
        row_group_readers.emplace_back(row_group_reader);
        total_row_count += metadata.parquetMetaData().row_groups[i].num_rows;
    }
    row_group_size = row_group_readers.size();


    // initialize row group readers.
    for (const auto& reader : row_group_readers)
    {
        reader->init();
    }
}


Chunk ParquetFileReader::getNext()
{
    while (cur_row_group_idx < row_group_size)
    {
        Chunk res = row_group_readers[cur_row_group_idx]->getNext();
        if (res.hasRows())
        {
            scan_row_count += res.getNumRows();
            return res;
        }
        else
        {
            row_group_readers[cur_row_group_idx]->close();
            cur_row_group_idx++;
        }
    }
    return {};
}

}
