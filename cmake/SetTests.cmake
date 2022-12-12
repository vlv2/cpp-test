if(BUILD_TESTS)
    enable_testing()

    message("")
    message(STATUS "Configuring googletest lib")
    set(INSTALL_GTEST OFF)
    add_subdirectory(dependencies/googletest)
    message("")
    
    add_subdirectory(tests)
endif(BUILD_TESTS)