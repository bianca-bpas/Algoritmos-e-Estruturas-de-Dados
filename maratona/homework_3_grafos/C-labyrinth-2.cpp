#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Graph {
    vector<vector<char>> grid;
    vector<vector<bool>> visited;
    vector<vector<int>> distances;
    vector<vector<int>> parents;
    int n, m;
} Graph;

Graph* create_graph(int n, int m) {
    Graph* g = new Graph;
    g->n = n; g->m = m;
    g->grid = vector<vector<char>>(n, vector<char>(m));
    g->visited = vector<vector<bool>>(n, vector<bool>(m, false));
    g->distances = vector<vector<int>>(n, vector<int>(m, -1));
    g->parents = vector<vector<int>>(n, vector<int>(m, -1));
    return g;
}

bool inRange(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; 
string dir = "RLDU";

void BFS(Graph* g, pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    g->distances[start.first][start.second] = 0;
    g->visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == end.first && y == end.second) break;

        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];

            if (inRange(ax, ay, g->n, g->m) && !g->visited[ax][ay] &&
                (g->grid[ax][ay] == '.' || g->grid[ax][ay] == 'B')) {
                g->visited[ax][ay] = true;
                g->distances[ax][ay] = g->distances[x][y] + 1;
                g->parents[ax][ay] = i;
                q.push({ax, ay});
            }
        }
    }
}

string reconstruct_path(Graph* g, pair<int, int> start, pair<int, int> end) {
    string path;
    auto [x, y] = end;

    while (make_pair(x, y) != start) {
        int parent_direction = g->parents[x][y];
        if (parent_direction == -1) break;

        path += dir[parent_direction];
        x -= dx[parent_direction];
        y -= dy[parent_direction];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; 
    cin >> n >> m;

    Graph* g = create_graph(n, m);
    pair<int, int> start = {-1, -1}, end = {-1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g->grid[i][j];
            if (g->grid[i][j] == 'A') start = {i, j};
            if (g->grid[i][j] == 'B') end = {i, j};
        }
    }

    if (start.first == -1 || end.first == -1) {
        cout << "NO" << endl;
        return 0;
    }

    BFS(g, start, end);

    if (g->distances[end.first][end.second] != -1) {
        cout << "YES" << endl;
        cout << g->distances[end.first][end.second] << endl;
        cout << reconstruct_path(g, start, end) << endl;
    } else {
        cout << "NO" << endl;
    }

    delete g;

    return 0;
}
