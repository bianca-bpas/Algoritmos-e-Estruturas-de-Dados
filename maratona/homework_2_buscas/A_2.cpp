#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int n, x, temp; cin >> n >> x;
    vector<int> lista;

    for (int i = 0; i < n; i++){
        cin >> temp;
        lista.push_back(temp);
    }

    map<int, pair<int, int>> numeros(lista.begin(), lista.end());




    return 0;
}