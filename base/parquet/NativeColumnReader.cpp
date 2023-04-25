#include "NativeColumnReader.h"

namespace DB
{
const DataTypePtr & NativeColumnReader::getType() const
{
    return type;
}
}
