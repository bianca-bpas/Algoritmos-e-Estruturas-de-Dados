#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef struct Graph {
    vector<list<int>> vetor;
    int numEdge;
    vector<string> Mark;
    int numVertices;
} Graph;

Graph* create_graph(int n) {
    Graph *g = new Graph;
    g->Mark.resize(n, "UNVISITED");
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

void setMark(Graph *g, int v, string val) {
    g->Mark[v] = val;
}

string getMark(const Graph &g, int v) {
    return g.Mark[v];
}

void preVisit(int v) {
    cout << "PreVisit: " << v << endl;
}

void posVisit(int v) {
    cout << "PosVisit: " << v << endl;
}

int first(const Graph &g, int v) {
    if (!g.vetor[v].empty()) {
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

void BFS(Graph *g, int start) {
    queue<int> Q;
    Q.push(start);
    setMark(g, start, "VISITED");
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        preVisit(v);
        int w = first(*g, v);
        while (w < g->numVertices) {
            if (getMark(*g, w) == "UNVISITED") {
                setMark(g, w, "VISITED");
                Q.push(w);
            }
            w = next(*g, v, w);
        }
        posVisit(v);
    }
}

void graphTraverse(Graph *g) {
    for (int v = 0; v < g->numVertices; v++) {
        setMark(g, v, "UNVISITED");
    }
    for (int v = 0; v < g->numVertices; v++) {
        if (getMark(*g, v) == "UNVISITED") {
            BFS(g, v);
        }
    }
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

    int start = 0;
    int end = 6;
    cout << "Calculando o caminho mais curto de " << start << " a " << end << "..." << endl;
    
    for (int v = 0; v < g->numVertices; v++) {
        setMark(g, v, "UNVISITED");
    }

    vector<int> path = BFS_shortest_path(g, start, end);

    if (path.size() > 1) {
        cout << "Caminho mais curto: ";
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "Nenhum caminho encontrado de " << start << " a " << end << endl;
    }

    delete g; // Libera a memória alocada para o grafo
    return 0;
}
