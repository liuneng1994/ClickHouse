#pragma once
#include <thrift/TBase.h>

namespace DB
{

struct Type {
    enum type {
        BOOLEAN = 0,
        INT32 = 1,
        INT64 = 2,
        INT96 = 3,
        FLOAT = 4,
        DOUBLE = 5,
        BYTE_ARRAY = 6,
        FIXED_LEN_BYTE_ARRAY = 7
    };
};

std::ostream& operator<<(std::ostream& out, const Type::type& val);

struct ConvertedType {
    enum type {
        UTF8 = 0,
        MAP = 1,
        MAP_KEY_VALUE = 2,
        LIST = 3,
        ENUM = 4,
        DECIMAL = 5,
        DATE = 6,
        TIME_MILLIS = 7,
        TIME_MICROS = 8,
        TIMESTAMP_MILLIS = 9,
        TIMESTAMP_MICROS = 10,
        UINT_8 = 11,
        UINT_16 = 12,
        UINT_32 = 13,
        UINT_64 = 14,
        INT_8 = 15,
        INT_16 = 16,
        INT_32 = 17,
        INT_64 = 18,
        JSON = 19,
        BSON = 20,
        INTERVAL = 21
    };
};

std::ostream& operator<<(std::ostream& out, const ConvertedType::type& val);

struct FieldRepetitionType {
    enum type {
        REQUIRED = 0,
        OPTIONAL = 1,
        REPEATED = 2
    };
};

extern const std::map<int, const char*> fieldRepetitionTypeValuesToNames;

std::ostream& operator<<(std::ostream& out, const FieldRepetitionType::type& val);

struct Encoding {
    enum type {
        PLAIN = 0,
        PLAIN_DICTIONARY = 2,
        RLE = 3,
        BIT_PACKED = 4,
        DELTA_BINARY_PACKED = 5,
        DELTA_LENGTH_BYTE_ARRAY = 6,
        DELTA_BYTE_ARRAY = 7,
        RLE_DICTIONARY = 8
    };
};

extern const std::map<int, const char*> encodingValuesToNames;

std::ostream& operator<<(std::ostream& out, const Encoding::type& val);

struct CompressionCodec {
    enum type {
        UNCOMPRESSED = 0,
        SNAPPY = 1,
        GZIP = 2,
        LZO = 3,
        BROTLI = 4,
        LZ4 = 5,
        ZSTD = 6
    };
};

extern const std::map<int, const char*> compressionCodecValuesToNames;

std::ostream& operator<<(std::ostream& out, const CompressionCodec::type& val);

struct PageType {
    enum type {
        DATA_PAGE = 0,
        INDEX_PAGE = 1,
        DICTIONARY_PAGE = 2,
        DATA_PAGE_V2 = 3
    };
};

extern const std::map<int, const char*> pageTypeValuesToNames;

std::ostream& operator<<(std::ostream& out, const PageType::type& val);

struct BoundaryOrder {
    enum type {
        UNORDERED = 0,
        ASCENDING = 1,
        DESCENDING = 2
    };
};

extern const std::map<int, const char*> boundaryOrderValuesToNames;

std::ostream& operator<<(std::ostream& out, const BoundaryOrder::type& val);

class Statistics;

class StringType;

class UUIDType;

class MapType;

class ListType;

class EnumType;

class DateType;

class NullType;

class DecimalType;

class MilliSeconds;

class MicroSeconds;

class NanoSeconds;

class TimeUnit;

class TimestampType;

class TimeType;

class IntType;

class JsonType;

class BsonType;

class LogicalType;

class SchemaElement;

class DataPageHeader;

class IndexPageHeader;

class DictionaryPageHeader;

class DataPageHeaderV2;

class PageHeader;

class KeyValue;

class SortingColumn;

class PageEncodingStats;

class ColumnMetaData;

class EncryptionWithFooterKey;

class EncryptionWithColumnKey;

class ColumnCryptoMetaData;

class ColumnChunk;

class RowGroup;

class TypeDefinedOrder;

class ColumnOrder;

class PageLocation;

class OffsetIndex;

class ColumnIndex;

class AesGcmV1;

class AesGcmCtrV1;

class EncryptionAlgorithm;

class FileMetaData;

class FileCryptoMetaData;

using statisticsSet = struct StatisticsSet
{
    StatisticsSet() : max(false), min(false), null_count(false), distinct_count(false), max_value(false), min_value(false) {}
    bool max :1;
    bool min :1;
    bool null_count :1;
    bool distinct_count :1;
    bool max_value :1;
    bool min_value :1;
};

class Statistics : public virtual ::apache::thrift::TBase {
public:

    Statistics(const Statistics&);
    Statistics& operator=(const Statistics&);
    Statistics() : max(), min(), null_count(0), distinct_count(0), max_value(), min_value() {
    }

    ~Statistics() noexcept override;
    std::string max;
    std::string min;
    int64_t null_count;
    int64_t distinct_count;
    std::string max_value;
    std::string min_value;

    StatisticsSet set;

    void setMax(const std::string& val);

    void setMin(const std::string& val);

    void setNullCount(int64_t val);

    void setDistinctCount(int64_t val);

    void setMaxValue(const std::string& val);

    void setMinValue(const std::string& val);

    bool operator == (const Statistics & rhs) const
    {
        if (set.max != rhs.set.max)
            return false;
        else if (set.max && !(max == rhs.max))
            return false;
        if (set.min != rhs.set.min)
            return false;
        else if (set.min && !(min == rhs.min))
            return false;
        if (set.null_count != rhs.set.null_count)
            return false;
        else if (set.null_count && null_count != rhs.null_count)
            return false;
        if (set.distinct_count != rhs.set.distinct_count)
            return false;
        else if (set.distinct_count && distinct_count != rhs.distinct_count)
            return false;
        if (set.max_value != rhs.set.max_value)
            return false;
        else if (set.max_value && !(max_value == rhs.max_value))
            return false;
        if (set.min_value != rhs.set.min_value)
            return false;
        else if (set.min_value && !(min_value == rhs.min_value))
            return false;
        return true;
    }
    bool operator != (const Statistics &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const Statistics & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(Statistics &a, Statistics &b);

std::ostream& operator<<(std::ostream& out, const Statistics& obj);


class StringType : public virtual ::apache::thrift::TBase {
public:

    StringType(const StringType&);
    StringType& operator=(const StringType&);
    StringType() = default;

    ~StringType() noexcept override;

    bool operator == (const StringType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const StringType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const StringType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(StringType &a, StringType &b);

std::ostream& operator<<(std::ostream& out, const StringType& obj);


class UUIDType : public virtual ::apache::thrift::TBase {
public:

    UUIDType(const UUIDType&);
    UUIDType& operator=(const UUIDType&);
    UUIDType() = default;

    ~UUIDType() noexcept override;

    bool operator == (const UUIDType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const UUIDType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const UUIDType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(UUIDType &a, UUIDType &b);

std::ostream& operator<<(std::ostream& out, const UUIDType& obj);


class MapType : public virtual ::apache::thrift::TBase {
public:

    MapType(const MapType&);
    MapType& operator=(const MapType&);
    MapType() = default;

    ~MapType() noexcept override;

    bool operator == (const MapType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const MapType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const MapType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(MapType &a, MapType &b);

std::ostream& operator<<(std::ostream& out, const MapType& obj);


class ListType : public virtual ::apache::thrift::TBase {
public:

    ListType(const ListType&);
    ListType& operator=(const ListType&);
    ListType() = default;

    ~ListType() noexcept override;

    bool operator == (const ListType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const ListType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const ListType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(ListType &a, ListType &b);

std::ostream& operator<<(std::ostream& out, const ListType& obj);


class EnumType : public virtual ::apache::thrift::TBase {
public:

    EnumType(const EnumType&);
    EnumType& operator=(const EnumType&);
    EnumType() {
    }

    ~EnumType() noexcept override;

    bool operator == (const EnumType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const EnumType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const EnumType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(EnumType &a, EnumType &b);

std::ostream& operator<<(std::ostream& out, const EnumType& obj);


class DateType : public virtual ::apache::thrift::TBase {
public:

    DateType(const DateType&);
    DateType& operator=(const DateType&);
    DateType() {
    }

    ~DateType() noexcept override;

    bool operator == (const DateType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const DateType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const DateType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(DateType &a, DateType &b);

std::ostream& operator<<(std::ostream& out, const DateType& obj);


class NullType : public virtual ::apache::thrift::TBase {
public:

    NullType(const NullType&);
    NullType& operator=(const NullType&);
    NullType() {
    }

    ~NullType() noexcept override;

    bool operator == (const NullType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const NullType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const NullType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(NullType &a, NullType &b);

std::ostream& operator<<(std::ostream& out, const NullType& obj);


class DecimalType : public virtual ::apache::thrift::TBase {
public:

    DecimalType(const DecimalType&);
    DecimalType& operator=(const DecimalType&);
    DecimalType() : scale(0), precision(0) {
    }

    ~DecimalType() noexcept override;
    int32_t scale;
    int32_t precision;

    void setScale(int32_t val);

    void setPrecision(int32_t val);

    bool operator == (const DecimalType & rhs) const
    {
        if (scale != rhs.scale)
            return false;
        if (precision != rhs.precision)
            return false;
        return true;
    }
    bool operator != (const DecimalType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const DecimalType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(DecimalType &a, DecimalType &b);

std::ostream& operator<<(std::ostream& out, const DecimalType& obj);


class MilliSeconds : public virtual ::apache::thrift::TBase {
public:

    MilliSeconds(const MilliSeconds&);
    MilliSeconds& operator=(const MilliSeconds&);
    MilliSeconds() {
    }

    ~MilliSeconds() noexcept override;

    bool operator == (const MilliSeconds & /* rhs */) const
    {
        return true;
    }
    bool operator != (const MilliSeconds &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const MilliSeconds & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(MilliSeconds &a, MilliSeconds &b);

std::ostream& operator<<(std::ostream& out, const MilliSeconds& obj);


class MicroSeconds : public virtual ::apache::thrift::TBase {
public:

    MicroSeconds(const MicroSeconds&);
    MicroSeconds& operator=(const MicroSeconds&);
    MicroSeconds() {
    }

    ~MicroSeconds() noexcept override;

    bool operator == (const MicroSeconds & /* rhs */) const
    {
        return true;
    }
    bool operator != (const MicroSeconds &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const MicroSeconds & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(MicroSeconds &a, MicroSeconds &b);

std::ostream& operator<<(std::ostream& out, const MicroSeconds& obj);


class NanoSeconds : public virtual ::apache::thrift::TBase {
public:

    NanoSeconds(const NanoSeconds&);
    NanoSeconds& operator=(const NanoSeconds&);
    NanoSeconds() {
    }

    ~NanoSeconds() noexcept override;

    bool operator == (const NanoSeconds & /* rhs */) const
    {
        return true;
    }
    bool operator != (const NanoSeconds &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const NanoSeconds & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(NanoSeconds &a, NanoSeconds &b);

std::ostream& operator<<(std::ostream& out, const NanoSeconds& obj);

typedef struct TimeUnitSet
{
    TimeUnitSet() : MILLIS(false), MICROS(false), NANOS(false) {}
    bool MILLIS :1;
    bool MICROS :1;
    bool NANOS :1;
} timeUnitSet;

class TimeUnit : public virtual ::apache::thrift::TBase {
public:

    TimeUnit(const TimeUnit&);
    TimeUnit& operator=(const TimeUnit&);
    TimeUnit() {
    }

    ~TimeUnit() noexcept override;
    MilliSeconds MILLIS;
    MicroSeconds MICROS;
    NanoSeconds NANOS;

    TimeUnitSet set;

    void setMillis(const MilliSeconds& val);

    void setMicros(const MicroSeconds& val);

    void setNanos(const NanoSeconds& val);

    bool operator == (const TimeUnit & rhs) const
    {
        if (set.MILLIS != rhs.set.MILLIS)
            return false;
        else if (set.MILLIS && !(MILLIS == rhs.MILLIS))
            return false;
        if (set.MICROS != rhs.set.MICROS)
            return false;
        else if (set.MICROS && !(MICROS == rhs.MICROS))
            return false;
        if (set.NANOS != rhs.set.NANOS)
            return false;
        else if (set.NANOS && !(NANOS == rhs.NANOS))
            return false;
        return true;
    }
    bool operator != (const TimeUnit &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TimeUnit & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(TimeUnit &a, TimeUnit &b);

std::ostream& operator<<(std::ostream& out, const TimeUnit& obj);


class TimestampType : public virtual ::apache::thrift::TBase {
public:

    TimestampType(const TimestampType&);
    TimestampType& operator=(const TimestampType&);
    TimestampType() : isAdjustedToUTC(0) {
    }

    ~TimestampType() noexcept override;
    bool isAdjustedToUTC;
    TimeUnit unit;

    void setIsAdjustedToUtc(const bool val);

    void setUnit(const TimeUnit& val);

    bool operator == (const TimestampType & rhs) const
    {
        if (isAdjustedToUTC != rhs.isAdjustedToUTC)
            return false;
        if (!(unit == rhs.unit))
            return false;
        return true;
    }
    bool operator != (const TimestampType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TimestampType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(TimestampType &a, TimestampType &b);

std::ostream& operator<<(std::ostream& out, const TimestampType& obj);


class TimeType : public virtual ::apache::thrift::TBase {
public:

    TimeType(const TimeType&);
    TimeType& operator=(const TimeType&);
    TimeType() : isAdjustedToUTC(0) {
    }

    ~TimeType() noexcept override;
    bool isAdjustedToUTC;
    TimeUnit unit;

    void setIsAdjustedToUtc(const bool val);

    void setUnit(const TimeUnit& val);

    bool operator == (const TimeType & rhs) const
    {
        if (isAdjustedToUTC != rhs.isAdjustedToUTC)
            return false;
        if (!(unit == rhs.unit))
            return false;
        return true;
    }
    bool operator != (const TimeType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TimeType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(TimeType &a, TimeType &b);

std::ostream& operator<<(std::ostream& out, const TimeType& obj);


class IntType : public virtual ::apache::thrift::TBase {
public:

    IntType(const IntType&);
    IntType& operator=(const IntType&);
    IntType() : bitWidth(0), isSigned(0) {
    }

    ~IntType() noexcept override;
    int8_t bitWidth;
    bool isSigned;

    void setBitWidth(const int8_t val);

    void setIsSigned(const bool val);

    bool operator == (const IntType & rhs) const
    {
        if (bitWidth != rhs.bitWidth)
            return false;
        if (isSigned != rhs.isSigned)
            return false;
        return true;
    }
    bool operator != (const IntType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const IntType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(IntType &a, IntType &b);

std::ostream& operator<<(std::ostream& out, const IntType& obj);


class JsonType : public virtual ::apache::thrift::TBase {
public:

    JsonType(const JsonType&);
    JsonType& operator=(const JsonType&);
    JsonType() {
    }

    ~JsonType() noexcept override;

    bool operator == (const JsonType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const JsonType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JsonType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(JsonType &a, JsonType &b);

std::ostream& operator<<(std::ostream& out, const JsonType& obj);


class BsonType : public virtual ::apache::thrift::TBase {
public:

    BsonType(const BsonType&);
    BsonType& operator=(const BsonType&);
    BsonType() {
    }

    ~BsonType() noexcept override;

    bool operator == (const BsonType & /* rhs */) const
    {
        return true;
    }
    bool operator != (const BsonType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const BsonType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(BsonType &a, BsonType &b);

std::ostream& operator<<(std::ostream& out, const BsonType& obj);

typedef struct LogicalTypeSet
{
    LogicalTypeSet() : STRING(false), MAP(false), LIST(false), ENUM(false), DECIMAL(false), DATE(false), TIME(false), TIMESTAMP(false), INTEGER(false), UNKNOWN(false), JSON(false), BSON(false), UUID(false) {}
    bool STRING :1;
    bool MAP :1;
    bool LIST :1;
    bool ENUM :1;
    bool DECIMAL :1;
    bool DATE :1;
    bool TIME :1;
    bool TIMESTAMP :1;
    bool INTEGER :1;
    bool UNKNOWN :1;
    bool JSON :1;
    bool BSON :1;
    bool UUID :1;
} logicalTypeSet;

class LogicalType : public virtual ::apache::thrift::TBase {
public:

    LogicalType(const LogicalType&);
    LogicalType& operator=(const LogicalType&);
    LogicalType() {
    }

    ~LogicalType() noexcept override;
    StringType STRING;
    MapType MAP;
    ListType LIST;
    EnumType ENUM;
    DecimalType DECIMAL;
    DateType DATE;
    TimeType TIME;
    TimestampType TIMESTAMP;
    IntType INTEGER;
    NullType UNKNOWN;
    JsonType JSON;
    BsonType BSON;
    UUIDType UUID;

    LogicalTypeSet set;

    void setString(const StringType& val);

    void setMap(const MapType& val);

    void setList(const ListType& val);

    void setEnum(const EnumType& val);

    void setDecimal(const DecimalType& val);

    void setDate(const DateType& val);

    void setTime(const TimeType& val);

    void setTimestamp(const TimestampType& val);

    void setInteger(const IntType& val);

    void setUnknown(const NullType& val);

    void setJson(const JsonType& val);

    void setBson(const BsonType& val);

    void setUuid(const UUIDType& val);

    bool operator == (const LogicalType & rhs) const
    {
        if (set.STRING != rhs.set.STRING)
            return false;
        else if (set.STRING && !(STRING == rhs.STRING))
            return false;
        if (set.MAP != rhs.set.MAP)
            return false;
        else if (set.MAP && !(MAP == rhs.MAP))
            return false;
        if (set.LIST != rhs.set.LIST)
            return false;
        else if (set.LIST && !(LIST == rhs.LIST))
            return false;
        if (set.ENUM != rhs.set.ENUM)
            return false;
        else if (set.ENUM && !(ENUM == rhs.ENUM))
            return false;
        if (set.DECIMAL != rhs.set.DECIMAL)
            return false;
        else if (set.DECIMAL && !(DECIMAL == rhs.DECIMAL))
            return false;
        if (set.DATE != rhs.set.DATE)
            return false;
        else if (set.DATE && !(DATE == rhs.DATE))
            return false;
        if (set.TIME != rhs.set.TIME)
            return false;
        else if (set.TIME && !(TIME == rhs.TIME))
            return false;
        if (set.TIMESTAMP != rhs.set.TIMESTAMP)
            return false;
        else if (set.TIMESTAMP && !(TIMESTAMP == rhs.TIMESTAMP))
            return false;
        if (set.INTEGER != rhs.set.INTEGER)
            return false;
        else if (set.INTEGER && !(INTEGER == rhs.INTEGER))
            return false;
        if (set.UNKNOWN != rhs.set.UNKNOWN)
            return false;
        else if (set.UNKNOWN && !(UNKNOWN == rhs.UNKNOWN))
            return false;
        if (set.JSON != rhs.set.JSON)
            return false;
        else if (set.JSON && !(JSON == rhs.JSON))
            return false;
        if (set.BSON != rhs.set.BSON)
            return false;
        else if (set.BSON && !(BSON == rhs.BSON))
            return false;
        if (set.UUID != rhs.set.UUID)
            return false;
        else if (set.UUID && !(UUID == rhs.UUID))
            return false;
        return true;
    }
    bool operator != (const LogicalType &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const LogicalType & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(LogicalType &a, LogicalType &b);

std::ostream& operator<<(std::ostream& out, const LogicalType& obj);

typedef struct SchemaElementSet
{
    SchemaElementSet() : type(false), type_length(false), repetition_type(false), num_children(false), converted_type(false), scale(false), precision(false), field_id(false), logicalType(false) {}
    bool type :1;
    bool type_length :1;
    bool repetition_type :1;
    bool num_children :1;
    bool converted_type :1;
    bool scale :1;
    bool precision :1;
    bool field_id :1;
    bool logicalType :1;
} schemaElementSet;


class SchemaElement : public virtual ::apache::thrift::TBase {
public:
    
    SchemaElement(const SchemaElement&);
    SchemaElement& operator=(const SchemaElement&);
    SchemaElement() : type(Type::BOOLEAN), type_length(0), repetition_type(FieldRepetitionType::REQUIRED), name(), num_children(0), converted_type(ConvertedType::UTF8), scale(0), precision(0), field_id(0) {
    }

    ~SchemaElement() noexcept override;
    Type::type type;
    int32_t type_length;
    FieldRepetitionType::type repetition_type;
    std::string name;
    int32_t num_children;
    ConvertedType::type converted_type;
    int32_t scale;
    int32_t precision;
    int32_t field_id;
    LogicalType logicalType;

    SchemaElementSet set;

    void setType(const Type::type val);

    void setTypeLength(const int32_t val);

    void setRepetitionType(const FieldRepetitionType::type val);

    void setName(const std::string& val);

    void setNumChildren(const int32_t val);

    void setConvertedType(const ConvertedType::type val);

    void setScale(const int32_t val);

    void setPrecision(const int32_t val);

    void setFieldId(const int32_t val);

    void setLogicalType(const LogicalType& val);

    bool operator == (const SchemaElement & rhs) const
    {
        if (set.type != rhs.set.type)
            return false;
        else if (set.type && type != rhs.type)
            return false;
        if (set.type_length != rhs.set.type_length)
            return false;
        else if (set.type_length && type_length != rhs.type_length)
            return false;
        if (set.repetition_type != rhs.set.repetition_type)
            return false;
        else if (set.repetition_type && repetition_type != rhs.repetition_type)
            return false;
        if (!(name == rhs.name))
            return false;
        if (set.num_children != rhs.set.num_children)
            return false;
        else if (set.num_children && num_children != rhs.num_children)
            return false;
        if (set.converted_type != rhs.set.converted_type)
            return false;
        else if (set.converted_type && converted_type != rhs.converted_type)
            return false;
        if (set.scale != rhs.set.scale)
            return false;
        else if (set.scale && scale != rhs.scale)
            return false;
        if (set.precision != rhs.set.precision)
            return false;
        else if (set.precision && precision != rhs.precision)
            return false;
        if (set.field_id != rhs.set.field_id)
            return false;
        else if (set.field_id && field_id != rhs.field_id)
            return false;
        if (set.logicalType != rhs.set.logicalType)
            return false;
        else if (set.logicalType && !(logicalType == rhs.logicalType))
            return false;
        return true;
    }
    bool operator != (const SchemaElement &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const SchemaElement & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(SchemaElement &a, SchemaElement &b);

std::ostream& operator<<(std::ostream& out, const SchemaElement& obj);

typedef struct DataPageHeaderSet
{
    DataPageHeaderSet() : statistics(false) {}
    bool statistics :1;
} dataPageHeaderSet;

class DataPageHeader : public virtual ::apache::thrift::TBase {
public:

    DataPageHeader(const DataPageHeader&);
    DataPageHeader& operator=(const DataPageHeader&);
    DataPageHeader() : num_values(0), encoding(Encoding::PLAIN), definition_level_encoding(Encoding::PLAIN), repetition_level_encoding(Encoding::PLAIN) {
    }

    ~DataPageHeader() noexcept override;
    int32_t num_values;
    Encoding::type encoding;
    Encoding::type definition_level_encoding;
    Encoding::type repetition_level_encoding;
    Statistics statistics;

    DataPageHeaderSet set;

    void setNumValues(const int32_t val);

    void setEncoding(const Encoding::type val);

    void setDefinitionLevelEncoding(const Encoding::type val);

    void setRepetitionLevelEncoding(const Encoding::type val);

    void setStatistics(const Statistics& val);

    bool operator == (const DataPageHeader & rhs) const
    {
        if (num_values != rhs.num_values)
            return false;
        if (encoding != rhs.encoding)
            return false;
        if (definition_level_encoding != rhs.definition_level_encoding)
            return false;
        if (repetition_level_encoding != rhs.repetition_level_encoding)
            return false;
        if (set.statistics != rhs.set.statistics)
            return false;
        else if (set.statistics && !(statistics == rhs.statistics))
            return false;
        return true;
    }
    bool operator != (const DataPageHeader &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(DataPageHeader &a, DataPageHeader &b);

std::ostream& operator<<(std::ostream& out, const DataPageHeader& obj);


class IndexPageHeader : public virtual ::apache::thrift::TBase {
public:

    IndexPageHeader(const IndexPageHeader&);
    IndexPageHeader& operator=(const IndexPageHeader&);
    IndexPageHeader() = default;

    ~IndexPageHeader() noexcept override;

    bool operator == (const IndexPageHeader & /* rhs */) const
    {
        return true;
    }
    bool operator != (const IndexPageHeader &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(IndexPageHeader &a, IndexPageHeader &b);

std::ostream& operator<<(std::ostream& out, const IndexPageHeader& obj);

typedef struct DictionaryPageHeaderSset
{
    DictionaryPageHeaderSset() : is_sorted(false) {}
    bool is_sorted :1;
} dictionaryPageHeaderSet;

class DictionaryPageHeader : public virtual ::apache::thrift::TBase {
public:

    DictionaryPageHeader(const DictionaryPageHeader&);
    DictionaryPageHeader& operator=(const DictionaryPageHeader&);
    DictionaryPageHeader() : num_values(0), encoding(Encoding::PLAIN), is_sorted(false) {
    }

    ~DictionaryPageHeader() noexcept override;
    int32_t num_values;
    Encoding::type encoding;
    bool is_sorted;

    DictionaryPageHeaderSset set;

    void setNumValues(int32_t val);

    void setEncoding(const Encoding::type val);

    void setIsSorted(bool val);

    bool operator == (const DictionaryPageHeader & rhs) const
    {
        if (num_values != rhs.num_values)
            return false;
        if (encoding != rhs.encoding)
            return false;
        if (set.is_sorted != rhs.set.is_sorted)
            return false;
        else if (set.is_sorted && is_sorted != rhs.is_sorted)
            return false;
        return true;
    }
    bool operator != (const DictionaryPageHeader &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(DictionaryPageHeader &a, DictionaryPageHeader &b);

std::ostream& operator<<(std::ostream& out, const DictionaryPageHeader& obj);

using DataPageHeaderV2Set = struct DataPageHeaderV2Set
{
    DataPageHeaderV2Set() : is_compressed(true), statistics(false) {}
    bool is_compressed :1;
    bool statistics :1;
};

class DataPageHeaderV2 : public virtual ::apache::thrift::TBase {
public:

    DataPageHeaderV2(const DataPageHeaderV2&);
    DataPageHeaderV2& operator=(const DataPageHeaderV2&);
    DataPageHeaderV2() : num_values(0), num_nulls(0), num_rows(0), encoding(Encoding::PLAIN), definition_levels_byte_length(0), repetition_levels_byte_length(0), is_compressed(true) {
    }

    ~DataPageHeaderV2() noexcept override;
    int32_t num_values;
    int32_t num_nulls;
    int32_t num_rows;
    Encoding::type encoding;
    int32_t definition_levels_byte_length;
    int32_t repetition_levels_byte_length;
    bool is_compressed;
    Statistics statistics;

    DataPageHeaderV2Set set;

    void setNumValues(int32_t val);

    void setNumNulls(int32_t val);

    void setNumRows(int32_t val);

    void setEncoding(Encoding::type val);

    void setDefinitionLevelsByteLength(int32_t val);

    void setRepetitionLevelsByteLength(int32_t val);

    void setIsCompressed(bool val);

    void setStatistics(const Statistics& val);

    bool operator == (const DataPageHeaderV2 & rhs) const
    {
        if (num_values != rhs.num_values)
            return false;
        if (num_nulls != rhs.num_nulls)
            return false;
        if (num_rows != rhs.num_rows)
            return false;
        if (encoding != rhs.encoding)
            return false;
        if (definition_levels_byte_length != rhs.definition_levels_byte_length)
            return false;
        if (repetition_levels_byte_length != rhs.repetition_levels_byte_length)
            return false;
        if (set.is_compressed != rhs.set.is_compressed)
            return false;
        else if (set.is_compressed && is_compressed != rhs.is_compressed)
            return false;
        if (set.statistics != rhs.set.statistics)
            return false;
        else if (set.statistics && !(statistics == rhs.statistics))
            return false;
        return true;
    }
    bool operator != (const DataPageHeaderV2 &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(DataPageHeaderV2 &a, DataPageHeaderV2 &b);

std::ostream& operator<<(std::ostream& out, const DataPageHeaderV2& obj);

using pageHeaderSet = struct PageHeaderSet
{
    PageHeaderSet() : crc(false), data_page_header(false), index_page_header(false), dictionary_page_header(false), data_page_header_v2(false) {}
    bool crc :1;
    bool data_page_header :1;
    bool index_page_header :1;
    bool dictionary_page_header :1;
    bool data_page_header_v2 :1;
};

class PageHeader : public virtual ::apache::thrift::TBase {
public:

    PageHeader(const PageHeader&);
    PageHeader& operator=(const PageHeader&);
    PageHeader() : type(PageType::DATA_PAGE), uncompressed_page_size(0), compressed_page_size(0), crc(0) {
    }

    ~PageHeader() noexcept override;
    PageType::type type;
    int32_t uncompressed_page_size;
    int32_t compressed_page_size;
    int32_t crc;
    DataPageHeader data_page_header;
    IndexPageHeader index_page_header;
    DictionaryPageHeader dictionary_page_header;
    DataPageHeaderV2 data_page_header_v2;

    PageHeaderSet set;

    void setType(const PageType::type val);

    void setUncompressedPageSize(const int32_t val);

    void setCompressedPageSize(const int32_t val);

    void setCrc(const int32_t val);

    void setDataPageHeader(const DataPageHeader& val);

    void setIndexPageHeader(const IndexPageHeader& val);

    void setDictionaryPageHeader(const DictionaryPageHeader& val);

    void setDataPageHeaderV2(const DataPageHeaderV2& val);

    bool operator == (const PageHeader & rhs) const
    {
        if (type != rhs.type)
            return false;
        if (uncompressed_page_size != rhs.uncompressed_page_size)
            return false;
        if (compressed_page_size != rhs.compressed_page_size)
            return false;
        if (set.crc != rhs.set.crc)
            return false;
        else if (set.crc && crc != rhs.crc)
            return false;
        if (set.data_page_header != rhs.set.data_page_header)
            return false;
        else if (set.data_page_header && !(data_page_header == rhs.data_page_header))
            return false;
        if (set.index_page_header != rhs.set.index_page_header)
            return false;
        else if (set.index_page_header && !(index_page_header == rhs.index_page_header))
            return false;
        if (set.dictionary_page_header != rhs.set.dictionary_page_header)
            return false;
        else if (set.dictionary_page_header && !(dictionary_page_header == rhs.dictionary_page_header))
            return false;
        if (set.data_page_header_v2 != rhs.set.data_page_header_v2)
            return false;
        else if (set.data_page_header_v2 && !(data_page_header_v2 == rhs.data_page_header_v2))
            return false;
        return true;
    }
    bool operator != (const PageHeader &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const PageHeader & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(PageHeader &a, PageHeader &b);

std::ostream& operator<<(std::ostream& out, const PageHeader& obj);

typedef struct KeyValueSet
{
    KeyValueSet() : value(false) {}
    bool value :1;
} KeyValueSet;

class KeyValue : public virtual ::apache::thrift::TBase {
public:

    KeyValue(const KeyValue&);
    KeyValue& operator=(const KeyValue&);
    KeyValue() : key(), value() {
    }

    ~KeyValue() noexcept override;
    std::string key;
    std::string value;

    KeyValueSet set;

    void setKey(const std::string& val);

    void setValue(const std::string& val);

    bool operator == (const KeyValue & rhs) const
    {
        if (!(key == rhs.key))
            return false;
        if (set.value != rhs.set.value)
            return false;
        else if (set.value && !(value == rhs.value))
            return false;
        return true;
    }
    bool operator != (const KeyValue &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const KeyValue & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(KeyValue &a, KeyValue &b);

std::ostream& operator<<(std::ostream& out, const KeyValue& obj);


class SortingColumn : public virtual ::apache::thrift::TBase {
public:

    SortingColumn(const SortingColumn&);
    SortingColumn& operator=(const SortingColumn&);
    SortingColumn() : column_idx(0), descending(0), nulls_first(0) {
    }

    ~SortingColumn() noexcept override;
    int32_t column_idx;
    bool descending;
    bool nulls_first;

    void setColumnIdx(const int32_t val);

    void setDescending(const bool val);

    void setNullsFirst(const bool val);

    bool operator == (const SortingColumn & rhs) const
    {
        if (column_idx != rhs.column_idx)
            return false;
        if (descending != rhs.descending)
            return false;
        if (nulls_first != rhs.nulls_first)
            return false;
        return true;
    }
    bool operator != (const SortingColumn &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const SortingColumn & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(SortingColumn &a, SortingColumn &b);

std::ostream& operator<<(std::ostream& out, const SortingColumn& obj);


class PageEncodingStats : public virtual ::apache::thrift::TBase {
public:

    PageEncodingStats(const PageEncodingStats&);
    PageEncodingStats& operator=(const PageEncodingStats&);
    PageEncodingStats() : page_type(PageType::DATA_PAGE), encoding(Encoding::PLAIN), count(0) {
    }

    ~PageEncodingStats() noexcept override;
    PageType::type page_type;
    Encoding::type encoding;
    int32_t count;

    void setPageType(const PageType::type val);

    void setEncoding(const Encoding::type val);

    void setCount(const int32_t val);

    bool operator == (const PageEncodingStats & rhs) const
    {
        if (page_type != rhs.page_type)
            return false;
        if (encoding != rhs.encoding)
            return false;
        if (count != rhs.count)
            return false;
        return true;
    }
    bool operator != (const PageEncodingStats &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(PageEncodingStats &a, PageEncodingStats &b);

std::ostream& operator<<(std::ostream& out, const PageEncodingStats& obj);

using ColumnMetaDataSet = struct ColumnMetaDataSet
{
    ColumnMetaDataSet() : key_value_metadata(false), index_page_offset(false), dictionary_page_offset(false), statistics(false), encoding_stats(false) {}
    bool key_value_metadata :1;
    bool index_page_offset :1;
    bool dictionary_page_offset :1;
    bool statistics :1;
    bool encoding_stats :1;
};

class ColumnMetaData : public virtual ::apache::thrift::TBase {
public:

    ColumnMetaData(const ColumnMetaData&);
    ColumnMetaData& operator=(const ColumnMetaData&);
    ColumnMetaData() : type(Type::BOOLEAN), codec(CompressionCodec::UNCOMPRESSED), num_values(0), total_uncompressed_size(0), total_compressed_size(0), data_page_offset(0), index_page_offset(0), dictionary_page_offset(0) {
    }

    ~ColumnMetaData() noexcept override;
    Type::type type;
    std::vector<Encoding::type>  encodings;
    std::vector<std::string>  path_in_schema;
    CompressionCodec::type codec;
    int64_t num_values;
    int64_t total_uncompressed_size;
    int64_t total_compressed_size;
    std::vector<KeyValue>  key_value_metadata;
    int64_t data_page_offset;
    int64_t index_page_offset;
    int64_t dictionary_page_offset;
    Statistics statistics;
    std::vector<PageEncodingStats>  encoding_stats;

    ColumnMetaDataSet set;

    void setType(const Type::type val);

    void setEncodings(const std::vector<Encoding::type> & val);

    void setPathInSchema(const std::vector<std::string> & val);

    void setCodec(CompressionCodec::type val);

    void setNumValues(const int64_t val);

    void setTotalUncompressedSize(const int64_t val);

    void setTotalCompressedSize(const int64_t val);

    void setKeyValueMetadata(const std::vector<KeyValue> & val);

    void setDataPageOffset(const int64_t val);

    void setIndexPageOffset(const int64_t val);

    void setDictionaryPageOffset(const int64_t val);

    void setStatistics(const Statistics& val);

    void setEncodingStats(const std::vector<PageEncodingStats> & val);

    bool operator == (const ColumnMetaData & rhs) const
    {
        if (type != rhs.type)
            return false;
        if (!(encodings == rhs.encodings))
            return false;
        if (!(path_in_schema == rhs.path_in_schema))
            return false;
        if (codec != rhs.codec)
            return false;
        if (num_values != rhs.num_values)
            return false;
        if (total_uncompressed_size != rhs.total_uncompressed_size)
            return false;
        if (total_compressed_size != rhs.total_compressed_size)
            return false;
        if (set.key_value_metadata != rhs.set.key_value_metadata)
            return false;
        else if (set.key_value_metadata && !(key_value_metadata == rhs.key_value_metadata))
            return false;
        if (data_page_offset != rhs.data_page_offset)
            return false;
        if (set.index_page_offset != rhs.set.index_page_offset)
            return false;
        else if (set.index_page_offset && index_page_offset != rhs.index_page_offset)
            return false;
        if (set.dictionary_page_offset != rhs.set.dictionary_page_offset)
            return false;
        else if (set.dictionary_page_offset && dictionary_page_offset != rhs.dictionary_page_offset)
            return false;
        if (set.statistics != rhs.set.statistics)
            return false;
        else if (set.statistics && !(statistics == rhs.statistics))
            return false;
        if (set.encoding_stats != rhs.set.encoding_stats)
            return false;
        else if (set.encoding_stats && !(encoding_stats == rhs.encoding_stats))
            return false;
        return true;
    }
    bool operator != (const ColumnMetaData &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(ColumnMetaData &a, ColumnMetaData &b);

std::ostream& operator<<(std::ostream& out, const ColumnMetaData& obj);


class EncryptionWithFooterKey : public virtual ::apache::thrift::TBase {
public:

    EncryptionWithFooterKey(const EncryptionWithFooterKey&);
    EncryptionWithFooterKey& operator=(const EncryptionWithFooterKey&);
    EncryptionWithFooterKey() = default;

    ~EncryptionWithFooterKey() noexcept override;

    bool operator == (const EncryptionWithFooterKey & /* rhs */) const
    {
        return true;
    }
    bool operator != (const EncryptionWithFooterKey &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(EncryptionWithFooterKey &a, EncryptionWithFooterKey &b);

std::ostream& operator<<(std::ostream& out, const EncryptionWithFooterKey& obj);

using EncryptionWithColumnKeySet = struct EncryptionWithColumnKeySet {
    EncryptionWithColumnKeySet() : key_metadata(false) {}
    bool key_metadata :1;
};

class EncryptionWithColumnKey : public virtual ::apache::thrift::TBase {
public:

    EncryptionWithColumnKey(const EncryptionWithColumnKey&);
    EncryptionWithColumnKey& operator=(const EncryptionWithColumnKey&);
    EncryptionWithColumnKey() {
    }

    ~EncryptionWithColumnKey() noexcept override;
    std::vector<std::string>  path_in_schema;
    std::string key_metadata;

    EncryptionWithColumnKeySet set;

    void setPathInSchema(const std::vector<std::string> & val);

    void setKeyMetadata(const std::string& val);

    bool operator == (const EncryptionWithColumnKey & rhs) const
    {
        if (!(path_in_schema == rhs.path_in_schema))
            return false;
        if (set.key_metadata != rhs.set.key_metadata)
            return false;
        else if (set.key_metadata && !(key_metadata == rhs.key_metadata))
            return false;
        return true;
    }
    bool operator != (const EncryptionWithColumnKey &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(EncryptionWithColumnKey &a, EncryptionWithColumnKey &b);

std::ostream& operator<<(std::ostream& out, const EncryptionWithColumnKey& obj);

using ColumnCryptoMetaDataSet = struct ColumnCryptoMetaDataSet {
    ColumnCryptoMetaDataSet() : ENCRYPTION_WITH_FOOTER_KEY(false), ENCRYPTION_WITH_COLUMN_KEY(false) {}
    bool ENCRYPTION_WITH_FOOTER_KEY :1;
    bool ENCRYPTION_WITH_COLUMN_KEY :1;
};

class ColumnCryptoMetaData : public virtual ::apache::thrift::TBase {
public:

    ColumnCryptoMetaData(const ColumnCryptoMetaData&);
    ColumnCryptoMetaData& operator=(const ColumnCryptoMetaData&);
    ColumnCryptoMetaData() {
    }

    ~ColumnCryptoMetaData() noexcept override;
    EncryptionWithFooterKey ENCRYPTION_WITH_FOOTER_KEY;
    EncryptionWithColumnKey ENCRYPTION_WITH_COLUMN_KEY;

    ColumnCryptoMetaDataSet set;

    void setEncryptionWithFooterKey(const EncryptionWithFooterKey& val);

    void setEncryptionWithColumnKey(const EncryptionWithColumnKey& val);

    bool operator == (const ColumnCryptoMetaData & rhs) const
    {
        if (set.ENCRYPTION_WITH_FOOTER_KEY != rhs.set.ENCRYPTION_WITH_FOOTER_KEY)
            return false;
        else if (set.ENCRYPTION_WITH_FOOTER_KEY && !(ENCRYPTION_WITH_FOOTER_KEY == rhs.ENCRYPTION_WITH_FOOTER_KEY))
            return false;
        if (set.ENCRYPTION_WITH_COLUMN_KEY != rhs.set.ENCRYPTION_WITH_COLUMN_KEY)
            return false;
        else if (set.ENCRYPTION_WITH_COLUMN_KEY && !(ENCRYPTION_WITH_COLUMN_KEY == rhs.ENCRYPTION_WITH_COLUMN_KEY))
            return false;
        return true;
    }
    bool operator != (const ColumnCryptoMetaData &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(ColumnCryptoMetaData &a, ColumnCryptoMetaData &b);

std::ostream& operator<<(std::ostream& out, const ColumnCryptoMetaData& obj);

using ColumnChunkSet = struct ColumnChunkSet
{
    ColumnChunkSet() : file_path(false), meta_data(false), offset_index_offset(false), offset_index_length(false), column_index_offset(false), column_index_length(false), crypto_metadata(false), encrypted_column_metadata(false) {}
    bool file_path :1;
    bool meta_data :1;
    bool offset_index_offset :1;
    bool offset_index_length :1;
    bool column_index_offset :1;
    bool column_index_length :1;
    bool crypto_metadata :1;
    bool encrypted_column_metadata :1;
};

class ColumnChunk : public virtual ::apache::thrift::TBase {
public:

    ColumnChunk(const ColumnChunk&);
    ColumnChunk& operator=(const ColumnChunk&);
    ColumnChunk() : file_path(), file_offset(0), offset_index_offset(0), offset_index_length(0), column_index_offset(0), column_index_length(0), encrypted_column_metadata() {
    }

    ~ColumnChunk() noexcept override;
    std::string file_path;
    int64_t file_offset;
    ColumnMetaData meta_data;
    int64_t offset_index_offset;
    int32_t offset_index_length;
    int64_t column_index_offset;
    int32_t column_index_length;
    ColumnCryptoMetaData crypto_metadata;
    std::string encrypted_column_metadata;

    ColumnChunkSet set;

    void setFilePath(const std::string& val);

    void setFileOffset(const int64_t val);

    void setMetaData(const ColumnMetaData& val);

    void setOffsetIndexOffset(const int64_t val);

    void setOffsetIndexLength(const int32_t val);

    void setColumnIndexOffset(const int64_t val);

    void setColumnIndexLength(const int32_t val);

    void setCryptoMetadata(const ColumnCryptoMetaData& val);

    void setEncryptedColumnMetadata(const std::string& val);

    bool operator == (const ColumnChunk & rhs) const
    {
        if (set.file_path != rhs.set.file_path)
            return false;
        else if (set.file_path && !(file_path == rhs.file_path))
            return false;
        if (file_offset != rhs.file_offset)
            return false;
        if (set.meta_data != rhs.set.meta_data)
            return false;
        else if (set.meta_data && !(meta_data == rhs.meta_data))
            return false;
        if (set.offset_index_offset != rhs.set.offset_index_offset)
            return false;
        else if (set.offset_index_offset && offset_index_offset != rhs.offset_index_offset)
            return false;
        if (set.offset_index_length != rhs.set.offset_index_length)
            return false;
        else if (set.offset_index_length && offset_index_length != rhs.offset_index_length)
            return false;
        if (set.column_index_offset != rhs.set.column_index_offset)
            return false;
        else if (set.column_index_offset && column_index_offset != rhs.column_index_offset)
            return false;
        if (set.column_index_length != rhs.set.column_index_length)
            return false;
        else if (set.column_index_length && column_index_length != rhs.column_index_length)
            return false;
        if (set.crypto_metadata != rhs.set.crypto_metadata)
            return false;
        else if (set.crypto_metadata && !(crypto_metadata == rhs.crypto_metadata))
            return false;
        if (set.encrypted_column_metadata != rhs.set.encrypted_column_metadata)
            return false;
        else if (set.encrypted_column_metadata && !(encrypted_column_metadata == rhs.encrypted_column_metadata))
            return false;
        return true;
    }
    bool operator != (const ColumnChunk &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(ColumnChunk &a, ColumnChunk &b);

std::ostream& operator<<(std::ostream& out, const ColumnChunk& obj);

using RowGroupSet = struct RowGroupSet {
    RowGroupSet() : sorting_columns(false), file_offset(false), total_compressed_size(false), ordinal(false) {}
    bool sorting_columns :1;
    bool file_offset :1;
    bool total_compressed_size :1;
    bool ordinal :1;
};

class RowGroup : public virtual ::apache::thrift::TBase {
public:

    RowGroup(const RowGroup&);
    RowGroup& operator=(const RowGroup&);
    RowGroup() : total_byte_size(0), num_rows(0), file_offset(0), total_compressed_size(0), ordinal(0) {
    }

    ~RowGroup() noexcept override;
    std::vector<ColumnChunk>  columns;
    int64_t total_byte_size;
    int64_t num_rows;
    std::vector<SortingColumn>  sorting_columns;
    int64_t file_offset;
    int64_t total_compressed_size;
    int16_t ordinal;

    RowGroupSet set;

    void setColumns(const std::vector<ColumnChunk> & val);

    void setTotalByteSize(const int64_t val);

    void setNumRows(const int64_t val);

    void setSortingColumns(const std::vector<SortingColumn> & val);

    void setFileOffset(const int64_t val);

    void setTotalCompressedSize(const int64_t val);

    void setOrdinal(const int16_t val);

    bool operator == (const RowGroup & rhs) const
    {
        if (!(columns == rhs.columns))
            return false;
        if (total_byte_size != rhs.total_byte_size)
            return false;
        if (num_rows != rhs.num_rows)
            return false;
        if (set.sorting_columns != rhs.set.sorting_columns)
            return false;
        else if (set.sorting_columns && !(sorting_columns == rhs.sorting_columns))
            return false;
        if (set.file_offset != rhs.set.file_offset)
            return false;
        else if (set.file_offset && file_offset != rhs.file_offset)
            return false;
        if (set.total_compressed_size != rhs.set.total_compressed_size)
            return false;
        else if (set.total_compressed_size && total_compressed_size != rhs.total_compressed_size)
            return false;
        if (set.ordinal != rhs.set.ordinal)
            return false;
        else if (set.ordinal && ordinal != rhs.ordinal)
            return false;
        return true;
    }
    bool operator != (const RowGroup &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(RowGroup &a, RowGroup &b);

std::ostream& operator<<(std::ostream& out, const RowGroup& obj);


class TypeDefinedOrder : public virtual ::apache::thrift::TBase {
public:

    TypeDefinedOrder(const TypeDefinedOrder&);
    TypeDefinedOrder& operator=(const TypeDefinedOrder&);
    TypeDefinedOrder() = default;

    ~TypeDefinedOrder() noexcept override;

    bool operator == (const TypeDefinedOrder & /* rhs */) const
    {
        return true;
    }
    bool operator != (const TypeDefinedOrder &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(TypeDefinedOrder &a, TypeDefinedOrder &b);

std::ostream& operator<<(std::ostream& out, const TypeDefinedOrder& obj);

using ColumnOrderSet = struct ColumnOrderSet {
    ColumnOrderSet() : TYPE_ORDER(false) {}
    bool TYPE_ORDER :1;
};

class ColumnOrder : public virtual ::apache::thrift::TBase {
public:

    ColumnOrder(const ColumnOrder&);
    ColumnOrder& operator=(const ColumnOrder&);
    ColumnOrder() = default;

    ~ColumnOrder() noexcept override;
    TypeDefinedOrder TYPE_ORDER;

    ColumnOrderSet set;

    void setTypeOrder(const TypeDefinedOrder& val);

    bool operator == (const ColumnOrder & rhs) const
    {
        if (set.TYPE_ORDER != rhs.set.TYPE_ORDER)
            return false;
        else if (set.TYPE_ORDER && !(TYPE_ORDER == rhs.TYPE_ORDER))
            return false;
        return true;
    }
    bool operator != (const ColumnOrder &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(ColumnOrder &a, ColumnOrder &b);

std::ostream& operator<<(std::ostream& out, const ColumnOrder& obj);


class PageLocation : public virtual ::apache::thrift::TBase {
public:

    PageLocation(const PageLocation&);
    PageLocation& operator=(const PageLocation&);
    PageLocation() : offset(0), compressed_page_size(0), first_row_index(0) {
    }

    ~PageLocation() noexcept override;
    int64_t offset;
    int32_t compressed_page_size;
    int64_t first_row_index;

    void setOffset(const int64_t val);

    void setCompressedPageSize(const int32_t val);

    void setFirstRowIndex(const int64_t val);

    bool operator == (const PageLocation & rhs) const
    {
        if (offset != rhs.offset)
            return false;
        if (compressed_page_size != rhs.compressed_page_size)
            return false;
        if (first_row_index != rhs.first_row_index)
            return false;
        return true;
    }
    bool operator != (const PageLocation &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(PageLocation &a, PageLocation &b);

std::ostream& operator<<(std::ostream& out, const PageLocation& obj);


class OffsetIndex : public virtual ::apache::thrift::TBase {
public:

    OffsetIndex(const OffsetIndex&);
    OffsetIndex& operator=(const OffsetIndex&);
    OffsetIndex() = default;

    ~OffsetIndex() noexcept override;
    std::vector<PageLocation>  page_locations;

    void setPageLocations(const std::vector<PageLocation> & val);

    bool operator == (const OffsetIndex & rhs) const
    {
        if (!(page_locations == rhs.page_locations))
            return false;
        return true;
    }
    bool operator != (const OffsetIndex &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(OffsetIndex &a, OffsetIndex &b);

std::ostream& operator<<(std::ostream& out, const OffsetIndex& obj);

using ColumnIndexSet = struct ColumnIndexSet {
    ColumnIndexSet() : null_counts(false) {}
    bool null_counts :1;
};

class ColumnIndex : public virtual ::apache::thrift::TBase {
public:

    ColumnIndex(const ColumnIndex&);
    ColumnIndex& operator=(const ColumnIndex&);
    ColumnIndex() : boundary_order(BoundaryOrder::UNORDERED) {
    }

    ~ColumnIndex() noexcept override;
    std::vector<bool>  null_pages;
    std::vector<std::string>  min_values;
    std::vector<std::string>  max_values;
    BoundaryOrder::type boundary_order;
    std::vector<int64_t>  null_counts;

    ColumnIndexSet set;

    void setNullPages(const std::vector<bool> & val);

    void setMinValues(const std::vector<std::string> & val);

    void setMaxValues(const std::vector<std::string> & val);

    void setBoundaryOrder(const BoundaryOrder::type val);

    void setNullCounts(const std::vector<int64_t> & val);

    bool operator == (const ColumnIndex & rhs) const
    {
        if (!(null_pages == rhs.null_pages))
            return false;
        if (!(min_values == rhs.min_values))
            return false;
        if (!(max_values == rhs.max_values))
            return false;
        if (boundary_order != rhs.boundary_order)
            return false;
        if (set.null_counts != rhs.set.null_counts)
            return false;
        else if (set.null_counts && !(null_counts == rhs.null_counts))
            return false;
        return true;
    }
    bool operator != (const ColumnIndex &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(ColumnIndex &a, ColumnIndex &b);

std::ostream& operator<<(std::ostream& out, const ColumnIndex& obj);

using AesGcmV1Set = struct AesGcmV1Set {
    AesGcmV1Set() : aad_prefix(false), aad_file_unique(false), supply_aad_prefix(false) {}
    bool aad_prefix :1;
    bool aad_file_unique :1;
    bool supply_aad_prefix :1;
};

class AesGcmV1 : public virtual ::apache::thrift::TBase {
public:

    AesGcmV1(const AesGcmV1&);
    AesGcmV1& operator=(const AesGcmV1&);
    AesGcmV1() : aad_prefix(), aad_file_unique(), supply_aad_prefix(false) {
    }

    ~AesGcmV1() noexcept override;
    std::string aad_prefix;
    std::string aad_file_unique;
    bool supply_aad_prefix;

    AesGcmV1Set set;

    void setAadPrefix(const std::string& val);

    void setAadFileUnique(const std::string& val);

    void setSupplyAadPrefix(const bool val);

    bool operator == (const AesGcmV1 & rhs) const
    {
        if (set.aad_prefix != rhs.set.aad_prefix)
            return false;
        else if (set.aad_prefix && !(aad_prefix == rhs.aad_prefix))
            return false;
        if (set.aad_file_unique != rhs.set.aad_file_unique)
            return false;
        else if (set.aad_file_unique && !(aad_file_unique == rhs.aad_file_unique))
            return false;
        if (set.supply_aad_prefix != rhs.set.supply_aad_prefix)
            return false;
        else if (set.supply_aad_prefix && supply_aad_prefix != rhs.supply_aad_prefix)
            return false;
        return true;
    }
    bool operator != (const AesGcmV1 &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(AesGcmV1 &a, AesGcmV1 &b);

std::ostream& operator<<(std::ostream& out, const AesGcmV1& obj);

using AesGcmCtrV1Set = struct AesGcmCtrV1Set {
    AesGcmCtrV1Set() : aad_prefix(false), aad_file_unique(false), supply_aad_prefix(false) {}
    bool aad_prefix :1;
    bool aad_file_unique :1;
    bool supply_aad_prefix :1;
};

class AesGcmCtrV1 : public virtual ::apache::thrift::TBase {
public:

    AesGcmCtrV1(const AesGcmCtrV1&);
    AesGcmCtrV1& operator=(const AesGcmCtrV1&);
    AesGcmCtrV1() : aad_prefix(), aad_file_unique(), supply_aad_prefix(0) {
    }

    ~AesGcmCtrV1() noexcept override;
    std::string aad_prefix;
    std::string aad_file_unique;
    bool supply_aad_prefix;

    AesGcmCtrV1Set set;

    void setAadPrefix(const std::string& val);

    void setAadFileUnique(const std::string& val);

    void setSupplyAadPrefix(const bool val);

    bool operator == (const AesGcmCtrV1 & rhs) const
    {
        if (set.aad_prefix != rhs.set.aad_prefix)
            return false;
        else if (set.aad_prefix && !(aad_prefix == rhs.aad_prefix))
            return false;
        if (set.aad_file_unique != rhs.set.aad_file_unique)
            return false;
        else if (set.aad_file_unique && !(aad_file_unique == rhs.aad_file_unique))
            return false;
        if (set.supply_aad_prefix != rhs.set.supply_aad_prefix)
            return false;
        else if (set.supply_aad_prefix && supply_aad_prefix != rhs.supply_aad_prefix)
            return false;
        return true;
    }
    bool operator != (const AesGcmCtrV1 &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(AesGcmCtrV1 &a, AesGcmCtrV1 &b);

std::ostream& operator<<(std::ostream& out, const AesGcmCtrV1& obj);

using EncryptionAlgorithmSet = struct EncryptionAlgorithmSet {
    EncryptionAlgorithmSet() : AES_GCM_V1(false), AES_GCM_CTR_V1(false) {}
    bool AES_GCM_V1 :1;
    bool AES_GCM_CTR_V1 :1;
};

class EncryptionAlgorithm : public virtual ::apache::thrift::TBase {
public:

    EncryptionAlgorithm(const EncryptionAlgorithm&);
    EncryptionAlgorithm& operator=(const EncryptionAlgorithm&);
    EncryptionAlgorithm() = default;

    ~EncryptionAlgorithm() noexcept override;
    AesGcmV1 AES_GCM_V1;
    AesGcmCtrV1 AES_GCM_CTR_V1;

    EncryptionAlgorithmSet set;

    void setAesGcmV1(const AesGcmV1& val);

    void setAesGcmCtrV1(const AesGcmCtrV1& val);

    bool operator == (const EncryptionAlgorithm & rhs) const
    {
        if (set.AES_GCM_V1 != rhs.set.AES_GCM_V1)
            return false;
        else if (set.AES_GCM_V1 && !(AES_GCM_V1 == rhs.AES_GCM_V1))
            return false;
        if (set.AES_GCM_CTR_V1 != rhs.set.AES_GCM_CTR_V1)
            return false;
        else if (set.AES_GCM_CTR_V1 && !(AES_GCM_CTR_V1 == rhs.AES_GCM_CTR_V1))
            return false;
        return true;
    }
    bool operator != (const EncryptionAlgorithm &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(EncryptionAlgorithm &a, EncryptionAlgorithm &b);

std::ostream& operator<<(std::ostream& out, const EncryptionAlgorithm& obj);

using FileMetaDataSet = struct FileMetaDataSet
{
    FileMetaDataSet() : key_value_metadata(false), created_by(false), column_orders(false), encryption_algorithm(false), footer_signing_key_metadata(false) {}
    bool key_value_metadata :1;
    bool created_by :1;
    bool column_orders :1;
    bool encryption_algorithm :1;
    bool footer_signing_key_metadata :1;
};

class FileMetaData : public virtual ::apache::thrift::TBase {
public:

    FileMetaData(const FileMetaData&);
    FileMetaData& operator=(const FileMetaData&);
    FileMetaData() : version(0), num_rows(0), created_by(), footer_signing_key_metadata() {
    }

    ~FileMetaData() noexcept override;
    int32_t version;
    std::vector<SchemaElement>  schema;
    int64_t num_rows;
    std::vector<RowGroup>  row_groups;
    std::vector<KeyValue>  key_value_metadata;
    std::string created_by;
    std::vector<ColumnOrder>  column_orders;
    EncryptionAlgorithm encryption_algorithm;
    std::string footer_signing_key_metadata;

    FileMetaDataSet set;

    void setVersion(const int32_t val);

    void setSchema(const std::vector<SchemaElement> & val);

    void setNumRows(const int64_t val);

    void setRowGroups(const std::vector<RowGroup> & val);

    void setKeyValueMetadata(const std::vector<KeyValue> & val);

    void setCreatedBy(const std::string& val);

    void setColumnOrders(const std::vector<ColumnOrder> & val);

    void setEncryptionAlgorithm(const EncryptionAlgorithm& val);

    void setFooterSigningKeyMetadata(const std::string& val);

    bool operator == (const FileMetaData & rhs) const
    {
        if (version != rhs.version)
            return false;
        if (!(schema == rhs.schema))
            return false;
        if (num_rows != rhs.num_rows)
            return false;
        if (!(row_groups == rhs.row_groups))
            return false;
        if (set.key_value_metadata != rhs.set.key_value_metadata)
            return false;
        else if (set.key_value_metadata && !(key_value_metadata == rhs.key_value_metadata))
            return false;
        if (set.created_by != rhs.set.created_by)
            return false;
        else if (set.created_by && !(created_by == rhs.created_by))
            return false;
        if (set.column_orders != rhs.set.column_orders)
            return false;
        else if (set.column_orders && !(column_orders == rhs.column_orders))
            return false;
        if (set.encryption_algorithm != rhs.set.encryption_algorithm)
            return false;
        else if (set.encryption_algorithm && !(encryption_algorithm == rhs.encryption_algorithm))
            return false;
        if (set.footer_signing_key_metadata != rhs.set.footer_signing_key_metadata)
            return false;
        else if (set.footer_signing_key_metadata && !(footer_signing_key_metadata == rhs.footer_signing_key_metadata))
            return false;
        return true;
    }
    bool operator != (const FileMetaData &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(FileMetaData &a, FileMetaData &b);

std::ostream& operator<<(std::ostream& out, const FileMetaData& obj);

typedef struct FileCryptoMetaDataset
{
    FileCryptoMetaDataset() : key_metadata(false) {}
    bool key_metadata :1;
} FileCryptoMetaDataset;

class FileCryptoMetaData : public virtual ::apache::thrift::TBase {
public:

    FileCryptoMetaData(const FileCryptoMetaData&);
    FileCryptoMetaData& operator=(const FileCryptoMetaData&);
    FileCryptoMetaData() : key_metadata() {
    }

    ~FileCryptoMetaData() noexcept override;
    EncryptionAlgorithm encryption_algorithm;
    std::string key_metadata;

    FileCryptoMetaDataset set;

    void setEncryptionAlgorithm(const EncryptionAlgorithm& val);

    void setKeyMetadata(const std::string& val);

    bool operator == (const FileCryptoMetaData & rhs) const
    {
        if (!(encryption_algorithm == rhs.encryption_algorithm))
            return false;
        if (set.key_metadata != rhs.set.key_metadata)
            return false;
        else if (set.key_metadata && !(key_metadata == rhs.key_metadata))
            return false;
        return true;
    }
    bool operator != (const FileCryptoMetaData &rhs) const {
        return !(*this == rhs);
    }

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(FileCryptoMetaData &a, FileCryptoMetaData &b);

std::ostream& operator<<(std::ostream& out, const FileCryptoMetaData& obj);
}
