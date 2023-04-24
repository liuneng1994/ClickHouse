#pragma once

#include <thrift/transport/TVirtualTransport.h>
#include <IO/ReadBufferFromFileBase.h>
namespace DB
{

class ThriftFileTransport : public apache::thrift::transport::TVirtualTransport<ThriftFileTransport>
{
public:
    ThriftFileTransport(const std::shared_ptr<ReadBufferFromFileBase> & file_)
        : file(file_), location(0){
    }


    uint32_t read_virt(uint8_t * buf, uint32_t len) override {
        size_t n = file->read(reinterpret_cast<char*>(buf), len);
        location += n;
    }

    void setLocation(size_t location_) {
        location = location_;
        file->seek(location, SEEK_SET);
    }

private:
    std::shared_ptr<ReadBufferFromFileBase> file;
    size_t location;
};
}
