set(SOURCE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)

set(ENABLE_LIBPQXX OFF)

macro(add_absolute_glob cur_list)
    file(GLOB __tmp CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${SOURCE_ROOT}/${ARGN})
    list(APPEND ${cur_list} ${__tmp})
endmacro()

macro(add_absolute_headers_and_sources prefix common_path)
    add_absolute_glob(${prefix}_headers ${common_path}/*.h)
    add_absolute_glob(${prefix}_sources ${common_path}/*.c)
    add_absolute_glob(${prefix}_sources ${common_path}/*.cpp)
    add_absolute_glob(${prefix}_sources ${common_path}/*.h)
endmacro()

include(${SOURCE_ROOT}/cmake/warnings.cmake)

add_absolute_headers_and_sources(embed_ch base/readpassphrase)
add_absolute_headers_and_sources(embed_ch base/base)

add_absolute_headers_and_sources(embed_ch src/Access)
add_absolute_headers_and_sources(embed_ch src/Access/Common)
add_absolute_headers_and_sources(embed_ch src/Analyzer)
add_absolute_headers_and_sources(embed_ch src/Analyzer/Passes)

add_absolute_headers_and_sources(embed_ch src/Backups)
#add_absolute_headers_and_sources(embed_ch src/Bridge)
add_absolute_headers_and_sources(embed_ch src/BridgeHelper)

add_absolute_headers_and_sources(embed_ch src/Core)
add_absolute_headers_and_sources(embed_ch src/Core/MySQL)
add_absolute_headers_and_sources(embed_ch src/Coordination)
add_absolute_headers_and_sources(embed_ch src/Client)
add_absolute_headers_and_sources(embed_ch src/Databases)
add_absolute_headers_and_sources(embed_ch src/Functions)
add_absolute_headers_and_sources(embed_ch src/Functions/UserDefined)
add_absolute_headers_and_sources(embed_ch src/Functions/JSONPath)
add_absolute_headers_and_sources(embed_ch src/Functions/JSONPath/Parsers)
add_absolute_headers_and_sources(embed_ch src/Functions/GatherUtils)
#add_absolute_headers_and_sources(embed_ch src/Functions/divide)
add_absolute_headers_and_sources(embed_ch src/Functions/array)

add_absolute_headers_and_sources(embed_ch src/Columns)

add_absolute_headers_and_sources(embed_ch src/Disks)
add_absolute_headers_and_sources(embed_ch src/Disks/IO)
add_absolute_headers_and_sources(embed_ch src/Disks/ObjectStorages)
add_absolute_headers_and_sources(embed_ch src/Disks/ObjectStorages/Cached)


add_absolute_headers_and_sources(embed_ch src/Common)
list(REMOVE_ITEM embed_ch_sources
        ../../src/Common/malloc.cpp
        )
add_absolute_headers_and_sources(embed_ch src/Common/Config)
add_absolute_headers_and_sources(embed_ch src/Common/ZooKeeper)
add_absolute_headers_and_sources(embed_ch src/Common/NamedCollections)
add_absolute_headers_and_sources(embed_ch src/Common/StringUtils)
add_absolute_headers_and_sources(embed_ch src/Common/HashTable)

add_absolute_headers_and_sources(embed_ch src/Parsers)
add_absolute_headers_and_sources(embed_ch src/Parsers/Access)
add_absolute_headers_and_sources(embed_ch src/Parsers/Kusto)


# AggregateFunctions
add_absolute_headers_and_sources(embed_ch src/AggregateFunctions)

# Compression
add_absolute_headers_and_sources(embed_ch src/Compression)

add_absolute_headers_and_sources(embed_ch src/DataTypes)
add_absolute_headers_and_sources(embed_ch src/DataTypes/Serializations)

list(APPEND embed_ch_sources
        ../../src/Dictionaries/DictionaryStructure.cpp
        ../../src/Dictionaries/DictionaryFactory.cpp
        ../../src/Dictionaries/DictionarySourceFactory.cpp
        ../../src/Dictionaries/getDictionaryConfigurationFromAST.cpp
        )

add_absolute_headers_and_sources(embed_ch src/Dictionaries/Embedded)
add_absolute_headers_and_sources(embed_ch src/Dictionaries/Embedded/GeodataProviders)

add_absolute_headers_and_sources(embed_ch src/Formats)
list(REMOVE_ITEM embed_ch_sources
        ../../src/Formats/ProtobufReader.cpp
        ../../src/Formats/ProtobufWriter.cpp
        ../../src/Formats/ProtobufSerializer.cpp
        )
add_absolute_headers_and_sources(embed_ch src/Interpreters)
add_absolute_headers_and_sources(embed_ch src/Interpreters/JIT)
add_absolute_headers_and_sources(embed_ch src/Interpreters/Access)
add_absolute_headers_and_sources(embed_ch src/Interpreters/Cache)
add_absolute_headers_and_sources(embed_ch src/Interpreters/ClusterProxy)

add_absolute_headers_and_sources(embed_ch src/IO)
add_absolute_headers_and_sources(embed_ch src/IO/S3)
add_absolute_headers_and_sources(embed_ch src/Loggers)
add_absolute_headers_and_sources(embed_ch src/Processors)
add_absolute_headers_and_sources(embed_ch src/Processors/QueryPlan)
add_absolute_headers_and_sources(embed_ch src/Processors/QueryPlan/Optimizations)
add_absolute_headers_and_sources(embed_ch src/Processors/Executors)
add_absolute_headers_and_sources(embed_ch src/Processors/Formats)
#add_absolute_headers_and_sources(embed_ch src/Processors/Formats/Impl)
list(APPEND embed_ch_sources
        ../../src/Processors/Formats/Impl/ArrowBufferedStreams.cpp
        ../../src/Processors/Formats/Impl/ArrowColumnToCHColumn.cpp
        ../../src/Processors/Formats/Impl/ORCBlockInputFormat.cpp
        ../../src/Processors/Formats/Impl/MySQLOutputFormat.cpp
        ../../src/Processors/Formats/Impl/ParallelFormattingOutputFormat.cpp
        ../../src/Processors/Formats/Impl/ParallelParsingInputFormat.cpp
        ../../src/Processors/Formats/Impl/ValuesBlockInputFormat.cpp
        ../../src/Processors/Formats/Impl/ConstantExpressionTemplate.cpp
        ../../src/Processors/Formats/Impl/NullFormat.cpp
        )

add_absolute_headers_and_sources(embed_ch src/Processors/Merges)
add_absolute_headers_and_sources(embed_ch src/Processors/Merges/Algorithms)
add_absolute_headers_and_sources(embed_ch src/Processors/Sinks)
add_absolute_headers_and_sources(embed_ch src/Processors/Sources)
add_absolute_headers_and_sources(embed_ch src/Processors/TTL)
add_absolute_headers_and_sources(embed_ch src/Processors/Transforms)
list(REMOVE_ITEM embed_ch_headers
        ../../src/Processors/Transforms/MongoDBSource.h
        )
list(REMOVE_ITEM embed_ch_sources
        ../../src/Processors/Transforms/MongoDBSource.cpp
        )

add_absolute_headers_and_sources(embed_ch src/QueryPipeline)
add_absolute_headers_and_sources(embed_ch src/Planner)

add_absolute_headers_and_sources(embed_ch src/Server)
list(REMOVE_ITEM embed_ch_sources
        ../../src/Server/ProtocolServerAdapter.cpp
        ../../src/Server/GRPCServer.cpp
        ../../src/Server/HTTPHandler.cpp
        ../../src/Server/NotFoundHandler.cpp
        ../../src/Server/ReplicasStatusHandler.cpp
        ../../src/Server/PrometheusRequestHandler.cpp
        ../../src/Server/InterserverIOHTTPHandler.cpp
        ../../src/Server/StaticRequestHandler.cpp
        ../../src/Server/HTTPHandlerFactory.cpp
        ../../src/Server/WebUIRequestHandler.cpp
        ../../src/Server/HTTPRequestHandlerFactoryMain.cpp
        )
# Storages
add_absolute_headers_and_sources(embed_ch src/Storages)
list(REMOVE_ITEM embed_ch_sources
        ../../src/Storages/ExternalDataSourceConfiguration.cpp
        ../../src/Storages/StorageExternalDistributed.cpp
        )
add_absolute_headers_and_sources(embed_ch src/Storages/MergeTree)
add_absolute_headers_and_sources(embed_ch src/Storages/WindowView)
add_absolute_headers_and_sources(embed_ch src/Storages/Distributed)
add_absolute_headers_and_sources(embed_ch src/Storages/Cache)
add_absolute_headers_and_sources(embed_ch src/Storages/LiveView)
add_absolute_headers_and_sources(embed_ch src/Storages/HDFS)
list(REMOVE_ITEM embed_ch_sources
        ../../src/Storages/StorageMongoDB.cpp
        ../../src/Storages/StorageMongoDBSocketFactory.cpp
        ../../src/Storages/Cache/registerRemoteFileMetadatas.cpp
        )

list(REMOVE_ITEM embed_ch_sources
        ../../src/Dictionaries/registerDictionaries.cpp
        ../../src/Disks/registerDisks.cpp
        ../../src/Storages/registerStorages.cpp
        ../../src/Formats/registerFormats.cpp
        )

list(APPEND embed_ch_sources
        ../../src/TableFunctions/ITableFunction.cpp
        ../../src/TableFunctions/TableFunctionView.cpp
        ../../src/TableFunctions/TableFunctionFactory.cpp
        )


add_library(embed_ch STATIC ${embed_ch_sources})
target_include_directories(embed_ch PUBLIC
        ${SOURCE_ROOT}/src
        ${SOURCE_ROOT}/base
        ${SOURCE_ROOT}/base/pcg-random
        ${SOURCE_ROOT}/base/widechar_width
        )

target_include_directories(embed_ch PUBLIC
        ${SOURCE_ROOT}/contrib/xxHash
        )

target_compile_options(embed_ch PUBLIC -fPIC)

target_compile_definitions(embed_ch PRIVATE XXH_INLINE_ALL)

target_compile_options(embed_ch PRIVATE
        -Wno-zero-as-null-pointer-constant
        -Wno-signed-enum-bitfield
        -Wno-deprecated-dynamic-exception-spec
        -Wno-extra-semi-stmt
        -Wno-suggest-override
        -Wno-sign-compare
        -Wno-suggest-destructor-override
        -Wno-old-style-cast
        -Wno-reserved-identifier
        -Wno-undef
        -Wno-deprecated
        -Wno-deprecated-builtins
        -Wno-redundant-parens
        -Wno-atomic-implicit-seq-cst
        -Wno-shorten-64-to-32
        -Wno-unused-but-set-variable
        -Wno-missing-noreturn
        -Wno-shorten-64-to-32
        -Wno-float-conversion
        -Wno-comma
        -Wno-extra-semi
        -Wno-unused-parameter
        -Wno-documentation
        -Wno-shadow-field
        -Wno-shadow-field-in-constructor
        -Wno-shadow
        -Wno-newline-eof
        -Wno-macro-redefined
        -Wno-used-but-marked-unused
        -Wno-cast-qual
        -Wno-unused-member-function
        -Wno-covered-switch-default
        -Wno-compound-token-split-by-space
        -Wno-cast-align
        -Wno-unused-private-field
        -Wno-inconsistent-missing-destructor-override
        -Wnon-power-of-two-alignment
        )

add_custom_command(OUTPUT copy_deps
        COMMAND rm -rf deps && mkdir -p deps &&
        cp $<TARGET_FILE:Poco::Foundation> deps/ &&
        cp ${CMAKE_BINARY_DIR}/contrib/boost-cmake/*.a deps/ &&
        cp ${CMAKE_BINARY_DIR}/contrib/abseil-cpp/absl/container/*.a deps/ &&
        cp ${CMAKE_BINARY_DIR}/contrib/abseil-cpp/absl/hash/*.a deps/ &&
        cp ${CMAKE_BINARY_DIR}/contrib/icu-cmake/*.a deps/ &&
        cp $<TARGET_FILE:ch_contrib::cityhash> deps/ &&
        cp $<TARGET_FILE:ch_contrib::nuraft> deps/ &&
        cp $<TARGET_FILE:ch_contrib::aws_s3> deps/ &&
        cp $<TARGET_FILE:ch_contrib::krb5> deps/ &&
        cp $<TARGET_FILE:ch_contrib::rocksdb> deps/ &&
        cp $<TARGET_FILE:ch_contrib::snappy> deps/ &&
        cp $<TARGET_FILE:ch_contrib::cctz> deps/ &&
        cp $<TARGET_FILE:ch_contrib::xz> deps/ &&
        cp $<TARGET_FILE:ch_contrib::fmt> deps/ &&
        cp $<TARGET_FILE:ch_contrib::re2> deps/ &&
        cp $<TARGET_FILE:ch_contrib::re2_st> deps/ &&
        cp $<TARGET_FILE:ch_contrib::metrohash> deps/ &&
        cp $<TARGET_FILE:ch_contrib::lz4> deps/ &&
        cp $<TARGET_FILE:ch_contrib::cityhash> deps/ &&
        cp $<TARGET_FILE:ch_contrib::dragonbox_to_chars> deps/ &&
        cp $<TARGET_FILE:ch_contrib::roaring> deps/ &&
        cp $<TARGET_FILE:ch_contrib::double_conversion> deps/ &&
        cp $<TARGET_FILE:ch_contrib::zlib> deps/ &&
        cp $<TARGET_FILE:ch_contrib::zstd> deps/ &&
        cp $<TARGET_FILE:ch_contrib::farmhash> deps/ &&
        cp $<TARGET_FILE:ch_contrib::hashidsxx> deps/ &&
        cp $<TARGET_FILE:ch_contrib::murmurhash> deps/ &&
        cp $<TARGET_FILE:ch_contrib::fastops> deps/ &&
        cp $<TARGET_FILE:ch_contrib::simdjson> deps/ &&
        cp $<TARGET_FILE:ch_contrib::vectorscan> deps/ &&
        cp $<TARGET_FILE:ch_contrib::base64> deps/ &&
        cp $<TARGET_FILE:ch_contrib::consistent_hashing> deps/ &&
        cp $<TARGET_FILE:ch_contrib::jemalloc> deps/ &&
        cp $<TARGET_FILE:ch_contrib::c-ares> deps/ &&
        cp $<TARGET_FILE:ch_contrib::hdfs> deps/ &&
        cp $<TARGET_FILE:ch_contrib::yaml_cpp> deps/ &&
        cp $<TARGET_FILE:ch_contrib::parquet> deps/ &&
        cp $<TARGET_FILE:ch_contrib::avrocpp> deps/ &&
        cp $<TARGET_FILE:divide_impl> deps/ &&
        cp $<TARGET_FILE:Poco::Crypto> deps/ &&
        cp $<TARGET_FILE:Poco::Foundation> deps/ &&
        cp $<TARGET_FILE:Poco::Data> deps/ &&
        cp $<TARGET_FILE:Poco::JSON> deps/ &&
        cp $<TARGET_FILE:Poco::JSON::Pdjson> deps/ &&
        cp $<TARGET_FILE:Poco::Net> deps/ &&
        cp $<TARGET_FILE:Poco::Net::SSL> deps/ &&
        cp $<TARGET_FILE:Poco::Util> deps/ &&
        cp $<TARGET_FILE:Poco::XML> deps/ &&
        cp $<TARGET_FILE:ch_contrib::thrift> deps/ &&
        cp $<TARGET_FILE:OpenSSL::Crypto> deps/ &&
        cp $<TARGET_FILE:OpenSSL::SSL> deps/ &&
        cp $<TARGET_FILE:Poco::Foundation::PCRE> deps/ &&
        cp ${CMAKE_BINARY_DIR}/contrib/llvm-project/llvm/lib/*.a deps/ &&
        cp $<TARGET_FILE:_arrow> deps/ &&
        cp $<TARGET_FILE:_parquet> deps/ &&
        cp $<TARGET_FILE:_orc> deps/ &&
        cp $<TARGET_FILE:protobuf::libprotobuf> deps/ &&
        cp $<TARGET_FILE:ch_contrib::thrift> deps/ &&
        cp $<TARGET_FILE:ch_contrib::zlib> deps/

        DEPENDS embed_ch)

add_custom_target(copy_deps ALL DEPENDS copy_deps)


target_link_libraries(embed_ch PUBLIC
        ch_contrib::nuraft
        ch_contrib::aws_s3
        ch_contrib::krb5
        ch_contrib::rocksdb
        ch_contrib::snappy
        ch_contrib::cctz
        ch_contrib::protobuf
        ch_contrib::libdivide
        ch_contrib::xz
        ch_contrib::fmt
        ch_contrib::abseil_swiss_tables
        ch_contrib::re2
        ch_contrib::metrohash
#        ch_contrib::xxHash
        ch_contrib::lz4
        ch_contrib::wyhash
        ch_contrib::cityhash
        ch_contrib::magic_enum
        ch_contrib::miniselect
        ch_contrib::dragonbox_to_chars
        ch_contrib::roaring
        ch_contrib::double_conversion
        ch_contrib::pdqsort
        ch_contrib::zlib
        ch_contrib::zstd
        ch_contrib::farmhash
        ch_contrib::hashidsxx
        ch_contrib::murmurhash
        ch_contrib::fast_float
        ch_contrib::fastops
        ch_rust::blake3
        ch_contrib::rapidjson
        ch_contrib::simdjson
        ch_contrib::vectorscan
        ch_contrib::llvm
        ch_contrib::base64
        ch_contrib::icu
        ch_contrib::consistent_hashing
        ch_contrib::morton_nd
        ch_contrib::jemalloc
        ch_contrib::c-ares
        ch_contrib::hdfs
        ch_contrib::yaml_cpp
        ch_contrib::sparsehash
        ch_contrib::parquet
        ch_contrib::avrocpp
        ch_rust::skim
        divide_impl

        boost::headers_only
        Poco::Crypto
        Poco::Foundation
        Poco::Data
        Poco::JSON
        Poco::Net
        Poco::Net::SSL
        Poco::Util
        Poco::XML

        OpenSSL::Crypto
        OpenSSL::SSL
        )

