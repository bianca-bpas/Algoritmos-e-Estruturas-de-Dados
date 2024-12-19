#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void BFS(int i, vector<int>& next, vector<int>& saltos, int N){
    int salto = 0;
    queue<int> q;
    q.push(i);

    while (!q.empty()){
        int c = q.front();
        q.pop();
        if (c == N-1){
            break;
        } else if (next[c] < N){
            q.push(next[c]);
            salto++;
        } else if (next[c] > N-1){
            salto = -1; 
            break;
        }
    }
    saltos[i] = salto;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("jumping.in", "r", stdin);

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

    //fclose(stdin);
    return 0;
}