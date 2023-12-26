cmake_minimum_required(VERSION 3.20.0)
project(Day03_Part2 VERSION 0.1.0 LANGUAGES C CXX)

#Source-Files 
set(SOURCES
    day3/part01/main.cpp
    day3/accumulationUnit/AccumulationUnit.cpp
    day3/stringDecoding/LineDecoder.cpp)

add_executable(Day03_Part2 ${SOURCES})

set_property(TARGET Day03_Part2 PROPERTY CXX_STANDARD 17)

#Include-Files
target_include_directories(Day03_Part2 PRIVATE
/stringDecoding/LineDecoder.h
/stringDecoding/FileNumber.h
/stringDecoding/FileSymbol.h
/accumulationUnit/AccumulationUnit.h)

############################# Day 4 Part 1 ###################################
project(Day04_Part1 VERSION 0.1.0 LANGUAGES C CXX)

#Source-Files 
set(SOURCES_DAY4_PART1
    day4/part1/calculationUnit/CalculationUnit.cpp
    day4/part1/main.cpp
    day4/card/Card.cpp
    day4/fileReader/FileReader.cpp)

add_executable(Day04_Part1 ${SOURCES_DAY4_PART1})

set_property(TARGET Day04_Part1 PROPERTY CXX_STANDARD 17)

#Include-Files
target_include_directories(Day04_Part1 PRIVATE
/day4/part1/calculationUnit/CalculationUnit.h
/day4/card/Card.h
/day4/fileReader/FileReader.h
)

############################# Day 4 Part 2 ###################################
project(Day04_Part2 VERSION 0.1.0 LANGUAGES C CXX)

#Source-Files 
set(SOURCES_DAY4_PART2
    day4/part2/calculationUnit/CalculationUnit.cpp
    day4/part2/main.cpp
    day4/card/Card.cpp
    day4/fileReader/FileReader.cpp)

add_executable(Day04_Part2 ${SOURCES_DAY4_PART2})

set_property(TARGET Day04_Part2 PROPERTY CXX_STANDARD 17)

#Include-Files
target_include_directories(Day04_Part2 PRIVATE
/day4/part2/calculationUnit/CalculationUnit.h
/day4/card/Card.h
/day4/fileReader/FileReader.h
)