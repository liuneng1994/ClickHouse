#include "metadata.h"

namespace DB
{
void FileMetaData::init(const parquet::format::FileMetaData& metadata) {
    // construct schema from thrift
    schema_.from_thrift(metadata.schema);
    num_rows = metadata.num_rows;
    parquet_metadata = metadata;
}

std::string FileMetaData::debug_string() const {
    std::stringstream ss;
    ss << "schema=" << schema_.debug_string();
    return ss.str();
}
}
