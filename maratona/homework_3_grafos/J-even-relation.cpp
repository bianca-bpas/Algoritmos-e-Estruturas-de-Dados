#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Graph {
    vector<vector<pair<int, int>>> adjList;
    int numVertices, numEdges;
    vector<bool> visited;
    vector<bool> color;
} Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->adjList.resize(n);
    g->numEdges = 0; g->numVertices = n;
    g->visited.resize(n, false);
    g->color.resize(n);
    return g;
}

void setEdge(Graph *g, int i, int j, int wt){
    if (wt == 0){
        return;
    }
    g->adjList[i-1].push_back({j-1, wt}); 
    g->adjList[j-1].push_back({i-1, wt});
    g->numEdges++;
}

void DFS(Graph *g, int v){
    g->visited[v] = true;
    for (auto vizinho : g->adjList[v]){
        if (!g->visited[vizinho.first]){
            int distancia = vizinho.second;
            if (distancia % 2 == 0){
                g->color[vizinho.first] = g->color[v];
            } else {
                g->color[vizinho.first] = !g->color[v];
            }
            DFS(g, vizinho.first);
        } 
    }
}

int main(){
    int N; cin >> N;
    Graph *g = create_graph(N);
    for (int i = 0; i < N-1; i++){
        int a, b, c; cin >> a >> b >> c;
        setEdge(g, a, b, c);
    }

    for (int v = 0; v < g->numVertices; v++){
        if (!g->visited[v]){
            g->color[v] = false;
            DFS(g, v);
        }
    }

    for (auto cor : g->color){
        cout << cor << endl;
    }

    return 0;
}