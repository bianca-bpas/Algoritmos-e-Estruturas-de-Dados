#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

int main() {
    int n, idx1=-1, idx2=-1;
    long long x, temp; 
    cin >> n >> x;
    map<int, pair<int, int>> num;
    vector<int> lista;
    
    for (int i = 0; i < n; i++){
        cin >> temp;
        lista.push_back(temp);
        num[temp] = make_pair(i, x-temp);
    }
    
    for (auto [chave, valor] : num){
        auto target = find(lista.begin(), lista.end(), valor.second);
        int indice = distance(lista.begin(), target);
        if (*target == valor.second && indice != valor.first){
            idx1 = valor.first;
            idx2 = num[*target].first;
            
            cout << idx1 << " " << idx2 << endl;
            break;
        } else {
            target = find(target, lista.end(), valor.second);
            if (* target == valor.second){
                idx1 = valor.first;
                idx2 = num[*target].first;
                cout << idx1 << " " << idx2 << endl;
                break;
            }
        }
    }
    if (idx1 == -1 && idx2 == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}