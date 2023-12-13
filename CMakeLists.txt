cmake_minimum_required(VERSION 3.20.0)
project(CodingAdvent2023 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(CodingAdvent2023 main.cpp)
set_property(TARGET CodingAdvent2023 PROPERTY CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})