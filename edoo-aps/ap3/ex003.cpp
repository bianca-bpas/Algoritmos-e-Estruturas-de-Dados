// Exercise 3
#include <iostream>
#include <string>
using namespace std;

long double factorial_loop(unsigned int n) {
    long double result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long double factorial_recursive(unsigned int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial_recursive(n - 1);
}
int main(){
    cout << "Factorials using loop:\n";
    for (unsigned int i = 0; i <= 20; ++i) {
        cout << i << "! = " << factorial_loop(i) << endl;
    }

    cout << "\nFactorials using recursion:\n";
    for (unsigned int i = 0; i <= 20; ++i) {
        cout << i << "! = " << factorial_recursive(i) << endl;
    }

    return 0;
}