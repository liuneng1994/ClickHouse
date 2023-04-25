#include "ParquetTypeInfo.h"
#include <DataTypes/DataTypeNested.h>

namespace DB
{
bool ParquetTypeInfo::hasNonRepeatedLeaf() const {
    WhichDataType which(type);
    if (which.isArray()) {
        return false;
    }
    if (isNested(type)) {
        for (size_t i = 0; i < typeid_cast<const DataTypeNestedCustomName *>(type->getCustomName())->getElementNum(); ++i) {
            if (parquetChildAt(i).hasNonRepeatedLeaf()) {
                return true;
            }
        }
        return false;
    } else {
        return true;
    }
}
}
