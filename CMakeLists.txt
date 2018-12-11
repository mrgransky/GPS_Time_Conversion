cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(gpsConversion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable (gps2unix src/gps_conv.cpp)
target_link_libraries (gps2unix)

