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

struct FieldRepetitionType {
    enum type {
        REQUIRED = 0,
        OPTIONAL = 1,
        REPEATED = 2
    };
};


class StringType : public virtual ::apache::thrift::TBase {
public:
    
    StringType(const StringType&);
    StringType& operator=(const StringType&);
    StringType() {
    }

    virtual ~StringType() noexcept override;

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
    UUIDType() {
    }

    virtual ~UUIDType() noexcept override;

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
    MapType() {
    }

    virtual ~MapType() noexcept override;

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
    ListType() {
    }

    virtual ~ListType() noexcept override;

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

    virtual ~EnumType() noexcept override;

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

    virtual ~DateType() noexcept override;

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

    virtual ~NullType() noexcept override;

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

    virtual ~DecimalType() noexcept override;
    int32_t scale;
    int32_t precision;

    void setScale(const int32_t val);

    void setPrecision(const int32_t val);

    bool operator == (const DecimalType & rhs) const
    {
        if (!(scale == rhs.scale))
            return false;
        if (!(precision == rhs.precision))
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

    virtual ~MilliSeconds() noexcept override;

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

    virtual ~MicroSeconds() noexcept override;

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

    virtual ~NanoSeconds() noexcept override;

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

    virtual ~TimeUnit() noexcept override;
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

    virtual ~TimestampType() noexcept override;
    bool isAdjustedToUTC;
    TimeUnit unit;

    void setIsAdjustedToUtc(const bool val);

    void setUnit(const TimeUnit& val);

    bool operator == (const TimestampType & rhs) const
    {
        if (!(isAdjustedToUTC == rhs.isAdjustedToUTC))
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

    virtual ~TimeType() noexcept override;
    bool isAdjustedToUTC;
    TimeUnit unit;

    void setIsAdjustedToUtc(const bool val);

    void setUnit(const TimeUnit& val);

    bool operator == (const TimeType & rhs) const
    {
        if (!(isAdjustedToUTC == rhs.isAdjustedToUTC))
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

    virtual ~IntType() noexcept override;
    int8_t bitWidth;
    bool isSigned;

    void setBitWidth(const int8_t val);

    void setIsSigned(const bool val);

    bool operator == (const IntType & rhs) const
    {
        if (!(bitWidth == rhs.bitWidth))
            return false;
        if (!(isSigned == rhs.isSigned))
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

    virtual ~JsonType() noexcept override;

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

    virtual ~BsonType() noexcept override;

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

    virtual ~LogicalType() noexcept override;
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
    SchemaElement() : type(Type::BOOLEAN), type_length(0), repetition_type((FieldRepetitionType::type)0), name(), num_children(0), converted_type((ConvertedType::type)0), scale(0), precision(0), field_id(0) {
    }

    virtual ~SchemaElement() noexcept override;
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
        else if (set.type && !(type == rhs.type))
            return false;
        if (set.type_length != rhs.set.type_length)
            return false;
        else if (set.type_length && !(type_length == rhs.type_length))
            return false;
        if (set.repetition_type != rhs.set.repetition_type)
            return false;
        else if (set.repetition_type && !(repetition_type == rhs.repetition_type))
            return false;
        if (!(name == rhs.name))
            return false;
        if (set.num_children != rhs.set.num_children)
            return false;
        else if (set.num_children && !(num_children == rhs.num_children))
            return false;
        if (set.converted_type != rhs.set.converted_type)
            return false;
        else if (set.converted_type && !(converted_type == rhs.converted_type))
            return false;
        if (set.scale != rhs.set.scale)
            return false;
        else if (set.scale && !(scale == rhs.scale))
            return false;
        if (set.precision != rhs.set.precision)
            return false;
        else if (set.precision && !(precision == rhs.precision))
            return false;
        if (set.field_id != rhs.set.field_id)
            return false;
        else if (set.field_id && !(field_id == rhs.field_id))
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

std::ostream& operator<<(std::ostream& out, const CompressionCodec::type& val);

struct PageType {
    enum type {
        DATA_PAGE = 0,
        INDEX_PAGE = 1,
        DICTIONARY_PAGE = 2,
        DATA_PAGE_V2 = 3
    };
};


std::ostream& operator<<(std::ostream& out, const PageType::type& val);

struct BoundaryOrder {
    enum type {
        UNORDERED = 0,
        ASCENDING = 1,
        DESCENDING = 2
    };
};


std::ostream& operator<<(std::ostream& out, const BoundaryOrder::type& val);


class PageEncodingStats : public virtual ::apache::thrift::TBase {
public:
    
    PageEncodingStats(const PageEncodingStats&);
    PageEncodingStats& operator=(const PageEncodingStats&);
    PageEncodingStats() : page_type(PageType::DATA_PAGE), encoding(Encoding::PLAIN), count(0) {
    }

    virtual ~PageEncodingStats() noexcept override;
    PageType::type page_type;
    Encoding::type encoding;
    int32_t count;

    void __set_page_type(const PageType::type val);

    void __set_encoding(const Encoding::type val);

    void __set_count(const int32_t val);

    bool operator == (const PageEncodingStats & rhs) const
    {
        if (!(page_type == rhs.page_type))
            return false;
        if (!(encoding == rhs.encoding))
            return false;
        if (!(count == rhs.count))
            return false;
        return true;
    }
    bool operator != (const PageEncodingStats &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const PageEncodingStats & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(PageEncodingStats &a, PageEncodingStats &b);

std::ostream& operator<<(std::ostream& out, const PageEncodingStats& obj);


typedef struct _KeyValue__isset {
    _KeyValue__isset() : value(false) {}
    bool value :1;
} _KeyValue__isset;

class KeyValue : public virtual ::apache::thrift::TBase {
public:

    KeyValue(const KeyValue&);
    KeyValue& operator=(const KeyValue&);
    KeyValue() : key(), value() {
    }

    virtual ~KeyValue() throw();
    std::string key;
    std::string value;

    _KeyValue__isset __isset;

    void __set_key(const std::string& val);

    void __set_value(const std::string& val);

    bool operator == (const KeyValue & rhs) const
    {
        if (!(key == rhs.key))
            return false;
        if (__isset.value != rhs.__isset.value)
            return false;
        else if (__isset.value && !(value == rhs.value))
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

typedef struct _ColumnMetaData__isset {
    _ColumnMetaData__isset() : key_value_metadata(false), index_page_offset(false), dictionary_page_offset(false), statistics(false), encoding_stats(false) {}
    bool key_value_metadata :1;
    bool index_page_offset :1;
    bool dictionary_page_offset :1;
    bool statistics :1;
    bool encoding_stats :1;
} _ColumnMetaData__isset;

class ColumnMetaData : public virtual ::apache::thrift::TBase {
public:

    ColumnMetaData(const ColumnMetaData&);
    ColumnMetaData& operator=(const ColumnMetaData&);
    ColumnMetaData() : type((Type::type)0), codec((CompressionCodec::type)0), num_values(0), total_uncompressed_size(0), total_compressed_size(0), data_page_offset(0), index_page_offset(0), dictionary_page_offset(0) {
    }

    virtual ~ColumnMetaData() throw();
    Type::type type;
    duckdb::vector<Encoding::type>  encodings;
    duckdb::vector<std::string>  path_in_schema;
    CompressionCodec::type codec;
    int64_t num_values;
    int64_t total_uncompressed_size;
    int64_t total_compressed_size;
    duckdb::vector<KeyValue>  key_value_metadata;
    int64_t data_page_offset;
    int64_t index_page_offset;
    int64_t dictionary_page_offset;
    Statistics statistics;
    duckdb::vector<PageEncodingStats>  encoding_stats;

    _ColumnMetaData__isset __isset;

    void __set_type(const Type::type val);

    void __set_encodings(const duckdb::vector<Encoding::type> & val);

    void __set_path_in_schema(const duckdb::vector<std::string> & val);

    void __set_codec(const CompressionCodec::type val);

    void __set_num_values(const int64_t val);

    void __set_total_uncompressed_size(const int64_t val);

    void __set_total_compressed_size(const int64_t val);

    void __set_key_value_metadata(const duckdb::vector<KeyValue> & val);

    void __set_data_page_offset(const int64_t val);

    void __set_index_page_offset(const int64_t val);

    void __set_dictionary_page_offset(const int64_t val);

    void __set_statistics(const Statistics& val);

    void __set_encoding_stats(const duckdb::vector<PageEncodingStats> & val);

    bool operator == (const ColumnMetaData & rhs) const
    {
        if (!(type == rhs.type))
            return false;
        if (!(encodings == rhs.encodings))
            return false;
        if (!(path_in_schema == rhs.path_in_schema))
            return false;
        if (!(codec == rhs.codec))
            return false;
        if (!(num_values == rhs.num_values))
            return false;
        if (!(total_uncompressed_size == rhs.total_uncompressed_size))
            return false;
        if (!(total_compressed_size == rhs.total_compressed_size))
            return false;
        if (__isset.key_value_metadata != rhs.__isset.key_value_metadata)
            return false;
        else if (__isset.key_value_metadata && !(key_value_metadata == rhs.key_value_metadata))
            return false;
        if (!(data_page_offset == rhs.data_page_offset))
            return false;
        if (__isset.index_page_offset != rhs.__isset.index_page_offset)
            return false;
        else if (__isset.index_page_offset && !(index_page_offset == rhs.index_page_offset))
            return false;
        if (__isset.dictionary_page_offset != rhs.__isset.dictionary_page_offset)
            return false;
        else if (__isset.dictionary_page_offset && !(dictionary_page_offset == rhs.dictionary_page_offset))
            return false;
        if (__isset.statistics != rhs.__isset.statistics)
            return false;
        else if (__isset.statistics && !(statistics == rhs.statistics))
            return false;
        if (__isset.encoding_stats != rhs.__isset.encoding_stats)
            return false;
        else if (__isset.encoding_stats && !(encoding_stats == rhs.encoding_stats))
            return false;
        return true;
    }
    bool operator != (const ColumnMetaData &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const ColumnMetaData & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(ColumnMetaData &a, ColumnMetaData &b);

std::ostream& operator<<(std::ostream& out, const ColumnMetaData& obj);



typedef struct _ColumnChunk__isset {
    _ColumnChunk__isset() : file_path(false), meta_data(false), offset_index_offset(false), offset_index_length(false), column_index_offset(false), column_index_length(false), crypto_metadata(false), encrypted_column_metadata(false) {}
    bool file_path :1;
    bool meta_data :1;
    bool offset_index_offset :1;
    bool offset_index_length :1;
    bool column_index_offset :1;
    bool column_index_length :1;
    bool crypto_metadata :1;
    bool encrypted_column_metadata :1;
} _ColumnChunk__isset;

class ColumnChunk : public virtual ::apache::thrift::TBase {
public:

    ColumnChunk(const ColumnChunk&);
    ColumnChunk& operator=(const ColumnChunk&);
    ColumnChunk() : file_path(), file_offset(0), offset_index_offset(0), offset_index_length(0), column_index_offset(0), column_index_length(0), encrypted_column_metadata() {
    }

    virtual ~ColumnChunk() throw();
    std::string file_path;
    int64_t file_offset;
    ColumnMetaData meta_data;
    int64_t offset_index_offset;
    int32_t offset_index_length;
    int64_t column_index_offset;
    int32_t column_index_length;
    ColumnCryptoMetaData crypto_metadata;
    std::string encrypted_column_metadata;

    _ColumnChunk__isset __isset;

    void __set_file_path(const std::string& val);

    void __set_file_offset(const int64_t val);

    void __set_meta_data(const ColumnMetaData& val);

    void __set_offset_index_offset(const int64_t val);

    void __set_offset_index_length(const int32_t val);

    void __set_column_index_offset(const int64_t val);

    void __set_column_index_length(const int32_t val);

    void __set_crypto_metadata(const ColumnCryptoMetaData& val);

    void __set_encrypted_column_metadata(const std::string& val);

    bool operator == (const ColumnChunk & rhs) const
    {
        if (__isset.file_path != rhs.__isset.file_path)
            return false;
        else if (__isset.file_path && !(file_path == rhs.file_path))
            return false;
        if (!(file_offset == rhs.file_offset))
            return false;
        if (__isset.meta_data != rhs.__isset.meta_data)
            return false;
        else if (__isset.meta_data && !(meta_data == rhs.meta_data))
            return false;
        if (__isset.offset_index_offset != rhs.__isset.offset_index_offset)
            return false;
        else if (__isset.offset_index_offset && !(offset_index_offset == rhs.offset_index_offset))
            return false;
        if (__isset.offset_index_length != rhs.__isset.offset_index_length)
            return false;
        else if (__isset.offset_index_length && !(offset_index_length == rhs.offset_index_length))
            return false;
        if (__isset.column_index_offset != rhs.__isset.column_index_offset)
            return false;
        else if (__isset.column_index_offset && !(column_index_offset == rhs.column_index_offset))
            return false;
        if (__isset.column_index_length != rhs.__isset.column_index_length)
            return false;
        else if (__isset.column_index_length && !(column_index_length == rhs.column_index_length))
            return false;
        if (__isset.crypto_metadata != rhs.__isset.crypto_metadata)
            return false;
        else if (__isset.crypto_metadata && !(crypto_metadata == rhs.crypto_metadata))
            return false;
        if (__isset.encrypted_column_metadata != rhs.__isset.encrypted_column_metadata)
            return false;
        else if (__isset.encrypted_column_metadata && !(encrypted_column_metadata == rhs.encrypted_column_metadata))
            return false;
        return true;
    }
    bool operator != (const ColumnChunk &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const ColumnChunk & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(ColumnChunk &a, ColumnChunk &b);

std::ostream& operator<<(std::ostream& out, const ColumnChunk& obj);


typedef struct _RowGroup__isset {
    _RowGroup__isset() : sorting_columns(false), file_offset(false), total_compressed_size(false), ordinal(false) {}
    bool sorting_columns :1;
    bool file_offset :1;
    bool total_compressed_size :1;
    bool ordinal :1;
} _RowGroup__isset;

class RowGroup : public virtual ::apache::thrift::TBase {
public:

    RowGroup(const RowGroup&);
    RowGroup& operator=(const RowGroup&);
    RowGroup() : total_byte_size(0), num_rows(0), file_offset(0), total_compressed_size(0), ordinal(0) {
    }

    virtual ~RowGroup() throw();
    std::vector<ColumnChunk>  columns;
    int64_t total_byte_size;
    int64_t num_rows;
    std::vector<SortingColumn>  sorting_columns;
    int64_t file_offset;
    int64_t total_compressed_size;
    int16_t ordinal;

    _RowGroup__isset __isset;

    void __set_columns(const duckdb::vector<ColumnChunk> & val);

    void __set_total_byte_size(const int64_t val);

    void __set_num_rows(const int64_t val);

    void __set_sorting_columns(const duckdb::vector<SortingColumn> & val);

    void __set_file_offset(const int64_t val);

    void __set_total_compressed_size(const int64_t val);

    void __set_ordinal(const int16_t val);

    bool operator == (const RowGroup & rhs) const
    {
        if (!(columns == rhs.columns))
            return false;
        if (!(total_byte_size == rhs.total_byte_size))
            return false;
        if (!(num_rows == rhs.num_rows))
            return false;
        if (__isset.sorting_columns != rhs.__isset.sorting_columns)
            return false;
        else if (__isset.sorting_columns && !(sorting_columns == rhs.sorting_columns))
            return false;
        if (__isset.file_offset != rhs.__isset.file_offset)
            return false;
        else if (__isset.file_offset && !(file_offset == rhs.file_offset))
            return false;
        if (__isset.total_compressed_size != rhs.__isset.total_compressed_size)
            return false;
        else if (__isset.total_compressed_size && !(total_compressed_size == rhs.total_compressed_size))
            return false;
        if (__isset.ordinal != rhs.__isset.ordinal)
            return false;
        else if (__isset.ordinal && !(ordinal == rhs.ordinal))
            return false;
        return true;
    }
    bool operator != (const RowGroup &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const RowGroup & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};

void swap(RowGroup &a, RowGroup &b);

std::ostream& operator<<(std::ostream& out, const RowGroup& obj);


class FileMetaData : public virtual ::apache::thrift::TBase
{
public:
    
    FileMetaData(const FileMetaData&);
    FileMetaData& operator=(const FileMetaData&);
    FileMetaData() : version(0), num_rows(0), created_by(), footer_signing_key_metadata() {
    }

    virtual ~FileMetaData() noexcept override;
    int32_t version;
    std::vector<SchemaElement>  schema;
    int64_t num_rows;
    duckdb::vector<RowGroup>  row_groups;
    duckdb::vector<KeyValue>  key_value_metadata;
    std::string created_by;
    duckdb::vector<ColumnOrder>  column_orders;
    EncryptionAlgorithm encryption_algorithm;
    std::string footer_signing_key_metadata;

    _FileMetaData__isset __isset;

    void __set_version(const int32_t val);

    void __set_schema(const duckdb::vector<SchemaElement> & val);

    void __set_num_rows(const int64_t val);

    void __set_row_groups(const duckdb::vector<RowGroup> & val);

    void __set_key_value_metadata(const duckdb::vector<KeyValue> & val);

    void __set_created_by(const std::string& val);

    void __set_column_orders(const duckdb::vector<ColumnOrder> & val);

    void __set_encryption_algorithm(const EncryptionAlgorithm& val);

    void __set_footer_signing_key_metadata(const std::string& val);

    bool operator == (const FileMetaData & rhs) const
    {
        if (!(version == rhs.version))
            return false;
        if (!(schema == rhs.schema))
            return false;
        if (!(num_rows == rhs.num_rows))
            return false;
        if (!(row_groups == rhs.row_groups))
            return false;
        if (__isset.key_value_metadata != rhs.__isset.key_value_metadata)
            return false;
        else if (__isset.key_value_metadata && !(key_value_metadata == rhs.key_value_metadata))
            return false;
        if (__isset.created_by != rhs.__isset.created_by)
            return false;
        else if (__isset.created_by && !(created_by == rhs.created_by))
            return false;
        if (__isset.column_orders != rhs.__isset.column_orders)
            return false;
        else if (__isset.column_orders && !(column_orders == rhs.column_orders))
            return false;
        if (__isset.encryption_algorithm != rhs.__isset.encryption_algorithm)
            return false;
        else if (__isset.encryption_algorithm && !(encryption_algorithm == rhs.encryption_algorithm))
            return false;
        if (__isset.footer_signing_key_metadata != rhs.__isset.footer_signing_key_metadata)
            return false;
        else if (__isset.footer_signing_key_metadata && !(footer_signing_key_metadata == rhs.footer_signing_key_metadata))
            return false;
        return true;
    }
    bool operator != (const FileMetaData &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const FileMetaData & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

    virtual void printTo(std::ostream& out) const;
};
}
