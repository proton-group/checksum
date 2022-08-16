#include "crc_parser.hpp"

uint32_t CRC_Parser::get_bytes(int bytes, int offset, bool& isEnd)
{
    isEnd = false;
    char buf;
    uint32_t outdata = 0;
    file.seekg(offset);
    if(file.fail() == true)
    {
        isEnd = true;
        return 0;
    }
    if (bytes > 4)
    {
        throw out_of_size();
    }
    for(int i = 0; i < bytes; ++i)
    {
        file.get(buf);
        if (file.eof() == true)
        {
            if (i != 0)
            {
                return outdata << bytes - i;
            }
            else
            {
                isEnd = true;
                return 0;
            }
        }
        outdata += buf;
        outdata = outdata << 8;
    }
    return outdata;
}