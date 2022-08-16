#ifndef MANIFEST_CHECK_HPP
#define MANIFEST_CHECK_HPP
#include <fstream>
#include "crc.hpp"
#include "crc_parser.hpp"
#include <string>
#include <iomanip>

std::stringstream checkmfest(int argc, char* argv[]);
#endif