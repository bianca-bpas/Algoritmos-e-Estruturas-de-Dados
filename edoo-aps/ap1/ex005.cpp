#include <iostream>
using namespace std;

int main(){
    string message = "I have learned something new again!";
    cout << message.length() << endl;

    string line1, line2;
    cin >> line1;
    cin >> line2;

    cout << line1 + '*' + line2 << endl;

    return 0;
}