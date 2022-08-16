#include "manifest_check.hpp"

std::stringstream checkmfest(int argc, char* argv[])
{
    uint16_t polynomial = 0x8005;
    std::ifstream manifest(argv[2]);
    std::string filename;
    std::ifstream checkfile;
    std::stringstream outdata;
    std::string manifestline;
    uint16_t checksum;
    size_t spliter;
    CRC_Parser prs(checkfile);
    CRC crc16(polynomial, prs);
    while(getline(manifest, manifestline))
    {
        spliter = manifestline.find_first_of(" ");
        filename = manifestline.substr(0, spliter);
        spliter = manifestline.find_last_of(" ");
        checksum = std::stoul(manifestline.substr(spliter));
        checkfile.open(filename);
        outdata << std::boolalpha << filename << " : " << (checksum == crc16.get_checksum()) << "\n";
        checkfile.close();
    } 
    return outdata;
}