// Exercise 1
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "As time by ...";
    string s2 = "goes";

    cout << "Initial string: " << s1 << endl;

    // Find position of "by" and insert s2
    size_t pos = s1.find("by");
    if (pos != string::npos) {
        s1.insert(pos, s2 + " ");
    }
    cout << "After insertion: " << s1 << endl;

    // Erase remainder after "by"
    pos = s1.find("by");
    if (pos != string::npos) {
        s1.erase(pos + 2);
    }
    cout << "After erasing remainder: " << s1 << endl;

    // Replace "time" with "Bill"
    pos = s1.find("time");
    if (pos != string::npos) {
        s1.replace(pos, 4, "Bill");
    }
    cout << "After replacement: " << s1 << endl;

    return 0;
}