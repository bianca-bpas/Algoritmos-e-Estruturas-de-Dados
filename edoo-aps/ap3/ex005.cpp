// Exercise 5
#include <iostream>
#include <string>
using namespace std;

namespace TOOL1 {
    inline double calculate(double num1, double num2) {
        return num1 + num2;
    }
}

namespace TOOL2 {
    inline double calculate(double num1, double num2) {
        return num1 * num2;
    }
}

int main() {
    double a = 5.0, b = 3.0;
    cout << "TOOL1::calculate(" << a << ", " << b << ") = " << TOOL1::calculate(a, b) << endl;
    cout << "TOOL2::calculate(" << a << ", " << b << ") = " << TOOL2::calculate(a, b) << endl;
    return 0;
}