#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef struct Graph {
    vector<vector<int>> matrix;
    int numEdge;
    vector<string> Mark;
    int numVertices;
} Graph;

Graph* create_graph(int n) {
    Graph *g = new Graph;
    g->Mark.resize(n, "UNVISITED");
    g->matrix.resize(n, vector<int>(n, 0));
    g->numEdge = 0;
    g->numVertices = n;
    return g;
}

void setEdge(Graph *g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    if (g->matrix[i][j] == 0) {
        g->numEdge++;
    }
    g->matrix[i][j] = wt;
    g->matrix[j][i] = wt; // Add this line for undirected graph
}

void setMark(Graph *g, int v, string val){
    g->Mark[v] = val;
}

string getMark(const Graph &g, int v){
    return g.Mark[v];
}

void preVisit(int v) {
    cout << v << " ";
}

int first(const Graph &g, int v) {
    for (int i = 0; i < g.numVertices; i++) {
        if (g.matrix[v][i] != 0) {
            return i;
        }
    }
    return g.numVertices;
}

int next(const Graph &g, int v, int w) {
    for (int i = w + 1; i < g.numVertices; i++) {
        if (g.matrix[v][i] != 0) {
            return i;
        }
    }
    return g.numVertices;
}

void BFS(Graph *g, int start){
    queue<int> Q;
    Q.push(start);
    setMark(g, start, "VISITED");
    while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        preVisit(v);
        int w = first(*g, v);
        while (w < g->numVertices){
            if (getMark(*g, w) == "UNVISITED"){
                setMark(g, w, "VISITED");
                Q.push(w);
            }
            w = next(*g, v, w);
        }
    }
    cout << endl;
}

void DFS(Graph *g, int v){
    preVisit(v);
    setMark(g, v, "VISITED");
    int w = first(*g, v);
    while (w < g->numVertices){
        if (getMark(*g, w) == "UNVISITED"){
            DFS(g, w);
        }
        w = next(*g, v, w);
    }
}

int main(){
    int n; // quantidade de vértices do grafo
    int q; // numero de operações que devem ser realizadas sobre o grafo
    cin >> n;
    cin >> q;
    string comando;
    int u, v;
    Graph* g = create_graph(n);
    for (int i = 0; i < q; i++){
        cin >> comando;
        if (comando == "add"){
            cin >> u >> v;
            setEdge(g, u, v, 1);
        } else if (comando == "BFS"){
            cin >> v;
            for (int j = 0; j < n; j++) setMark(g, j, "UNVISITED"); // Reset marks before BFS
            BFS(g, v);
        } else if (comando == "DFS"){
            cin >> v;
            for (int j = 0; j < n; j++) setMark(g, j, "UNVISITED"); // Reset marks before DFS
            DFS(g, v);
            cout << endl;
        }
    }
    return 0;
}
