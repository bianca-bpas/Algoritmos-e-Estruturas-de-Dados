#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, 1, -1, 0};

bool valid(int x, int y, vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size(); 
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] > 0;
}

int BFS(int x, int y, vector<vector<int>>& grid){
    int volume = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    volume += grid[x][y];
    grid[x][y] = 0;

    while (!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++){
            int ax = cx + dx[d], ay = cy + dy[d];
            if (valid(ax, ay, grid)){
                q.push({ax, ay});
                volume += grid[ax][ay];
                grid[ax][ay] = 0;
            }
        }
    }
    return volume;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;
    int x_casa, y_casa; cin >> x_casa >> y_casa;
    int x_armazem, y_armazem; cin >> x_armazem >> y_armazem;
    vector<vector<int>> grid(N, vector<int>(M));
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    int menor_distancia=0;
    menor_distancia = min(menor_distancia, distancia);
            


    int distancia = BFS(i, j, grid);
    cout << menor_distancia << endl;


    return 0;
}