cmake_minimum_required(VERSION 3.20.0)
project(Day03_Part1 VERSION 0.1.0 LANGUAGES C CXX)

#Source-Files 
set(SOURCES
    day3/part01/main.cpp)

add_executable(Day03_Part1 ${SOURCES})

set_property(TARGET Day03_Part1 PROPERTY CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#Include-Files
target_include_directories(Day03_Part1 PRIVATE)
#${CMAKE_SOURCE_DIR}/stringDecoding/LineDecoder.h
#${CMAKE_SOURCE_DIR}/stringDecoding/Number.h
#${CMAKE_SOURCE_DIR}/stringDecoding/Symbol.h)
