// textPtr.cpp
// Using arrays of char and pointers to char
// -----------------------------------------------------
#include <iostream>
using namespace std;

int main(){
    cout << "Demonstrating arrays of char "
         << " and pointers to char.\n"
         << endl;
        
    char text[] = "Good morning!", name[] = "Bill!";

    char *cPtr = "Hello ";

    cout << cPtr << name << '\n' << text << endl;

    cout << text + 6 << endl;

    cPtr = name;

    cout << "This is the " << *cPtr << " of " << cPtr << endl;

    *cPtr = 'k';
    cout << "Bill can not " << cPtr << "!\n" << endl;

    return 0;
}