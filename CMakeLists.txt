cmake_minimum_required(VERSION 3.16)

project(
    main 
    VERSION 1.0.0
    DESCRIPTION "A main project for c++."
    LANGUAGES C CXX
)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options (-fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options (-fcolor-diagnostics)
    endif ()
endif ()

set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build/bin)
set(THIRD_PARTY_PATH ${PROJECT_SOURCE_DIR}/third_party)

option(BUILD_TESTS "Build tests" TRUE)

find_package(Threads REQUIRED)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(SetTests)

message("Configuring spdlog")
add_subdirectory(${THIRD_PARTY_PATH}/spdlog)
message("Configuring fmt")
add_subdirectory(${THIRD_PARTY_PATH}/fmt)
message("Configuring CL11")
add_subdirectory(${THIRD_PARTY_PATH}/CLI11)
message("Configuring abseil")
add_subdirectory(${THIRD_PARTY_PATH}/abseil)
message("Configuring protobuf")
add_subdirectory(${THIRD_PARTY_PATH}/protobuf)
message("Configuring nlohmann-json")
add_subdirectory(${THIRD_PARTY_PATH}/nlohmann-json)

add_subdirectory(src)
