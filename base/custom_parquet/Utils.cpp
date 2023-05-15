#include "Utils.h"

namespace DB
{
CompressionMethod getCompressionMethod(parquet::format::CompressionCodec::type codec)
{
    switch (codec)
    {
        case parquet::format::CompressionCodec::UNCOMPRESSED:
            return CompressionMethod::None;
        case parquet::format::CompressionCodec::SNAPPY:
            return CompressionMethod::Snappy;
        case parquet::format::CompressionCodec::LZ4:
            return CompressionMethod::Lz4;
        case parquet::format::CompressionCodec::ZSTD:
            return CompressionMethod::Zstd;
        case parquet::format::CompressionCodec::GZIP:
            return CompressionMethod::Gzip;
        case parquet::format::CompressionCodec::BROTLI:
            return CompressionMethod::Brotli;
        default:
            throw Exception(ErrorCodes::LOGICAL_ERROR, "unknown compression codec");
    }
}

}
