#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int N, Q, contagem, l, r; cin >> N >> Q;
    string S; cin >> S;
    vector<string> letras = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    for (int q = 0; q < Q; q++){
        contagem = 0;
        cin >> l >> r;

        for (auto i : letras){
            const string letra = i+i;
            contagem += count(S.begin(), S.end(), letra);
        }

        cout << contagem << endl;

        
    }

    return 0;
}