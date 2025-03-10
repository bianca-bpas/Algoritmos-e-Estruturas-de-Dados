#include <bits/stdc++.h>
#define endl "\n"
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

void setMark(Graph *g, int v, string val){
    g->Mark[v] = val;
}

string getMark(const Graph &g, int v){
    return g.Mark[v];
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

    if (!s.empty()){
        while (!s.empty()){
            cout << s.top() + 1 << " ";  // Ajuste para base 1
            s.pop();
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_cursos, num_requisitos; cin >> num_cursos >> num_requisitos;
    Graph* g = create_graph(num_cursos); // Grafo com base 0
    int a, b;

    for (int i = 0; i < num_requisitos; i++){
        cin >> a >> b;
        setEdge(g, a - 1, b - 1, 1); // Ajuste para converter para base 0
    }

    graphTraverseToposort(g);

    delete g;
    return 0;
}
