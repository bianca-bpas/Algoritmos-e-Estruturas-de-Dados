#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double valor1 = 0.123456, valor2 = 23.987, valor3 = 327823788989;
    
    cout.setf(ios::fixed);
    // Alinhar ao centro
    cout << right << setw(10) << " " << setw(10) << left << valor1 << endl;
    cout << right << setw(10) << " " << setw(10) << left << valor2 << endl;
    cout << right << setw(10) << " " << setw(10) << left << valor3 << endl;

    
    return 0;
}