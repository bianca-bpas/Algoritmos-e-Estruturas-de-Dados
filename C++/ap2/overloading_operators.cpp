#include "DayTime.h"
#include <iostream>
using namespace std;

int main(){
    DayTime depart1(11, 11, 11), depart2(12, 0, 0);
    if (depart1 < depart2){
        cout << "\nThe 1st plane takes off earlier!" << endl;
    }

    return 0;
}

