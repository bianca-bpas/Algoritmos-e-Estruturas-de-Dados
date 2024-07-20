#include <bits/stdc++.h>
using namespace std;
const int infinite = INT_MAX;

struct Graph {
    vector<list<pair<int, int>>> adjList;
    int numEdge;
    vector<string> Mark;
    int numVertice;
    vector<int> distance;
    vector<int> Vprim;
};

Graph* create_graph(int n) {
    Graph* g = new Graph;
    g->adjList.resize(n);
    g->numEdge = 0;
    g->Mark.resize(n, "UNVISITED");
    g->numVertice = n;
    g->distance.resize(n, infinite);
    g->Vprim.resize(n, -1);
    return g;
}

void setEdge(Graph* g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    g->adjList[i].push_back({ j, wt });
    g->adjList[j].push_back({ i, wt });
    g->numEdge++;
}

void setMark(Graph* g, int v, string val) {
    g->Mark[v] = val;
}

string getMark(Graph* g, int v) {
    return g->Mark[v];
}

int prim(Graph* g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    g->distance[0] = 0;
    pq.push({0, 0});

    int maxWeightInMST = -1;
    int edgesUsed = 0;

    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (getMark(g, v) == "VISITED") {
            continue;
        }
        
        setMark(g, v, "VISITED");
        maxWeightInMST = max(maxWeightInMST, d);
        edgesUsed++;

        for (const auto& [adj, wt] : g->adjList[v]) {
            if (getMark(g, adj) == "UNVISITED" && wt < g->distance[adj]) {
                g->distance[adj] = wt;
                pq.push({wt, adj});
            }
        }
    }

    if (edgesUsed == g->numVertice) {
        return maxWeightInMST;
    } else {
        return -1;
    }
}

int main() {
    int numCidades, numEstradas;
    cin >> numCidades >> numEstradas;
    while (numCidades > 0 || numEstradas > 0) {
        Graph* g = create_graph(numCidades);
        for (int k = 0; k < numEstradas; k++) {
            int i, j, comprimento;
            cin >> i >> j >> comprimento;
            setEdge(g, i, j, comprimento);
        }

        int result = prim(g);
        if (result != -1) {
            cout << result << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }

        delete g;

        cin >> numCidades >> numEstradas;
    }
    return 0;
}
