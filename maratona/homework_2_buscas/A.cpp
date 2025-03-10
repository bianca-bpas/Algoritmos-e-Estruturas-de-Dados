#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, temp, target; cin >> n; cin >> x;
    vector<int> numeros;
    
    for (int i = 0; i < n; i++){
        cin >> temp;
        numeros.push_back(temp);
    }

    vector<int> numeros_ordenados(numeros.begin(), numeros.end());
    sort(numeros_ordenados.begin(), numeros_ordenados.end());
    for (int i = 0 ; i < n; i++){
        target = x - numeros_ordenados[i];
        auto t = lower_bound(numeros_ordenados.begin(), numeros_ordenados.end(), target);

        if (t != numeros_ordenados.end()){
            int idx = distance(numeros.begin(), t);
            cout << i << " " << idx << endl;
        } else {
            cout << "IMPOSSIBLE";
        }
    }

    return 0;
}
