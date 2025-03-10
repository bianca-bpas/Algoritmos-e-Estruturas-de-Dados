#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    int A=0;
    for (int i = 1; i < S.length(); i++){
        if (S[i] != '|'){
            A++;
        } else {
            cout << A << " ";
            A=0;
        }
    }
    cout << '\n';

    return 0;
}