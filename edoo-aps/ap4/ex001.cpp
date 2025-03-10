#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    Date date1, date2;

    date1.init();
    cout << "Current date: ";
    date1.print();

    date2.init(12, 25, 2024);
    cout << "Custom date: ";
    date2.print();

    return 0;
}
