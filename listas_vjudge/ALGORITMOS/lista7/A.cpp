#include <iostream>
#include <vector>
using namespace std;

bool valid(const vector<vector<int>> &M, int row, int col, int n) {
    if (row < 0 || col < 0 || row >= n || col >= n) {
        return false;
    }
    if (M[row][col] == -1 || M[row][col] == 1) {
        return false;
    }
    return true;
}

void knight(int x, int y, vector<vector<int>> &M, int &min_unvisited, int visited) {
    if (!valid(M, x, y, 10)) {
        return;
    }

    M[x][y] = 1;
    visited++;

    vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (auto move : moves) {
        int newX = x + move.first;
        int newY = y + move.second;
        if (valid(M, newX, newY, 10)) {
            knight(newX, newY, M, min_unvisited, visited);
        }
    }

    int unvisited = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (M[i][j] == 0) {
                unvisited++;
            }
        }
    }
    min_unvisited = min(min_unvisited, unvisited);

    M[x][y] = 0;
}

int main() {
    int n; // número de linhas no tabuleiro
    cin >> n;

    int caso = 1;
    while (n != 0) {
        vector<vector<int>> Matrix(10, vector<int>(10, -1));

        for (int i = 0; i < n; i++) {
            int a; // número de casas ignoradas no início da linha
            int b; // número de casas na linha
            cin >> a >> b;
            for (int j = a; j < a + b; j++) {
                Matrix[i][j] = 0;
            }
        }

        int min_unvisited = 100;
        knight(0, 0, Matrix, min_unvisited, 0);

        if (min_unvisited == 1) {
            cout << "Case " << caso << ", " << min_unvisited << " square can not be reached." << endl;
        } else {
            cout << "Case " << caso << ", " << min_unvisited << " squares can not be reached." << endl;
        }

        cin >> n;
        caso++;
    }

    return 0;
}
