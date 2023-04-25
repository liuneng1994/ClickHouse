add_executable(unit_tests_parquet
        test_parquet.cpp
        )

target_compile_options(unit_tests_parquet PRIVATE
        -Wno-sign-compare
        )

target_link_libraries(unit_tests_parquet PRIVATE
        parquet
        ch_contrib::gtest_all
        Poco::Foundation
        )