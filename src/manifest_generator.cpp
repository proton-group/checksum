#include "manifest_generator.hpp"
void genmfest(int argc, char* argv[])
{
    uint16_t polynomial = 0x8005;
    std::ifstream checkfile;
    std::ofstream manifest("manifest.txt");
    CRC_Parser prs(checkfile);
    CRC crc16(polynomial, prs);
    for(int i = 2; i < argc; i++)
    {
        checkfile.open(argv[i]);
        manifest << argv[i] << " : " << crc16.get_checksum() << "\n";
        checkfile.close();
    } 
    return;
}