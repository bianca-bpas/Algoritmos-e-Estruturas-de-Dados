#include <iostream>
#include <vector>
#include <set>
using namespace std;

void findSubsets(vector<int>& arr, vector<vector<bool>>& dp, int i, int target, vector<int>& current, vector<vector<int>>& result);
bool subsetSumWithSubsets(vector<int>& arr, int target);

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 12;

    if (!subsetSumWithSubsets(arr, target)) {
        cout << "Nenhum subset com soma " << target << " encontrado." << endl;
    }

    return 0;
}

// Função para encontrar todos os subconjuntos que formam a soma-alvo
void findSubsets(vector<int>& arr, vector<vector<bool>>& dp, int i, int target, vector<int>& current, vector<vector<int>>& result) {
    // Caso base: se a soma for 0, adiciona o subconjunto atual ao resultado
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // Se não houver mais elementos ou a soma não for possível, retorna
    if (i == 0 || target < 0) {
        return;
    }

    // Ignorar o elemento atual (não incluir no subconjunto)
    if (dp[i - 1][target]) {
        findSubsets(arr, dp, i - 1, target, current, result);
    }

    // Incluir o elemento atual no subconjunto, se possível
    if (target >= arr[i - 1] && dp[i - 1][target - arr[i - 1]]) {
        current.push_back(arr[i - 1]);
        findSubsets(arr, dp, i - 1, target - arr[i - 1], current, result);
        current.pop_back(); // Backtracking
    }
}

bool subsetSumWithSubsets(vector<int>& arr, int target) {
    int n = arr.size();
    // Criando a matriz dp[n+1][target+1]
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base do DP
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // Soma 0 é sempre possível
    }

    // Preenchendo a matriz
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j < arr[i - 1]) { // Não podemos incluir arr[i-1]
                dp[i][j] = dp[i - 1][j];
            } else { // Podemos incluir ou não incluir arr[i-1]
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    // Verifica se existe um subconjunto com soma target
    if (!dp[n][target]) {
        return false;
    }

    // Encontrando todos os subconjuntos
    vector<int> current;
    vector<vector<int>> result;
    findSubsets(arr, dp, n, target, current, result);

    // Imprime os subconjuntos
    cout << "Subconjuntos que somam " << target << ":\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return true;
}