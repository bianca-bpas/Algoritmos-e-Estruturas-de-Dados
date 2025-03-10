#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int calcularSaltos(vector<int>& next, int start, int N) {
    int atual = start;
    int saltos = 0;
    vector<bool> visitado(N, false);

    while (atual < N-1) {
        // Se já visitou este ponto, ciclo detectado
        if (visitado[atual]) return -1;
        
        visitado[atual] = true;

        // Próximo salto
        atual = next[atual];
        
        // Verifica se ultrapassou o array
        if (atual >= N) return -1;
        
        saltos++;
    }

    return saltos;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("jumping.in", "r", stdin);

    int T; cin >> T;
    for (int caso = 0; caso < T; caso++){
        int N; cin >> N;
        vector<int> d(N), next(N);
        
        for (int i = 0; i < N; i++){
            cin >> d[i];
            next[i] = i + d[i];
        }

        for (int i = 0; i < N; i++){
            cout << calcularSaltos(next, i, N) << endl;
        }
    }


    fclose(stdin);
    return 0;
}