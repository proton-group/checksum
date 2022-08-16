cmake_minimum_required(VERSION 3.1.0)
project(checksum)

add_subdirectory(src)

include_directories(include)

add_executable(checksum checksum.cpp)
target_link_libraries(checksum crc)