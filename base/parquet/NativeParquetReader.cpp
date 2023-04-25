//
// Created by admin1 on 23-4-24.
//

#include "NativeParquetReader.h"
#include <DataTypes/DataTypeArray.h>
#include <DataTypes/DataTypeFactory.h>
#include <DataTypes/DataTypeMap.h>
#include <IO/ReadBufferFromFileBase.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/protocol/TProtocol.h>
#include <Common/Exception.h>
#include <Common/PODArray.h>
#include "thrift/ThriftFileTransport.h"


namespace DB
{

namespace ErrorCodes
{
    extern const int LOGICAL_ERROR;
}


void check(bool condition, String msg)
{
    if (!condition)
    {
        throw Exception::createRuntime(ErrorCodes::LOGICAL_ERROR, msg);
    }
}

NativeParquetReader::NativeParquetReader(const std::shared_ptr<ReadBufferFromFileBase> file_) : file(file_)
{
    file_length = file->getFileSize();
    if (file_length == 0)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Parquet file is empty");
    if (file_length < 12)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Parquet file is too small");
    loadFileMetaData();
    initializeSchema();
    std::cerr << header->dumpStructure() << std::endl;
}

static std::unique_ptr<apache::thrift::protocol::TProtocol> createThriftProtocol(std::shared_ptr<ReadBufferFromFileBase> file)
{
    auto transport = std::make_shared<ThriftFileTransport>(file);
    return std::make_unique<apache::thrift::protocol::TCompactProtocolT<ThriftFileTransport>>(transport);
}

void NativeParquetReader::loadFileMetaData()
{
    auto file_size = file->getFileSize();
    auto proto = createThriftProtocol(file);
    auto & transport = *reinterpret_cast<ThriftFileTransport *>(proto->getTransport().get());
    PODArray<uint8_t> buf;
    buf.resize(8);
    transport.setLocation(file_length - 8);
    transport.read(buf.data(), 8);
    if (strncmp(reinterpret_cast<char *>(buf.data()) + 4, "PAR1", 4) != 0)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "No magic bytes found at end of file '{}'", file->getFileName());
    }
    auto footer_len = *reinterpret_cast<size_t *>(buf.data());
    if (footer_len <= 0 || file_size < 12 + footer_len)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Footer length error in file '{}'", file->getFileName());
    }
    auto metadata_pos = file_size - (footer_len + 8);
    transport.setLocation(metadata_pos);
    metaData = std::make_unique<FileMetaData>();
    metaData->read(proto.get());
}

BlockPtr NativeParquetReader::createHeader(std::vector<ParquetTypeInfoPtr> cols)
{
    ColumnsWithTypeAndName columns;
    for (auto & child : cols)
    {
        columns.push_back({child->type, std::static_pointer_cast<ParquetTypeInfo>(child)->name_});
    }
    return std::make_shared<Block>(columns);
}

void NativeParquetReader::initializeSchema()
{
    if (metaData->set.encryption_algorithm)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Encrypted Parquet files are not supported");
    if (metaData->schema.size() < 2)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Need at least one non-root column in the file");

    auto root_reader = createReader();
    auto root_type = root_reader->getType();
    std::vector<std::shared_ptr<ParquetTypeInfo>> children;
    children.reserve(metaData->schema[0].num_children);

    size_t maxDefine = 0;
    size_t maxRepeat = 0;
    size_t schemaIdx = 0;
    size_t columnIdx = 0;
    size_t maxSchemaElementIdx = metaData->schema.size() - 1;
    schema_info = getParquetColumnInfo(maxSchemaElementIdx, maxRepeat, maxDefine, schemaIdx, columnIdx);
    header = createHeader(schema_info->getChildren());
}

std::unique_ptr<NativeColumnReader> NativeParquetReader::createReader()
{
    if (metaData->schema.empty())
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Parquet reader: no schema elements found");
    }
    if (metaData->schema[0].repetition_type != FieldRepetitionType::REQUIRED)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Invalid Parquet schema: root element must be REQUIRED");
    }
    if (metaData->schema[0].num_children == 0)
    {
        throw Exception(ErrorCodes::LOGICAL_ERROR, "Parquet reader: root schema element has no children");
    }

    return std::unique_ptr<NativeColumnReader>();
}
std::shared_ptr<ParquetTypeInfo> NativeParquetReader::getParquetColumnInfo(
    size_t maxSchemaElementIdx, size_t maxRepeat, size_t maxDefine, size_t schemaIdx, size_t columnIdx) const
{
    assert(metaData);
    assert(schemaIdx < metaData->schema.size());

    auto & schema = metaData->schema;
    size_t curSchemaIdx = schemaIdx;
    auto & schemaElement = schema[curSchemaIdx];

    if (schemaElement.set.repetition_type)
    {
        if (schemaElement.repetition_type != FieldRepetitionType::REQUIRED)
        {
            maxDefine++;
        }
        if (schemaElement.repetition_type == FieldRepetitionType::REPEATED)
        {
            maxRepeat++;
        }
    }

    if (!schemaElement.set.type)
    { // inner node
        check(schemaElement.set.num_children && schemaElement.num_children > 0, "Node has no children but should");

        std::vector<std::shared_ptr<ParquetTypeInfo>> children;

        for (int32_t i = 0; i < schemaElement.num_children; i++)
        {
            auto child = getParquetColumnInfo(maxSchemaElementIdx, maxRepeat, maxDefine, ++schemaIdx, columnIdx);
            children.push_back(child);
        }
        assert(!children.empty());

        if (schemaElement.set.converted_type)
        {
            switch (schemaElement.converted_type)
            {
                case ConvertedType::LIST:
                case ConvertedType::MAP: {
                    auto element = children.at(0)->getChildren();
                    assert(children.size() == 1);
                    return std::make_shared<ParquetTypeInfo>(
                        children[0]->type,
                        std::move(element),
                        curSchemaIdx, // TODO: there are holes in the ids
                        maxSchemaElementIdx,
                        ParquetTypeInfo::kNonLeaf, // columnIdx,
                        schemaElement.name,
                        std::nullopt,
                        maxRepeat + 1,
                        maxDefine);
                }
                case ConvertedType::MAP_KEY_VALUE: {
                    // child of MAP
                    assert(schemaElement.repetition_type == FieldRepetitionType::REPEATED);
                    assert(children.size() == 2);
                    auto childrenCopy = children;
                    return std::make_shared<ParquetTypeInfo>(
                        std::make_shared<DataTypeMap>(children[0]->type, children[1]->type),
                        std::move(childrenCopy),
                        curSchemaIdx, // TODO: there are holes in the ids
                        maxSchemaElementIdx,
                        ParquetTypeInfo::kNonLeaf, // columnIdx,
                        schemaElement.name,
                        std::nullopt,
                        maxRepeat,
                        maxDefine);
                }
                default:
                    throw Exception(ErrorCodes::LOGICAL_ERROR, "Unsupported SchemaElement type: {}", schemaElement.converted_type);
            }
        }
        else
        {
            if (schemaElement.repetition_type == FieldRepetitionType::REPEATED)
            {
                //                VELOX_CHECK_LE(children.size(), 2, "children size should not be larger than 2");
                if (children.size() == 1)
                {
                    // child of LIST
                    auto childrenCopy = children;
                    return std::make_shared<ParquetTypeInfo>(
                        std::make_shared<DataTypeArray>(children[0]->type),
                        std::move(childrenCopy),
                        curSchemaIdx,
                        maxSchemaElementIdx,
                        ParquetTypeInfo::kNonLeaf, // columnIdx,
                        schemaElement.name,
                        std::nullopt,
                        maxRepeat,
                        maxDefine);
                }
                else if (children.size() == 2)
                {
                    // children  of MAP
                    auto childrenCopy = children;
                    return std::make_shared<ParquetTypeInfo>(
                        std::make_shared<DataTypeMap>(children[0]->type, children[1]->type),
                        std::move(childrenCopy),
                        curSchemaIdx, // TODO: there are holes in the ids
                        maxSchemaElementIdx,
                        ParquetTypeInfo::kNonLeaf, // columnIdx,
                        schemaElement.name,
                        std::nullopt,
                        maxRepeat,
                        maxDefine);
                }
            }
            else
            {
                // Row type
                auto childrenCopy = children;
                return std::make_shared<ParquetTypeInfo>(
                    createRowType(children),
                    std::move(childrenCopy),
                    curSchemaIdx,
                    maxSchemaElementIdx,
                    ParquetTypeInfo::kNonLeaf, // columnIdx,
                    schemaElement.name,
                    std::nullopt,
                    maxRepeat,
                    maxDefine);
            }
        }
    }
    else
    { // leaf node
        const auto ch_type = convertType(schemaElement);
        int32_t precision = schemaElement.set.precision ? schemaElement.precision : 0;
        int32_t scale = schemaElement.set.scale ? schemaElement.scale : 0;
        int32_t type_length = schemaElement.set.type_length ? schemaElement.type_length : 0;
        std::vector<std::shared_ptr<ParquetTypeInfo>> children;
        std::shared_ptr<ParquetTypeInfo> leafTypePtr = std::make_shared<ParquetTypeInfo>(
            ch_type,
            std::move(children),
            curSchemaIdx,
            maxSchemaElementIdx,
            columnIdx++,
            schemaElement.name,
            schemaElement.type,
            maxRepeat,
            maxDefine,
            precision,
            scale,
            type_length);

        if (schemaElement.repetition_type == FieldRepetitionType::REPEATED)
        {
            // Array
            children.clear();
            children.reserve(1);
            children.push_back(leafTypePtr);
            return std::make_shared<ParquetTypeInfo>(
                std::make_shared<DataTypeArray>(ch_type),
                std::move(children),
                curSchemaIdx,
                maxSchemaElementIdx,
                columnIdx++,
                schemaElement.name,
                std::nullopt,
                maxRepeat,
                maxDefine);
        }
        return leafTypePtr;
    }

    throw Exception(ErrorCodes::LOGICAL_ERROR, "Unable to extract Parquet column info.");
}
DataTypePtr NativeParquetReader::createRowType(std::vector<std::shared_ptr<ParquetTypeInfo>> children)
{
    Names childNames;
    DataTypes childTypes;
    for (auto & child : children)
    {
        childNames.push_back(std::static_pointer_cast<ParquetTypeInfo>(child)->name_);
        childTypes.push_back(child->type);
    }
    return createNested(childTypes, childNames);
}


DataTypePtr NativeParquetReader::convertType(const SchemaElement & schemaElement) const
{
    assert(schemaElement.set.type && schemaElement.num_children == 0);
    check(
        schemaElement.type != Type::FIXED_LEN_BYTE_ARRAY || schemaElement.set.type_length,
        "FIXED_LEN_BYTE_ARRAY requires length to be set");

    if (schemaElement.set.converted_type)
    {
        switch (schemaElement.converted_type)
        {
            case ConvertedType::INT_8:
                check(schemaElement.type == Type::INT32, "INT8 converted type can only be set for value of Type::INT32");
                return DataTypeFactory::instance().get("Int8");

            case ConvertedType::INT_16:
                check(schemaElement.type == Type::INT32, "INT16 converted type can only be set for value of Type::INT32");
                return DataTypeFactory::instance().get("Int16");

            case ConvertedType::INT_32:
                check(schemaElement.type == Type::INT32, "INT32 converted type can only be set for value of Type::INT32");
                return DataTypeFactory::instance().get("Int32");

            case ConvertedType::INT_64:
                check(schemaElement.type == Type::INT32, "INT64 converted type can only be set for value of Type::INT32");
                return DataTypeFactory::instance().get("Int64");

            case ConvertedType::UINT_8:
                check(schemaElement.type == Type::INT32, "UINT_8 converted type can only be set for value of Type::INT32");
                return DataTypeFactory::instance().get("UInt8");

            case ConvertedType::UINT_16:
                check(schemaElement.type == Type::INT32, "UINT_16 converted type can only be set for value of Type::INT32");
                return DataTypeFactory::instance().get("UInt16");

            case ConvertedType::UINT_32:
                check(schemaElement.type == Type::INT32, "UINT_32 converted type can only be set for value of Type::INT32");
                return DataTypeFactory::instance().get("UInt32");

            case ConvertedType::UINT_64:
                check(schemaElement.type == Type::INT64, "UINT_64 converted type can only be set for value of Type::INT64");
                return DataTypeFactory::instance().get("UInt64");

            case ConvertedType::DATE:
                check(schemaElement.type == Type::INT32, "DATE converted type can only be set for value of Type::INT32");
                return DataTypeFactory::instance().get("Date32");

                //            case ConvertedType::TIMESTAMP_MICROS:
                //            case ConvertedType::TIMESTAMP_MILLIS:
                //                check(
                //                    schemaElement.type ==
                //                    Type::INT64,
                //                    "TIMESTAMP_MICROS or TIMESTAMP_MILLIS converted type can only be set for value of Type::INT64");
                //                return TIMESTAMP();

                //            case ConvertedType::DECIMAL: {
                //                VELOX_CHECK(
                //                    schemaElement.set.precision && schemaElement.set.scale,
                //                    "DECIMAL requires a length and scale specifier!");
                //                return DECIMAL(schemaElement.precision, schemaElement.scale);
                //            }

            case ConvertedType::UTF8:
                switch (schemaElement.type)
                {
                    case Type::BYTE_ARRAY:
                        return DataTypeFactory::instance().get("String");
                    case Type::FIXED_LEN_BYTE_ARRAY:
                        return DataTypeFactory::instance().get("FixedString");
                    default:
                        throw Exception(ErrorCodes::LOGICAL_ERROR, "UTF8 converted type can only be set for Type::(FIXED_LEN_)BYTE_ARRAY");
                }
            case ConvertedType::MAP:
            case ConvertedType::MAP_KEY_VALUE:
            case ConvertedType::LIST:
            case ConvertedType::ENUM:
            case ConvertedType::TIME_MILLIS:
            case ConvertedType::TIME_MICROS:
            case ConvertedType::JSON:
            case ConvertedType::BSON:
            case ConvertedType::INTERVAL:
            default:
                throw Exception(
                    ErrorCodes::LOGICAL_ERROR, "Unsupported Parquet SchemaElement converted type: {}", schemaElement.converted_type);
        }
    }
    else
    {
        switch (schemaElement.type)
        {
            case Type::type::BOOLEAN:
                return DataTypeFactory::instance().get("UInt8");
            case Type::type::INT32:
                return DataTypeFactory::instance().get("Int32");
            case Type::type::INT64:
                return DataTypeFactory::instance().get("Int64");
                //            case Type::type::INT96:
                //                return DataTypeFactory::instance().get("Float64"); // TODO: Lose precision
            case Type::type::FLOAT:
                return DataTypeFactory::instance().get("Float32");
            case Type::type::DOUBLE:
                return DataTypeFactory::instance().get("Float64");
            case Type::type::BYTE_ARRAY:
                return DataTypeFactory::instance().get("String");
            case Type::type::FIXED_LEN_BYTE_ARRAY:
                return DataTypeFactory::instance().get("FixedString");
            default:
                throw Exception(ErrorCodes::LOGICAL_ERROR, "Unknown Parquet SchemaElement type: {}", schemaElement.type);
        }
    }
}

}
