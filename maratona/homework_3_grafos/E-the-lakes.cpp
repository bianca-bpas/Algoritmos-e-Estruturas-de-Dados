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

void rec(int x, int y, vector<vector<int>>& grid, int& volume){
    volume += grid[x][y];
    grid[x][y] = 0;
    for (int d = 0; d < 4; d++){
        int ax = x + dx[d], ay = y + dy[d];
        if (!valid(ax, ay, grid)) {
            continue;
        }
        rec(ax, ay, grid, volume);
    }
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
        int x, y;
        int lastRow=0, lastColumn=0;
        int volume=0;

        bool found_water = false;
        
        for (int i = 0; i < n && !found_water; i++){
            for (int j = 0; j < m && !found_water; j++){
                if (grid[i][j] > 0){
                    x = i; y = j;
                    found_water = true;
                    break;
                }
            }
        }
        if (found_water){
            rec(x, y, grid, volume);
        } 

        cout << volume << endl;
    }

    return 0;
}