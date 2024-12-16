// scope.cpp
// Accessing objects with equal names
// ---------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
int var = 0;
namespace Special { int var = 100; }
int main() {
    int var = 10;
    cout << setw(10) << var;
        {
    int var = 20;
    cout << setw(10) << var << endl;
    {
    ++var;
    cout << setw(10) << var;
    cout << setw(10) << ++ ::var;
    cout << setw(10) << Special::var * 2 << endl;
    }
    cout << setw(10) << var - ::var;
    }
    cout << setw(10) << var << endl;
    return 0;
}
