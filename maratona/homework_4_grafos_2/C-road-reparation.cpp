#include <bits/stdc++.h>
using ll = long long;
#define pi pair<ll, int>
using namespace std;

class Graph {
    private:
        int numVertices;
        vector<vector<pair<int, ll>>> adjList;
        vector<bool> visited;
    
    public:
        Graph(int n) : numVertices(n) {
            this->adjList.resize(n);
            this->visited.resize(n, false);
        }
        ~Graph() {}
        void setEdge(int a, int b, ll wt){
            if (a-1 < this->numVertices && b-1 < this->numVertices){
                this->adjList[a-1].push_back(make_pair(b-1, wt));
            }
        }
        ll Prim(int start){
            priority_queue <pi, vector<pi>, greater<pi>> minHeap;
            minHeap.push(make_pair(0, start-1));
            ll cost = 0;

            while (!minHeap.empty()){
                auto [w, u] = minHeap.top();
                minHeap.pop();

                if (this->visited[u] == false){
                    this->visited[u] = true;
                    cost += w;

                    for (auto [v, c] : this->adjList[u]){
                        if (this->visited[v] == false){
                            minHeap.push(make_pair(c, v));
                        }
                    }
                }
            }
            for (bool v : this->visited){
                if (v == false){
                    cost = 0; break;
                }
            }
            return cost;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g.setEdge(a, b, c);
        g.setEdge(b, a, c);
    }
    ll cost = g.Prim(1);
    if (cost == 0){
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << cost << '\n';
    }

    return 0;
}