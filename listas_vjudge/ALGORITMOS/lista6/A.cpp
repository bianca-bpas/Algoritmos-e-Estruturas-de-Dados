#include <bits/stdc++.h>
using namespace std;

const int infinite = INT_MAX;

struct Graph {
    vector<list<pair<int, int>>> adjList;
    int numVertices;
};

Graph* create_graph(int n) {
    Graph* g = new Graph;
    g->adjList.resize(n);
    g->numVertices = n;
    return g;
}

void setEdge(Graph* g, int i, int j, int wt) {
    g->adjList[i].push_back({ j, wt });
    g->adjList[j].push_back({ i, wt });
}

int dijkstra(Graph* g, int S, int T) {
    vector<int> dist(g->numVertices, infinite);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    dist[S] = 0;
    minHeap.push({0, S});

    while (!minHeap.empty()) {
        int p = minHeap.top().first;
        int v = minHeap.top().second;
        minHeap.pop();

        if (v == T) {
            return p;
        }

        for (const auto& [adj, wt] : g->adjList[v]) {
            if (dist[v] + wt < dist[adj]) {
                dist[adj] = dist[v] + wt;
                minHeap.push({dist[adj], adj});
            }
        }
    }

    return infinite;
}

int main() {
    int N;
    cin >> N;

    for (int numCaso = 1; numCaso <= N; numCaso++) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        Graph* g = create_graph(n);

        for (int i = 0; i < m; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            setEdge(g, u, v, weight);
        }

        int result = dijkstra(g, S, T);

        if (result != infinite) {
            cout << "Case #" << numCaso << ": " << result << endl;
        } else {
            cout << "Case #" << numCaso << ": unreachable" << endl;
        }

        delete g;
    }

    return 0;
}
