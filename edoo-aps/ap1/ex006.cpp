#include <iostream>
using namespace std;

int main(){
    int n, sum=0, avg, temp; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        sum += temp;
    }

    avg = sum / n;
    cout << "Average = " << avg << endl;

    return 0;
}