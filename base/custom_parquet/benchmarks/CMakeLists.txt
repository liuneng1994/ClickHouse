clickhouse_add_executable(benchmark_parquet benchmark_parquet.cpp)
target_link_libraries (benchmark_parquet PRIVATE
        ch_contrib::gbenchmark_all
        clickhouse_functions
        dbms
        parquet
        )