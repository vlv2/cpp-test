#include <gtest/gtest.h>

#include "math/calculator.h"

// NOLINTNEXTLINE
TEST(SumTest, SumTwoIntegers) {
    Calculator<int, int> calc;
    EXPECT_EQ(calc.Sum(1, 1), 2);
}

// NOLINTNEXTLINE
TEST(SumTest, SumIntegerAndFloat) {
    Calculator<int, float> calc;
    EXPECT_EQ(calc.Sum(1, 1.0f), 2.0f);
}

// NOLINTNEXTLINE
TEST(SubTest, SubIntegerAndFloat) {
    Calculator<float, int> calc;
    EXPECT_EQ(calc.Sub(1.0f, 1), 0.0f);
}

// NOLINTNEXTLINE
TEST(SubTest, SubFloatAndFloat) {
    Calculator<float, float> calc;
    EXPECT_EQ(calc.Sub(1.0f, 1.0f), 0.0f);
}

// NOLINTNEXTLINE
TEST(MulTest, MulFloatAndFloat) {
    Calculator<float, float> calc;
    EXPECT_EQ(calc.Mul(1.5f, 1.5f), 2.25f);
}

// NOLINTNEXTLINE
TEST(DivTest, DivFloatAndFloat) {
    Calculator<float, float> calc;
    EXPECT_EQ(calc.Div(1.5f, 0.2f), 7.5f);
}

// NOLINTNEXTLINE
TEST(DivTest, DivByZero) {
    Calculator<float, float> calc;
    // NOLINTNEXTLINE
    EXPECT_EXIT(calc.Div(1.5f, 0.0f), testing::ExitedWithCode(EXIT_FAILURE), "");
}
