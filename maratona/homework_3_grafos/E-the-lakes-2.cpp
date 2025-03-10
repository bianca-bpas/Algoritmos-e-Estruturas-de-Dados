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

    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n, m; cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cin >> grid[j][k];
            }
        }

        int maior_volume=0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] > 0){
                    int volume = BFS(i, j, grid);
                    maior_volume = max(maior_volume, volume);
                }
            }
        }

        cout << maior_volume << endl;
    }

    return 0;
}