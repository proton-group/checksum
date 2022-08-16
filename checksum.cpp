#include "crc.hpp"
#include <fstream>
#include "manifest_generator.hpp"
#include "manifest_check.hpp"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[])
{
    std::ifstream file("test.txt");
    if (!file || argc < 2)
    {
        std::cout << "use: [--calc, --check] filename\n";
        return -1;
    }
    if(strcmp(argv[1], "--calc") == 0)
    {
        genmfest(argc, argv);
    }
    if(strcmp(argv[1], "--check") == 0)
    {
        if (argc > 3)
        {
            std::cout << "use manifest file\n";
            return -1;
        }
        std::cout << checkmfest(argc, argv).str();
    }
    //TODO:catch exception
    return 0;
}