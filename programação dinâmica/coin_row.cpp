#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Utilizando uma abordagem bottom-up, implemente um algoritmo de programação dinâmica para resolver o problema da fila de moedas: dada uma fila de n moedas com valores v1, v2, …, vn-1 e vn, coletar a maior quantia, sem escolher duas moedas adjacentes.
 */

int CoinRow(vector<int> C){
    int n = C.size();
    vector<int> F(n, -1);
    F[0] = 0;
    F[1] = C[1];
    for (int i = 2; i <= n; i++){
        F[i] = max(C[i] + F[i-2], F[i-1]);
    }
    return F[n];
}

int main() {
    int c;
    cout << "Digite o número de casos: ";
    cin >> c;

    for (int i = 0; i < c; i++) {
        int n;
        cout << "Digite a quantidade de moedas: ";
        cin >> n;

        vector<int> coins(n+1);
        coins[0] = -1;
        cout << "Digite os valores das moedas: ";
        for (int j = 1; j <= n; j++) {
            cin >> coins[j];
        }

        int money = CoinRow(coins);
        cout << money << endl;
    }

    return 0;
}
