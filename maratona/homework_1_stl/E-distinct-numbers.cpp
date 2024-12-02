#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int n, temp, distinto=0; cin >> n;
    set<int> lista;

    for (int i = 0; i < n; i++){
        cin >> temp;
        lista.insert(temp);
    }

    distinto = lista.size();

    cout << distinto << endl;

    return 0;
}