// [project checksum]
// designed by Anatoly Aleksandrov
// description:
// CRC module is engaged in the calculation of the checksum using the CRC algorithm.
// the polynomial serves as a divisor for the input data. The remainder of the division is the result of the work
// example: CRC16 use 0x8005 polynomial

#ifndef CRC_HPP
#define CRC_HPP
#include "crc_parser.hpp"
#include <string>
#include <math.h>
class CRC
{
    uint16_t poly;
    CRC_Parser& prs;
public:
    CRC(uint16_t polynomial, CRC_Parser& parser): 
        poly(polynomial), prs(parser) {}
    // set_divisor method is needed to set the polynomial.
    void set_divisor(uint16_t polynomial);
    // check method checks for a user checksum match with file checksum
    bool check(uint16_t checksum);
    uint16_t get_checksum();
};

#endif