#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, moves=0;
    long long temp;
    cin >> n;

    vector<long long> x;
    x.push_back(-1);
    cin >> temp;
    x.push_back(temp);
    for (long long i = 2; i <= n; i++){
        cin >> temp;
        x.push_back(temp);
        if (x.at(i) < x.at(i-1)){
            long long res = x.at(i-1) - x.at(i);
            x.at(i) += res;
            moves += res;
        }
    }
    
    cout << moves << endl;

    return 0;
}