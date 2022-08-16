#include "crc.hpp"
#include <iostream>
void CRC::set_divisor(uint16_t polynomial)
{
    poly = polynomial;
}

uint16_t CRC::get_checksum()
{
    uint32_t file_data;
    uint32_t checksum = 0;
    uint16_t half_fdata;
    bool isEnd = false;
    size_t counter = 0;
    int scounter = 0;
    file_data = prs.get_bytes(4, counter, isEnd);
    half_fdata = file_data >> 16;
    while(isEnd != true)
    {
        for(int i = 0; i < 16; ++i)
        {
            if(half_fdata & 0x8000)
            {
                half_fdata = (half_fdata << 1) ^ poly;
            }
            half_fdata <<= 1;
            half_fdata |= ((file_data >> 16 - i) & 1);
        }
        counter += 2;
        file_data = (file_data << 16) | prs.get_bytes(2, counter, isEnd);
    }
    return half_fdata;
}

bool CRC::check(uint16_t checksum)
{
    return checksum == get_checksum();
}