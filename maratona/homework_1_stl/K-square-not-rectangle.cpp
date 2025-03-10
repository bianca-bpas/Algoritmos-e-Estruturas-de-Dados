#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, h; cin >> N;
    set<long long> H;
    for (long long i = 0; i < N; i++){
        cin >> h;
        H.insert(h);
    }    

    vector<long long> alturas(H.begin(), H.end());
    long long idx = floor((alturas.size()-1)/2);
    long long mediana = alturas[idx];

    cout << mediana << endl;

    return 0;
}