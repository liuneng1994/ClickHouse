#include <Server/HTTP/HTMLForm.h>

#include <IO/EmptyReadBuffer.h>
#include <IO/ReadBufferFromString.h>
#include <Server/HTTP/ReadHeaders.h>

#include <Poco/CountingStream.h>
#include <Poco/Net/MultipartReader.h>
#include <Poco/Net/MultipartWriter.h>
#include <Poco/Net/NetException.h>
#include <Poco/Net/NullPartHandler.h>
#include <Poco/NullStream.h>
#include <Poco/StreamCopier.h>
#include <Poco/UTF8String.h>

#include <sstream>


namespace DB
{

namespace
{

class NullPartHandler : public HTMLForm::PartHandler
{
public:
    void handlePart(const Poco::Net::MessageHeader &, ReadBuffer &) override {}
};

}

const std::string HTMLForm::ENCODING_URL = "application/x-www-form-urlencoded";
const std::string HTMLForm::ENCODING_MULTIPART = "multipart/form-data";
const int HTMLForm::UNKNOWN_CONTENT_LENGTH = -1;


HTMLForm::HTMLForm() : field_limit(DFL_FIELD_LIMIT), value_length_limit(DFL_MAX_VALUE_LENGTH), encoding(ENCODING_URL)
{
}


HTMLForm::HTMLForm(const std::string & encoding_)
    : field_limit(DFL_FIELD_LIMIT), value_length_limit(DFL_MAX_VALUE_LENGTH), encoding(encoding_)
{
}


HTMLForm::HTMLForm(const Poco::Net::HTTPRequest & request, ReadBuffer & requestBody, PartHandler & handler)
    : field_limit(DFL_FIELD_LIMIT), value_length_limit(DFL_MAX_VALUE_LENGTH)
{
    load(request, requestBody, handler);
}


HTMLForm::HTMLForm(const Poco::Net::HTTPRequest & request, ReadBuffer & requestBody)
    : field_limit(DFL_FIELD_LIMIT), value_length_limit(DFL_MAX_VALUE_LENGTH)
{
    load(request, requestBody);
}


HTMLForm::HTMLForm(const Poco::Net::HTTPRequest & request) : HTMLForm(Poco::URI(request.getURI()))
{
}

HTMLForm::HTMLForm(const Poco::URI & uri) : field_limit(DFL_FIELD_LIMIT), value_length_limit(DFL_MAX_VALUE_LENGTH)
{
    ReadBufferFromString istr(uri.getRawQuery()); // STYLE_CHECK_ALLOW_STD_STRING_STREAM
    readQuery(istr);
}


void HTMLForm::setEncoding(const std::string & encoding_)
{
    encoding = encoding_;
}


void HTMLForm::addPart(const std::string & name, Poco::Net::PartSource * source)
{
    poco_check_ptr(source);

    Part part;
    part.name = name;
    part.source = std::unique_ptr<Poco::Net::PartSource>(source);
    parts.push_back(std::move(part));
}


void HTMLForm::load(const Poco::Net::HTTPRequest & request, ReadBuffer & requestBody, PartHandler & handler)
{
    clear();

    Poco::URI uri(request.getURI());
    const std::string & query = uri.getRawQuery();
    if (!query.empty())
    {
        ReadBufferFromString istr(query);
        readQuery(istr);
    }

    if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST || request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT)
    {
        std::string media_type;
        NameValueCollection params;
        Poco::Net::MessageHeader::splitParameters(request.getContentType(), media_type, params);
        encoding = media_type;
        if (encoding == ENCODING_MULTIPART)
        {
            boundary = params["boundary"];
            readMultipart(requestBody, handler);
        }
        else
        {
            readQuery(requestBody);
        }
    }
}


void HTMLForm::load(const Poco::Net::HTTPRequest & request, ReadBuffer & requestBody)
{
    NullPartHandler nah;
    load(request, requestBody, nah);
}


void HTMLForm::load(const Poco::Net::HTTPRequest & request)
{
    NullPartHandler nah;
    EmptyReadBuffer nis;
    load(request, nis, nah);
}


void HTMLForm::read(ReadBuffer & in, PartHandler & handler)
{
    if (encoding == ENCODING_URL)
        readQuery(in);
    else
        readMultipart(in, handler);
}


void HTMLForm::read(ReadBuffer & in)
{
    readQuery(in);
}


void HTMLForm::read(const std::string & queryString)
{
    ReadBufferFromString istr(queryString);
    readQuery(istr);
}


void HTMLForm::readQuery(ReadBuffer & in)
{
    size_t fields = 0;
    char ch = 0;  // silence "uninitialized" warning from gcc-*
    bool is_first = true;

    while (true)
    {
        if (field_limit > 0 && fields == field_limit)
            throw Poco::Net::HTMLFormException("Too many form fields");

        std::string name;
        std::string value;

        while (in.read(ch) && ch != '=' && ch != '&')
        {
            if (ch == '+')
                ch = ' ';
            if (name.size() < MAX_NAME_LENGTH)
                name += ch;
            else
                throw Poco::Net::HTMLFormException("Field name too long");
        }

        if (ch == '=')
        {
            while (in.read(ch) && ch != '&')
            {
                if (ch == '+')
                    ch = ' ';
                if (value.size() < value_length_limit)
                    value += ch;
                else
                    throw Poco::Net::HTMLFormException("Field value too long");
            }
        }

        // Remove UTF-8 BOM from first name, if present
        if (is_first)
            Poco::UTF8::removeBOM(name);

        std::string decoded_name;
        std::string decoded_value;
        Poco::URI::decode(name, decoded_name);
        Poco::URI::decode(value, decoded_value);
        add(decoded_name, decoded_value);
        ++fields;

        is_first = false;

        if (in.eof())
            break;
    }
}


void HTMLForm::readMultipart(ReadBuffer & in_, PartHandler & handler)
{
    /// Assume there is always a boundary provided.
    assert(!boundary.empty());

    size_t fields = 0;
    MultipartReadBuffer in(in_, boundary);

    /// Assume there is at least one part
    in.skipToNextBoundary();

    /// Read each part until next boundary (or last boundary)
    while (!in.eof())
    {
        if (field_limit && fields > field_limit)
            throw Poco::Net::HTMLFormException("Too many form fields");

        Poco::Net::MessageHeader header;
        readHeaders(header, in);
        skipToNextLineOrEOF(in);

        NameValueCollection params;
        if (header.has("Content-Disposition"))
        {
            std::string unused;
            Poco::Net::MessageHeader::splitParameters(header.get("Content-Disposition"), unused, params);
        }

        if (params.has("filename"))
            handler.handlePart(header, in);
        else
        {
            std::string name = params["name"];
            std::string value;
            char ch;

            while (in.read(ch))
            {
                if (value.size() > value_length_limit)
                    throw Poco::Net::HTMLFormException("Field value too long");
                value += ch;
            }

            add(name, value);
        }

        ++fields;

        /// If we already encountered EOF for the buffer |in|, it's possible that the next symbol is a start of boundary line.
        /// In this case reading the boundary line will reset the EOF state, potentially breaking invariant of EOF idempotency -
        /// if there is such invariant in the first place.
        if (!in.skipToNextBoundary())
            break;
    }
}


void HTMLForm::setFieldLimit(int limit)
{
    poco_assert(limit >= 0);

    field_limit = limit;
}


void HTMLForm::setValueLengthLimit(int limit)
{
    poco_assert(limit >= 0);

    value_length_limit = limit;
}


HTMLForm::MultipartReadBuffer::MultipartReadBuffer(ReadBuffer & in_, const std::string & boundary_)
    : ReadBuffer(nullptr, 0), in(in_), boundary("--" + boundary_)
{
    /// For consistency with |nextImpl()|
    position() = in.position();
}

bool HTMLForm::MultipartReadBuffer::skipToNextBoundary()
{
    assert(working_buffer.empty() || eof());
    assert(boundary_hit);

    boundary_hit = false;

    while (!in.eof())
    {
        auto line = readLine();
        if (startsWith(line, boundary))
        {
            set(in.position(), 0);
            next();  /// We need to restrict our buffer to size of next available line.
            return !startsWith(line, boundary + "--");
        }
    }

    throw Poco::Net::HTMLFormException("No boundary line found");
}

std::string HTMLForm::MultipartReadBuffer::readLine(bool strict)
{
    std::string line;
    char ch = 0;  // silence "uninitialized" warning from gcc-*

    while (in.read(ch) && ch != '\r' && ch != '\n')
        line += ch;

    if (in.eof())
    {
        if (strict)
            throw Poco::Net::HTMLFormException("Unexpected end of message");
        return line;
    }

    line += ch;

    if (ch == '\r')
    {
        if (!in.read(ch) || ch != '\n')
            throw Poco::Net::HTMLFormException("No CRLF found");
        else
            line += ch;
    }

    return line;
}

bool HTMLForm::MultipartReadBuffer::nextImpl()
{
    if (boundary_hit)
        return false;

    assert(position() >= in.position());

    in.position() = position();

    /// We expect to start from the first symbol after EOL, so we can put checkpoint
    /// and safely try to read til the next EOL and check for boundary.
    in.setCheckpoint();

    /// FIXME: there is an extra copy because we cannot traverse PeekableBuffer from checkpoint to position()
    ///        since it may store different data parts in different sub-buffers,
    ///        anyway calling makeContinuousMemoryFromCheckpointToPos() will also make an extra copy.
    std::string line = readLine(false);

    /// According to RFC2046 the preceding CRLF is a part of boundary line.
    if (line == "\r\n")
    {
        line = readLine(false);
        boundary_hit = startsWith(line, boundary);
        if (!boundary_hit) line = "\r\n";
    }
    else
        boundary_hit = startsWith(line, boundary);

    if (!line.empty())
        /// If we don't make sure that memory is contiguous then situation may happen, when part of the line is inside internal memory
        /// and other part is inside sub-buffer, thus we'll be unable to setup our working buffer properly.
        in.makeContinuousMemoryFromCheckpointToPos();

    in.rollbackToCheckpoint(true);

    /// Rolling back to checkpoint may change underlying buffers.
    /// Limit readable data to a single line.
    BufferBase::set(in.position(), line.size(), 0);

    return !boundary_hit && !line.empty();
}

}
