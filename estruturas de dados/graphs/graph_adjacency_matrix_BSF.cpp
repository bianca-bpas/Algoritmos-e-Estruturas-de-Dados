#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Graph {
    vector<vector<int>> matrix;
    int numEdge;
    vector<string> Mark;
    int numVertices;
} Graph;

Graph* create_graph(int n) {
    Graph *g = new Graph;
    g->Mark.resize(n);
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
}

void delEdge(Graph *g, int i, int j) {
    if (g->matrix[i][j] != 0) {
        g->numEdge--;
    }
    g->matrix[i][j] = 0;
}

bool isEdge(const Graph &g, int i, int j){
    return (g.matrix[i][j] != 0);
}

int weight(const Graph &g, int i, int j){
    return g.matrix[i][j];
}

void setMark(Graph *g, int v, string val){
    g->Mark[v] = val;
}

string getMark(const Graph &g, int v){
    return g.Mark[v];
}

void preVisit(int v) {
    cout << "PreVisit: " << v << endl;
}

void posVisit(int v) {
    cout << "PosVisit: " << v << endl;
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

vector<int> BFS_shortest_path(Graph *g, int start, int end) {
    queue<int> Q;
    vector<int> predecessor(g->numVertices, -1);
    vector<int> path;
    bool found = false;

    Q.push(start);
    setMark(g, start, "VISITED");
    while (!Q.empty() && !found) {
        int v = Q.front();
        Q.pop();
        int w = first(*g, v);
        while (w < g->numVertices) {
            if (getMark(*g, w) == "UNVISITED") {
                setMark(g, w, "VISITED");
                predecessor[w] = v;
                if (w == end) {
                    found = true;
                    break;
                }
                Q.push(w);
            }
            w = next(*g, v, w);
        }
    }

    if (found) {
        for (int at = end; at != -1; at = predecessor[at]) {
            path.insert(path.begin(), at);
        }
    }

    return path;
}

void BFS(Graph *g, int start){
    queue<int> Q;
    Q.push(start);
    setMark(g, start, "VISITED");
    while (Q.size() > 0){
        int v = Q.front();
        Q.pop();
        preVisit(v);
        int w = first(*g, v);
        while (w < g->numVertices){
            if (getMark(*g, v) == "UNVISITED"){
                setMark(g, w, "VISITED");
                Q.push(w);
            }
            w = next(*g, v, w);
        }
        posVisit(v);
    }
}

void graphTraverse(Graph *g){
    for (int v = 0; v < g->numVertices; v++){
        setMark(g, v, "UNVISITED");
    }
    for (int v = 0; v < g->numVertices; v++){
        if (getMark(*g, v) == "UNVISITED"){
            BFS(g, v);
        }
    }
}

int main() {
    int numVertices = 6;
    cout << "Criando grafo de " << numVertices << " vertices..." << endl;
    Graph* g = create_graph(numVertices);

    cout << "Adicionando arestas..." << endl;
    setEdge(g, 0, 2, 1);
    setEdge(g, 0, 4, 1);
    setEdge(g, 1, 2, 1);
    setEdge(g, 1, 5, 1);
    setEdge(g, 2, 0, 1);
    setEdge(g, 2, 1, 1);
    setEdge(g, 2, 3, 1);
    setEdge(g, 2, 5, 1);
    setEdge(g, 3, 2, 1);
    setEdge(g, 3, 5, 1);
    setEdge(g, 4, 0, 1);
    setEdge(g, 4, 5, 1);
    setEdge(g, 5, 1, 1);
    setEdge(g, 5, 2, 1);
    setEdge(g, 5, 3, 1);
    setEdge(g, 5, 4, 1);

    cout << "Matriz de Adjacencia:" << endl;
    cout << " - [0][1][2][3][4][5]" << endl;
    for (int i = 0; i < g->numVertices; ++i) {
        cout << "[" << i << "] ";
        for (int j = 0; j < g->numVertices; ++j) {
            cout << g->matrix[i][j] << "  ";
        }
        cout << endl;
    }

    // Busca pelo menor caminho de 0 a 5
    for (int v = 0; v < g->numVertices; v++){
        setMark(g, v, "UNVISITED");
    }
    vector<int> shortest_path = BFS_shortest_path(g, 0, 5);
    
    cout << "Menor caminho de 0 a 5:" << endl;
    for (int v : shortest_path) {
        cout << v << " ";
    }
    cout << endl;

    delete g; // Libera a memória alocada para o grafo
    return 0;
}
