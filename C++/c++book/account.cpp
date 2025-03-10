// account.cpp
// Defines methods init() and display().
// ---------------------------------------------------
#include "account.h" // Class definition
#include <iostream>
#include <iomanip>
using namespace std;

Account::Account( const string& a_name,unsigned long a_nr, double a_state){
    nr = a_nr;
    name = a_name;
    state = a_state;
}

Account::Account( const string& a_name ){
    name = a_name;
    nr = 1111111; state = 0.0;
}

// The method init() copies the given arguments into the private members of the class.
bool Account::init(const string& i_name, unsigned long i_nr, double i_balance){
    if( i_name.size() < 1){ // No empty name
        return false;
    }
    name = i_name;
    nr = i_nr;
    //balance = i_balance;
    return true;
}

// The method display() outputs private data.
void Account::display(){
    cout << fixed << setprecision(2)
    << "--------------------------------------\n"
    << "Account holder: " << name << '\n'
    << "Account number: " << nr << '\n'
    //<< "Account balance: " << balance << '\n'
    << "--------------------------------------\n"
    << endl;
}