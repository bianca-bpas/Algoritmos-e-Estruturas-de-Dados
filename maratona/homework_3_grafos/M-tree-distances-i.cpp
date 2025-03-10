#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Graph {
    vector<vector<int>> adjList;
    int numVertices, numEdges;
    vector<bool> visited;
} Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->adjList.resize(n);
    g->numEdges = 0; g->numVertices = n;
    g->visited.resize(n, false);
    return g;
}

void setEdge(Graph *g, int i, int j, int wt){
    if (wt == 0){
        return;
    }
    g->adjList[i-1].push_back(j-1); 
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    Graph *g = create_graph(N);
    for (int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        setEdge(g, a, b, 1);
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