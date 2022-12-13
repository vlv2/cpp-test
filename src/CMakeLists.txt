set(FINNANCE_COMPILE_OPTIONS 
    -Wall -Werror -Wextra -Wpedantic -Wshadow -Wunused 
    
    -Wnon-virtual-dtor -Wcast-align -Woverloaded-virtual -Wconversion  -Wmisleading-indentation 
    -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast 
    -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough 
    
    -Wno-c++98-compat-pedantic -Wno-old-style-cast -Wno-sign-conversion
)
add_executable(main main.cpp)
target_compile_options(main PUBLIC ${FINNANCE_COMPILE_OPTIONS})
target_link_libraries(
    main 
    spdlog::spdlog fmt::fmt
)