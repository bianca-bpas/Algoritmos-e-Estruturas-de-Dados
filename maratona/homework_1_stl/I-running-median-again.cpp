#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long casos, n=-2, mediana, idx; cin >> casos;
    multiset<long long> lista;

    for (long long caso = 0; caso < casos; caso++){
        while (n != 0){
            cin >> n;
            if (n > 0){
                lista.insert(n);
            } else if (n == -1){
                if (!lista.empty()){
                    vector<long long> l(lista.begin(), lista.end());
                    idx = floor(((l.size()-1)/2));
                    mediana = (l[idx]);
                    l.erase(l.begin()+idx);
                    cout << mediana << endl;
                    multiset<long long> temp(l.begin(), l.end());
                    lista = temp;
                }
            }

        }
    }

    return 0;
}