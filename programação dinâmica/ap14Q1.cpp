#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Utilizando uma abordagem bottom-up, implemente um algoritmo de programação dinâmica para resolver o problema da fila de moedas: dada uma fila de n moedas com valores v1, v2, …, vn-1 e vn, coletar a maior quantia, sem escolher duas moedas adjacentes.
 */

void solve(vector<int>& coins) {
    int n = coins.size();
    if (n == 0) {
        cout << "0\n" << endl;
        return;
    }
    if (n == 1) {
        cout << coins[0] << endl;
        cout << coins[0] << endl;
        return;
    }

    // dp[i] will be the max value we can collect from the first i coins
    vector<int> dp(n, 0);
    vector<int> chosen(n, 0);
    
    dp[0] = coins[0];
    chosen[0] = 1; // coin 0 is chosen

    if (coins[1] > coins[0]) {
        dp[1] = coins[1];
        chosen[1] = 1; // coin 1 is chosen
    } else {
        dp[1] = coins[0];
    }

    for (int i = 2; i < n; ++i) {
        if (dp[i-1] > dp[i-2] + coins[i]) {
            dp[i] = dp[i-1];
        } else {
            dp[i] = dp[i-2] + coins[i];
            chosen[i] = 1; // coin i is chosen
        }
    }

    cout << dp[n-1] << endl;

    // To find the coins that were chosen
    vector<int> result;
    for (int i = n-1; i >= 0;) {
        if (chosen[i] == 1) {
            result.push_back(coins[i]);
            i -= 2;
        } else {
            i--;
        }
    }
    reverse(result.begin(), result.end());
    
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;
}

int main() {
    int c;
    cout << "Digite o número de casos: ";
    cin >> c;

    for (int i = 0; i < c; ++i) {
        int n;
        cout << "Digite a quantidade de moedas: ";
        cin >> n;

        vector<int> coins(n);
        cout << "Digite os valores das moedas: ";
        for (int j = 0; j < n; ++j) {
            cin >> coins[j];
        }

        solve(coins);
    }

    return 0;
}
