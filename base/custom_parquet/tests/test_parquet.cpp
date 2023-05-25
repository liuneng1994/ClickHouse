#include <DataTypes/DataTypeNullable.h>
#include <DataTypes/DataTypeString.h>
#include <DataTypes/DataTypesNumber.h>
#include <DataTypes/DataTypeDate32.h>
#include <Columns/ColumnNullable.h>
#include <IO/ReadBufferFromFile.h>
#include <gtest/gtest.h>
#include <Poco/AutoPtr.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/Logger.h>
#include <Functions/FunctionFactory.h>
#include "../ParquetFileReader.h"

using namespace DB;

DataTypePtr string_type = makeNullable(std::make_shared<DataTypeString>());
DataTypePtr int64_type = makeNullable(std::make_shared<DataTypeInt64>());
DataTypePtr float_type = makeNullable(std::make_shared<DataTypeFloat64>());
DataTypePtr date_type = makeNullable(std::make_shared<DataTypeDate32>());



TEST(Parquet, load_meta_data)
{
    auto file = std::make_shared<ReadBufferFromFile>(
        "/home/admin1/data/tpch100/parquet/lineitem/part-00000-066b93b4-39e1-4d46-83ab-d7752096b599-c000.snappy.parquet");
    ScanParam param;
//    param.header.insert({int64_type, "l_orderkey"});
//    param.header.insert({int64_type, "l_partkey"});
//    param.header.insert({int64_type, "l_suppkey"});
//    param.header.insert({int64_type, "l_linenumber"});
    param.header.insert({string_type, "l_comment"});
//    param.header.insert({string_type, "l_shipmode"});
//    param.header.insert({string_type, "l_returnflag"});
//    param.header.insert({string_type, "l_linestatus"});
//    param.header.insert({date_type, "l_shipdate"});
//    param.header.insert({date_type, "l_commitdate"});
//    param.header.insert({date_type, "l_receiptdate"});

    param.case_sensitive = false;
//    param.skip_row_groups.insert(0);   // 3351607
//    param.skip_row_groups.insert(1);   // 3351607
//    param.skip_row_groups.insert(2);   // 3351607
//    param.skip_row_groups.insert(3);   // 3351607
//    param.skip_row_groups.insert(4);   // 3347771
//    param.skip_row_groups.insert(5);   // 3241150

    auto reader = std::make_shared<ParquetFileReader>(file.get(), param, 8192);
    reader->init();
    size_t count = 0;
    while (true)
    {
        auto chunk = reader->getNext();

        if (chunk.getNumRows() == 0)
            break;
        if (count < 30)
        {
            for (size_t i = 0; i < std::min(chunk.getNumRows(), (size_t)50); ++i)
            {
                for (size_t j = 0; j < chunk.getNumColumns(); ++j)
                {
                    auto nested_column = chunk.getColumns().at(j);
                    if (const auto *nullable_column = checkAndGetColumn<ColumnNullable>(*nested_column))
                    {
                        nested_column = nullable_column->getNestedColumnPtr();
                    }
                    if (nested_column->isNumeric())
                    {
                        std::cerr << std::to_string(nested_column->getFloat64(i)) << '\t';
                    }
                    else
                    {
                        auto data = nested_column->getDataAt(i);
                        std::string_view res(data.data, data.size);
                        std::cerr << res << '\t';
                    }
                }
                std::cerr << std::endl;
            }
        }
        count += chunk.getNumRows();
    }
    ASSERT_EQ(count, 6667105);
}

int main(int argc, char ** argv)
{
    Poco::AutoPtr<Poco::ConsoleChannel> channel(new Poco::ConsoleChannel(std::cerr));
    Poco::Logger::root().setChannel(channel);
    Poco::Logger::root().setLevel("trace");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
