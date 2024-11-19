#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double v1 = 0.123456, v2 = 23.987,  v3 = -123.456;

    cout << left << setw(15) << v1 << endl;
    cout << right << setw(12) << fixed << setprecision(2) << v2 << endl;
    cout << setw(10) << scientific << setprecision(4) << v3 << endl;

    return 0;
}