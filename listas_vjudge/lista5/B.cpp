#include <iostream>
#include <vector>
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
    posVisit(v);
}

void graphTraverse(Graph *g){
    for (int v = 0; v < g->numVertices; v++){
        setMark(g, v, "UNVISITED");
    }
    for (int v = 0; v < g->numVertices; v++){
        if (getMark(*g, v) == "UNVISITED"){
            DFS(g, v);
        }
    }
}

void toposort(Graph *g, int v, stack<int> *s){
    setMark(g, v, "VISITED");
    int w = first(*g, v);
    while (w < g->numVertices){
        if (getMark(*g, w) == "UNVISITED"){
            toposort(g, w, s);
        }
        w = next(*g, v, w);
    }
    s->push(v);
}

void graphTraverseToposort(Graph *g){
    stack<int> s;
    for (int v = 0; v < g->numVertices; v++){
        setMark(g, v, "UNVISITED");
    }
    for (int v = 0; v < g->numVertices; v++){
        if (getMark(*g, v) == "UNVISITED"){
            toposort(g, v, &s);
        }
    }

    cout << "Ordenacao Topologica: ";
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    int numVertices, numArestas;
    cin >> numVertices >> numArestas;
    cout << "Criando grafo de " << numVertices << " vertices..." << endl;
    Graph* g = create_graph(numVertices);

    cout << "Adicionando arestas..." << endl;
    for (int i = 0; i < numArestas; i++){
        int x, y;
        cin >> x >> y;
        setEdge(g, x, y, 1);
    }
    
    cout << "Matriz de Adjacencia:" << endl;
    cout << " - [0][1][2][3][4][5][6]" << endl;
    for (int i = 0; i < g->numVertices; ++i) {
        cout << "[" << i << "] ";
        for (int j = 0; j < g->numVertices; ++j) {
            cout << g->matrix[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "Travessia do Grafo para Ordenacao Topologica:" << endl;
    graphTraverseToposort(g);

    delete g; // Libera a memória alocada para o grafo
    return 0;
}
