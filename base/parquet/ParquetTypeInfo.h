#pragma once
#include "ParquetMetaData.h"
#include <DataTypes/IDataType.h>

namespace DB
{
/// Describes what to extract from leaf repetition / definition
/// levels for a particular level. Selects between using
/// DefLevelsToBitmap, DefRepLevelsToList or DefRepLevelsToBitmap
/// respectively.
enum class LevelMode { kList, kNulls, kStructOverLists };

// Describes a Parquet column.
class ParquetTypeInfo {
public:
    // Occurs in 'column' for non-leaf nodes.
    static constexpr uint32_t kNonLeaf = ~0;

    ParquetTypeInfo(
        DataTypePtr type_,
        std::vector<std::shared_ptr<ParquetTypeInfo>>&& children,
        uint32_t id_,
        uint32_t maxId_,
        uint32_t column_,
        std::string name,
        std::optional<Type::type> parquetType,
        uint32_t maxRepeat,
        uint32_t maxDefine,
        int32_t precision = 0,
        int32_t scale = 0,
        int32_t typeLength = 0)
        :type(type_),
        parent{nullptr},
        id(id_),
        maxId(maxId_),
        column(column_),
        children_(std::move(children)),
        name_(name),
        parquetType_(parquetType),
        maxRepeat_(maxRepeat),
        maxDefine_(maxDefine),
        precision_(precision),
        scale_(scale),
        typeLength_(typeLength) {}

    bool isLeaf() const {
        // Negative column ordinal means non-leaf column.
        return static_cast<int32_t>(column) >= 0;
    }

    const std::shared_ptr<ParquetTypeInfo>& childAt(
        size_t idx) const {
        return children_.at(idx);
    }

    const ParquetTypeInfo& parquetChildAt(size_t index) const {
        return *reinterpret_cast<const ParquetTypeInfo*>(childAt(index).get());
    }

    const ParquetTypeInfo* parquetParent() const {
        return reinterpret_cast<const ParquetTypeInfo*>(parent);
    }

    const std::vector<std::shared_ptr<ParquetTypeInfo>>& getChildren() const {
        return children_;
    }

    /// Fills 'info' and returns the mode for interpreting levels.
//    LevelMode makeLevelInfo(::parquet::internal::LevelInfo& info) const;
    // True if this is or has a non-repeated leaf.
    bool hasNonRepeatedLeaf() const;

    const DataTypePtr type;
    const ParquetTypeInfo* const parent;
    const uint32_t id;
    const uint32_t maxId;
    const uint32_t column;
    const std::vector<std::shared_ptr<ParquetTypeInfo>> children_;
    const std::string name_;
    const std::optional<Type::type> parquetType_;
    const uint32_t maxRepeat_;
    const uint32_t maxDefine_;
    const int32_t precision_;
    const int32_t scale_;
    const int32_t typeLength_;
};

using ParquetTypeInfoPtr = std::shared_ptr<ParquetTypeInfo>;
}

