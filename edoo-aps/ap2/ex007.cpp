#include <iostream>
#include "myMacros.h"

int main() {
    int a = -5, b = 10;
    std::cout << "ABS(" << a << ") = " << ABS(a) << std::endl;
    std::cout << "MAX(" << a << ", " << b << ") = " << MAX(a, b) << std::endl;

    double x = -4.7, y = 3.2;
    std::cout << "ABS(" << x << ") = " << ABS(x) << std::endl;
    std::cout << "MAX(" << x << ", " << y << ") = " << MAX(x, y) << std::endl;

    return 0;
}
