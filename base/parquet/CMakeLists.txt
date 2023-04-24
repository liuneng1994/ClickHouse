add_library(
        parquet
        NativeParquetReader.h
        NativeParquetReader.cpp
        ParquetMetaData.h
        ParquetMetaData.cpp
        thrift/ThriftFileTransport.h
)

target_link_libraries(parquet
        clickhouse_common_io
        ch_contrib::thrift
)