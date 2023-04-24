//
// Created by admin1 on 23-4-24.
//

#include "NativeParquetReader.h"
#include "thrift/ThriftFileTransport.h"
#include "ParquetMetaData.h"
#include <Common/Exception.h>
#include <Common/PODArray.h>
#include <IO/ReadBufferFromFileBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/protocol/TCompactProtocol.h>


namespace DB
{

namespace ErrorCodes
{
    extern const int LOGICAL_ERROR;
}


NativeParquetReader::NativeParquetReader(const std::shared_ptr<ReadBufferFromFileBase> file_) : file(file_)
{
    file_length = file->getFileSize();
    if (file_length == 0)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Parquet file is empty");
    if (file_length < 12)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Parquet file is too small");
    loadFileMetaData();
    initializeSchema();
}

static std::unique_ptr<apache::thrift::protocol::TProtocol> createThriftProtocol(std::shared_ptr<ReadBufferFromFileBase> file)
{
    auto transport = std::make_shared<ThriftFileTransport>(file);
    return std::make_unique<apache::thrift::protocol::TCompactProtocolT<ThriftFileTransport>>(transport);
}

void NativeParquetReader::loadFileMetaData()
{
    Stopwatch timer;
    timer.start();
    auto file_size = file->getFileSize();
    auto proto = createThriftProtocol(file);
    auto &transport = *reinterpret_cast<ThriftFileTransport*>(proto->getTransport().get());
    PODArray<uint8_t> buf;
    buf.resize(8);
    transport.setLocation(file_length - 8);
    transport.read(buf.data(), 8);
    if (strncmp(reinterpret_cast<char*>(buf.data()) + 4, "PAR1", 4) != 0) {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "No magic bytes found at end of file '{}'", file->getFileName());
    }
    auto footer_len = *reinterpret_cast<uint32_t*>(buf.data());
    if (footer_len <= 0 || file_size < 12 + footer_len) {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Footer length error in file '{}'", file->getFileName());
    }
    auto metadata_pos = file_size - (footer_len + 8);
    transport.setLocation(metadata_pos);

}

void NativeParquetReader::initializeSchema()
{
}
}
