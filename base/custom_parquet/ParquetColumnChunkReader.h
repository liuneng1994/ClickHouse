#pragma once
#include <generated/parquet_types.h>
#include "ParquetColumnReader.h"
#include "PageReader.h"
#include "Decoder.h"
#include <IO/CompressionMethod.h>
#include <Common/PODArray.h>
#include <Common/PODArray_fwd.h>
#include "Utils.h"
#include "CompressCodec.h"


namespace DB
{

struct ColumnReaderOptions;


class ParquetColumnChunkReader
{
public:
    ParquetColumnChunkReader(size_t max_def_level, size_t max_rep_level,
                      const parquet::format::ColumnChunk* column_chunk, const ColumnReaderOptions& opts);
    ~ParquetColumnChunkReader() = default;

    void init(size_t chunk_size);

    void loadHeader();

    void loadPage();

    void skipPage();

    bool currentPageIsDict();

    size_t numValues() const { return num_values; }

    size_t decode_def_levels(size_t n, level_t * levels) {
//        DCHECK_GT(_max_def_level, 0);
        return def_level_decoder.decode_batch(n, levels);
    }

    LevelDecoder& getDefLevelDecoder() { return def_level_decoder; }
    LevelDecoder& getRepLevelDecoder() { return rep_level_decoder; }

    size_t decode_rep_levels(size_t n, level_t * levels) {
//        DCHECK_GT(_max_rep_level, 0);
        return rep_level_decoder.decode_batch(n, levels);
    }

    void decode_values(size_t n, const uint8_t* is_nulls, MutableColumnPtr dst) {
        size_t idx = 0;
        while (idx < n) {
            bool is_null = is_nulls[idx++];
            size_t run = 1;
            while (idx < n && is_nulls[idx] == is_null) {
                idx++;
                run++;
            }
            if (is_null) {
                dst->insertManyDefaults(run);
            } else {
                cur_decoder->nextBatch(run, dst);
            }
        }
    }

    void decode_values(size_t n, MutableColumnPtr& dst) {
        return cur_decoder->nextBatch(n, dst);
    }

    void getDictValues(MutableColumnPtr & column) {
        tryLoadDictionary();
        return cur_decoder->getDictValues(column);
    }

    void getDictValues(const std::vector<int32_t>& dict_codes, MutableColumnPtr & column) {
        tryLoadDictionary();
        return cur_decoder->getDictValues(dict_codes, column);
    }

    void getDictCodes(const std::vector<Slice>& dict_values, std::vector<int32_t>& dict_codes) {
        tryLoadDictionary();
        return cur_decoder->getDictCodes(dict_values, dict_codes);
    }

    const parquet::format::ColumnMetaData& metadata() const { return chunk_metadata->meta_data; }


private:
    void parsePageHeader();
    void parsePageData();

    void tryLoadDictionary();
    void parseDataPage();
    void parseDictPage();

    void readAndDecompressPageData(size_t compressed_size, size_t uncompressed_size, bool is_compressed);

    enum PageParseState {
        INITIALIZED,
        PAGE_HEADER_PARSED,
        PAGE_LEVELS_PARSED,
        PAGE_DATA_PARSED,
    };

    size_t max_def_level = 0;
    size_t max_rep_level = 0;
    const parquet::format::ColumnChunk* chunk_metadata = nullptr;
    const ColumnReaderOptions& opts;
    std::unique_ptr<PageReader> page_reader;

    CompressCodecPtr compress_codec = nullptr;

    LevelDecoder def_level_decoder;
    LevelDecoder rep_level_decoder;

    size_t chunk_size = 0;
    size_t num_values = 0;

    PaddedPODArray<char> uncompressed_buf;
    PaddedPODArray<char> compressed_data_buf;

    PageParseState page_parse_state = INITIALIZED;
    Slice data;

    bool dict_page_parsed = false;
    Decoder* cur_decoder = nullptr;
    std::unordered_map<int, std::unique_ptr<Decoder>> decoders;
};
}
