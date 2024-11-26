#include "date.h"
#include <iostream>
#include <ctime>
using namespace std;

void Date::init(int a_day, int a_month, int a_year){
    day = a_day; month = a_month; year = a_year;
}

void Date::init(){
    time_t time(time_t *ptrSec);
    struct tm *localtime(const time_t *ptrSec);
}

void Date::print(){
    cout << month << "-" << day << "-" << year << endl;
}