#include <bits/stdc++.h>
using namespace std;

long long fatorial(long long n){
    long long f = 1;
    while (n > 0){
        f *= n;
        n--;
    }
    return f;
}

int main(){
    long long n, zeros=0;
    long long fat;
    cin >> n;
    fat = fatorial(n);
    string temp = to_string(fat);

    for (long long i = temp.length()-1; i >= 0; i--){
        if (temp[i] == '0'){
            zeros++;
        } else {
            break;
        }
    }

    cout << zeros << endl;

    return 0;
}