#pragma once
#include <generated/parquet_types.h>
#include <DataTypes/IDataType.h>

namespace DB
{
struct LevelInfo {
    int16_t max_def_level = 0;
    int16_t max_rep_level = 0;

    int16_t immediate_repeated_ancestor_def_level = 0;

    bool is_nullable() const { return max_def_level > immediate_repeated_ancestor_def_level; }

    int16_t increment_repeated() {
        auto origin_ancestor_rep_levels = immediate_repeated_ancestor_def_level;
        max_def_level++;
        max_rep_level++;
        immediate_repeated_ancestor_def_level = max_def_level;
        return origin_ancestor_rep_levels;
    }

    std::string debug_string() const;
};

struct ParquetField {
    std::string name;
    parquet::format::SchemaElement schema_element;

    // Used to identify if this field is a nested field.
    DataTypePtr type;
    bool is_nullable;

    // Only valid when this field is a leaf node
    parquet::format::Type::type physical_type;
    // If type is FIXED_LEN_BYTE_ARRAY, this is the byte length of the vales.
    int32_t type_length;

    // Used when this column contains decimal data.
    int32_t scale;
    int32_t precision;

    // used to get ColumnChunk in parquet file's metadata
    size_t physical_column_index;

    LevelInfo level_info;
    std::vector<ParquetField> children;

    int16_t max_def_level() const { return level_info.max_def_level; }
    int16_t max_rep_level() const { return level_info.max_rep_level; }

    std::string debug_string() const;
};


class Schema
{
    friend class ParquetFileReader;
public:
    Schema() = default;
    ~Schema() = default;

    void from_thrift(const std::vector<parquet::format::SchemaElement>& t_schemas);

    std::string debug_string() const;

    size_t get_column_index(const std::string& column, bool case_sensitive) const;
    const ParquetField* getStoredColumnByIdx(size_t idx) const { return &_fields[idx]; }

    const ParquetField* resolveByName(const std::string& name) const {
        auto it = _field_by_name.find(name);
        if (it != _field_by_name.end()) {
            return it->second;
        }
        return nullptr;
    }

    void get_field_names(std::unordered_set<std::string>& names, bool case_sensitive) const;

private:
    void leaf_to_field(const parquet::format::SchemaElement& t_schema, const LevelInfo& cur_level_info, bool is_nullable,
                       ParquetField* field);

//    Status list_to_field(const std::vector<tparquet::SchemaElement>& t_schemas, size_t pos, LevelInfo cur_level_info,
//                         ParquetField* field, size_t* next_pos);
//
//    Status map_to_field(const std::vector<tparquet::SchemaElement>& t_schemas, size_t pos, LevelInfo cur_level_info,
//                        ParquetField* field, size_t* next_pos);
//
//    Status group_to_struct_field(const std::vector<tparquet::SchemaElement>& t_schemas, size_t pos,
//                                 LevelInfo cur_level_info, ParquetField* field, size_t* next_pos);
//
//    Status group_to_field(const std::vector<tparquet::SchemaElement>& t_schemas, size_t pos, LevelInfo cur_level_info,
//                          ParquetField* field, size_t* next_pos);
//
    void node_to_field(const std::vector<parquet::format::SchemaElement>& schemas, size_t pos, LevelInfo cur_level_info,
                         ParquetField* field, size_t* next_pos);

    std::vector<ParquetField> _fields;
    std::vector<ParquetField*> _physical_fields;

    std::unordered_map<std::string, const ParquetField*> _field_by_name;
};


}
