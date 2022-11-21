#pragma once

class SourceStatistics
{
public:
    long output_rows = 0;
    long time_micro_sec = 0;
    long data_size = 0;
    virtual long getReadBufferTime();
    virtual long getReadBufferDataSize();
    virtual ~SourceStatistics() {};

};


