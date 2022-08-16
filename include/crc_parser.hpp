#ifndef CRC_PARSER_HPP
#define CRC_PARSER_HPP
#include <string>
#include <istream>

class CRC_Parser
{
    std::istream& file;
public:
    CRC_Parser(std::istream& checkdata)
        : file(checkdata) {}
    uint32_t get_bytes(int bytes, int offset, bool& isEnd);
    class out_of_size: public std::exception {}; 
};
#endif