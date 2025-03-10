#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

int main() {
    int n, idx1=-1, idx2=-1;
    long long x, temp; 
    cin >> n >> x;
    multimap<int, pair<int, int>> num;
    vector<int> lista;
    
    for (int i = 0; i < n; i++){
        cin >> temp;
        lista.push_back(temp);
        num.insert(pair{temp, pair{i, x-temp}});
    }
    
    if (n > 1){
        for (auto [chave, valor] : num){
            vector<int>::iterator target = find(lista.begin(), lista.end(), valor.second);
            int indice = distance(lista.begin(), target);
            if (indice < num.size() && indice >= 0){
                if (*target == valor.second && indice != valor.first){
                    idx1 = valor.first;
                    auto range = num.equal_range(*target);
                    for (auto it = range.first; it != range.second; ++it) {
                        idx2 = it->second.first;
                    }          
                    cout << ++idx1 << " " << ++idx2 << endl;
                    break;
                } else {
                    target = find(target, lista.end(), valor.second);
                    if (*target == valor.second){
                        idx1 = valor.first;
                        auto range = num.equal_range(*target);
                        for (auto it = range.first; it != range.second; ++it) {
                            idx2 = it->second.first;
                        }    
                        cout << ++idx1 << " " << ++idx2 << endl;
                        break;
                    }
                }
            }
        }
    }
    if (idx1 == -1 && idx2 == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}