#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int N, vector<int>& d, vector<int>& saltos) {
    queue<int> q;
    vector<bool> visited(N, false);

    q.push(0); // Começa no índice 0
    saltos[0] = 0;
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int max_jump = min(N - 1, current + d[current]);

        for (int next = current + 1; next <= max_jump; ++next) {
            if (!visited[next]) {
                visited[next] = true;
                saltos[next] = saltos[current] + 1;
                q.push(next);
            }
        }
    }

    // Atualiza índices não alcançáveis
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            saltos[i] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> d(N);
        for (int i = 0; i < N; ++i) {
            cin >> d[i];
        }

        vector<int> saltos(N, -1);
        BFS(N, d, saltos);

        for (int i = 0; i < N; ++i) {
            cout << saltos[i] << endl;
        }
    }

    return 0;
}
