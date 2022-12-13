add_executable(
  calculator_test
  calculator_test.cpp
)
target_link_libraries(
  calculator_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(calculator_test)