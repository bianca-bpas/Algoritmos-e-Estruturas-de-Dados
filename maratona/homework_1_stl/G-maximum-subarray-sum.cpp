#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x; cin >> n;
    vector<long long> numbers;

    for (int i = 0; i < n; i++){
        cin >> x;
        numbers.push_back(x);
    }

    long long res, prefixSum;
    res = prefixSum = numbers[0];

    for (int i = 1; i < n; i++){
        prefixSum = max(numbers[i], numbers[i] + prefixSum);
        res = max(res, prefixSum);
    }

    cout << res << endl;

    return 0;
}