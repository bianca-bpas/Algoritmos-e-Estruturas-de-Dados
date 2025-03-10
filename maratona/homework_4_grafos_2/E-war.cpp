#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int numVertices;
        vector<vector<int>> adjList;
        vector<int> representant;
        vector<int> size;

    public:
        Graph(int n) : numVertices(n) {
            adjList.resize(n); size.resize(n); representant.resize(n);
            for (int i = 0; i < n; i++){
                representant[i] = i;
                size[i] = 1;
            }
        }
        ~Graph() = default;
        int find(int v){
            if (v == representant[v]){
                return v;
            }
            return representant[v] = find(representant[v]);
        }
        void join(int u, int v){
            u = find(u); v = find(v);
            if (u == v){
                return;
            }
            if (size[u] < size[v]){
                swap(u, v);
            }
            representant[v] = u;
            size[u] += size[v];
        }
        bool setFriends(int x, int y){
            join(x, y);
            if (areFriends(x, x) && areFriends(y, y)){
                if (areFriends(x, y)){
                    for (int z = y+1; z < size[y]; z++){
                        if (areFriends(x, z)){
                            return false;
                        }
                    }
                    for (int z = x+1; z < size[x]; z++){
                        if (!areFriends(y, z)){
                            return false;
                        }
                    }
                    return true;
                }
            }
            return false;
        }
        bool setEnemies(int x, int y){
            join(x, y);
            if (!areEnemies(x, x) && !areEnemies(y, y)){
                if (areEnemies(x, y)){
                    for (int z = 0; z < size[y]; z++){
                        if (!areFriends(x, z)){
                            return false;
                        }
                    }
                    for (int z = 0; z < size[x]; z++){
                        if (!areFriends(y, z)){
                            return false;
                        }
                    }
                    for (int z = 0; z < size[y]; z++){
                        if (areFriends(x, y) && areEnemies(y, z)){
                            if (!areEnemies(x, z)){
                                return false;
                            }
                        }
                    }
                    for (int z = 0; z < size[x]; z++){
                        if (areFriends(x, y) && areEnemies(x, z)){
                            if (!areEnemies(y, z)){
                                return false;
                            }
                        }
                    }
                    return true;
                }
            }
            return false;
        }
        bool areFriends(int x, int y){
            if (representant[x] == representant[y]){
                return true;
            }
            return false;
        }
        bool areEnemies(int x, int y){
            if (representant[x] == representant[y]){
                return true;
            }
            return false;
        }
};

int main() {
    int n; cin >> n;
    Graph g(n);
    int c;
    while (cin >> c) {
        int x, y; cin >> x >> y;
        if (c!= 0 && x != 0 && y != 0){
            if (c == 1){
                if (!g.setFriends(x, y)){
                    cout << -1 << '\n';
                }
            } else if (c == 2){
                if (!g.setEnemies(x, y)){
                    cout << -1 << '\n';
                }
            } else if (c == 3){
                cout << g.areFriends(x, y) << '\n';
            } else if (c == 4){
                cout << g.areEnemies(x, y) << '\n';
            }
        }
    }
    return 0;
}