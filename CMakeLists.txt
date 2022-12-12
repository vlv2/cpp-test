cmake_minimum_required(VERSION 3.21)

project(
    main 
    VERSION 1.0.0
    DESCRIPTION "A main project for c++."
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build/bin)

option(BUILD_TESTS "Build tests" TRUE)

find_package(Threads REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(SetTests)

message(STATUS "Configuring spdlog lib")
add_subdirectory(dependencies/spdlog)
message("")

message(STATUS "Configuring fmt lib")
add_subdirectory(dependencies/fmt)
message("")

message(STATUS "Configuring CLI11 lib")
add_subdirectory(dependencies/CLI11)
message("")

message(STATUS "Configuring abseil lib")
add_subdirectory(dependencies/abseil)
message("")

message(STATUS "Configuring protobuf lib")
add_subdirectory(dependencies/protobuf)
message("")

include_directories(dependencies/inifile-cpp)
include_directories(dependencies/nlohmann)

add_subdirectory(src)