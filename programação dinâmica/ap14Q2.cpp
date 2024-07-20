#include <iostream>
#include <vector>
#include <cstring> // for memset
using namespace std;

/* Utilizando uma abordagem top-down, implemente um algoritmo de programação dinâmica para resolver o problema da mochila. Dada uma mochila com capacidade W e n itens com pesos w1, w2, …, wn-1 e wn e valores v1, v2, …, vn-1 e vn, encontre o subconjunto de itens mais valioso que cabe na mochila.
 */

// Função auxiliar para impressão da matriz
void printMatrix(const vector<vector<int>>& dp) {
    for (const auto& row : dp) {
        for (int value : row) {
            if (value == -1) {
                cout << "-1 ";
            } else {
                cout << value << " ";
            }
        }
        cout << endl;
    }
}

int knapsack(int i, int W, vector<int>& weights, vector<int>& values, vector<vector<int>>& dp) {
    if (i == 0 || W == 0) {
        return 0;
    }
    
    if (dp[i][W] != -1) {
        return dp[i][W];
    }
    
    if (weights[i-1] > W) {
        dp[i][W] = knapsack(i-1, W, weights, values, dp);
    } else {
        dp[i][W] = max(
            knapsack(i-1, W, weights, values, dp), 
            values[i-1] + knapsack(i-1, W-weights[i-1], weights, values, dp)
        );
    }
    
    return dp[i][W];
}

int main() {
    int n, W;
    cout << "Digite o número de itens e a capacidade da mochila: ";
    cin >> n >> W;

    vector<int> weights(n);
    vector<int> values(n);
    
    cout << "Digite os pesos e valores dos itens:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    // Inicializa a matriz dp com -1
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    // Preenche a primeira linha e a primeira coluna com 0s
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int w = 0; w <= W; ++w) {
        dp[0][w] = 0;
    }

    // Resolve o problema da mochila
    knapsack(n, W, weights, values, dp);
    
    // Imprime a matriz dp
    printMatrix(dp);

    return 0;
}
