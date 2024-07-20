#include <iostream>
#include <vector>
using namespace std;

/* O problema das N rainhas consiste em encontrar um posicionamento para N rainhas em um tabuleiro de dimensões N x N, de forma que nenhuma delas consiga, de acordo com as regras do xadrez, se atacar. Dado N, encontre todas as soluções possíveis para o problema das N rainhas para esse tabuleiro. */

bool valid(vector<vector<int>>& M, int row, int col) {
    int n = M.size();
    
    // Verifica a coluna
    for (int i = 0; i < row; i++) {
        if (M[i][col] == 1) {
            return false;
        }
    }
    
    // Verifica a diagonal principal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (M[i][j] == 1) {
            return false;
        }
    }
    
    // Verifica a diagonal secundária
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (M[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

void qns(int l, vector<vector<int>>& M, vector<vector<vector<int>>>& solutions) {
    int n = M.size();
    if (l == n) {
        solutions.push_back(M);
    } else {
        for (int i = 0; i < n; i++) {
            if (valid(M, l, i)) {
                M[l][i] = 1;
                qns(l + 1, M, solutions);
                M[l][i] = 0;
            }
        }
    }
}

int main() {
    int n;
    cout << "Digite o valor de n: ";
    cin >> n;
    
    vector<vector<int>> M(n, vector<int>(n, 0));
    vector<vector<vector<int>>> solutions;
    
    qns(0, M, solutions);
    
    cout << solutions.size() << endl;
    cout << endl;
    
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Sol. " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << solutions[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}
