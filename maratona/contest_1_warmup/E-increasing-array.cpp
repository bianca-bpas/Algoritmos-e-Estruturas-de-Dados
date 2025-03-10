#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> X(n);
    for (ll i = 0; i < n; i++){
        cin >> X[i];
    }

    ll moves = 0;
    for (ll i = 1; i < n; i++){
        if (X[i] < X[i-1]){
            ll res = X[i-1] - X[i];
            X[i] += res;
            moves += res;
        }
    }
    
    cout << moves << '\n';

    return 0;
}