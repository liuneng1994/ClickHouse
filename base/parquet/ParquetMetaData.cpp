#include "ParquetMetaData.h"
#include <iostream>
#include <thrift/TToString.h>

namespace DB
{

int kTypeValues[] = {
    Type::BOOLEAN,
    Type::INT32,
    Type::INT64,
    Type::INT96,
    Type::FLOAT,
    Type::DOUBLE,
    Type::BYTE_ARRAY,
    Type::FIXED_LEN_BYTE_ARRAY
};
const char* kTypeNames[] = {
    "BOOLEAN",
    "INT32",
    "INT64",
    "INT96",
    "FLOAT",
    "DOUBLE",
    "BYTE_ARRAY",
    "FIXED_LEN_BYTE_ARRAY"
};
const std::map<int, const char*>
    typeValuesToNames(::apache::thrift::TEnumIterator(8, kTypeValues, kTypeNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const Type::type& val) {
    std::map<int, const char*>::const_iterator it = typeValuesToNames.find(val);
    if (it != typeValuesToNames.end()) {
        out << it->second;
    } else {
        out << static_cast<int>(val);
    }
    return out;
}

int _kConvertedTypeValues[] = {
    ConvertedType::UTF8,
    ConvertedType::MAP,
    ConvertedType::MAP_KEY_VALUE,
    ConvertedType::LIST,
    ConvertedType::ENUM,
    ConvertedType::DECIMAL,
    ConvertedType::DATE,
    ConvertedType::TIME_MILLIS,
    ConvertedType::TIME_MICROS,
    ConvertedType::TIMESTAMP_MILLIS,
    ConvertedType::TIMESTAMP_MICROS,
    ConvertedType::UINT_8,
    ConvertedType::UINT_16,
    ConvertedType::UINT_32,
    ConvertedType::UINT_64,
    ConvertedType::INT_8,
    ConvertedType::INT_16,
    ConvertedType::INT_32,
    ConvertedType::INT_64,
    ConvertedType::JSON,
    ConvertedType::BSON,
    ConvertedType::INTERVAL
};
const char* _kConvertedTypeNames[] = {
    "UTF8",
    "MAP",
    "MAP_KEY_VALUE",
    "LIST",
    "ENUM",
    "DECIMAL",
    "DATE",
    "TIME_MILLIS",
    "TIME_MICROS",
    "TIMESTAMP_MILLIS",
    "TIMESTAMP_MICROS",
    "UINT_8",
    "UINT_16",
    "UINT_32",
    "UINT_64",
    "INT_8",
    "INT_16",
    "INT_32",
    "INT_64",
    "JSON",
    "BSON",
    "INTERVAL"
};
const std::map<int, const char*> ConvertedType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(22, _kConvertedTypeValues, _kConvertedTypeNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const ConvertedType::type& val) {
    std::map<int, const char*>::const_iterator it = ConvertedType_VALUES_TO_NAMES.find(val);
    if (it != ConvertedType_VALUES_TO_NAMES.end()) {
        out << it->second;
    } else {
        out << static_cast<int>(val);
    }
    return out;
}

int _kFieldRepetitionTypeValues[] = {
    FieldRepetitionType::REQUIRED,
    FieldRepetitionType::OPTIONAL,
    FieldRepetitionType::REPEATED
};
const char* _kFieldRepetitionTypeNames[] = {
    "REQUIRED",
    "OPTIONAL",
    "REPEATED"
};
const std::map<int, const char*> fieldRepetitionTypeValuesToNames(::apache::thrift::TEnumIterator(3, _kFieldRepetitionTypeValues, _kFieldRepetitionTypeNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const FieldRepetitionType::type& val) {
    std::map<int, const char*>::const_iterator it = fieldRepetitionTypeValuesToNames.find(val);
    if (it != fieldRepetitionTypeValuesToNames.end()) {
        out << it->second;
    } else {
        out << static_cast<int>(val);
    }
    return out;
}

int _kEncodingValues[] = {
    Encoding::PLAIN,
    Encoding::PLAIN_DICTIONARY,
    Encoding::RLE,
    Encoding::BIT_PACKED,
    Encoding::DELTA_BINARY_PACKED,
    Encoding::DELTA_LENGTH_BYTE_ARRAY,
    Encoding::DELTA_BYTE_ARRAY,
    Encoding::RLE_DICTIONARY
};
const char* _kEncodingNames[] = {
    "PLAIN",
    "PLAIN_DICTIONARY",
    "RLE",
    "BIT_PACKED",
    "DELTA_BINARY_PACKED",
    "DELTA_LENGTH_BYTE_ARRAY",
    "DELTA_BYTE_ARRAY",
    "RLE_DICTIONARY"
};
const std::map<int, const char*> encodingValuesToNames(::apache::thrift::TEnumIterator(8, _kEncodingValues, _kEncodingNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const Encoding::type& val) {
    std::map<int, const char*>::const_iterator it = encodingValuesToNames.find(val);
    if (it != encodingValuesToNames.end()) {
        out << it->second;
    } else {
        out << static_cast<int>(val);
    }
    return out;
}

int _kCompressionCodecValues[] = {
    CompressionCodec::UNCOMPRESSED,
    CompressionCodec::SNAPPY,
    CompressionCodec::GZIP,
    CompressionCodec::LZO,
    CompressionCodec::BROTLI,
    CompressionCodec::LZ4,
    CompressionCodec::ZSTD
};
const char* _kCompressionCodecNames[] = {
    "UNCOMPRESSED",
    "SNAPPY",
    "GZIP",
    "LZO",
    "BROTLI",
    "LZ4",
    "ZSTD"
};
const std::map<int, const char*> compressionCodecValuesToNames(::apache::thrift::TEnumIterator(7, _kCompressionCodecValues, _kCompressionCodecNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const CompressionCodec::type& val) {
    std::map<int, const char*>::const_iterator it = compressionCodecValuesToNames.find(val);
    if (it != compressionCodecValuesToNames.end()) {
        out << it->second;
    } else {
        out << static_cast<int>(val);
    }
    return out;
}

int _kPageTypeValues[] = {
    PageType::DATA_PAGE,
    PageType::INDEX_PAGE,
    PageType::DICTIONARY_PAGE,
    PageType::DATA_PAGE_V2
};
const char* _kPageTypeNames[] = {
    "DATA_PAGE",
    "INDEX_PAGE",
    "DICTIONARY_PAGE",
    "DATA_PAGE_V2"
};
const std::map<int, const char*> pageTypeValuesToNames(::apache::thrift::TEnumIterator(4, _kPageTypeValues, _kPageTypeNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const PageType::type& val) {
    std::map<int, const char*>::const_iterator it = pageTypeValuesToNames.find(val);
    if (it != pageTypeValuesToNames.end()) {
        out << it->second;
    } else {
        out << static_cast<int>(val);
    }
    return out;
}

int _kBoundaryOrderValues[] = {
    BoundaryOrder::UNORDERED,
    BoundaryOrder::ASCENDING,
    BoundaryOrder::DESCENDING
};
const char* _kBoundaryOrderNames[] = {
    "UNORDERED",
    "ASCENDING",
    "DESCENDING"
};
const std::map<int, const char*> boundaryOrderValuesToNames(::apache::thrift::TEnumIterator(3, _kBoundaryOrderValues, _kBoundaryOrderNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const BoundaryOrder::type& val) {
    std::map<int, const char*>::const_iterator it = boundaryOrderValuesToNames.find(val);
    if (it != boundaryOrderValuesToNames.end()) {
        out << it->second;
    } else {
        out << static_cast<int>(val);
    }
    return out;
}


Statistics::~Statistics() noexcept {
}


void Statistics::setMax(const std::string& val) {
    this->max = val;
    set.max = true;
}

void Statistics::setMin(const std::string& val) {
    this->min = val;
    set.min = true;
}

void Statistics::setNullCount(const int64_t val) {
    this->null_count = val;
    set.null_count = true;
}

void Statistics::setDistinctCount(const int64_t val) {
    this->distinct_count = val;
    set.distinct_count = true;
}

void Statistics::setMaxValue(const std::string& val) {
    this->max_value = val;
    set.max_value = true;
}

void Statistics::setMinValue(const std::string& val) {
    this->min_value = val;
    set.min_value = true;
}
std::ostream& operator<<(std::ostream& out, const Statistics& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t Statistics::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->max);
                    this->set.max = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->min);
                    this->set.min = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->null_count);
                    this->set.null_count = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->distinct_count);
                    this->set.distinct_count = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->max_value);
                    this->set.max_value = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->min_value);
                    this->set.min_value = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t Statistics::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("Statistics");

    if (this->set.max) {
        xfer += oprot->writeFieldBegin("max", ::apache::thrift::protocol::T_STRING, 1);
        xfer += oprot->writeBinary(this->max);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.min) {
        xfer += oprot->writeFieldBegin("min", ::apache::thrift::protocol::T_STRING, 2);
        xfer += oprot->writeBinary(this->min);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.null_count) {
        xfer += oprot->writeFieldBegin("null_count", ::apache::thrift::protocol::T_I64, 3);
        xfer += oprot->writeI64(this->null_count);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.distinct_count) {
        xfer += oprot->writeFieldBegin("distinct_count", ::apache::thrift::protocol::T_I64, 4);
        xfer += oprot->writeI64(this->distinct_count);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.max_value) {
        xfer += oprot->writeFieldBegin("max_value", ::apache::thrift::protocol::T_STRING, 5);
        xfer += oprot->writeBinary(this->max_value);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.min_value) {
        xfer += oprot->writeFieldBegin("min_value", ::apache::thrift::protocol::T_STRING, 6);
        xfer += oprot->writeBinary(this->min_value);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(Statistics &a, Statistics &b) {
    using ::std::swap;
    swap(a.max, b.max);
    swap(a.min, b.min);
    swap(a.null_count, b.null_count);
    swap(a.distinct_count, b.distinct_count);
    swap(a.max_value, b.max_value);
    swap(a.min_value, b.min_value);
    swap(a.set, b.set);
}

Statistics::Statistics(const Statistics& other0) {
    max = other0.max;
    min = other0.min;
    null_count = other0.null_count;
    distinct_count = other0.distinct_count;
    max_value = other0.max_value;
    min_value = other0.min_value;
    set = other0.set;
}
Statistics& Statistics::operator=(const Statistics& other1) {
    max = other1.max;
    min = other1.min;
    null_count = other1.null_count;
    distinct_count = other1.distinct_count;
    max_value = other1.max_value;
    min_value = other1.min_value;
    set = other1.set;
    return *this;
}
void Statistics::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "Statistics(";
    out << "max="; (set.max ? (out << to_string(max)) : (out << "<null>"));
    out << ", " << "min="; (set.min ? (out << to_string(min)) : (out << "<null>"));
    out << ", " << "null_count="; (set.null_count ? (out << to_string(null_count)) : (out << "<null>"));
    out << ", " << "distinct_count="; (set.distinct_count ? (out << to_string(distinct_count)) : (out << "<null>"));
    out << ", " << "max_value="; (set.max_value ? (out << to_string(max_value)) : (out << "<null>"));
    out << ", " << "min_value="; (set.min_value ? (out << to_string(min_value)) : (out << "<null>"));
    out << ")";
}


StringType::~StringType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const StringType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t StringType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t StringType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("StringType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(StringType &a, StringType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

StringType::StringType(const StringType& other2) {
    (void) other2;
}
StringType& StringType::operator=(const StringType& other3) {
    (void) other3;
    return *this;
}
void StringType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "StringType(";
    out << ")";
}


UUIDType::~UUIDType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const UUIDType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t UUIDType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t UUIDType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("UUIDType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(UUIDType &a, UUIDType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

UUIDType::UUIDType(const UUIDType& other4) {
    (void) other4;
}
UUIDType& UUIDType::operator=(const UUIDType& other5) {
    (void) other5;
    return *this;
}
void UUIDType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "UUIDType(";
    out << ")";
}


MapType::~MapType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const MapType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t MapType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t MapType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("MapType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(MapType &a, MapType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

MapType::MapType(const MapType& other6) {
    (void) other6;
}
MapType& MapType::operator=(const MapType& other7) {
    (void) other7;
    return *this;
}
void MapType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "MapType(";
    out << ")";
}


ListType::~ListType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const ListType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t ListType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t ListType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("ListType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(ListType &a, ListType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

ListType::ListType(const ListType& other8) {
    (void) other8;
}
ListType& ListType::operator=(const ListType& other9) {
    (void) other9;
    return *this;
}
void ListType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "ListType(";
    out << ")";
}


EnumType::~EnumType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const EnumType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t EnumType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t EnumType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("EnumType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(EnumType &a, EnumType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

EnumType::EnumType(const EnumType& other10) {
    (void) other10;
}
EnumType& EnumType::operator=(const EnumType& other11) {
    (void) other11;
    return *this;
}
void EnumType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "EnumType(";
    out << ")";
}


DateType::~DateType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const DateType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t DateType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t DateType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("DateType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(DateType &a, DateType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

DateType::DateType(const DateType& other12) {
    (void) other12;
}
DateType& DateType::operator=(const DateType& other13) {
    (void) other13;
    return *this;
}
void DateType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "DateType(";
    out << ")";
}


NullType::~NullType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const NullType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t NullType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t NullType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("NullType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(NullType &a, NullType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

NullType::NullType(const NullType& other14) {
    (void) other14;
}
NullType& NullType::operator=(const NullType& other15) {
    (void) other15;
    return *this;
}
void NullType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "NullType(";
    out << ")";
}


DecimalType::~DecimalType() noexcept {
}


void DecimalType::setScale(const int32_t val) {
    this->scale = val;
}

void DecimalType::setPrecision(const int32_t val) {
    this->precision = val;
}
std::ostream& operator<<(std::ostream& out, const DecimalType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t DecimalType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_scale = false;
    bool isset_precision = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->scale);
                    isset_scale = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->precision);
                    isset_precision = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_scale)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_precision)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t DecimalType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("DecimalType");

    xfer += oprot->writeFieldBegin("scale", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->scale);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("precision", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->precision);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(DecimalType &a, DecimalType &b) {
    using ::std::swap;
    swap(a.scale, b.scale);
    swap(a.precision, b.precision);
}

DecimalType::DecimalType(const DecimalType& other16) {
    scale = other16.scale;
    precision = other16.precision;
}
DecimalType& DecimalType::operator=(const DecimalType& other17) {
    scale = other17.scale;
    precision = other17.precision;
    return *this;
}
void DecimalType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "DecimalType(";
    out << "scale=" << to_string(scale);
    out << ", " << "precision=" << to_string(precision);
    out << ")";
}


MilliSeconds::~MilliSeconds() noexcept {
}

std::ostream& operator<<(std::ostream& out, const MilliSeconds& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t MilliSeconds::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t MilliSeconds::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("MilliSeconds");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(MilliSeconds &a, MilliSeconds &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

MilliSeconds::MilliSeconds(const MilliSeconds& other18) {
    (void) other18;
}
MilliSeconds& MilliSeconds::operator=(const MilliSeconds& other19) {
    (void) other19;
    return *this;
}
void MilliSeconds::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "MilliSeconds(";
    out << ")";
}


MicroSeconds::~MicroSeconds() noexcept {
}

std::ostream& operator<<(std::ostream& out, const MicroSeconds& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t MicroSeconds::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t MicroSeconds::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("MicroSeconds");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(MicroSeconds &a, MicroSeconds &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

MicroSeconds::MicroSeconds(const MicroSeconds& other20) {
    (void) other20;
}
MicroSeconds& MicroSeconds::operator=(const MicroSeconds& other21) {
    (void) other21;
    return *this;
}
void MicroSeconds::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "MicroSeconds(";
    out << ")";
}


NanoSeconds::~NanoSeconds() noexcept {
}

std::ostream& operator<<(std::ostream& out, const NanoSeconds& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t NanoSeconds::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t NanoSeconds::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("NanoSeconds");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(NanoSeconds &a, NanoSeconds &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

NanoSeconds::NanoSeconds(const NanoSeconds& other22) {
    (void) other22;
}
NanoSeconds& NanoSeconds::operator=(const NanoSeconds& other23) {
    (void) other23;
    return *this;
}
void NanoSeconds::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "NanoSeconds(";
    out << ")";
}


TimeUnit::~TimeUnit() noexcept {
}


void TimeUnit::setMillis(const MilliSeconds& val) {
    this->MILLIS = val;
    set.MILLIS = true;
}

void TimeUnit::setMicros(const MicroSeconds& val) {
    this->MICROS = val;
    set.MICROS = true;
}

void TimeUnit::setNanos(const NanoSeconds& val) {
    this->NANOS = val;
    set.NANOS = true;
}
std::ostream& operator<<(std::ostream& out, const TimeUnit& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t TimeUnit::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->MILLIS.read(iprot);
                    this->set.MILLIS = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->MICROS.read(iprot);
                    this->set.MICROS = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->NANOS.read(iprot);
                    this->set.NANOS = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t TimeUnit::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("TimeUnit");

    if (this->set.MILLIS) {
        xfer += oprot->writeFieldBegin("MILLIS", ::apache::thrift::protocol::T_STRUCT, 1);
        xfer += this->MILLIS.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.MICROS) {
        xfer += oprot->writeFieldBegin("MICROS", ::apache::thrift::protocol::T_STRUCT, 2);
        xfer += this->MICROS.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.NANOS) {
        xfer += oprot->writeFieldBegin("NANOS", ::apache::thrift::protocol::T_STRUCT, 3);
        xfer += this->NANOS.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(TimeUnit &a, TimeUnit &b) {
    using ::std::swap;
    swap(a.MILLIS, b.MILLIS);
    swap(a.MICROS, b.MICROS);
    swap(a.NANOS, b.NANOS);
    swap(a.set, b.set);
}

TimeUnit::TimeUnit(const TimeUnit& other24) {
    MILLIS = other24.MILLIS;
    MICROS = other24.MICROS;
    NANOS = other24.NANOS;
    set = other24.set;
}
TimeUnit& TimeUnit::operator=(const TimeUnit& other25) {
    MILLIS = other25.MILLIS;
    MICROS = other25.MICROS;
    NANOS = other25.NANOS;
    set = other25.set;
    return *this;
}
void TimeUnit::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "TimeUnit(";
    out << "MILLIS="; (set.MILLIS ? (out << to_string(MILLIS)) : (out << "<null>"));
    out << ", " << "MICROS="; (set.MICROS ? (out << to_string(MICROS)) : (out << "<null>"));
    out << ", " << "NANOS="; (set.NANOS ? (out << to_string(NANOS)) : (out << "<null>"));
    out << ")";
}


TimestampType::~TimestampType() noexcept {
}


void TimestampType::setIsAdjustedToUtc(const bool val) {
    this->isAdjustedToUTC = val;
}

void TimestampType::setUnit(const TimeUnit& val) {
    this->unit = val;
}
std::ostream& operator<<(std::ostream& out, const TimestampType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t TimestampType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_isAdjustedToUTC = false;
    bool isset_unit = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->isAdjustedToUTC);
                    isset_isAdjustedToUTC = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->unit.read(iprot);
                    isset_unit = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_isAdjustedToUTC)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_unit)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t TimestampType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("TimestampType");

    xfer += oprot->writeFieldBegin("isAdjustedToUTC", ::apache::thrift::protocol::T_BOOL, 1);
    xfer += oprot->writeBool(this->isAdjustedToUTC);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("unit", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->unit.write(oprot);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(TimestampType &a, TimestampType &b) {
    using ::std::swap;
    swap(a.isAdjustedToUTC, b.isAdjustedToUTC);
    swap(a.unit, b.unit);
}

TimestampType::TimestampType(const TimestampType& other26) {
    isAdjustedToUTC = other26.isAdjustedToUTC;
    unit = other26.unit;
}
TimestampType& TimestampType::operator=(const TimestampType& other27) {
    isAdjustedToUTC = other27.isAdjustedToUTC;
    unit = other27.unit;
    return *this;
}
void TimestampType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "TimestampType(";
    out << "isAdjustedToUTC=" << to_string(isAdjustedToUTC);
    out << ", " << "unit=" << to_string(unit);
    out << ")";
}


TimeType::~TimeType() noexcept {
}


void TimeType::setIsAdjustedToUtc(const bool val) {
    this->isAdjustedToUTC = val;
}

void TimeType::setUnit(const TimeUnit& val) {
    this->unit = val;
}
std::ostream& operator<<(std::ostream& out, const TimeType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t TimeType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_isAdjustedToUTC = false;
    bool isset_unit = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->isAdjustedToUTC);
                    isset_isAdjustedToUTC = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->unit.read(iprot);
                    isset_unit = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_isAdjustedToUTC)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_unit)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t TimeType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("TimeType");

    xfer += oprot->writeFieldBegin("isAdjustedToUTC", ::apache::thrift::protocol::T_BOOL, 1);
    xfer += oprot->writeBool(this->isAdjustedToUTC);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("unit", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->unit.write(oprot);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(TimeType &a, TimeType &b) {
    using ::std::swap;
    swap(a.isAdjustedToUTC, b.isAdjustedToUTC);
    swap(a.unit, b.unit);
}

TimeType::TimeType(const TimeType& other28) {
    isAdjustedToUTC = other28.isAdjustedToUTC;
    unit = other28.unit;
}
TimeType& TimeType::operator=(const TimeType& other29) {
    isAdjustedToUTC = other29.isAdjustedToUTC;
    unit = other29.unit;
    return *this;
}
void TimeType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "TimeType(";
    out << "isAdjustedToUTC=" << to_string(isAdjustedToUTC);
    out << ", " << "unit=" << to_string(unit);
    out << ")";
}


IntType::~IntType() noexcept {
}


void IntType::setBitWidth(const int8_t val) {
    this->bitWidth = val;
}

void IntType::setIsSigned(const bool val) {
    this->isSigned = val;
}
std::ostream& operator<<(std::ostream& out, const IntType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t IntType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_bitWidth = false;
    bool isset_isSigned = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_BYTE) {
                    xfer += iprot->readByte(this->bitWidth);
                    isset_bitWidth = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->isSigned);
                    isset_isSigned = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_bitWidth)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_isSigned)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t IntType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("IntType");

    xfer += oprot->writeFieldBegin("bitWidth", ::apache::thrift::protocol::T_BYTE, 1);
    xfer += oprot->writeByte(this->bitWidth);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("isSigned", ::apache::thrift::protocol::T_BOOL, 2);
    xfer += oprot->writeBool(this->isSigned);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(IntType &a, IntType &b) {
    using ::std::swap;
    swap(a.bitWidth, b.bitWidth);
    swap(a.isSigned, b.isSigned);
}

IntType::IntType(const IntType& other30) {
    bitWidth = other30.bitWidth;
    isSigned = other30.isSigned;
}
IntType& IntType::operator=(const IntType& other31) {
    bitWidth = other31.bitWidth;
    isSigned = other31.isSigned;
    return *this;
}
void IntType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "IntType(";
    out << "bitWidth=" << to_string(bitWidth);
    out << ", " << "isSigned=" << to_string(isSigned);
    out << ")";
}


JsonType::~JsonType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const JsonType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t JsonType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t JsonType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("JsonType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(JsonType &a, JsonType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

JsonType::JsonType(const JsonType& other32) {
    (void) other32;
}
JsonType& JsonType::operator=(const JsonType& other33) {
    (void) other33;
    return *this;
}
void JsonType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "JsonType(";
    out << ")";
}


BsonType::~BsonType() noexcept {
}

std::ostream& operator<<(std::ostream& out, const BsonType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t BsonType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t BsonType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("BsonType");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(BsonType &a, BsonType &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

BsonType::BsonType(const BsonType& other34) {
    (void) other34;
}
BsonType& BsonType::operator=(const BsonType& other35) {
    (void) other35;
    return *this;
}
void BsonType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "BsonType(";
    out << ")";
}


LogicalType::~LogicalType() noexcept {
}


void LogicalType::setString(const StringType& val) {
    this->STRING = val;
    set.STRING = true;
}

void LogicalType::setMap(const MapType& val) {
    this->MAP = val;
    set.MAP = true;
}

void LogicalType::setList(const ListType& val) {
    this->LIST = val;
    set.LIST = true;
}

void LogicalType::setEnum(const EnumType& val) {
    this->ENUM = val;
    set.ENUM = true;
}

void LogicalType::setDecimal(const DecimalType& val) {
    this->DECIMAL = val;
    set.DECIMAL = true;
}

void LogicalType::setDate(const DateType& val) {
    this->DATE = val;
    set.DATE = true;
}

void LogicalType::setTime(const TimeType& val) {
    this->TIME = val;
    set.TIME = true;
}

void LogicalType::setTimestamp(const TimestampType& val) {
    this->TIMESTAMP = val;
    set.TIMESTAMP = true;
}

void LogicalType::setInteger(const IntType& val) {
    this->INTEGER = val;
    set.INTEGER = true;
}

void LogicalType::setUnknown(const NullType& val) {
    this->UNKNOWN = val;
    set.UNKNOWN = true;
}

void LogicalType::setJson(const JsonType& val) {
    this->JSON = val;
    set.JSON = true;
}

void LogicalType::setBson(const BsonType& val) {
    this->BSON = val;
    set.BSON = true;
}

void LogicalType::setUuid(const UUIDType& val) {
    this->UUID = val;
    set.UUID = true;
}
std::ostream& operator<<(std::ostream& out, const LogicalType& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t LogicalType::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->STRING.read(iprot);
                    this->set.STRING = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->MAP.read(iprot);
                    this->set.MAP = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->LIST.read(iprot);
                    this->set.LIST = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->ENUM.read(iprot);
                    this->set.ENUM = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->DECIMAL.read(iprot);
                    this->set.DECIMAL = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->DATE.read(iprot);
                    this->set.DATE = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 7:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->TIME.read(iprot);
                    this->set.TIME = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 8:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->TIMESTAMP.read(iprot);
                    this->set.TIMESTAMP = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 10:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->INTEGER.read(iprot);
                    this->set.INTEGER = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 11:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->UNKNOWN.read(iprot);
                    this->set.UNKNOWN = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 12:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->JSON.read(iprot);
                    this->set.JSON = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 13:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->BSON.read(iprot);
                    this->set.BSON = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 14:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->UUID.read(iprot);
                    this->set.UUID = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t LogicalType::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("LogicalType");

    if (this->set.STRING) {
        xfer += oprot->writeFieldBegin("STRING", ::apache::thrift::protocol::T_STRUCT, 1);
        xfer += this->STRING.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.MAP) {
        xfer += oprot->writeFieldBegin("MAP", ::apache::thrift::protocol::T_STRUCT, 2);
        xfer += this->MAP.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.LIST) {
        xfer += oprot->writeFieldBegin("LIST", ::apache::thrift::protocol::T_STRUCT, 3);
        xfer += this->LIST.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.ENUM) {
        xfer += oprot->writeFieldBegin("ENUM", ::apache::thrift::protocol::T_STRUCT, 4);
        xfer += this->ENUM.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.DECIMAL) {
        xfer += oprot->writeFieldBegin("DECIMAL", ::apache::thrift::protocol::T_STRUCT, 5);
        xfer += this->DECIMAL.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.DATE) {
        xfer += oprot->writeFieldBegin("DATE", ::apache::thrift::protocol::T_STRUCT, 6);
        xfer += this->DATE.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.TIME) {
        xfer += oprot->writeFieldBegin("TIME", ::apache::thrift::protocol::T_STRUCT, 7);
        xfer += this->TIME.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.TIMESTAMP) {
        xfer += oprot->writeFieldBegin("TIMESTAMP", ::apache::thrift::protocol::T_STRUCT, 8);
        xfer += this->TIMESTAMP.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.INTEGER) {
        xfer += oprot->writeFieldBegin("INTEGER", ::apache::thrift::protocol::T_STRUCT, 10);
        xfer += this->INTEGER.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.UNKNOWN) {
        xfer += oprot->writeFieldBegin("UNKNOWN", ::apache::thrift::protocol::T_STRUCT, 11);
        xfer += this->UNKNOWN.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.JSON) {
        xfer += oprot->writeFieldBegin("JSON", ::apache::thrift::protocol::T_STRUCT, 12);
        xfer += this->JSON.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.BSON) {
        xfer += oprot->writeFieldBegin("BSON", ::apache::thrift::protocol::T_STRUCT, 13);
        xfer += this->BSON.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.UUID) {
        xfer += oprot->writeFieldBegin("UUID", ::apache::thrift::protocol::T_STRUCT, 14);
        xfer += this->UUID.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(LogicalType &a, LogicalType &b) {
    using ::std::swap;
    swap(a.STRING, b.STRING);
    swap(a.MAP, b.MAP);
    swap(a.LIST, b.LIST);
    swap(a.ENUM, b.ENUM);
    swap(a.DECIMAL, b.DECIMAL);
    swap(a.DATE, b.DATE);
    swap(a.TIME, b.TIME);
    swap(a.TIMESTAMP, b.TIMESTAMP);
    swap(a.INTEGER, b.INTEGER);
    swap(a.UNKNOWN, b.UNKNOWN);
    swap(a.JSON, b.JSON);
    swap(a.BSON, b.BSON);
    swap(a.UUID, b.UUID);
    swap(a.set, b.set);
}

LogicalType::LogicalType(const LogicalType& other36) {
    STRING = other36.STRING;
    MAP = other36.MAP;
    LIST = other36.LIST;
    ENUM = other36.ENUM;
    DECIMAL = other36.DECIMAL;
    DATE = other36.DATE;
    TIME = other36.TIME;
    TIMESTAMP = other36.TIMESTAMP;
    INTEGER = other36.INTEGER;
    UNKNOWN = other36.UNKNOWN;
    JSON = other36.JSON;
    BSON = other36.BSON;
    UUID = other36.UUID;
    set = other36.set;
}
LogicalType& LogicalType::operator=(const LogicalType& other37) {
    STRING = other37.STRING;
    MAP = other37.MAP;
    LIST = other37.LIST;
    ENUM = other37.ENUM;
    DECIMAL = other37.DECIMAL;
    DATE = other37.DATE;
    TIME = other37.TIME;
    TIMESTAMP = other37.TIMESTAMP;
    INTEGER = other37.INTEGER;
    UNKNOWN = other37.UNKNOWN;
    JSON = other37.JSON;
    BSON = other37.BSON;
    UUID = other37.UUID;
    set = other37.set;
    return *this;
}
void LogicalType::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "LogicalType(";
    out << "STRING="; (set.STRING ? (out << to_string(STRING)) : (out << "<null>"));
    out << ", " << "MAP="; (set.MAP ? (out << to_string(MAP)) : (out << "<null>"));
    out << ", " << "LIST="; (set.LIST ? (out << to_string(LIST)) : (out << "<null>"));
    out << ", " << "ENUM="; (set.ENUM ? (out << to_string(ENUM)) : (out << "<null>"));
    out << ", " << "DECIMAL="; (set.DECIMAL ? (out << to_string(DECIMAL)) : (out << "<null>"));
    out << ", " << "DATE="; (set.DATE ? (out << to_string(DATE)) : (out << "<null>"));
    out << ", " << "TIME="; (set.TIME ? (out << to_string(TIME)) : (out << "<null>"));
    out << ", " << "TIMESTAMP="; (set.TIMESTAMP ? (out << to_string(TIMESTAMP)) : (out << "<null>"));
    out << ", " << "INTEGER="; (set.INTEGER ? (out << to_string(INTEGER)) : (out << "<null>"));
    out << ", " << "UNKNOWN="; (set.UNKNOWN ? (out << to_string(UNKNOWN)) : (out << "<null>"));
    out << ", " << "JSON="; (set.JSON ? (out << to_string(JSON)) : (out << "<null>"));
    out << ", " << "BSON="; (set.BSON ? (out << to_string(BSON)) : (out << "<null>"));
    out << ", " << "UUID="; (set.UUID ? (out << to_string(UUID)) : (out << "<null>"));
    out << ")";
}


SchemaElement::~SchemaElement() noexcept {
}


void SchemaElement::setType(const Type::type val) {
    this->type = val;
    set.type = true;
}

void SchemaElement::setTypeLength(const int32_t val) {
    this->type_length = val;
    set.type_length = true;
}

void SchemaElement::setRepetitionType(const FieldRepetitionType::type val) {
    this->repetition_type = val;
    set.repetition_type = true;
}

void SchemaElement::setName(const std::string& val) {
    this->name = val;
}

void SchemaElement::setNumChildren(const int32_t val) {
    this->num_children = val;
    set.num_children = true;
}

void SchemaElement::setConvertedType(const ConvertedType::type val) {
    this->converted_type = val;
    set.converted_type = true;
}

void SchemaElement::setScale(const int32_t val) {
    this->scale = val;
    set.scale = true;
}

void SchemaElement::setPrecision(const int32_t val) {
    this->precision = val;
    set.precision = true;
}

void SchemaElement::setFieldId(const int32_t val) {
    this->field_id = val;
    set.field_id = true;
}

void SchemaElement::setLogicalType(const LogicalType& val) {
    this->logicalType = val;
    set.logicalType = true;
}
std::ostream& operator<<(std::ostream& out, const SchemaElement& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t SchemaElement::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_name = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast38;
                    xfer += iprot->readI32(ecast38);
                    this->type = Type::type(ecast38);
                    this->set.type = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->type_length);
                    this->set.type_length = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast39;
                    xfer += iprot->readI32(ecast39);
                    this->repetition_type = FieldRepetitionType::type(ecast39);
                    this->set.repetition_type = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->name);
                    isset_name = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->num_children);
                    this->set.num_children = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast40;
                    xfer += iprot->readI32(ecast40);
                    this->converted_type = ConvertedType::type(ecast40);
                    this->set.converted_type = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 7:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->scale);
                    this->set.scale = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 8:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->precision);
                    this->set.precision = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 9:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->field_id);
                    this->set.field_id = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 10:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->logicalType.read(iprot);
                    this->set.logicalType = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_name)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t SchemaElement::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("SchemaElement");

    if (this->set.type) {
        xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_I32, 1);
        xfer += oprot->writeI32(this->type);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.type_length) {
        xfer += oprot->writeFieldBegin("type_length", ::apache::thrift::protocol::T_I32, 2);
        xfer += oprot->writeI32(this->type_length);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.repetition_type) {
        xfer += oprot->writeFieldBegin("repetition_type", ::apache::thrift::protocol::T_I32, 3);
        xfer += oprot->writeI32(this->repetition_type);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->name);
    xfer += oprot->writeFieldEnd();

    if (this->set.num_children) {
        xfer += oprot->writeFieldBegin("num_children", ::apache::thrift::protocol::T_I32, 5);
        xfer += oprot->writeI32(this->num_children);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.converted_type) {
        xfer += oprot->writeFieldBegin("converted_type", ::apache::thrift::protocol::T_I32, 6);
        xfer += oprot->writeI32(this->converted_type);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.scale) {
        xfer += oprot->writeFieldBegin("scale", ::apache::thrift::protocol::T_I32, 7);
        xfer += oprot->writeI32(this->scale);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.precision) {
        xfer += oprot->writeFieldBegin("precision", ::apache::thrift::protocol::T_I32, 8);
        xfer += oprot->writeI32(this->precision);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.field_id) {
        xfer += oprot->writeFieldBegin("field_id", ::apache::thrift::protocol::T_I32, 9);
        xfer += oprot->writeI32(this->field_id);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.logicalType) {
        xfer += oprot->writeFieldBegin("logicalType", ::apache::thrift::protocol::T_STRUCT, 10);
        xfer += this->logicalType.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(SchemaElement &a, SchemaElement &b) {
    using ::std::swap;
    swap(a.type, b.type);
    swap(a.type_length, b.type_length);
    swap(a.repetition_type, b.repetition_type);
    swap(a.name, b.name);
    swap(a.num_children, b.num_children);
    swap(a.converted_type, b.converted_type);
    swap(a.scale, b.scale);
    swap(a.precision, b.precision);
    swap(a.field_id, b.field_id);
    swap(a.logicalType, b.logicalType);
    swap(a.set, b.set);
}

SchemaElement::SchemaElement(const SchemaElement& other41) {
    type = other41.type;
    type_length = other41.type_length;
    repetition_type = other41.repetition_type;
    name = other41.name;
    num_children = other41.num_children;
    converted_type = other41.converted_type;
    scale = other41.scale;
    precision = other41.precision;
    field_id = other41.field_id;
    logicalType = other41.logicalType;
    set = other41.set;
}
SchemaElement& SchemaElement::operator=(const SchemaElement& other42) {
    type = other42.type;
    type_length = other42.type_length;
    repetition_type = other42.repetition_type;
    name = other42.name;
    num_children = other42.num_children;
    converted_type = other42.converted_type;
    scale = other42.scale;
    precision = other42.precision;
    field_id = other42.field_id;
    logicalType = other42.logicalType;
    set = other42.set;
    return *this;
}
void SchemaElement::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "SchemaElement(";
    out << "type="; (set.type ? (out << to_string(type)) : (out << "<null>"));
    out << ", " << "type_length="; (set.type_length ? (out << to_string(type_length)) : (out << "<null>"));
    out << ", " << "repetition_type="; (set.repetition_type ? (out << to_string(repetition_type)) : (out << "<null>"));
    out << ", " << "name=" << to_string(name);
    out << ", " << "num_children="; (set.num_children ? (out << to_string(num_children)) : (out << "<null>"));
    out << ", " << "converted_type="; (set.converted_type ? (out << to_string(converted_type)) : (out << "<null>"));
    out << ", " << "scale="; (set.scale ? (out << to_string(scale)) : (out << "<null>"));
    out << ", " << "precision="; (set.precision ? (out << to_string(precision)) : (out << "<null>"));
    out << ", " << "field_id="; (set.field_id ? (out << to_string(field_id)) : (out << "<null>"));
    out << ", " << "logicalType="; (set.logicalType ? (out << to_string(logicalType)) : (out << "<null>"));
    out << ")";
}


DataPageHeader::~DataPageHeader() noexcept {
}


void DataPageHeader::setNumValues(const int32_t val) {
    this->num_values = val;
}

void DataPageHeader::setEncoding(const Encoding::type val) {
    this->encoding = val;
}

void DataPageHeader::setDefinitionLevelEncoding(const Encoding::type val) {
    this->definition_level_encoding = val;
}

void DataPageHeader::setRepetitionLevelEncoding(const Encoding::type val) {
    this->repetition_level_encoding = val;
}

void DataPageHeader::setStatistics(const Statistics& val) {
    this->statistics = val;
    set.statistics = true;
}
std::ostream& operator<<(std::ostream& out, const DataPageHeader& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t DataPageHeader::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_num_values = false;
    bool isset_encoding = false;
    bool isset_definition_level_encoding = false;
    bool isset_repetition_level_encoding = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->num_values);
                    isset_num_values = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast43;
                    xfer += iprot->readI32(ecast43);
                    this->encoding = Encoding::type(ecast43);
                    isset_encoding = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast44;
                    xfer += iprot->readI32(ecast44);
                    this->definition_level_encoding = Encoding::type(ecast44);
                    isset_definition_level_encoding = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast45;
                    xfer += iprot->readI32(ecast45);
                    this->repetition_level_encoding = Encoding::type(ecast45);
                    isset_repetition_level_encoding = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->statistics.read(iprot);
                    this->set.statistics = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_num_values)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_encoding)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_definition_level_encoding)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_repetition_level_encoding)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t DataPageHeader::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("DataPageHeader");

    xfer += oprot->writeFieldBegin("num_values", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->num_values);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("encoding", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->encoding);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("definition_level_encoding", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->definition_level_encoding);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("repetition_level_encoding", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->repetition_level_encoding);
    xfer += oprot->writeFieldEnd();

    if (this->set.statistics) {
        xfer += oprot->writeFieldBegin("statistics", ::apache::thrift::protocol::T_STRUCT, 5);
        xfer += this->statistics.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(DataPageHeader &a, DataPageHeader &b) {
    using ::std::swap;
    swap(a.num_values, b.num_values);
    swap(a.encoding, b.encoding);
    swap(a.definition_level_encoding, b.definition_level_encoding);
    swap(a.repetition_level_encoding, b.repetition_level_encoding);
    swap(a.statistics, b.statistics);
    swap(a.set, b.set);
}

DataPageHeader::DataPageHeader(const DataPageHeader& other46) {
    num_values = other46.num_values;
    encoding = other46.encoding;
    definition_level_encoding = other46.definition_level_encoding;
    repetition_level_encoding = other46.repetition_level_encoding;
    statistics = other46.statistics;
    set = other46.set;
}
DataPageHeader& DataPageHeader::operator=(const DataPageHeader& other47) {
    num_values = other47.num_values;
    encoding = other47.encoding;
    definition_level_encoding = other47.definition_level_encoding;
    repetition_level_encoding = other47.repetition_level_encoding;
    statistics = other47.statistics;
    set = other47.set;
    return *this;
}
void DataPageHeader::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "DataPageHeader(";
    out << "num_values=" << to_string(num_values);
    out << ", " << "encoding=" << to_string(encoding);
    out << ", " << "definition_level_encoding=" << to_string(definition_level_encoding);
    out << ", " << "repetition_level_encoding=" << to_string(repetition_level_encoding);
    out << ", " << "statistics="; (set.statistics ? (out << to_string(statistics)) : (out << "<null>"));
    out << ")";
}


IndexPageHeader::~IndexPageHeader() noexcept {
}

std::ostream& operator<<(std::ostream& out, const IndexPageHeader& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t IndexPageHeader::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t IndexPageHeader::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("IndexPageHeader");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(IndexPageHeader &a, IndexPageHeader &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

IndexPageHeader::IndexPageHeader(const IndexPageHeader& other48) {
    (void) other48;
}
IndexPageHeader& IndexPageHeader::operator=(const IndexPageHeader& other49) {
    (void) other49;
    return *this;
}
void IndexPageHeader::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "IndexPageHeader(";
    out << ")";
}


DictionaryPageHeader::~DictionaryPageHeader() noexcept {
}


void DictionaryPageHeader::setNumValues(int32_t val) {
    this->num_values = val;
}

void DictionaryPageHeader::setEncoding(const Encoding::type val) {
    this->encoding = val;
}

void DictionaryPageHeader::setIsSorted(const bool val) {
    this->is_sorted = val;
    set.is_sorted = true;
}
std::ostream& operator<<(std::ostream& out, const DictionaryPageHeader& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t DictionaryPageHeader::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_num_values = false;
    bool isset_encoding = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->num_values);
                    isset_num_values = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast50;
                    xfer += iprot->readI32(ecast50);
                    this->encoding = Encoding::type(ecast50);
                    isset_encoding = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->is_sorted);
                    this->set.is_sorted = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_num_values)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_encoding)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t DictionaryPageHeader::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("DictionaryPageHeader");

    xfer += oprot->writeFieldBegin("num_values", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->num_values);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("encoding", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->encoding);
    xfer += oprot->writeFieldEnd();

    if (this->set.is_sorted) {
        xfer += oprot->writeFieldBegin("is_sorted", ::apache::thrift::protocol::T_BOOL, 3);
        xfer += oprot->writeBool(this->is_sorted);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(DictionaryPageHeader &a, DictionaryPageHeader &b) {
    using ::std::swap;
    swap(a.num_values, b.num_values);
    swap(a.encoding, b.encoding);
    swap(a.is_sorted, b.is_sorted);
    swap(a.set, b.set);
}

DictionaryPageHeader::DictionaryPageHeader(const DictionaryPageHeader& other51) {
    num_values = other51.num_values;
    encoding = other51.encoding;
    is_sorted = other51.is_sorted;
    set = other51.set;
}
DictionaryPageHeader& DictionaryPageHeader::operator=(const DictionaryPageHeader& other52) {
    num_values = other52.num_values;
    encoding = other52.encoding;
    is_sorted = other52.is_sorted;
    set = other52.set;
    return *this;
}
void DictionaryPageHeader::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "DictionaryPageHeader(";
    out << "num_values=" << to_string(num_values);
    out << ", " << "encoding=" << to_string(encoding);
    out << ", " << "is_sorted="; (set.is_sorted ? (out << to_string(is_sorted)) : (out << "<null>"));
    out << ")";
}


DataPageHeaderV2::~DataPageHeaderV2() noexcept {
}


void DataPageHeaderV2::setNumValues(int32_t val) {
    this->num_values = val;
}

void DataPageHeaderV2::setNumNulls(int32_t val) {
    this->num_nulls = val;
}

void DataPageHeaderV2::setNumRows(int32_t val) {
    this->num_rows = val;
}

void DataPageHeaderV2::setEncoding(Encoding::type val) {
    this->encoding = val;
}

void DataPageHeaderV2::setDefinitionLevelsByteLength(int32_t val) {
    this->definition_levels_byte_length = val;
}

void DataPageHeaderV2::setRepetitionLevelsByteLength(int32_t val) {
    this->repetition_levels_byte_length = val;
}

void DataPageHeaderV2::setIsCompressed(const bool val) {
    this->is_compressed = val;
    set.is_compressed = true;
}

void DataPageHeaderV2::setStatistics(const Statistics& val) {
    this->statistics = val;
    set.statistics = true;
}
std::ostream& operator<<(std::ostream& out, const DataPageHeaderV2& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t DataPageHeaderV2::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_num_values = false;
    bool isset_num_nulls = false;
    bool isset_num_rows = false;
    bool isset_encoding = false;
    bool isset_definition_levels_byte_length = false;
    bool isset_repetition_levels_byte_length = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->num_values);
                    isset_num_values = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->num_nulls);
                    isset_num_nulls = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->num_rows);
                    isset_num_rows = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast53;
                    xfer += iprot->readI32(ecast53);
                    this->encoding = Encoding::type(ecast53);
                    isset_encoding = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->definition_levels_byte_length);
                    isset_definition_levels_byte_length = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->repetition_levels_byte_length);
                    isset_repetition_levels_byte_length = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 7:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->is_compressed);
                    this->set.is_compressed = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 8:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->statistics.read(iprot);
                    this->set.statistics = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_num_values)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_num_nulls)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_num_rows)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_encoding)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_definition_levels_byte_length)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_repetition_levels_byte_length)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t DataPageHeaderV2::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("DataPageHeaderV2");

    xfer += oprot->writeFieldBegin("num_values", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->num_values);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("num_nulls", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->num_nulls);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("num_rows", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->num_rows);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("encoding", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->encoding);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("definition_levels_byte_length", ::apache::thrift::protocol::T_I32, 5);
    xfer += oprot->writeI32(this->definition_levels_byte_length);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("repetition_levels_byte_length", ::apache::thrift::protocol::T_I32, 6);
    xfer += oprot->writeI32(this->repetition_levels_byte_length);
    xfer += oprot->writeFieldEnd();

    if (this->set.is_compressed) {
        xfer += oprot->writeFieldBegin("is_compressed", ::apache::thrift::protocol::T_BOOL, 7);
        xfer += oprot->writeBool(this->is_compressed);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.statistics) {
        xfer += oprot->writeFieldBegin("statistics", ::apache::thrift::protocol::T_STRUCT, 8);
        xfer += this->statistics.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(DataPageHeaderV2 &a, DataPageHeaderV2 &b) {
    using ::std::swap;
    swap(a.num_values, b.num_values);
    swap(a.num_nulls, b.num_nulls);
    swap(a.num_rows, b.num_rows);
    swap(a.encoding, b.encoding);
    swap(a.definition_levels_byte_length, b.definition_levels_byte_length);
    swap(a.repetition_levels_byte_length, b.repetition_levels_byte_length);
    swap(a.is_compressed, b.is_compressed);
    swap(a.statistics, b.statistics);
    swap(a.set, b.set);
}

DataPageHeaderV2::DataPageHeaderV2(const DataPageHeaderV2& other54) {
    num_values = other54.num_values;
    num_nulls = other54.num_nulls;
    num_rows = other54.num_rows;
    encoding = other54.encoding;
    definition_levels_byte_length = other54.definition_levels_byte_length;
    repetition_levels_byte_length = other54.repetition_levels_byte_length;
    is_compressed = other54.is_compressed;
    statistics = other54.statistics;
    set = other54.set;
}
DataPageHeaderV2& DataPageHeaderV2::operator=(const DataPageHeaderV2& other55) {
    num_values = other55.num_values;
    num_nulls = other55.num_nulls;
    num_rows = other55.num_rows;
    encoding = other55.encoding;
    definition_levels_byte_length = other55.definition_levels_byte_length;
    repetition_levels_byte_length = other55.repetition_levels_byte_length;
    is_compressed = other55.is_compressed;
    statistics = other55.statistics;
    set = other55.set;
    return *this;
}
void DataPageHeaderV2::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "DataPageHeaderV2(";
    out << "num_values=" << to_string(num_values);
    out << ", " << "num_nulls=" << to_string(num_nulls);
    out << ", " << "num_rows=" << to_string(num_rows);
    out << ", " << "encoding=" << to_string(encoding);
    out << ", " << "definition_levels_byte_length=" << to_string(definition_levels_byte_length);
    out << ", " << "repetition_levels_byte_length=" << to_string(repetition_levels_byte_length);
    out << ", " << "is_compressed="; (set.is_compressed ? (out << to_string(is_compressed)) : (out << "<null>"));
    out << ", " << "statistics="; (set.statistics ? (out << to_string(statistics)) : (out << "<null>"));
    out << ")";
}


PageHeader::~PageHeader() noexcept {
}


void PageHeader::setType(const PageType::type val) {
    this->type = val;
}

void PageHeader::setUncompressedPageSize(const int32_t val) {
    this->uncompressed_page_size = val;
}

void PageHeader::setCompressedPageSize(const int32_t val) {
    this->compressed_page_size = val;
}

void PageHeader::setCrc(const int32_t val) {
    this->crc = val;
    set.crc = true;
}

void PageHeader::setDataPageHeader(const DataPageHeader& val) {
    this->data_page_header = val;
    set.data_page_header = true;
}

void PageHeader::setIndexPageHeader(const IndexPageHeader& val) {
    this->index_page_header = val;
    set.index_page_header = true;
}

void PageHeader::setDictionaryPageHeader(const DictionaryPageHeader& val) {
    this->dictionary_page_header = val;
    set.dictionary_page_header = true;
}

void PageHeader::setDataPageHeaderV2(const DataPageHeaderV2& val) {
    this->data_page_header_v2 = val;
    set.data_page_header_v2 = true;
}
std::ostream& operator<<(std::ostream& out, const PageHeader& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t PageHeader::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_type = false;
    bool isset_uncompressed_page_size = false;
    bool isset_compressed_page_size = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast56;
                    xfer += iprot->readI32(ecast56);
                    this->type = PageType::type(ecast56);
                    isset_type = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->uncompressed_page_size);
                    isset_uncompressed_page_size = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->compressed_page_size);
                    isset_compressed_page_size = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->crc);
                    this->set.crc = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->data_page_header.read(iprot);
                    this->set.data_page_header = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->index_page_header.read(iprot);
                    this->set.index_page_header = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 7:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->dictionary_page_header.read(iprot);
                    this->set.dictionary_page_header = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 8:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->data_page_header_v2.read(iprot);
                    this->set.data_page_header_v2 = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_type)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_uncompressed_page_size)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_compressed_page_size)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t PageHeader::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("PageHeader");

    xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->type);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("uncompressed_page_size", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->uncompressed_page_size);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("compressed_page_size", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->compressed_page_size);
    xfer += oprot->writeFieldEnd();

    if (this->set.crc) {
        xfer += oprot->writeFieldBegin("crc", ::apache::thrift::protocol::T_I32, 4);
        xfer += oprot->writeI32(this->crc);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.data_page_header) {
        xfer += oprot->writeFieldBegin("data_page_header", ::apache::thrift::protocol::T_STRUCT, 5);
        xfer += this->data_page_header.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.index_page_header) {
        xfer += oprot->writeFieldBegin("index_page_header", ::apache::thrift::protocol::T_STRUCT, 6);
        xfer += this->index_page_header.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.dictionary_page_header) {
        xfer += oprot->writeFieldBegin("dictionary_page_header", ::apache::thrift::protocol::T_STRUCT, 7);
        xfer += this->dictionary_page_header.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.data_page_header_v2) {
        xfer += oprot->writeFieldBegin("data_page_header_v2", ::apache::thrift::protocol::T_STRUCT, 8);
        xfer += this->data_page_header_v2.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(PageHeader &a, PageHeader &b) {
    using ::std::swap;
    swap(a.type, b.type);
    swap(a.uncompressed_page_size, b.uncompressed_page_size);
    swap(a.compressed_page_size, b.compressed_page_size);
    swap(a.crc, b.crc);
    swap(a.data_page_header, b.data_page_header);
    swap(a.index_page_header, b.index_page_header);
    swap(a.dictionary_page_header, b.dictionary_page_header);
    swap(a.data_page_header_v2, b.data_page_header_v2);
    swap(a.set, b.set);
}

PageHeader::PageHeader(const PageHeader& other57) {
    type = other57.type;
    uncompressed_page_size = other57.uncompressed_page_size;
    compressed_page_size = other57.compressed_page_size;
    crc = other57.crc;
    data_page_header = other57.data_page_header;
    index_page_header = other57.index_page_header;
    dictionary_page_header = other57.dictionary_page_header;
    data_page_header_v2 = other57.data_page_header_v2;
    set = other57.set;
}
PageHeader& PageHeader::operator=(const PageHeader& other58) {
    type = other58.type;
    uncompressed_page_size = other58.uncompressed_page_size;
    compressed_page_size = other58.compressed_page_size;
    crc = other58.crc;
    data_page_header = other58.data_page_header;
    index_page_header = other58.index_page_header;
    dictionary_page_header = other58.dictionary_page_header;
    data_page_header_v2 = other58.data_page_header_v2;
    set = other58.set;
    return *this;
}
void PageHeader::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "PageHeader(";
    out << "type=" << to_string(type);
    out << ", " << "uncompressed_page_size=" << to_string(uncompressed_page_size);
    out << ", " << "compressed_page_size=" << to_string(compressed_page_size);
    out << ", " << "crc="; (set.crc ? (out << to_string(crc)) : (out << "<null>"));
    out << ", " << "data_page_header="; (set.data_page_header ? (out << to_string(data_page_header)) : (out << "<null>"));
    out << ", " << "index_page_header="; (set.index_page_header ? (out << to_string(index_page_header)) : (out << "<null>"));
    out << ", " << "dictionary_page_header="; (set.dictionary_page_header ? (out << to_string(dictionary_page_header)) : (out << "<null>"));
    out << ", " << "data_page_header_v2="; (set.data_page_header_v2 ? (out << to_string(data_page_header_v2)) : (out << "<null>"));
    out << ")";
}


KeyValue::~KeyValue() noexcept {
}


void KeyValue::setKey(const std::string& val) {
    this->key = val;
}

void KeyValue::setValue(const std::string& val) {
    this->value = val;
    set.value = true;
}
std::ostream& operator<<(std::ostream& out, const KeyValue& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t KeyValue::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_key = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->key);
                    isset_key = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->value);
                    this->set.value = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_key)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t KeyValue::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("KeyValue");

    xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->key);
    xfer += oprot->writeFieldEnd();

    if (this->set.value) {
        xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
        xfer += oprot->writeString(this->value);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(KeyValue &a, KeyValue &b) {
    using ::std::swap;
    swap(a.key, b.key);
    swap(a.value, b.value);
    swap(a.set, b.set);
}

KeyValue::KeyValue(const KeyValue& other59) {
    key = other59.key;
    value = other59.value;
    set = other59.set;
}
KeyValue& KeyValue::operator=(const KeyValue& other60) {
    key = other60.key;
    value = other60.value;
    set = other60.set;
    return *this;
}
void KeyValue::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "KeyValue(";
    out << "key=" << to_string(key);
    out << ", " << "value="; (set.value ? (out << to_string(value)) : (out << "<null>"));
    out << ")";
}


SortingColumn::~SortingColumn() noexcept {
}


void SortingColumn::setColumnIdx(const int32_t val) {
    this->column_idx = val;
}

void SortingColumn::setDescending(const bool val) {
    this->descending = val;
}

void SortingColumn::setNullsFirst(const bool val) {
    this->nulls_first = val;
}
std::ostream& operator<<(std::ostream& out, const SortingColumn& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t SortingColumn::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_column_idx = false;
    bool isset_descending = false;
    bool isset_nulls_first = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->column_idx);
                    isset_column_idx = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->descending);
                    isset_descending = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->nulls_first);
                    isset_nulls_first = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_column_idx)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_descending)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_nulls_first)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t SortingColumn::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("SortingColumn");

    xfer += oprot->writeFieldBegin("column_idx", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->column_idx);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("descending", ::apache::thrift::protocol::T_BOOL, 2);
    xfer += oprot->writeBool(this->descending);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("nulls_first", ::apache::thrift::protocol::T_BOOL, 3);
    xfer += oprot->writeBool(this->nulls_first);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(SortingColumn &a, SortingColumn &b) {
    using ::std::swap;
    swap(a.column_idx, b.column_idx);
    swap(a.descending, b.descending);
    swap(a.nulls_first, b.nulls_first);
}

SortingColumn::SortingColumn(const SortingColumn& other61) {
    column_idx = other61.column_idx;
    descending = other61.descending;
    nulls_first = other61.nulls_first;
}
SortingColumn& SortingColumn::operator=(const SortingColumn& other62) {
    column_idx = other62.column_idx;
    descending = other62.descending;
    nulls_first = other62.nulls_first;
    return *this;
}
void SortingColumn::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "SortingColumn(";
    out << "column_idx=" << to_string(column_idx);
    out << ", " << "descending=" << to_string(descending);
    out << ", " << "nulls_first=" << to_string(nulls_first);
    out << ")";
}


PageEncodingStats::~PageEncodingStats() noexcept {
}


void PageEncodingStats::setPageType(const PageType::type val) {
    this->page_type = val;
}

void PageEncodingStats::setEncoding(const Encoding::type val) {
    this->encoding = val;
}

void PageEncodingStats::setCount(const int32_t val) {
    this->count = val;
}
std::ostream& operator<<(std::ostream& out, const PageEncodingStats& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t PageEncodingStats::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_page_type = false;
    bool isset_encoding = false;
    bool isset_count = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast63;
                    xfer += iprot->readI32(ecast63);
                    this->page_type = PageType::type(ecast63);
                    isset_page_type = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast64;
                    xfer += iprot->readI32(ecast64);
                    this->encoding = Encoding::type(ecast64);
                    isset_encoding = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->count);
                    isset_count = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_page_type)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_encoding)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_count)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t PageEncodingStats::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("PageEncodingStats");

    xfer += oprot->writeFieldBegin("page_type", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->page_type);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("encoding", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->encoding);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("count", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->count);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(PageEncodingStats &a, PageEncodingStats &b) {
    using ::std::swap;
    swap(a.page_type, b.page_type);
    swap(a.encoding, b.encoding);
    swap(a.count, b.count);
}

PageEncodingStats::PageEncodingStats(const PageEncodingStats& other65) {
    page_type = other65.page_type;
    encoding = other65.encoding;
    count = other65.count;
}
PageEncodingStats& PageEncodingStats::operator=(const PageEncodingStats& other66) {
    page_type = other66.page_type;
    encoding = other66.encoding;
    count = other66.count;
    return *this;
}
void PageEncodingStats::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "PageEncodingStats(";
    out << "page_type=" << to_string(page_type);
    out << ", " << "encoding=" << to_string(encoding);
    out << ", " << "count=" << to_string(count);
    out << ")";
}


ColumnMetaData::~ColumnMetaData() noexcept {
}


void ColumnMetaData::setType(const Type::type val) {
    this->type = val;
}

void ColumnMetaData::setEncodings(const std::vector<Encoding::type> & val) {
    this->encodings = val;
}

void ColumnMetaData::setPathInSchema(const std::vector<std::string> & val) {
    this->path_in_schema = val;
}

void ColumnMetaData::setCodec(CompressionCodec::type val) {
    this->codec = val;
}

void ColumnMetaData::setNumValues(const int64_t val) {
    this->num_values = val;
}

void ColumnMetaData::setTotalUncompressedSize(const int64_t val) {
    this->total_uncompressed_size = val;
}

void ColumnMetaData::setTotalCompressedSize(const int64_t val) {
    this->total_compressed_size = val;
}

void ColumnMetaData::setKeyValueMetadata(const std::vector<KeyValue> & val) {
    this->key_value_metadata = val;
    set.key_value_metadata = true;
}

void ColumnMetaData::setDataPageOffset(const int64_t val) {
    this->data_page_offset = val;
}

void ColumnMetaData::setIndexPageOffset(const int64_t val) {
    this->index_page_offset = val;
    set.index_page_offset = true;
}

void ColumnMetaData::setDictionaryPageOffset(const int64_t val) {
    this->dictionary_page_offset = val;
    set.dictionary_page_offset = true;
}

void ColumnMetaData::setStatistics(const Statistics& val) {
    this->statistics = val;
    set.statistics = true;
}

void ColumnMetaData::setEncodingStats(const std::vector<PageEncodingStats> & val) {
    this->encoding_stats = val;
    set.encoding_stats = true;
}
std::ostream& operator<<(std::ostream& out, const ColumnMetaData& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t ColumnMetaData::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_type = false;
    bool isset_encodings = false;
    bool isset_path_in_schema = false;
    bool isset_codec = false;
    bool isset_num_values = false;
    bool isset_total_uncompressed_size = false;
    bool isset_total_compressed_size = false;
    bool isset_data_page_offset = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast67;
                    xfer += iprot->readI32(ecast67);
                    this->type = Type::type(ecast67);
                    isset_type = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->encodings.clear();
                        uint32_t _size68;
                        ::apache::thrift::protocol::TType _etype71;
                        xfer += iprot->readListBegin(_etype71, _size68);
                        this->encodings.resize(_size68);
                        uint32_t _i72;
                        for (_i72 = 0; _i72 < _size68; ++_i72)
                        {
                            int32_t ecast73;
                            xfer += iprot->readI32(ecast73);
                            this->encodings[_i72] = Encoding::type(ecast73);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_encodings = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->path_in_schema.clear();
                        uint32_t _size74;
                        ::apache::thrift::protocol::TType _etype77;
                        xfer += iprot->readListBegin(_etype77, _size74);
                        this->path_in_schema.resize(_size74);
                        uint32_t _i78;
                        for (_i78 = 0; _i78 < _size74; ++_i78)
                        {
                            xfer += iprot->readString(this->path_in_schema[_i78]);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_path_in_schema = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast79;
                    xfer += iprot->readI32(ecast79);
                    this->codec = CompressionCodec::type(ecast79);
                    isset_codec = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->num_values);
                    isset_num_values = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->total_uncompressed_size);
                    isset_total_uncompressed_size = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 7:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->total_compressed_size);
                    isset_total_compressed_size = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 8:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->key_value_metadata.clear();
                        uint32_t _size80;
                        ::apache::thrift::protocol::TType _etype83;
                        xfer += iprot->readListBegin(_etype83, _size80);
                        this->key_value_metadata.resize(_size80);
                        uint32_t _i84;
                        for (_i84 = 0; _i84 < _size80; ++_i84)
                        {
                            xfer += this->key_value_metadata[_i84].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    this->set.key_value_metadata = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 9:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->data_page_offset);
                    isset_data_page_offset = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 10:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->index_page_offset);
                    this->set.index_page_offset = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 11:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->dictionary_page_offset);
                    this->set.dictionary_page_offset = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 12:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->statistics.read(iprot);
                    this->set.statistics = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 13:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->encoding_stats.clear();
                        uint32_t _size85;
                        ::apache::thrift::protocol::TType _etype88;
                        xfer += iprot->readListBegin(_etype88, _size85);
                        this->encoding_stats.resize(_size85);
                        uint32_t _i89;
                        for (_i89 = 0; _i89 < _size85; ++_i89)
                        {
                            xfer += this->encoding_stats[_i89].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    this->set.encoding_stats = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_type)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_encodings)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_path_in_schema)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_codec)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_num_values)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_total_uncompressed_size)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_total_compressed_size)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_data_page_offset)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t ColumnMetaData::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("ColumnMetaData");

    xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->type);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("encodings", ::apache::thrift::protocol::T_LIST, 2);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->encodings.size()));
        std::vector<Encoding::type> ::const_iterator _iter90;
        for (_iter90 = this->encodings.begin(); _iter90 != this->encodings.end(); ++_iter90)
        {
            xfer += oprot->writeI32((*_iter90));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("path_in_schema", ::apache::thrift::protocol::T_LIST, 3);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->path_in_schema.size()));
        std::vector<std::string> ::const_iterator _iter91;
        for (_iter91 = this->path_in_schema.begin(); _iter91 != this->path_in_schema.end(); ++_iter91)
        {
            xfer += oprot->writeString((*_iter91));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("codec", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->codec);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("num_values", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->num_values);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("total_uncompressed_size", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->total_uncompressed_size);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("total_compressed_size", ::apache::thrift::protocol::T_I64, 7);
    xfer += oprot->writeI64(this->total_compressed_size);
    xfer += oprot->writeFieldEnd();

    if (this->set.key_value_metadata) {
        xfer += oprot->writeFieldBegin("key_value_metadata", ::apache::thrift::protocol::T_LIST, 8);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->key_value_metadata.size()));
            std::vector<KeyValue> ::const_iterator _iter92;
            for (_iter92 = this->key_value_metadata.begin(); _iter92 != this->key_value_metadata.end(); ++_iter92)
            {
                xfer += (*_iter92).write(oprot);
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldBegin("data_page_offset", ::apache::thrift::protocol::T_I64, 9);
    xfer += oprot->writeI64(this->data_page_offset);
    xfer += oprot->writeFieldEnd();

    if (this->set.index_page_offset) {
        xfer += oprot->writeFieldBegin("index_page_offset", ::apache::thrift::protocol::T_I64, 10);
        xfer += oprot->writeI64(this->index_page_offset);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.dictionary_page_offset) {
        xfer += oprot->writeFieldBegin("dictionary_page_offset", ::apache::thrift::protocol::T_I64, 11);
        xfer += oprot->writeI64(this->dictionary_page_offset);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.statistics) {
        xfer += oprot->writeFieldBegin("statistics", ::apache::thrift::protocol::T_STRUCT, 12);
        xfer += this->statistics.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.encoding_stats) {
        xfer += oprot->writeFieldBegin("encoding_stats", ::apache::thrift::protocol::T_LIST, 13);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->encoding_stats.size()));
            std::vector<PageEncodingStats> ::const_iterator _iter93;
            for (_iter93 = this->encoding_stats.begin(); _iter93 != this->encoding_stats.end(); ++_iter93)
            {
                xfer += (*_iter93).write(oprot);
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(ColumnMetaData &a, ColumnMetaData &b) {
    using ::std::swap;
    swap(a.type, b.type);
    swap(a.encodings, b.encodings);
    swap(a.path_in_schema, b.path_in_schema);
    swap(a.codec, b.codec);
    swap(a.num_values, b.num_values);
    swap(a.total_uncompressed_size, b.total_uncompressed_size);
    swap(a.total_compressed_size, b.total_compressed_size);
    swap(a.key_value_metadata, b.key_value_metadata);
    swap(a.data_page_offset, b.data_page_offset);
    swap(a.index_page_offset, b.index_page_offset);
    swap(a.dictionary_page_offset, b.dictionary_page_offset);
    swap(a.statistics, b.statistics);
    swap(a.encoding_stats, b.encoding_stats);
    swap(a.set, b.set);
}

ColumnMetaData::ColumnMetaData(const ColumnMetaData& other94) {
    type = other94.type;
    encodings = other94.encodings;
    path_in_schema = other94.path_in_schema;
    codec = other94.codec;
    num_values = other94.num_values;
    total_uncompressed_size = other94.total_uncompressed_size;
    total_compressed_size = other94.total_compressed_size;
    key_value_metadata = other94.key_value_metadata;
    data_page_offset = other94.data_page_offset;
    index_page_offset = other94.index_page_offset;
    dictionary_page_offset = other94.dictionary_page_offset;
    statistics = other94.statistics;
    encoding_stats = other94.encoding_stats;
    set = other94.set;
}
ColumnMetaData& ColumnMetaData::operator=(const ColumnMetaData& other95) {
    type = other95.type;
    encodings = other95.encodings;
    path_in_schema = other95.path_in_schema;
    codec = other95.codec;
    num_values = other95.num_values;
    total_uncompressed_size = other95.total_uncompressed_size;
    total_compressed_size = other95.total_compressed_size;
    key_value_metadata = other95.key_value_metadata;
    data_page_offset = other95.data_page_offset;
    index_page_offset = other95.index_page_offset;
    dictionary_page_offset = other95.dictionary_page_offset;
    statistics = other95.statistics;
    encoding_stats = other95.encoding_stats;
    set = other95.set;
    return *this;
}
void ColumnMetaData::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "ColumnMetaData(";
    out << "type=" << to_string(type);
    out << ", " << "encodings=" << to_string(encodings);
    out << ", " << "path_in_schema=" << to_string(path_in_schema);
    out << ", " << "codec=" << to_string(codec);
    out << ", " << "num_values=" << to_string(num_values);
    out << ", " << "total_uncompressed_size=" << to_string(total_uncompressed_size);
    out << ", " << "total_compressed_size=" << to_string(total_compressed_size);
    out << ", " << "key_value_metadata="; (set.key_value_metadata ? (out << to_string(key_value_metadata)) : (out << "<null>"));
    out << ", " << "data_page_offset=" << to_string(data_page_offset);
    out << ", " << "index_page_offset="; (set.index_page_offset ? (out << to_string(index_page_offset)) : (out << "<null>"));
    out << ", " << "dictionary_page_offset="; (set.dictionary_page_offset ? (out << to_string(dictionary_page_offset)) : (out << "<null>"));
    out << ", " << "statistics="; (set.statistics ? (out << to_string(statistics)) : (out << "<null>"));
    out << ", " << "encoding_stats="; (set.encoding_stats ? (out << to_string(encoding_stats)) : (out << "<null>"));
    out << ")";
}


EncryptionWithFooterKey::~EncryptionWithFooterKey() noexcept {
}

std::ostream& operator<<(std::ostream& out, const EncryptionWithFooterKey& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t EncryptionWithFooterKey::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t EncryptionWithFooterKey::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("EncryptionWithFooterKey");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(EncryptionWithFooterKey &a, EncryptionWithFooterKey &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

EncryptionWithFooterKey::EncryptionWithFooterKey(const EncryptionWithFooterKey& other96) {
    (void) other96;
}
EncryptionWithFooterKey& EncryptionWithFooterKey::operator=(const EncryptionWithFooterKey& other97) {
    (void) other97;
    return *this;
}
void EncryptionWithFooterKey::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "EncryptionWithFooterKey(";
    out << ")";
}


EncryptionWithColumnKey::~EncryptionWithColumnKey() noexcept {
}


void EncryptionWithColumnKey::setPathInSchema(const std::vector<std::string> & val) {
    this->path_in_schema = val;
}

void EncryptionWithColumnKey::setKeyMetadata(const std::string& val) {
    this->key_metadata = val;
    set.key_metadata = true;
}
std::ostream& operator<<(std::ostream& out, const EncryptionWithColumnKey& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t EncryptionWithColumnKey::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_path_in_schema = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->path_in_schema.clear();
                        uint32_t _size98;
                        ::apache::thrift::protocol::TType _etype101;
                        xfer += iprot->readListBegin(_etype101, _size98);
                        this->path_in_schema.resize(_size98);
                        uint32_t _i102;
                        for (_i102 = 0; _i102 < _size98; ++_i102)
                        {
                            xfer += iprot->readString(this->path_in_schema[_i102]);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_path_in_schema = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->key_metadata);
                    this->set.key_metadata = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_path_in_schema)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t EncryptionWithColumnKey::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("EncryptionWithColumnKey");

    xfer += oprot->writeFieldBegin("path_in_schema", ::apache::thrift::protocol::T_LIST, 1);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->path_in_schema.size()));
        std::vector<std::string> ::const_iterator _iter103;
        for (_iter103 = this->path_in_schema.begin(); _iter103 != this->path_in_schema.end(); ++_iter103)
        {
            xfer += oprot->writeString((*_iter103));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    if (this->set.key_metadata) {
        xfer += oprot->writeFieldBegin("key_metadata", ::apache::thrift::protocol::T_STRING, 2);
        xfer += oprot->writeBinary(this->key_metadata);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(EncryptionWithColumnKey &a, EncryptionWithColumnKey &b) {
    using ::std::swap;
    swap(a.path_in_schema, b.path_in_schema);
    swap(a.key_metadata, b.key_metadata);
    swap(a.set, b.set);
}

EncryptionWithColumnKey::EncryptionWithColumnKey(const EncryptionWithColumnKey& other104) {
    path_in_schema = other104.path_in_schema;
    key_metadata = other104.key_metadata;
    set = other104.set;
}
EncryptionWithColumnKey& EncryptionWithColumnKey::operator=(const EncryptionWithColumnKey& other105) {
    path_in_schema = other105.path_in_schema;
    key_metadata = other105.key_metadata;
    set = other105.set;
    return *this;
}
void EncryptionWithColumnKey::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "EncryptionWithColumnKey(";
    out << "path_in_schema=" << to_string(path_in_schema);
    out << ", " << "key_metadata="; (set.key_metadata ? (out << to_string(key_metadata)) : (out << "<null>"));
    out << ")";
}


ColumnCryptoMetaData::~ColumnCryptoMetaData() noexcept {
}


void ColumnCryptoMetaData::setEncryptionWithFooterKey(const EncryptionWithFooterKey& val) {
    this->ENCRYPTION_WITH_FOOTER_KEY = val;
    set.ENCRYPTION_WITH_FOOTER_KEY = true;
}

void ColumnCryptoMetaData::setEncryptionWithColumnKey(const EncryptionWithColumnKey& val) {
    this->ENCRYPTION_WITH_COLUMN_KEY = val;
    set.ENCRYPTION_WITH_COLUMN_KEY = true;
}
std::ostream& operator<<(std::ostream& out, const ColumnCryptoMetaData& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t ColumnCryptoMetaData::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->ENCRYPTION_WITH_FOOTER_KEY.read(iprot);
                    this->set.ENCRYPTION_WITH_FOOTER_KEY = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->ENCRYPTION_WITH_COLUMN_KEY.read(iprot);
                    this->set.ENCRYPTION_WITH_COLUMN_KEY = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t ColumnCryptoMetaData::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("ColumnCryptoMetaData");

    if (this->set.ENCRYPTION_WITH_FOOTER_KEY) {
        xfer += oprot->writeFieldBegin("ENCRYPTION_WITH_FOOTER_KEY", ::apache::thrift::protocol::T_STRUCT, 1);
        xfer += this->ENCRYPTION_WITH_FOOTER_KEY.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.ENCRYPTION_WITH_COLUMN_KEY) {
        xfer += oprot->writeFieldBegin("ENCRYPTION_WITH_COLUMN_KEY", ::apache::thrift::protocol::T_STRUCT, 2);
        xfer += this->ENCRYPTION_WITH_COLUMN_KEY.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(ColumnCryptoMetaData &a, ColumnCryptoMetaData &b) {
    using ::std::swap;
    swap(a.ENCRYPTION_WITH_FOOTER_KEY, b.ENCRYPTION_WITH_FOOTER_KEY);
    swap(a.ENCRYPTION_WITH_COLUMN_KEY, b.ENCRYPTION_WITH_COLUMN_KEY);
    swap(a.set, b.set);
}

ColumnCryptoMetaData::ColumnCryptoMetaData(const ColumnCryptoMetaData& other106) {
    ENCRYPTION_WITH_FOOTER_KEY = other106.ENCRYPTION_WITH_FOOTER_KEY;
    ENCRYPTION_WITH_COLUMN_KEY = other106.ENCRYPTION_WITH_COLUMN_KEY;
    set = other106.set;
}
ColumnCryptoMetaData& ColumnCryptoMetaData::operator=(const ColumnCryptoMetaData& other107) {
    ENCRYPTION_WITH_FOOTER_KEY = other107.ENCRYPTION_WITH_FOOTER_KEY;
    ENCRYPTION_WITH_COLUMN_KEY = other107.ENCRYPTION_WITH_COLUMN_KEY;
    set = other107.set;
    return *this;
}
void ColumnCryptoMetaData::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "ColumnCryptoMetaData(";
    out << "ENCRYPTION_WITH_FOOTER_KEY="; (set.ENCRYPTION_WITH_FOOTER_KEY ? (out << to_string(ENCRYPTION_WITH_FOOTER_KEY)) : (out << "<null>"));
    out << ", " << "ENCRYPTION_WITH_COLUMN_KEY="; (set.ENCRYPTION_WITH_COLUMN_KEY ? (out << to_string(ENCRYPTION_WITH_COLUMN_KEY)) : (out << "<null>"));
    out << ")";
}


ColumnChunk::~ColumnChunk() noexcept {
}


void ColumnChunk::setFilePath(const std::string& val) {
    this->file_path = val;
    set.file_path = true;
}

void ColumnChunk::setFileOffset(const int64_t val) {
    this->file_offset = val;
}

void ColumnChunk::setMetaData(const ColumnMetaData& val) {
    this->meta_data = val;
    set.meta_data = true;
}

void ColumnChunk::setOffsetIndexOffset(const int64_t val) {
    this->offset_index_offset = val;
    set.offset_index_offset = true;
}

void ColumnChunk::setOffsetIndexLength(const int32_t val) {
    this->offset_index_length = val;
    set.offset_index_length = true;
}

void ColumnChunk::setColumnIndexOffset(const int64_t val) {
    this->column_index_offset = val;
    set.column_index_offset = true;
}

void ColumnChunk::setColumnIndexLength(const int32_t val) {
    this->column_index_length = val;
    set.column_index_length = true;
}

void ColumnChunk::setCryptoMetadata(const ColumnCryptoMetaData& val) {
    this->crypto_metadata = val;
    set.crypto_metadata = true;
}

void ColumnChunk::setEncryptedColumnMetadata(const std::string& val) {
    this->encrypted_column_metadata = val;
    set.encrypted_column_metadata = true;
}
std::ostream& operator<<(std::ostream& out, const ColumnChunk& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t ColumnChunk::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_file_offset = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->file_path);
                    this->set.file_path = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->file_offset);
                    isset_file_offset = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->meta_data.read(iprot);
                    this->set.meta_data = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->offset_index_offset);
                    this->set.offset_index_offset = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->offset_index_length);
                    this->set.offset_index_length = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->column_index_offset);
                    this->set.column_index_offset = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 7:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->column_index_length);
                    this->set.column_index_length = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 8:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->crypto_metadata.read(iprot);
                    this->set.crypto_metadata = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 9:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->encrypted_column_metadata);
                    this->set.encrypted_column_metadata = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_file_offset)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t ColumnChunk::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("ColumnChunk");

    if (this->set.file_path) {
        xfer += oprot->writeFieldBegin("file_path", ::apache::thrift::protocol::T_STRING, 1);
        xfer += oprot->writeString(this->file_path);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldBegin("file_offset", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->file_offset);
    xfer += oprot->writeFieldEnd();

    if (this->set.meta_data) {
        xfer += oprot->writeFieldBegin("meta_data", ::apache::thrift::protocol::T_STRUCT, 3);
        xfer += this->meta_data.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.offset_index_offset) {
        xfer += oprot->writeFieldBegin("offset_index_offset", ::apache::thrift::protocol::T_I64, 4);
        xfer += oprot->writeI64(this->offset_index_offset);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.offset_index_length) {
        xfer += oprot->writeFieldBegin("offset_index_length", ::apache::thrift::protocol::T_I32, 5);
        xfer += oprot->writeI32(this->offset_index_length);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.column_index_offset) {
        xfer += oprot->writeFieldBegin("column_index_offset", ::apache::thrift::protocol::T_I64, 6);
        xfer += oprot->writeI64(this->column_index_offset);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.column_index_length) {
        xfer += oprot->writeFieldBegin("column_index_length", ::apache::thrift::protocol::T_I32, 7);
        xfer += oprot->writeI32(this->column_index_length);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.crypto_metadata) {
        xfer += oprot->writeFieldBegin("crypto_metadata", ::apache::thrift::protocol::T_STRUCT, 8);
        xfer += this->crypto_metadata.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.encrypted_column_metadata) {
        xfer += oprot->writeFieldBegin("encrypted_column_metadata", ::apache::thrift::protocol::T_STRING, 9);
        xfer += oprot->writeBinary(this->encrypted_column_metadata);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(ColumnChunk &a, ColumnChunk &b) {
    using ::std::swap;
    swap(a.file_path, b.file_path);
    swap(a.file_offset, b.file_offset);
    swap(a.meta_data, b.meta_data);
    swap(a.offset_index_offset, b.offset_index_offset);
    swap(a.offset_index_length, b.offset_index_length);
    swap(a.column_index_offset, b.column_index_offset);
    swap(a.column_index_length, b.column_index_length);
    swap(a.crypto_metadata, b.crypto_metadata);
    swap(a.encrypted_column_metadata, b.encrypted_column_metadata);
    swap(a.set, b.set);
}

ColumnChunk::ColumnChunk(const ColumnChunk& other108) {
    file_path = other108.file_path;
    file_offset = other108.file_offset;
    meta_data = other108.meta_data;
    offset_index_offset = other108.offset_index_offset;
    offset_index_length = other108.offset_index_length;
    column_index_offset = other108.column_index_offset;
    column_index_length = other108.column_index_length;
    crypto_metadata = other108.crypto_metadata;
    encrypted_column_metadata = other108.encrypted_column_metadata;
    set = other108.set;
}
ColumnChunk& ColumnChunk::operator=(const ColumnChunk& other109) {
    file_path = other109.file_path;
    file_offset = other109.file_offset;
    meta_data = other109.meta_data;
    offset_index_offset = other109.offset_index_offset;
    offset_index_length = other109.offset_index_length;
    column_index_offset = other109.column_index_offset;
    column_index_length = other109.column_index_length;
    crypto_metadata = other109.crypto_metadata;
    encrypted_column_metadata = other109.encrypted_column_metadata;
    set = other109.set;
    return *this;
}
void ColumnChunk::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "ColumnChunk(";
    out << "file_path="; (set.file_path ? (out << to_string(file_path)) : (out << "<null>"));
    out << ", " << "file_offset=" << to_string(file_offset);
    out << ", " << "meta_data="; (set.meta_data ? (out << to_string(meta_data)) : (out << "<null>"));
    out << ", " << "offset_index_offset="; (set.offset_index_offset ? (out << to_string(offset_index_offset)) : (out << "<null>"));
    out << ", " << "offset_index_length="; (set.offset_index_length ? (out << to_string(offset_index_length)) : (out << "<null>"));
    out << ", " << "column_index_offset="; (set.column_index_offset ? (out << to_string(column_index_offset)) : (out << "<null>"));
    out << ", " << "column_index_length="; (set.column_index_length ? (out << to_string(column_index_length)) : (out << "<null>"));
    out << ", " << "crypto_metadata="; (set.crypto_metadata ? (out << to_string(crypto_metadata)) : (out << "<null>"));
    out << ", " << "encrypted_column_metadata="; (set.encrypted_column_metadata ? (out << to_string(encrypted_column_metadata)) : (out << "<null>"));
    out << ")";
}


RowGroup::~RowGroup() noexcept {
}


void RowGroup::setColumns(const std::vector<ColumnChunk> & val) {
    this->columns = val;
}

void RowGroup::setTotalByteSize(const int64_t val) {
    this->total_byte_size = val;
}

void RowGroup::setNumRows(const int64_t val) {
    this->num_rows = val;
}

void RowGroup::setSortingColumns(const std::vector<SortingColumn> & val) {
    this->sorting_columns = val;
    set.sorting_columns = true;
}

void RowGroup::setFileOffset(const int64_t val) {
    this->file_offset = val;
    set.file_offset = true;
}

void RowGroup::setTotalCompressedSize(const int64_t val) {
    this->total_compressed_size = val;
    set.total_compressed_size = true;
}

void RowGroup::setOrdinal(const int16_t val) {
    this->ordinal = val;
    set.ordinal = true;
}
std::ostream& operator<<(std::ostream& out, const RowGroup& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t RowGroup::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_columns = false;
    bool isset_total_byte_size = false;
    bool isset_num_rows = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->columns.clear();
                        uint32_t _size110;
                        ::apache::thrift::protocol::TType _etype113;
                        xfer += iprot->readListBegin(_etype113, _size110);
                        this->columns.resize(_size110);
                        uint32_t _i114;
                        for (_i114 = 0; _i114 < _size110; ++_i114)
                        {
                            xfer += this->columns[_i114].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_columns = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->total_byte_size);
                    isset_total_byte_size = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->num_rows);
                    isset_num_rows = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->sorting_columns.clear();
                        uint32_t _size115;
                        ::apache::thrift::protocol::TType _etype118;
                        xfer += iprot->readListBegin(_etype118, _size115);
                        this->sorting_columns.resize(_size115);
                        uint32_t _i119;
                        for (_i119 = 0; _i119 < _size115; ++_i119)
                        {
                            xfer += this->sorting_columns[_i119].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    this->set.sorting_columns = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->file_offset);
                    this->set.file_offset = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->total_compressed_size);
                    this->set.total_compressed_size = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 7:
                if (ftype == ::apache::thrift::protocol::T_I16) {
                    xfer += iprot->readI16(this->ordinal);
                    this->set.ordinal = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_columns)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_total_byte_size)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_num_rows)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t RowGroup::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("RowGroup");

    xfer += oprot->writeFieldBegin("columns", ::apache::thrift::protocol::T_LIST, 1);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->columns.size()));
        std::vector<ColumnChunk> ::const_iterator _iter120;
        for (_iter120 = this->columns.begin(); _iter120 != this->columns.end(); ++_iter120)
        {
            xfer += (*_iter120).write(oprot);
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("total_byte_size", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->total_byte_size);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("num_rows", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->num_rows);
    xfer += oprot->writeFieldEnd();

    if (this->set.sorting_columns) {
        xfer += oprot->writeFieldBegin("sorting_columns", ::apache::thrift::protocol::T_LIST, 4);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->sorting_columns.size()));
            std::vector<SortingColumn> ::const_iterator _iter121;
            for (_iter121 = this->sorting_columns.begin(); _iter121 != this->sorting_columns.end(); ++_iter121)
            {
                xfer += (*_iter121).write(oprot);
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.file_offset) {
        xfer += oprot->writeFieldBegin("file_offset", ::apache::thrift::protocol::T_I64, 5);
        xfer += oprot->writeI64(this->file_offset);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.total_compressed_size) {
        xfer += oprot->writeFieldBegin("total_compressed_size", ::apache::thrift::protocol::T_I64, 6);
        xfer += oprot->writeI64(this->total_compressed_size);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.ordinal) {
        xfer += oprot->writeFieldBegin("ordinal", ::apache::thrift::protocol::T_I16, 7);
        xfer += oprot->writeI16(this->ordinal);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(RowGroup &a, RowGroup &b) {
    using ::std::swap;
    swap(a.columns, b.columns);
    swap(a.total_byte_size, b.total_byte_size);
    swap(a.num_rows, b.num_rows);
    swap(a.sorting_columns, b.sorting_columns);
    swap(a.file_offset, b.file_offset);
    swap(a.total_compressed_size, b.total_compressed_size);
    swap(a.ordinal, b.ordinal);
    swap(a.set, b.set);
}

RowGroup::RowGroup(const RowGroup& other122) {
    columns = other122.columns;
    total_byte_size = other122.total_byte_size;
    num_rows = other122.num_rows;
    sorting_columns = other122.sorting_columns;
    file_offset = other122.file_offset;
    total_compressed_size = other122.total_compressed_size;
    ordinal = other122.ordinal;
    set = other122.set;
}
RowGroup& RowGroup::operator=(const RowGroup& other123) {
    columns = other123.columns;
    total_byte_size = other123.total_byte_size;
    num_rows = other123.num_rows;
    sorting_columns = other123.sorting_columns;
    file_offset = other123.file_offset;
    total_compressed_size = other123.total_compressed_size;
    ordinal = other123.ordinal;
    set = other123.set;
    return *this;
}
void RowGroup::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "RowGroup(";
    out << "columns=" << to_string(columns);
    out << ", " << "total_byte_size=" << to_string(total_byte_size);
    out << ", " << "num_rows=" << to_string(num_rows);
    out << ", " << "sorting_columns="; (set.sorting_columns ? (out << to_string(sorting_columns)) : (out << "<null>"));
    out << ", " << "file_offset="; (set.file_offset ? (out << to_string(file_offset)) : (out << "<null>"));
    out << ", " << "total_compressed_size="; (set.total_compressed_size ? (out << to_string(total_compressed_size)) : (out << "<null>"));
    out << ", " << "ordinal="; (set.ordinal ? (out << to_string(ordinal)) : (out << "<null>"));
    out << ")";
}


TypeDefinedOrder::~TypeDefinedOrder() noexcept {
}

std::ostream& operator<<(std::ostream& out, const TypeDefinedOrder& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t TypeDefinedOrder::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t TypeDefinedOrder::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("TypeDefinedOrder");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(TypeDefinedOrder &a, TypeDefinedOrder &b) {
    using ::std::swap;
    (void) a;
    (void) b;
}

TypeDefinedOrder::TypeDefinedOrder(const TypeDefinedOrder& other124) {
    (void) other124;
}
TypeDefinedOrder& TypeDefinedOrder::operator=(const TypeDefinedOrder& other125) {
    (void) other125;
    return *this;
}
void TypeDefinedOrder::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "TypeDefinedOrder(";
    out << ")";
}


ColumnOrder::~ColumnOrder() noexcept {
}


void ColumnOrder::setTypeOrder(const TypeDefinedOrder& val) {
    this->TYPE_ORDER = val;
    set.TYPE_ORDER = true;
}
std::ostream& operator<<(std::ostream& out, const ColumnOrder& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t ColumnOrder::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->TYPE_ORDER.read(iprot);
                    this->set.TYPE_ORDER = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t ColumnOrder::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("ColumnOrder");

    if (this->set.TYPE_ORDER) {
        xfer += oprot->writeFieldBegin("TYPE_ORDER", ::apache::thrift::protocol::T_STRUCT, 1);
        xfer += this->TYPE_ORDER.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(ColumnOrder &a, ColumnOrder &b) {
    using ::std::swap;
    swap(a.TYPE_ORDER, b.TYPE_ORDER);
    swap(a.set, b.set);
}

ColumnOrder::ColumnOrder(const ColumnOrder& other126) {
    TYPE_ORDER = other126.TYPE_ORDER;
    set = other126.set;
}
ColumnOrder& ColumnOrder::operator=(const ColumnOrder& other127) {
    TYPE_ORDER = other127.TYPE_ORDER;
    set = other127.set;
    return *this;
}
void ColumnOrder::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "ColumnOrder(";
    out << "TYPE_ORDER="; (set.TYPE_ORDER ? (out << to_string(TYPE_ORDER)) : (out << "<null>"));
    out << ")";
}


PageLocation::~PageLocation() noexcept {
}


void PageLocation::setOffset(const int64_t val) {
    this->offset = val;
}

void PageLocation::setCompressedPageSize(const int32_t val) {
    this->compressed_page_size = val;
}

void PageLocation::setFirstRowIndex(const int64_t val) {
    this->first_row_index = val;
}
std::ostream& operator<<(std::ostream& out, const PageLocation& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t PageLocation::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_offset = false;
    bool isset_compressed_page_size = false;
    bool isset_first_row_index = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->offset);
                    isset_offset = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->compressed_page_size);
                    isset_compressed_page_size = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->first_row_index);
                    isset_first_row_index = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_offset)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_compressed_page_size)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_first_row_index)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t PageLocation::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("PageLocation");

    xfer += oprot->writeFieldBegin("offset", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->offset);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("compressed_page_size", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->compressed_page_size);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("first_row_index", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->first_row_index);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(PageLocation &a, PageLocation &b) {
    using ::std::swap;
    swap(a.offset, b.offset);
    swap(a.compressed_page_size, b.compressed_page_size);
    swap(a.first_row_index, b.first_row_index);
}

PageLocation::PageLocation(const PageLocation& other128) {
    offset = other128.offset;
    compressed_page_size = other128.compressed_page_size;
    first_row_index = other128.first_row_index;
}
PageLocation& PageLocation::operator=(const PageLocation& other129) {
    offset = other129.offset;
    compressed_page_size = other129.compressed_page_size;
    first_row_index = other129.first_row_index;
    return *this;
}
void PageLocation::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "PageLocation(";
    out << "offset=" << to_string(offset);
    out << ", " << "compressed_page_size=" << to_string(compressed_page_size);
    out << ", " << "first_row_index=" << to_string(first_row_index);
    out << ")";
}


OffsetIndex::~OffsetIndex() noexcept {
}


void OffsetIndex::setPageLocations(const std::vector<PageLocation> & val) {
    this->page_locations = val;
}
std::ostream& operator<<(std::ostream& out, const OffsetIndex& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t OffsetIndex::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_page_locations = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->page_locations.clear();
                        uint32_t _size130;
                        ::apache::thrift::protocol::TType _etype133;
                        xfer += iprot->readListBegin(_etype133, _size130);
                        this->page_locations.resize(_size130);
                        uint32_t _i134;
                        for (_i134 = 0; _i134 < _size130; ++_i134)
                        {
                            xfer += this->page_locations[_i134].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_page_locations = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_page_locations)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t OffsetIndex::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("OffsetIndex");

    xfer += oprot->writeFieldBegin("page_locations", ::apache::thrift::protocol::T_LIST, 1);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->page_locations.size()));
        std::vector<PageLocation> ::const_iterator _iter135;
        for (_iter135 = this->page_locations.begin(); _iter135 != this->page_locations.end(); ++_iter135)
        {
            xfer += (*_iter135).write(oprot);
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(OffsetIndex &a, OffsetIndex &b) {
    using ::std::swap;
    swap(a.page_locations, b.page_locations);
}

OffsetIndex::OffsetIndex(const OffsetIndex& other136) {
    page_locations = other136.page_locations;
}
OffsetIndex& OffsetIndex::operator=(const OffsetIndex& other137) {
    page_locations = other137.page_locations;
    return *this;
}
void OffsetIndex::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "OffsetIndex(";
    out << "page_locations=" << to_string(page_locations);
    out << ")";
}


ColumnIndex::~ColumnIndex() noexcept {
}


void ColumnIndex::setNullPages(const std::vector<bool> & val) {
    this->null_pages = val;
}

void ColumnIndex::setMinValues(const std::vector<std::string> & val) {
    this->min_values = val;
}

void ColumnIndex::setMaxValues(const std::vector<std::string> & val) {
    this->max_values = val;
}

void ColumnIndex::setBoundaryOrder(const BoundaryOrder::type val) {
    this->boundary_order = val;
}

void ColumnIndex::setNullCounts(const std::vector<int64_t> & val) {
    this->null_counts = val;
    set.null_counts = true;
}
std::ostream& operator<<(std::ostream& out, const ColumnIndex& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t ColumnIndex::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_null_pages = false;
    bool isset_min_values = false;
    bool isset_max_values = false;
    bool isset_boundary_order = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->null_pages.clear();
                        uint32_t _size138;
                        ::apache::thrift::protocol::TType _etype141;
                        xfer += iprot->readListBegin(_etype141, _size138);
                        this->null_pages.resize(_size138);
                        uint32_t _i142;
                        for (_i142 = 0; _i142 < _size138; ++_i142)
                        {
                            xfer += iprot->readBool(this->null_pages[_i142]);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_null_pages = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->min_values.clear();
                        uint32_t _size143;
                        ::apache::thrift::protocol::TType _etype146;
                        xfer += iprot->readListBegin(_etype146, _size143);
                        this->min_values.resize(_size143);
                        uint32_t _i147;
                        for (_i147 = 0; _i147 < _size143; ++_i147)
                        {
                            xfer += iprot->readBinary(this->min_values[_i147]);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_min_values = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->max_values.clear();
                        uint32_t _size148;
                        ::apache::thrift::protocol::TType _etype151;
                        xfer += iprot->readListBegin(_etype151, _size148);
                        this->max_values.resize(_size148);
                        uint32_t _i152;
                        for (_i152 = 0; _i152 < _size148; ++_i152)
                        {
                            xfer += iprot->readBinary(this->max_values[_i152]);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_max_values = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    int32_t ecast153;
                    xfer += iprot->readI32(ecast153);
                    this->boundary_order = BoundaryOrder::type(ecast153);
                    isset_boundary_order = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->null_counts.clear();
                        uint32_t _size154;
                        ::apache::thrift::protocol::TType _etype157;
                        xfer += iprot->readListBegin(_etype157, _size154);
                        this->null_counts.resize(_size154);
                        uint32_t _i158;
                        for (_i158 = 0; _i158 < _size154; ++_i158)
                        {
                            xfer += iprot->readI64(this->null_counts[_i158]);
                        }
                        xfer += iprot->readListEnd();
                    }
                    this->set.null_counts = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_null_pages)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_min_values)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_max_values)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_boundary_order)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t ColumnIndex::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("ColumnIndex");

    xfer += oprot->writeFieldBegin("null_pages", ::apache::thrift::protocol::T_LIST, 1);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_BOOL, static_cast<uint32_t>(this->null_pages.size()));
        std::vector<bool> ::const_iterator _iter159;
        for (_iter159 = this->null_pages.begin(); _iter159 != this->null_pages.end(); ++_iter159)
        {
            xfer += oprot->writeBool((*_iter159));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("min_values", ::apache::thrift::protocol::T_LIST, 2);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->min_values.size()));
        std::vector<std::string> ::const_iterator _iter160;
        for (_iter160 = this->min_values.begin(); _iter160 != this->min_values.end(); ++_iter160)
        {
            xfer += oprot->writeBinary((*_iter160));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("max_values", ::apache::thrift::protocol::T_LIST, 3);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->max_values.size()));
        std::vector<std::string> ::const_iterator _iter161;
        for (_iter161 = this->max_values.begin(); _iter161 != this->max_values.end(); ++_iter161)
        {
            xfer += oprot->writeBinary((*_iter161));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("boundary_order", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->boundary_order);
    xfer += oprot->writeFieldEnd();

    if (this->set.null_counts) {
        xfer += oprot->writeFieldBegin("null_counts", ::apache::thrift::protocol::T_LIST, 5);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->null_counts.size()));
            std::vector<int64_t> ::const_iterator _iter162;
            for (_iter162 = this->null_counts.begin(); _iter162 != this->null_counts.end(); ++_iter162)
            {
                xfer += oprot->writeI64((*_iter162));
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(ColumnIndex &a, ColumnIndex &b) {
    using ::std::swap;
    swap(a.null_pages, b.null_pages);
    swap(a.min_values, b.min_values);
    swap(a.max_values, b.max_values);
    swap(a.boundary_order, b.boundary_order);
    swap(a.null_counts, b.null_counts);
    swap(a.set, b.set);
}

ColumnIndex::ColumnIndex(const ColumnIndex& other163) {
    null_pages = other163.null_pages;
    min_values = other163.min_values;
    max_values = other163.max_values;
    boundary_order = other163.boundary_order;
    null_counts = other163.null_counts;
    set = other163.set;
}
ColumnIndex& ColumnIndex::operator=(const ColumnIndex& other164) {
    null_pages = other164.null_pages;
    min_values = other164.min_values;
    max_values = other164.max_values;
    boundary_order = other164.boundary_order;
    null_counts = other164.null_counts;
    set = other164.set;
    return *this;
}
void ColumnIndex::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "ColumnIndex(";
    out << "null_pages=" << to_string(null_pages);
    out << ", " << "min_values=" << to_string(min_values);
    out << ", " << "max_values=" << to_string(max_values);
    out << ", " << "boundary_order=" << to_string(boundary_order);
    out << ", " << "null_counts="; (set.null_counts ? (out << to_string(null_counts)) : (out << "<null>"));
    out << ")";
}


AesGcmV1::~AesGcmV1() noexcept {
}


void AesGcmV1::setAadPrefix(const std::string& val) {
    this->aad_prefix = val;
    set.aad_prefix = true;
}

void AesGcmV1::setAadFileUnique(const std::string& val) {
    this->aad_file_unique = val;
    set.aad_file_unique = true;
}

void AesGcmV1::setSupplyAadPrefix(const bool val) {
    this->supply_aad_prefix = val;
    set.supply_aad_prefix = true;
}
std::ostream& operator<<(std::ostream& out, const AesGcmV1& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t AesGcmV1::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->aad_prefix);
                    this->set.aad_prefix = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->aad_file_unique);
                    this->set.aad_file_unique = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->supply_aad_prefix);
                    this->set.supply_aad_prefix = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t AesGcmV1::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("AesGcmV1");

    if (this->set.aad_prefix) {
        xfer += oprot->writeFieldBegin("aad_prefix", ::apache::thrift::protocol::T_STRING, 1);
        xfer += oprot->writeBinary(this->aad_prefix);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.aad_file_unique) {
        xfer += oprot->writeFieldBegin("aad_file_unique", ::apache::thrift::protocol::T_STRING, 2);
        xfer += oprot->writeBinary(this->aad_file_unique);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.supply_aad_prefix) {
        xfer += oprot->writeFieldBegin("supply_aad_prefix", ::apache::thrift::protocol::T_BOOL, 3);
        xfer += oprot->writeBool(this->supply_aad_prefix);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(AesGcmV1 &a, AesGcmV1 &b) {
    using ::std::swap;
    swap(a.aad_prefix, b.aad_prefix);
    swap(a.aad_file_unique, b.aad_file_unique);
    swap(a.supply_aad_prefix, b.supply_aad_prefix);
    swap(a.set, b.set);
}

AesGcmV1::AesGcmV1(const AesGcmV1& other165) {
    aad_prefix = other165.aad_prefix;
    aad_file_unique = other165.aad_file_unique;
    supply_aad_prefix = other165.supply_aad_prefix;
    set = other165.set;
}
AesGcmV1& AesGcmV1::operator=(const AesGcmV1& other166) {
    aad_prefix = other166.aad_prefix;
    aad_file_unique = other166.aad_file_unique;
    supply_aad_prefix = other166.supply_aad_prefix;
    set = other166.set;
    return *this;
}
void AesGcmV1::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "AesGcmV1(";
    out << "aad_prefix="; (set.aad_prefix ? (out << to_string(aad_prefix)) : (out << "<null>"));
    out << ", " << "aad_file_unique="; (set.aad_file_unique ? (out << to_string(aad_file_unique)) : (out << "<null>"));
    out << ", " << "supply_aad_prefix="; (set.supply_aad_prefix ? (out << to_string(supply_aad_prefix)) : (out << "<null>"));
    out << ")";
}


AesGcmCtrV1::~AesGcmCtrV1() noexcept {
}


void AesGcmCtrV1::setAadPrefix(const std::string& val) {
    this->aad_prefix = val;
    set.aad_prefix = true;
}

void AesGcmCtrV1::setAadFileUnique(const std::string& val) {
    this->aad_file_unique = val;
    set.aad_file_unique = true;
}

void AesGcmCtrV1::setSupplyAadPrefix(const bool val) {
    this->supply_aad_prefix = val;
    set.supply_aad_prefix = true;
}
std::ostream& operator<<(std::ostream& out, const AesGcmCtrV1& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t AesGcmCtrV1::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->aad_prefix);
                    this->set.aad_prefix = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->aad_file_unique);
                    this->set.aad_file_unique = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_BOOL) {
                    xfer += iprot->readBool(this->supply_aad_prefix);
                    this->set.supply_aad_prefix = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t AesGcmCtrV1::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("AesGcmCtrV1");

    if (this->set.aad_prefix) {
        xfer += oprot->writeFieldBegin("aad_prefix", ::apache::thrift::protocol::T_STRING, 1);
        xfer += oprot->writeBinary(this->aad_prefix);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.aad_file_unique) {
        xfer += oprot->writeFieldBegin("aad_file_unique", ::apache::thrift::protocol::T_STRING, 2);
        xfer += oprot->writeBinary(this->aad_file_unique);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.supply_aad_prefix) {
        xfer += oprot->writeFieldBegin("supply_aad_prefix", ::apache::thrift::protocol::T_BOOL, 3);
        xfer += oprot->writeBool(this->supply_aad_prefix);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(AesGcmCtrV1 &a, AesGcmCtrV1 &b) {
    using ::std::swap;
    swap(a.aad_prefix, b.aad_prefix);
    swap(a.aad_file_unique, b.aad_file_unique);
    swap(a.supply_aad_prefix, b.supply_aad_prefix);
    swap(a.set, b.set);
}

AesGcmCtrV1::AesGcmCtrV1(const AesGcmCtrV1& other167) {
    aad_prefix = other167.aad_prefix;
    aad_file_unique = other167.aad_file_unique;
    supply_aad_prefix = other167.supply_aad_prefix;
    set = other167.set;
}
AesGcmCtrV1& AesGcmCtrV1::operator=(const AesGcmCtrV1& other168) {
    aad_prefix = other168.aad_prefix;
    aad_file_unique = other168.aad_file_unique;
    supply_aad_prefix = other168.supply_aad_prefix;
    set = other168.set;
    return *this;
}
void AesGcmCtrV1::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "AesGcmCtrV1(";
    out << "aad_prefix="; (set.aad_prefix ? (out << to_string(aad_prefix)) : (out << "<null>"));
    out << ", " << "aad_file_unique="; (set.aad_file_unique ? (out << to_string(aad_file_unique)) : (out << "<null>"));
    out << ", " << "supply_aad_prefix="; (set.supply_aad_prefix ? (out << to_string(supply_aad_prefix)) : (out << "<null>"));
    out << ")";
}


EncryptionAlgorithm::~EncryptionAlgorithm() noexcept {
}


void EncryptionAlgorithm::setAesGcmV1(const AesGcmV1& val) {
    this->AES_GCM_V1 = val;
    set.AES_GCM_V1 = true;
}

void EncryptionAlgorithm::setAesGcmCtrV1(const AesGcmCtrV1& val) {
    this->AES_GCM_CTR_V1 = val;
    set.AES_GCM_CTR_V1 = true;
}
std::ostream& operator<<(std::ostream& out, const EncryptionAlgorithm& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t EncryptionAlgorithm::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->AES_GCM_V1.read(iprot);
                    this->set.AES_GCM_V1 = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->AES_GCM_CTR_V1.read(iprot);
                    this->set.AES_GCM_CTR_V1 = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t EncryptionAlgorithm::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("EncryptionAlgorithm");

    if (this->set.AES_GCM_V1) {
        xfer += oprot->writeFieldBegin("AES_GCM_V1", ::apache::thrift::protocol::T_STRUCT, 1);
        xfer += this->AES_GCM_V1.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.AES_GCM_CTR_V1) {
        xfer += oprot->writeFieldBegin("AES_GCM_CTR_V1", ::apache::thrift::protocol::T_STRUCT, 2);
        xfer += this->AES_GCM_CTR_V1.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(EncryptionAlgorithm &a, EncryptionAlgorithm &b) {
    using ::std::swap;
    swap(a.AES_GCM_V1, b.AES_GCM_V1);
    swap(a.AES_GCM_CTR_V1, b.AES_GCM_CTR_V1);
    swap(a.set, b.set);
}

EncryptionAlgorithm::EncryptionAlgorithm(const EncryptionAlgorithm& other169) {
    AES_GCM_V1 = other169.AES_GCM_V1;
    AES_GCM_CTR_V1 = other169.AES_GCM_CTR_V1;
    set = other169.set;
}
EncryptionAlgorithm& EncryptionAlgorithm::operator=(const EncryptionAlgorithm& other170) {
    AES_GCM_V1 = other170.AES_GCM_V1;
    AES_GCM_CTR_V1 = other170.AES_GCM_CTR_V1;
    set = other170.set;
    return *this;
}
void EncryptionAlgorithm::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "EncryptionAlgorithm(";
    out << "AES_GCM_V1="; (set.AES_GCM_V1 ? (out << to_string(AES_GCM_V1)) : (out << "<null>"));
    out << ", " << "AES_GCM_CTR_V1="; (set.AES_GCM_CTR_V1 ? (out << to_string(AES_GCM_CTR_V1)) : (out << "<null>"));
    out << ")";
}


FileMetaData::~FileMetaData() noexcept {
}


void FileMetaData::setVersion(const int32_t val) {
    this->version = val;
}

void FileMetaData::setSchema(const std::vector<SchemaElement> & val) {
    this->schema = val;
}

void FileMetaData::setNumRows(const int64_t val) {
    this->num_rows = val;
}

void FileMetaData::setRowGroups(const std::vector<RowGroup> & val) {
    this->row_groups = val;
}

void FileMetaData::setKeyValueMetadata(const std::vector<KeyValue> & val) {
    this->key_value_metadata = val;
    set.key_value_metadata = true;
}

void FileMetaData::setCreatedBy(const std::string& val) {
    this->created_by = val;
    set.created_by = true;
}

void FileMetaData::setColumnOrders(const std::vector<ColumnOrder> & val) {
    this->column_orders = val;
    set.column_orders = true;
}

void FileMetaData::setEncryptionAlgorithm(const EncryptionAlgorithm& val) {
    this->encryption_algorithm = val;
    set.encryption_algorithm = true;
}

void FileMetaData::setFooterSigningKeyMetadata(const std::string& val) {
    this->footer_signing_key_metadata = val;
    set.footer_signing_key_metadata = true;
}
std::ostream& operator<<(std::ostream& out, const FileMetaData& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t FileMetaData::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_version = false;
    bool isset_schema = false;
    bool isset_num_rows = false;
    bool isset_row_groups = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_I32) {
                    xfer += iprot->readI32(this->version);
                    isset_version = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->schema.clear();
                        uint32_t _size171;
                        ::apache::thrift::protocol::TType _etype174;
                        xfer += iprot->readListBegin(_etype174, _size171);
                        this->schema.resize(_size171);
                        uint32_t _i175;
                        for (_i175 = 0; _i175 < _size171; ++_i175)
                        {
                            xfer += this->schema[_i175].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_schema = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 3:
                if (ftype == ::apache::thrift::protocol::T_I64) {
                    xfer += iprot->readI64(this->num_rows);
                    isset_num_rows = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 4:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->row_groups.clear();
                        uint32_t _size176;
                        ::apache::thrift::protocol::TType _etype179;
                        xfer += iprot->readListBegin(_etype179, _size176);
                        this->row_groups.resize(_size176);
                        uint32_t _i180;
                        for (_i180 = 0; _i180 < _size176; ++_i180)
                        {
                            xfer += this->row_groups[_i180].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    isset_row_groups = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 5:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->key_value_metadata.clear();
                        uint32_t _size181;
                        ::apache::thrift::protocol::TType _etype184;
                        xfer += iprot->readListBegin(_etype184, _size181);
                        this->key_value_metadata.resize(_size181);
                        uint32_t _i185;
                        for (_i185 = 0; _i185 < _size181; ++_i185)
                        {
                            xfer += this->key_value_metadata[_i185].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    this->set.key_value_metadata = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 6:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readString(this->created_by);
                    this->set.created_by = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 7:
                if (ftype == ::apache::thrift::protocol::T_LIST) {
                    {
                        this->column_orders.clear();
                        uint32_t _size186;
                        ::apache::thrift::protocol::TType _etype189;
                        xfer += iprot->readListBegin(_etype189, _size186);
                        this->column_orders.resize(_size186);
                        uint32_t _i190;
                        for (_i190 = 0; _i190 < _size186; ++_i190)
                        {
                            xfer += this->column_orders[_i190].read(iprot);
                        }
                        xfer += iprot->readListEnd();
                    }
                    this->set.column_orders = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 8:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->encryption_algorithm.read(iprot);
                    this->set.encryption_algorithm = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 9:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->footer_signing_key_metadata);
                    this->set.footer_signing_key_metadata = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_version)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_schema)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_num_rows)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_row_groups)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t FileMetaData::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("FileMetaData");

    xfer += oprot->writeFieldBegin("version", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->version);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("schema", ::apache::thrift::protocol::T_LIST, 2);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->schema.size()));
        std::vector<SchemaElement> ::const_iterator _iter191;
        for (_iter191 = this->schema.begin(); _iter191 != this->schema.end(); ++_iter191)
        {
            xfer += (*_iter191).write(oprot);
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("num_rows", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->num_rows);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("row_groups", ::apache::thrift::protocol::T_LIST, 4);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->row_groups.size()));
        std::vector<RowGroup> ::const_iterator _iter192;
        for (_iter192 = this->row_groups.begin(); _iter192 != this->row_groups.end(); ++_iter192)
        {
            xfer += (*_iter192).write(oprot);
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    if (this->set.key_value_metadata) {
        xfer += oprot->writeFieldBegin("key_value_metadata", ::apache::thrift::protocol::T_LIST, 5);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->key_value_metadata.size()));
            std::vector<KeyValue> ::const_iterator _iter193;
            for (_iter193 = this->key_value_metadata.begin(); _iter193 != this->key_value_metadata.end(); ++_iter193)
            {
                xfer += (*_iter193).write(oprot);
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.created_by) {
        xfer += oprot->writeFieldBegin("created_by", ::apache::thrift::protocol::T_STRING, 6);
        xfer += oprot->writeString(this->created_by);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.column_orders) {
        xfer += oprot->writeFieldBegin("column_orders", ::apache::thrift::protocol::T_LIST, 7);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->column_orders.size()));
            std::vector<ColumnOrder> ::const_iterator _iter194;
            for (_iter194 = this->column_orders.begin(); _iter194 != this->column_orders.end(); ++_iter194)
            {
                xfer += (*_iter194).write(oprot);
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.encryption_algorithm) {
        xfer += oprot->writeFieldBegin("encryption_algorithm", ::apache::thrift::protocol::T_STRUCT, 8);
        xfer += this->encryption_algorithm.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    if (this->set.footer_signing_key_metadata) {
        xfer += oprot->writeFieldBegin("footer_signing_key_metadata", ::apache::thrift::protocol::T_STRING, 9);
        xfer += oprot->writeBinary(this->footer_signing_key_metadata);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(FileMetaData &a, FileMetaData &b) {
    using ::std::swap;
    swap(a.version, b.version);
    swap(a.schema, b.schema);
    swap(a.num_rows, b.num_rows);
    swap(a.row_groups, b.row_groups);
    swap(a.key_value_metadata, b.key_value_metadata);
    swap(a.created_by, b.created_by);
    swap(a.column_orders, b.column_orders);
    swap(a.encryption_algorithm, b.encryption_algorithm);
    swap(a.footer_signing_key_metadata, b.footer_signing_key_metadata);
    swap(a.set, b.set);
}

FileMetaData::FileMetaData(const FileMetaData& other195) {
    version = other195.version;
    schema = other195.schema;
    num_rows = other195.num_rows;
    row_groups = other195.row_groups;
    key_value_metadata = other195.key_value_metadata;
    created_by = other195.created_by;
    column_orders = other195.column_orders;
    encryption_algorithm = other195.encryption_algorithm;
    footer_signing_key_metadata = other195.footer_signing_key_metadata;
    set = other195.set;
}
FileMetaData& FileMetaData::operator=(const FileMetaData& other196) {
    version = other196.version;
    schema = other196.schema;
    num_rows = other196.num_rows;
    row_groups = other196.row_groups;
    key_value_metadata = other196.key_value_metadata;
    created_by = other196.created_by;
    column_orders = other196.column_orders;
    encryption_algorithm = other196.encryption_algorithm;
    footer_signing_key_metadata = other196.footer_signing_key_metadata;
    set = other196.set;
    return *this;
}

void FileMetaData::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "FileMetaData(";
    out << "version=" << to_string(version);
    out << ", " << "schema=" << to_string(schema);
    out << ", " << "num_rows=" << to_string(num_rows);
    out << ", " << "row_groups=" << to_string(row_groups);
    out << ", " << "key_value_metadata="; (set.key_value_metadata ? (out << to_string(key_value_metadata)) : (out << "<null>"));
    out << ", " << "created_by="; (set.created_by ? (out << to_string(created_by)) : (out << "<null>"));
    out << ", " << "column_orders="; (set.column_orders ? (out << to_string(column_orders)) : (out << "<null>"));
    out << ", " << "encryption_algorithm="; (set.encryption_algorithm ? (out << to_string(encryption_algorithm)) : (out << "<null>"));
    out << ", " << "footer_signing_key_metadata="; (set.footer_signing_key_metadata ? (out << to_string(footer_signing_key_metadata)) : (out << "<null>"));
    out << ")";
}


FileCryptoMetaData::~FileCryptoMetaData() noexcept {
}


void FileCryptoMetaData::setEncryptionAlgorithm(const EncryptionAlgorithm& val) {
    this->encryption_algorithm = val;
}

void FileCryptoMetaData::setKeyMetadata(const std::string& val) {
    this->key_metadata = val;
    set.key_metadata = true;
}
std::ostream& operator<<(std::ostream& out, const FileCryptoMetaData& obj)
{
    obj.printTo(out);
    return out;
}


uint32_t FileCryptoMetaData::read(::apache::thrift::protocol::TProtocol* iprot) {

    ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_encryption_algorithm = false;

    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                    xfer += this->encryption_algorithm.read(iprot);
                    isset_encryption_algorithm = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::apache::thrift::protocol::T_STRING) {
                    xfer += iprot->readBinary(this->key_metadata);
                    this->set.key_metadata = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_encryption_algorithm)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t FileCryptoMetaData::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
    xfer += oprot->writeStructBegin("FileCryptoMetaData");

    xfer += oprot->writeFieldBegin("encryption_algorithm", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->encryption_algorithm.write(oprot);
    xfer += oprot->writeFieldEnd();

    if (this->set.key_metadata) {
        xfer += oprot->writeFieldBegin("key_metadata", ::apache::thrift::protocol::T_STRING, 2);
        xfer += oprot->writeBinary(this->key_metadata);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}

void swap(FileCryptoMetaData &a, FileCryptoMetaData &b) {
    using ::std::swap;
    swap(a.encryption_algorithm, b.encryption_algorithm);
    swap(a.key_metadata, b.key_metadata);
    swap(a.set, b.set);
}

FileCryptoMetaData::FileCryptoMetaData(const FileCryptoMetaData& other197) {
    encryption_algorithm = other197.encryption_algorithm;
    key_metadata = other197.key_metadata;
    set = other197.set;
}
FileCryptoMetaData& FileCryptoMetaData::operator=(const FileCryptoMetaData& other198) {
    encryption_algorithm = other198.encryption_algorithm;
    key_metadata = other198.key_metadata;
    set = other198.set;
    return *this;
}
void FileCryptoMetaData::printTo(std::ostream& out) const {
    using ::apache::thrift::to_string;
    out << "FileCryptoMetaData(";
    out << "encryption_algorithm=" << to_string(encryption_algorithm);
    out << ", " << "key_metadata="; (set.key_metadata ? (out << to_string(key_metadata)) : (out << "<null>"));
    out << ")";
}

}
