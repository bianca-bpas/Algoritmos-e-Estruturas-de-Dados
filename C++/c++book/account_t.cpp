// account_t.cpp
// Uses objects of class Account.
// ---------------------------------------------------
#include "Account.h"

int main(){
    Account current1, current2;

    current1.init("Cheers, Mary", 1234567, -1200.99);
    current1.display();
    // current1.balance += 100; // Error: private member

    current2 = current1; // ok: Assignment of objects is possible.
    current2.display(); // ok

    // New values for current2
    current2.init("Jones, Tom", 3512347, 199.40);
    current2.display();

    // To use a reference:
    Account& mtr = current1; // mtr is an alias name for object current1.
    mtr.display(); // mtr can be used just as object current1.
    return 0;
}