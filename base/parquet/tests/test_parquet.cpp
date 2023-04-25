#include <gtest/gtest.h>
#include <Poco/Logger.h>
#include <Poco/AutoPtr.h>
#include <Poco/ConsoleChannel.h>
#include <IO/ReadBufferFromFile.h>
#include "../NativeParquetReader.h"

using namespace DB;

TEST(Parquet, load_meta_data)
{
    auto file = std::make_shared<ReadBufferFromFile>("/home/admin1/github/ClickHouse-origin/tests/queries/0_stateless/data_parquet/alltypes_plain.parquet");
    auto reader = std::make_shared<NativeParquetReader>(file);
}

int main(int argc, char ** argv)
{
    Poco::AutoPtr<Poco::ConsoleChannel> channel(new Poco::ConsoleChannel(std::cerr));
    Poco::Logger::root().setChannel(channel);
    Poco::Logger::root().setLevel("trace");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
