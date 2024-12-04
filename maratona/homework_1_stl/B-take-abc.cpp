#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    deque<char> aux;

    aux.push_back(S[0]); 
    if (S.size() > 1){
        aux.push_back(S[1]);

        for (int i = 2; i < S.size(); i++){
            aux.push_back(S[i]);
            if (aux.size() >= 3){
                if (aux[aux.size()-3] == 'A' && aux[aux.size()-2] == 'B' && aux.back() == 'C'){
                    aux.pop_back(); aux.pop_back(); aux.pop_back();
                }
            }
        }
    }

    string res;
    for (int i = 0; i < aux.size(); i++){
        res.push_back(aux[i]);
    }

    cout << res << endl;

    return 0;
}