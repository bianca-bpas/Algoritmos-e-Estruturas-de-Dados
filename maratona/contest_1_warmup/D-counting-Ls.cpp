#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    char s;
    vector<vector<char>> S(N, vector<char>(N));
    vector<int> linhas(N, 0), colunas(N, 0);
    for (int i = 0; i < N; i++){ // linha
        for (int j = 0; j < N; j++){ // coluna
            cin >> s;
            if (s == 'o'){
                linhas[i]++;
                colunas[j]++;            
            }
            S[i][j] = s;
        }
    }

    int res=0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (S[i][j] == 'o'){
                int linha = linhas[i]-1, coluna = colunas[j]-1;
                res += (linha * coluna);
            }
        }
    }
    cout << res << '\n';

    return 0;
}