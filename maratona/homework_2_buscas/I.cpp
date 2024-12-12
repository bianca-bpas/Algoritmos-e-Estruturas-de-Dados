#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_lojas, num_days; cin >> num_lojas;
    vector<long long> moedas;
    vector<int> precos_lojas;
    for (int precos = 0; precos < num_lojas; precos++){
        cin >> precos_lojas[precos];
    }

    cin >> num_days;
    for (int day = 0; day < num_days; day++){
        cin >> moedas[day];
    }

    for (int moeda = 0; moeda < moedas.size(); moeda++){
        auto maior_que_moeda = upper_bound(precos_lojas.begin(), precos_lojas.end(), moedas[moeda]);
        int num_possibles;

        if (maior_que_moeda != precos_lojas.end()){
            num_possibles = precos_lojas.size() - *maior_que_moeda;
        } else {
            num_possibles = 0;
        }

        cout << num_possibles << endl;
    }

    return 0;
}
