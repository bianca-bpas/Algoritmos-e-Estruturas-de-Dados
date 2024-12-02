#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string S, s_right, s_left;
    cin >> S;
    int pos = 0;
    pos = S.find("ABC");

    while (pos != -1){
        s_right = S.substr(pos+3);
        s_left = S.substr(0, pos);

        S = s_left+s_right;
        
        pos = S.find("ABC");
    }

    cout << S << endl;

    return 0;
}