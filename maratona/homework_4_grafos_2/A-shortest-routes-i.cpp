#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, int>
using namespace std;

class Graph {
    private:
        int numVertices;
        int numEdges;
        vector<vector<pair<int, ll>>> adjList;
        vector<ll> distances;
        vector<int> predecessor;

    public:
        Graph(int V) : numVertices(V), numEdges(0) {
            this->adjList.resize(V);
            this->distances.resize(V, LLONG_MAX);
            this->predecessor.resize(V, -1);
        }
        ~Graph() {}
        void setEdge(int a, int b, ll wt) {
            if (wt == 0){
                return;
            }
            if (a-1 < this->numVertices && b-1 < this->numVertices){
                this->adjList[a-1].push_back(make_pair(b-1, wt));
                this->numEdges++;
            }
        }
        void Dijkstra (int start){
            this->distances[start-1] = 0;
            priority_queue <pi, vector<pi>, greater<pi>> minHeap;
            minHeap.push(make_pair(0, start-1));

            while (!minHeap.empty()){
                pi t = minHeap.top();
                ll distance = t.first; int origin = t.second;
                minHeap.pop();

                if (distance <= this->distances[origin]){
                    for (pair<int, ll> p : this->adjList[origin]){
                        int vertex = p.first; ll cost = p.second;
                        if (this->distances[vertex] > this->distances[origin] + cost){
                            this->distances[vertex] = this->distances[origin] + cost;
                            this->predecessor[vertex] = origin;
                            minHeap.push(make_pair(this->distances[vertex], vertex));
                        }
                    }
                }
            }
            
        }
        ll getDistance(int vertex) {
            if (vertex-1 < numVertices){
                return this->distances[vertex-1];
            }
            return 0;
        }
};


int main(){
    int n, m; cin >> n >> m;
    Graph g(n);

    int a, b;
    ll c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g.setEdge(a, b, c);
    }

    g.Dijkstra(1);

    for (int i = 1; i <= n; i++){
        ll dist = g.getDistance(i);
        cout << dist << " ";
    }
    cout << '\n';

    return 0;
}