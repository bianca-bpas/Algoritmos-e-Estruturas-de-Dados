#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    int count=0;
    for (int i = 1; i <= 12; i++){
        cin >> S;
        if (S.length() == i){
            count++;
        }
    }

    cout << count << '\n';
    
    return 0;
}