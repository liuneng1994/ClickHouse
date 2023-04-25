#pragma once

#include <DataTypes/IDataType.h>

namespace DB
{

class NativeColumnReader
{
public:
    const DataTypePtr &getType() const;

private:
    DataTypePtr type;
};

} // DB
