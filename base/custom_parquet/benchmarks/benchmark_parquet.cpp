#include <iostream>
#include <DataTypes/DataTypesNumber.h>
#include <IO/ReadBufferFromFile.h>
#include <Processors/Executors/PullingPipelineExecutor.h>
#include <Processors/Formats/Impl/ParquetBlockInputFormat.h>
#include <QueryPipeline/QueryPipelineBuilder.h>
#include <benchmark/benchmark.h>
#include "../ParquetFileReader.h"

using namespace DB;


class ParquetFixture : public ::benchmark::Fixture
{
public:
    void SetUp(const ::benchmark::State &) { }

    ~ParquetFixture() { }
};

const String file_path = "/home/saber/dev/data/tpch/parquet/lineitem/part-00000-f83d0a59-2bff-41bc-acde-911002bf1b33-c000.snappy.parquet";

void testCustomParquet()
{
    auto file = std::make_shared<ReadBufferFromFile>(
        file_path);
    ScanParam param;
    param.header.insert({std::make_shared<DataTypeInt64>(), "l_orderkey"});
    param.header.insert({std::make_shared<DataTypeInt64>(), "l_partkey"});
    param.header.insert({std::make_shared<DataTypeInt64>(), "l_suppkey"});
    param.header.insert({std::make_shared<DataTypeInt64>(), "l_linenumber"});
    param.header.insert({std::make_shared<DataTypeFloat64>(), "l_quantity"});
    param.header.insert({std::make_shared<DataTypeFloat64>(), "l_extendedprice"});
    param.header.insert({std::make_shared<DataTypeFloat64>(), "l_discount"});
    param.case_sensitive = false;
    auto reader = std::make_shared<ParquetFileReader>(file, param);
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

void testCommunityParquet()
{
    auto file = std::make_shared<ReadBufferFromFile>(
        file_path);
    Block header;
    header.insert({std::make_shared<DataTypeInt64>(), "l_orderkey"});
    header.insert({std::make_shared<DataTypeInt64>(), "l_partkey"});
    header.insert({std::make_shared<DataTypeInt64>(), "l_suppkey"});
    header.insert({std::make_shared<DataTypeInt64>(), "l_linenumber"});
    header.insert({std::make_shared<DataTypeFloat64>(), "l_quantity"});
    header.insert({std::make_shared<DataTypeFloat64>(), "l_extendedprice"});
    header.insert({std::make_shared<DataTypeFloat64>(), "l_discount"});
    FormatSettings settings;
    auto input_format = std::make_shared<ParquetBlockInputFormat>(file.get(), nullptr, header, settings, 1, 8192);
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


BENCHMARK_F(ParquetFixture, BM_CustomParquet)(benchmark::State & state)
{
    for (auto _ : state)
    {
        testCustomParquet();
    }
}
//BENCHMARK_F(ParquetFixture, BM_CommunityParquet)(benchmark::State & state)
//{
//    for (auto _ : state)
//    {
//        testCommunityParquet();
//    }
//}

BENCHMARK_REGISTER_F(ParquetFixture, BM_CustomParquet)->Unit(benchmark::TimeUnit::kMillisecond)->Iterations(20);
//BENCHMARK_REGISTER_F(ParquetFixture, BM_CommunityParquet)->Unit(benchmark::TimeUnit::kMillisecond)->Iterations(20);


// Run the benchmark
BENCHMARK_MAIN();
