include(GoogleTest)

add_executable(
  calculator_test
  calculator_test.cpp
)
target_link_libraries(
  calculator_test
  GTest::gtest_main
)

gtest_discover_tests(calculator_test)