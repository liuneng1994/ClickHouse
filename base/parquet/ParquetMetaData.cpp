#include "ParquetMetaData.h"
#include <iostream>
#include <thrift/TToString.h>

namespace DB
{

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


DecimalType::~DecimalType() noexcept = default;


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

}
