cmake_minimum_required(VERSION 3.16)

# C compiler
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_EXTENSIONS ON)

# C++ compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS ON)

# Both developer and user mode
set(ENABLE_CACHE_DEFAULT ON)
set(ENABLE_CONAN_DEFAULT OFF)
set(ENABLE_CLANG_TIDY_DEFAULT OFF)

# Developer mode
option(ENABLE_DEVELOPER_MODE "Enable 'developer mode'" TRUE)

set(ENABLE_COVERAGE_DEVELOPER_DEFAULT ON)
set(ENABLE_CPPCHECK_DEVELOPER_DEFAULT ON)
set(ENABLE_SANITIZER_ADDRESS_DEVELOPER_DEFAULT ON)
set(ENABLE_SANITIZER_LEAK_DEVELOPER_DEFAULT ON)
set(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR_DEVELOPER_DEFAULT ON)
set(ENABLE_SANITIZER_MEMORY_DEVELOPER_DEFAULT ON)
set(ENABLE_SANITIZER_THREAD_DEVELOPER_DEFAULT OFF)

include(FetchContent)
FetchContent_Declare(
    _project_options 
    URL https://github.com/aminya/project_options/archive/refs/tags/v0.26.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)

project(
    main 
    VERSION 1.0.0
    DESCRIPTION "A main project for c++."
    LANGUAGES C CXX
)

include(${_project_options_SOURCE_DIR}/src/Common.cmake)
common_project_options()

include(${_project_options_SOURCE_DIR}/src/DynamicProjectOptions.cmake)
dynamic_project_options(
    CPPCHECK_OPTIONS
    --project=${CMAKE_BINARY_DIR}/compile_commands.json
    -i${PROJECT_SOURCE_DIR}/third_party/
)

target_compile_features(project_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})

# Adding third_parties:
set(THIRD_PARTIES abseil CLI11 fmt googletest nlohmann-json protobuf spdlog)
foreach(THIRD_PARTY ${THIRD_PARTIES})
    add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/${THIRD_PARTY})
endforeach()

# Only main and tests targets will be analyzed by cppcheck.
if(${OPT_ENABLE_CPPCHECK})
    include(${_project_options_SOURCE_DIR}/src/Utilities.cmake)
    include(${_project_options_SOURCE_DIR}/src/StaticAnalyzers.cmake)

    get_all_targets(_targets_list)
    foreach(target ${_targets_list})
        target_disable_static_analysis(${target})
    endforeach()
endif()

# Adding the src:
include_directories(src)
add_subdirectory(src)

# Adding the tests:
option(ENABLE_TESTING "Enable the tests" ON)
if(ENABLE_TESTING)
  enable_testing()
  message(STATUS "Building Tests.")
  add_subdirectory(tests)
endif()

option(ENABLE_FUZZING "Enable the fuzz tests" OFF)
if(ENABLE_FUZZING)
  message(STATUS "Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html")
  add_subdirectory(fuzz_tests)
endif()
