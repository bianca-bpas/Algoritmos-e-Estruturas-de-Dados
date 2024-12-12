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

    // moedas.size() - lower_bound()
    return 0;
}