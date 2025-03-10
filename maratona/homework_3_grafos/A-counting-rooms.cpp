#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, 1, -1, 0};

bool valid(int x, int y, vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size(); 
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void rec(int x, int y, vector<vector<char>>& grid){
    grid[x][y] = '#';
    for (int d = 0; d < 4; d++){
        int ax = x + dx[d], ay = y + dy[d];
        if (!valid(ax, ay, grid)) {
            continue;
        }
        rec(ax, ay, grid);
    }
}

bool findFloor(vector<vector<char>>& grid, int& x, int& y, int& lastRow) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = lastRow; i < n; i++) {
        auto it = find(grid[i].begin(), grid[i].end(), '.');
        if (it != grid[i].end()) {
            x = i; y = distance(grid[i].begin(), it);
            lastRow = i;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    int x, y, room=0;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int lastRow=0;
    while (findFloor(grid, x, y, lastRow)){
        rec(x, y, grid);
        room++;
    }

    cout << room << endl;

    return 0;
}