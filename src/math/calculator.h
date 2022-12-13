#ifndef BASE_REPO_MATH_CALCULATOR_H
#define BASE_REPO_MATH_CALCULATOR_H

#include <cstdlib>

template <typename T, typename U>
class Calculator {
public:
    decltype(auto) Sum(const T& a, const U& b) {
        return a + b;
    }

    decltype(auto) Sub(const T& a, const U& b) {
        return a - b;
    }

    decltype(auto) Mul(const T& a, const U& b) {
        return a * b;
    }

    decltype(auto) Div(const T& a, const U& b) {
        if (b == 0) {
            exit(EXIT_FAILURE);
        }
        return a / b;
    }
};

#endif /* BASE_REPO_MATH_CALCULATOR_H */
