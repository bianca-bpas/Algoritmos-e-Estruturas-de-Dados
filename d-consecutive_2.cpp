#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int N, Q, count, l, r; cin >> N >> Q;
    string S = " ", temp;
    cin >> temp;
    S += temp;

    for (int q = 0; q < Q; q++){
        count = 0;
        cin >> l >> r;

        for (int i = l+1; i < r+1; i++){
            if (S[i] == S[i-1]){
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}