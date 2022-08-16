cmake_minimum_required(VERSION 3.1.0)
project(crc)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(crc crc_parser.cpp crc.cpp manifest_generator.cpp manifest_check.cpp)