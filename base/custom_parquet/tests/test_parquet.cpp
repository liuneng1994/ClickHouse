#include <Columns/ColumnNullable.h>
#include <DataTypes/DataTypeDate32.h>
#include <DataTypes/DataTypeNullable.h>
#include <DataTypes/DataTypeString.h>
#include <DataTypes/DataTypesNumber.h>
#include <Functions/FunctionFactory.h>
#include <Functions/FunctionsComparison.h>
#include <Functions/FunctionsLogical.h>
#include <IO/ReadBufferFromFile.h>
#include <Interpreters/Context.h>
#include <gtest/gtest.h>
#include <Poco/AutoPtr.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/Logger.h>
#include "../Filters.h"
#include "../ParquetFileReader.h"

using namespace DB;

DataTypePtr string_type = makeNullable(std::make_shared<DataTypeString>());
DataTypePtr int64_type = makeNullable(std::make_shared<DataTypeInt64>());
DataTypePtr double_type = makeNullable(std::make_shared<DataTypeFloat64>());
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
                    if (const auto * nullable_column = checkAndGetColumn<ColumnNullable>(*nested_column))
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

TEST(Parquet, PageFilter)
{
    auto file = std::make_shared<ReadBufferFromFile>(
        "/home/saber/dev/data/tpch100/parquet/lineitem/part-00000-066b93b4-39e1-4d46-83ab-d7752096b599-c000.snappy.parquet");
    ScanParam param;
    //    param.header.insert({int64_type, "l_orderkey"});
    //    param.header.insert({int64_type, "l_partkey"});
    //    param.header.insert({int64_type, "l_suppkey"});
    //        param.header.insert({int64_type, "l_linenumber"});

    //    param.header.insert({string_type, "l_comment"});
    //    param.header.insert({string_type, "l_shipmode"});
    //    param.header.insert({string_type, "l_returnflag"});
    //    param.header.insert({string_type, "l_linestatus"});
    param.header.insert({date_type, "l_shipdate"});
            param.header.insert({double_type, "l_quantity"});
    param.header.insert({double_type, "l_extendedprice"});
    param.header.insert({double_type, "l_discount"});
    //    param.header.insert({date_type, "l_commitdate"});
    //    param.header.insert({date_type, "l_receiptdate"});

    param.case_sensitive = false;
    param.active_columns = {2, 3};
    //    param.skip_row_groups.insert(0);   // 3351607
    //    param.skip_row_groups.insert(1);   // 3351607
    //    param.skip_row_groups.insert(2);   // 3351607
    //    param.skip_row_groups.insert(3);   // 3351607
    //    param.skip_row_groups.insert(4);   // 3347771
    //    param.skip_row_groups.insert(5);   // 3241150
    ActionsDAGPtr dag = std::make_shared<ActionsDAG>();
    SharedContextHolder shared_context = Context::createShared();
    ContextMutablePtr context = Context::createGlobal(shared_context.get());
    FunctionOverloadResolverPtr func_builder_lt
        = std::make_unique<FunctionToOverloadResolverAdaptor>(std::make_shared<FunctionComparison<LessOp, NameLess>>(context));
    FunctionOverloadResolverPtr func_builder_ge
        = std::make_unique<FunctionToOverloadResolverAdaptor>(std::make_shared<FunctionComparison<GreaterOrEqualsOp, NameGreaterOrEquals>>(context));
    FunctionOverloadResolverPtr func_builder_le
        = std::make_unique<FunctionToOverloadResolverAdaptor>(std::make_shared<FunctionComparison<LessOrEqualsOp, NameLessOrEquals>>(context));
    FunctionOverloadResolverPtr func_builder_and = std::make_unique<FunctionToOverloadResolverAdaptor>(std::make_shared<FunctionAnd>());


    const auto & l_shipdate = dag->addInput("l_shipdate", date_type);
    const auto & l_quantity = dag->addInput("l_quantity", double_type);
    const auto & l_discount = dag->addInput("l_discount", double_type);
    const auto & const_8766 = dag->addColumn({date_type->createColumnConst(1, 8766), date_type, "8766"});
    const auto & const_9131 = dag->addColumn({date_type->createColumnConst(1, 9131), date_type, "9131"});
    const auto & const_24 = dag->addColumn({double_type->createColumnConst(1, 24.0), double_type, "24"});
    const auto & const_005 = dag->addColumn({double_type->createColumnConst(1, 0.05), double_type, "0.05"});
    const auto & const_007 = dag->addColumn({double_type->createColumnConst(1, 0.07), double_type, "0.07"});

    const auto & condition1_node = dag->addFunction(func_builder_ge, {&l_shipdate, &const_8766}, "");
    const auto & condition2_node = dag->addFunction(func_builder_lt, {&l_shipdate, &const_9131}, "");
    const auto & condition3_node = dag->addFunction(func_builder_ge, {&l_discount, &const_005}, "");
    const auto & condition4_node = dag->addFunction(func_builder_le, {&l_discount, &const_007}, "");
    const auto & condition5_node = dag->addFunction(func_builder_lt, {&l_quantity, &const_24}, "");

    const auto & and_node_1 = dag->addFunction(func_builder_and, {&condition1_node, &condition2_node}, "");
    const auto & and_node_2 = dag->addFunction(func_builder_and, {&and_node_1, &condition3_node}, "");
    const auto & and_node_3 = dag->addFunction(func_builder_and, {&and_node_2, &condition4_node}, "");
    const auto & and_node_4 = dag->addFunction(func_builder_and, {&and_node_3, &condition5_node}, "");



    dag->addOrReplaceInOutputs(and_node_4);
param.filter = std::make_shared<PushDownFilter>(dag);
param.groupFilter = param.filter->getRowGroupFilter();


    auto reader = std::make_shared<ParquetFileReader>(file.get(), param, 8192);
    reader->init();
    size_t count [[maybe_unused]] = 0;
    while (true)
    {
        auto chunk = reader->getNext();

        if (chunk.getNumRows() == 0)
            break;
        if (count <= 0)
        {
            for (size_t i = 0; i < std::min(chunk.getNumRows(), (size_t)50); ++i)
            {
                for (size_t j = 0; j < chunk.getNumColumns(); ++j)
                {
                    auto nested_column = chunk.getColumns().at(j);
                    if (const auto * nullable_column = checkAndGetColumn<ColumnNullable>(*nested_column))
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
