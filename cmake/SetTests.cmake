if(BUILD_TESTS)
    enable_testing()
    
    set(INSTALL_GTEST OFF)
    add_subdirectory(${THIRD_PARTY_PATH}/googletest)
    include_directories(src)
    add_subdirectory(tests)
endif(BUILD_TESTS)