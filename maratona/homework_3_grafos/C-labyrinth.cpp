#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Graph {
    vector<vector<char>> grid; // Matriz do grid (labirinto)
    vector<vector<bool>> visited; // Matriz de visitados
    int n, m; // Dimensões do grid
    vector<vector<int>> dist; // Distâncias
    vector<vector<string>> movements; // Movimentos para cada célula
} Graph;

bool inRange(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {0, 0, 1, -1}; // Movimentos: Direita, Esquerda, Baixo, Cima
int dy[] = {1, -1, 0, 0}; 

string dir[] = {"R", "L", "D", "U"}; // Direções correspondentes

void bfs(Graph &g, pair<int, int> start, pair<int, int> end) {
    // Inicializando as matrizes
    queue<pair<int, int>> q;
    q.push(start);
    g.dist[start.first][start.second] = 0;
    g.visited[start.first][start.second] = true;

    // BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Se chegamos ao destino, podemos parar
        if (x == end.first && y == end.second) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];

            if (inRange(ax, ay, g.n, g.m) && !g.visited[ax][ay] && g.grid[ax][ay] == '.') {
                g.visited[ax][ay] = true;
                g.dist[ax][ay] = g.dist[x][y] + 1; // Atualiza a distância
                g.movements[ax][ay] = g.movements[x][y] + dir[i]; // Registra o movimento
                q.push({ax, ay});
            }
        }
    }
}

void print_path(Graph &g, pair<int, int> end) {
    // Imprimir o caminho até o destino
    cout << "Distância: " << g.dist[end.first][end.second] << endl;
    cout << "Movimentos: " << g.movements[end.first][end.second] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Graph g;
    g.n = n;
    g.m = m;
    g.grid.resize(n, vector<char>(m));
    g.visited.resize(n, vector<bool>(m, false));
    g.dist.resize(n, vector<int>(m, -1)); // Inicializa as distâncias com -1 (não visitado)
    g.movements.resize(n, vector<string>(m, "")); // Inicializa os movimentos com string vazia

    pair<int, int> start, end;

    // Lê o grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g.grid[i][j];
            if (g.grid[i][j] == 'S') start = {i, j}; // Posição de partida
            if (g.grid[i][j] == 'E') end = {i, j}; // Posição de chegada
        }
    }

    // Realiza a busca em largura
    bfs(g, start, end);

    // Imprime o resultado
    if (g.dist[end.first][end.second] != -1) {
        print_path(g, end);
    } else {
        cout << "Impossível chegar ao destino." << endl;
    }

    return 0;
}
