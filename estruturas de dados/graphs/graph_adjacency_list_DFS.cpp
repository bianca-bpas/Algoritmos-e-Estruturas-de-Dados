#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

typedef struct Graph {
    vector<list<int>> vetor;
    int numEdge;
    vector<string> Mark;
    int numVertices;
} Graph;

Graph* create_graph(int n) {
    Graph *g = new Graph;
    g->Mark.resize(n);
    g->vetor.resize(n);
    g->numEdge = 0;
    g->numVertices = n;
    return g;
}

void setEdge(Graph *g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    g->vetor[i].push_back(j);
    g->numEdge++;
}

void delEdge(Graph *g, int i, int j) {
    g->vetor[i].remove(j);
    g->numEdge--;
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
    if (!g.vetor[v].empty()){
        return g.vetor[v].front();
    } else {
        return g.numVertices;
    }
}

int next(const Graph &g, int v, int w) {
    const list<int>& adjList = g.vetor[v];
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        if (*it > w) {
            return *it;
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
    int numVertices = 7;
    cout << "Criando grafo de " << numVertices << " vertices..." << endl;
    Graph* g = create_graph(numVertices);

    cout << "Adicionando arestas..." << endl;
    setEdge(g, 0, 1, 1);
    setEdge(g, 0, 2, 1);
    setEdge(g, 1, 3, 1);
    setEdge(g, 1, 4, 1);
    setEdge(g, 1, 5, 1);
    setEdge(g, 2, 3, 1);
    setEdge(g, 3, 4, 1);
    setEdge(g, 4, 6, 1);

    cout << "Travessia do Grafo para Ordenacao Topologica:" << endl;
    graphTraverseToposort(g);

    delete g; // Libera a memória alocada para o grafo
    return 0;
}
