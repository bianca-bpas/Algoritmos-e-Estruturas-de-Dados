#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;

void Date::init(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
}

void Date::init() {
    time_t sec;
    time(&sec);
    struct tm* ptr = localtime(&sec);
    this->month = ptr->tm_mon + 1;
    this->day = ptr->tm_mday;
    this->year = ptr->tm_year + 1900;
}

void Date::print() const {
    cout << month << "-" << day << "-" << year << endl;
}
