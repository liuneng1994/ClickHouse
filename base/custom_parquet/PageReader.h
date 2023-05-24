#pragma once

#include <IO/SeekableReadBuffer.h>
#include <generated/parquet_types.h>
#include <Common/PODArray.h>
#include <Common/PODArray_fwd.h>

namespace DB
{
static constexpr size_t HEADER_INIT_SIZE = 1024;

class PageReader
{
public:
    PageReader(SeekableReadBuffer * stream, size_t start, size_t length);
    ~PageReader() = default;

    void nextHeader();

    //
    const parquet::format::PageHeader * currentHeader() const { return &cur_page_header; }

    void readBytes(char * buffer, size_t size);

    void skipBytes(size_t size);

    // seek to read position, this position must be a start of a page header.
    void seekToOffset(uint64_t offset_)
    {
        stream->seek(offset, SEEK_SET);
        offset = offset_;
        next_header_pos = offset;
    }

    uint64_t getOffset() const { return offset; }

private:
    SeekableReadBuffer * stream;
    parquet::format::PageHeader cur_page_header;
    PaddedPODArray<char> page_buffer;
    uint64_t offset = 0;
    uint64_t next_header_pos = 0;

    uint64_t finish_offset = 0;
};

} // DB
