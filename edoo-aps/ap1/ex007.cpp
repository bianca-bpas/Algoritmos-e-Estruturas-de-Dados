#include <iostream>
using namespace std;

int main() {
    
    cout << "Hello world!" << endl;
    
    int n = 10;
    n += n;

    cout << "Value of n: " << n << endl;

    int array[10];
    for (int i=0; i<10; i++) {
        array[i] = 10+i;
    }

    int *array2 = new int[10];
    for (int i=0; i<10; i++) {
        array2[i] = 10+i;
    }

    return 0;
}
