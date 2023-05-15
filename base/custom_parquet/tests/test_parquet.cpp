#include <IO/ReadBufferFromFile.h>
#include <gtest/gtest.h>
#include <Poco/AutoPtr.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/Logger.h>
#include <DataTypes/DataTypesNumber.h>
#include "../ParquetFileReader.h"

using namespace DB;

TEST(Parquet, load_meta_data)
{
    auto file = std::make_shared<ReadBufferFromFile>("/home/saber/dev/data/tpch/parquet/lineitem/part-00000-f83d0a59-2bff-41bc-acde-911002bf1b33-c000.snappy.parquet");
    ScanParam param;
    param.header.insert({std::make_shared<DataTypeInt64>(), "l_orderkey"});
    param.header.insert({std::make_shared<DataTypeInt64>(), "l_partkey"});
    param.header.insert({std::make_shared<DataTypeInt64>(), "l_suppkey"});
    param.header.insert({std::make_shared<DataTypeInt64>(), "l_linenumber"});
    param.case_sensitive = false;
//    param.skip_row_groups.insert(0);   // 3351607
//    param.skip_row_groups.insert(1);   // 3351607
//    param.skip_row_groups.insert(2);   // 3351607
//    param.skip_row_groups.insert(3);   // 3351607
//    param.skip_row_groups.insert(4);   // 3347771
//    param.skip_row_groups.insert(5);   // 3241150

    auto reader = std::make_shared<ParquetFileReader>(file, param);
    reader->init();
    size_t count = 0;
    while (true)
    {
        auto chunk = reader->getNext();
        if (chunk.getNumRows() == 0)
            break;
        count += chunk.getNumRows();
    }
    ASSERT_EQ(count, 19995349);
}

int main(int argc, char ** argv)
{
    Poco::AutoPtr<Poco::ConsoleChannel> channel(new Poco::ConsoleChannel(std::cerr));
    Poco::Logger::root().setChannel(channel);
    Poco::Logger::root().setLevel("trace");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
