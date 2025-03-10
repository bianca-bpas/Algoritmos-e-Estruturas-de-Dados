#include <iostream>
#include <ctime>
using namespace std;

int main() {
struct tm *ptr;
time_t sec;

time(&sec);
ptr = localtime(&sec);

cout << "Today is the " << ptr->tm_yday + 1
        << ". day of the year " << ptr->tm_year
        << endl;

}
