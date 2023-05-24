#include <filesystem>
#include <iostream>
#include <DataTypes/DataTypeString.h>
#include <DataTypes/DataTypesNumber.h>
#include <DataTypes/DataTypeNullable.h>
#include <DataTypes/DataTypeDate32.h>
#include <IO/ReadBufferFromFile.h>
#include <Processors/Executors/PullingPipelineExecutor.h>
#include <Processors/Formats/Impl/ParquetBlockInputFormat.h>
#include <QueryPipeline/QueryPipelineBuilder.h>
#include <benchmark/benchmark.h>
#include "../ParquetFileReader.h"

using namespace DB;

const String data_path = "/home/admin1/data/tpch-velox/lineitem/";

DataTypePtr string_type = makeNullable(std::make_shared<DataTypeString>());
DataTypePtr int64_type = makeNullable(std::make_shared<DataTypeInt64>());
DataTypePtr double_type = makeNullable(std::make_shared<DataTypeFloat64>());
DataTypePtr date_type = makeNullable(std::make_shared<DataTypeDate32>());


//DataTypePtr string_type = std::make_shared<DataTypeString>();
//DataTypePtr int64_type = std::make_shared<DataTypeInt64>();
//DataTypePtr double_type = std::make_shared<DataTypeFloat64>();

void testCustomParquet(int chunk_size)
{
    for (const auto & entry : fs::directory_iterator(data_path))
    {
        if (entry.path().extension() != ".parquet")
            continue;
        auto file = std::make_shared<ReadBufferFromFile>(entry.path());
        ScanParam param;
        param.header.insert({int64_type, "l_orderkey"});
        param.header.insert({int64_type, "l_partkey"});
        param.header.insert({int64_type, "l_suppkey"});
        param.header.insert({int64_type, "l_linenumber"});
        param.header.insert({double_type, "l_quantity"});
        param.header.insert({double_type, "l_extendedprice"});
        param.header.insert({double_type, "l_discount"});
        param.header.insert({double_type, "l_tax"});
        param.header.insert({string_type, "l_returnflag"});
        param.header.insert({string_type, "l_linestatus"});
        param.header.insert({date_type, "l_shipdate"});
        param.header.insert({date_type, "l_commitdate"});
        param.header.insert({date_type, "l_receiptdate"});
        param.header.insert({string_type, "l_shipinstruct"});
        param.header.insert({string_type, "l_shipmode"});
        param.header.insert({string_type, "l_comment"});

        param.case_sensitive = false;
        auto reader = std::make_shared<ParquetFileReader>(file, param, chunk_size);
        reader->init();
        [[maybe_unused]] size_t count = 0;
        while (true)
        {
            auto chunk = reader->getNext();
            if (chunk.getNumRows() == 0)
                break;
            count += chunk.getNumRows();
        }
    }
}

void testCommunityParquet(int chunk_size)
{
    for (const auto & entry : fs::directory_iterator(data_path))
    {
        if (entry.path().extension() != ".parquet")
            continue;
        auto file = std::make_shared<ReadBufferFromFile>(entry.path());
        Block header;
        header.insert({int64_type, "l_orderkey"});
        header.insert({int64_type, "l_partkey"});
        header.insert({int64_type, "l_suppkey"});
        header.insert({int64_type, "l_linenumber"});
        header.insert({double_type, "l_quantity"});
        header.insert({double_type, "l_extendedprice"});
        header.insert({double_type, "l_discount"});
        header.insert({double_type, "l_tax"});
        header.insert({string_type, "l_returnflag"});
        header.insert({string_type, "l_linestatus"});
        header.insert({date_type, "l_shipdate"});
        header.insert({date_type, "l_commitdate"});
        header.insert({date_type, "l_receiptdate"});
        header.insert({string_type, "l_shipinstruct"});
        header.insert({string_type, "l_shipmode"});
        header.insert({string_type, "l_comment"});

        FormatSettings settings;
        auto input_format = std::make_shared<ParquetBlockInputFormat>(file.get(), nullptr, header, settings, 1, chunk_size);
        QueryPipelineBuilder builder;
        builder.init(Pipe(input_format));
        auto pipeline = QueryPipelineBuilder::getPipeline(std::move(builder));
        auto executor = std::make_shared<PullingPipelineExecutor>(pipeline);
        Chunk chunk;
        [[maybe_unused]] size_t count = 0;
        while (executor->pull(chunk))
        {
            count += chunk.getNumRows();
        }
    }
}


void BM_CustomParquet(benchmark::State & state)
{
    for (auto _ : state)
    {
        testCustomParquet(state.range(0));
    }
}
void BM_CommunityParquet(benchmark::State & state)
{
    for (auto _ : state)
    {
        testCommunityParquet(state.range(0));
    }
}

BENCHMARK(BM_CustomParquet)
//    ->Arg(2048)
//    ->Arg(4096)
    ->Arg(8192)
    ->Arg(8192 * 2)
    ->Arg(8192 * 3)
    ->Arg(8192 * 4)
    ->MinWarmUpTime(2)
    ->MinTime(20)
    //    ->Threads(8)
    ->Unit(benchmark::TimeUnit::kMillisecond);

BENCHMARK(BM_CommunityParquet)
//    ->Arg(2048)
//    ->Arg(4096)
    ->Arg(8192)
    ->Arg(8192 * 2)
    ->Arg(8192 * 3)
    ->Arg(8192 * 4)
    ->MinWarmUpTime(2)
    ->MinTime(20)
//        ->Threads(8)
    ->Unit(benchmark::TimeUnit::kMillisecond);


// Run the benchmark
BENCHMARK_MAIN();
