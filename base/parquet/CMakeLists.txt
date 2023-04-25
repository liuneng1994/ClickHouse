add_library(
        parquet
        NativeParquetReader.h
        NativeParquetReader.cpp
        ParquetMetaData.h
        ParquetMetaData.cpp
        thrift/ThriftFileTransport.h
        NativeColumnReader.cpp NativeColumnReader.h ParquetTypeInfo.cpp ParquetTypeInfo.h)

target_link_libraries(parquet
        clickhouse_common_io
        dbms
        ch_contrib::thrift
)

add_subdirectory(tests)