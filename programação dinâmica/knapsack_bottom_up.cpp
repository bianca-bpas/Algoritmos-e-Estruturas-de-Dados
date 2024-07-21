#include <iostream>
#include <vector>
#include <cstring> // for memset
using namespace std;

/* Utilizando uma abordagem top-down, implemente um algoritmo de programação dinâmica para resolver o problema da mochila. Dada uma mochila com capacidade W e n itens com pesos w1, w2, …, wn-1 e wn e valores v1, v2, …, vn-1 e vn, encontre o subconjunto de itens mais valioso que cabe na mochila.
 */

// Função auxiliar para impressão da matriz
void printMatrix(vector<vector<int>> F) {
    for (int i = 0; i < F.size(); i++){
        for (int j = 0; j < F[0].size(); j++){
            if (i == 0 || j == 0){
                cout << "0 ";
            } else {
                cout << F[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int Knapsack(int n, int W, vector<int> w, vector<int> v, vector<vector<int>> &F) {
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= W; j++){
            if (i == 0 || j == 0){
                F[i][j] = 0;
            } else if (w[i] <= j){
                F[i][j] = max(F[i-1][j], v[i]+F[i-1][j-w[i]]);
            } else {
                F[i][j] = F[i-1][j];
            }
        }
    }
    return F[n][W];
}

int main() {
    int n, W;
    cout << "Digite o número de itens e a capacidade da mochila: ";
    cin >> n >> W;

    vector<int> weights(n+1);
    vector<int> values(n+1);
    
    cout << "Digite os pesos e valores dos itens:\n";
    for (int i = 1; i <= n; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> F(n+1, vector<int>(W+1, -1));

    int res = Knapsack(n, W, weights, values, F);
    cout << "Valor máximo que pode ser colocado na mochila: " << res << endl;
    printMatrix(F);

    return 0;
}
