#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
    private:
        int numVertices;
        int numEdges;
        vector<vector<pair<int, ll>>> adjList;
        vector<vector<ll>> distances;

    public:
        Graph(int V) : numVertices(V), numEdges(0) {
            this->adjList.resize(V);
            this->distances.resize(V, vector<ll>(V, LLONG_MAX));
        }
        ~Graph() {}
        void setEdge(int a, int b, ll wt) {
            if (wt == 0){
                return;
            }
            if (a-1 < this->numVertices && b-1 < this->numVertices){
                this->adjList[a-1].push_back(make_pair(b-1, wt));
                this->distances[a-1][b-1] = min(this->distances[a-1][b-1], wt);
                this->numEdges++;
            }
        }
        void FloydWarshall(){
            for (int vertex = 0; vertex < this->numVertices; vertex++){
                this->distances[vertex][vertex] = 0;
            }
            for (int k = 0; k < this->numVertices; k++){
                for (int u = 0; u < this->numVertices; u++){
                    for (int v = 0; v < this->numVertices; v++){
                        if (this->distances[u][k] < LLONG_MAX && this->distances[k][v] < LLONG_MAX){
                            this->distances[u][v] = min(this->distances[u][v], this->distances[u][k]+this->distances[k][v]);
                        }
                    }
                }
            }
        }

        ll getDistance(int source, int target) {
            if (source-1 < this->numVertices){
                if  (this->distances[source-1][target-1] == LLONG_MAX){
                    return -1;
                }
                return this->distances[source-1][target-1];
            }
            return -1;
        }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q; cin >> n >> m >> q;
    Graph g(n);

    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g.setEdge(a, b, c);
        g.setEdge(b, a, c);
    }

    g.FloydWarshall();
    for (int i = 0; i < q; i++){
        cin >> a >> b;
        cout << g.getDistance(a, b) << '\n';
    }

    return 0;
}