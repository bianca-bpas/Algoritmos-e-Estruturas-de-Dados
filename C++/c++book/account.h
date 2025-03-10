// account.h
// Class Account with set- and get-methods
// ----------------------------------------------------
#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account{
    private:
        string name;
        unsigned long nr; // unsigned para valores não-negativos, unsigned long para 0-10^19
        double state;
    
    public:
        Account(const string &a_name = "X", unsigned long a_nr = 1111111L, double a_state = 0.0){name = a_name; nr = a_nr; state = a_state;}
        ~Account(){}

        const string& getName() const {return name;}
        bool setName(const string &s){
            if (s.size() < 1){
                return false;
            }
            name = s;
            return true;
        }
        unsigned long getNr() const {return nr;}
        void setNr(unsigned long n){nr = n;}
        double getState() const {return state;}
        void setState(double x){state = x;}
        void display() const;

};
inline void Account::display() const{
    cout << fixed << setprecision(2)
        << "--------------------------------------\n"
        << "Account holder: " << name << '\n'
        << "Account number: " << nr << '\n'
        << "Account state: " << state << '\n'
        << "--------------------------------------\n"
        << endl;
}
#endif        //  _ACCOUNT_