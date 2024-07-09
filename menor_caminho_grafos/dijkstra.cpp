#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

const int infinite = INT_MAX;

struct Graph {
    vector<string> Mark;
    vector<vector<int>> matrix;
    int numEdge;
    int numVertices;
    vector<int> distance;
    vector<int> predecessor;
};

Graph* create_graph(int n) {
    Graph* g = new Graph;
    g->Mark.resize(n, "UNVISITED");
    g->matrix.resize(n, vector<int>(n, 0));
    g->numEdge = 0;
    g->numVertices = n;
    g->distance.resize(n, infinite);
    g->predecessor.resize(n, -1); // Inicializar com -1 para indicar ausência de predecessor
    return g;
}

void setEdge(Graph* g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    if (i < g->numVertices && j < g->numVertices) {
        if (g->matrix[i][j] == 0) {
            g->numEdge++;
        }
        g->matrix[i][j] = wt;
        g->matrix[j][i] = wt; // Por ser um grafo não-dirigido
    } else {
        cout << "Erro: índice fora do limite" << endl;
    }
}

int weight(const Graph& g, int i, int j) {
    return g.matrix[i][j];
}

void setMark(Graph* g, int v, string val) {
    g->Mark[v] = val;
}

string getMark(const Graph& g, int v) {
    return g.Mark[v];
}

int first(const Graph& g, int v) {
    for (int i = 0; i < g.numVertices; i++) {
        if (g.matrix[v][i] != 0) {
            return i;
        }
    }
    return g.numVertices;
}

int next(const Graph& g, int v, int w) {
    for (int i = w + 1; i < g.numVertices; i++) {
        if (g.matrix[v][i] != 0) {
            return i;
        }
    }
    return g.numVertices;
}

struct Tripla {
    int vertice1;
    int vertice2;
    int distance;

    Tripla(int v1, int v2, int d) : vertice1(v1), vertice2(v2), distance(d) {}
};

struct compareTripla {
    bool operator()(Tripla const& a, Tripla const& b) {
        return a.distance > b.distance;
    }
};

void Dijkstra(Graph *G, int s){
    priority_queue<Tripla, vector<Tripla>, compareTripla> minHeap;
    minHeap.push(Tripla(s, s, 0));
    G->distance[s] = 0;

    for (int i = 0; i < G->numVertices; i++) {
        int p;
        int v;
        do {
            if (minHeap.empty()) {
                return;
            }
            Tripla top = minHeap.top();
            minHeap.pop();
            int p = top.vertice1;
            v = top.vertice2;
        } while (getMark(*G, v) == "VISITED");

        setMark(G, v, "VISITED");
        G->predecessor[v] = p;

        int w = first(*G, v);
        while (w < G->numVertices) {
            if (getMark(*G, w) != "VISITED" && G->distance[w] > G->distance[v] + weight(*G, v, w)) {
                G->distance[w] = G->distance[v] + weight(*G, v, w);
                minHeap.push(Tripla(v, w, G->distance[w]));
            }
            w = next(*G, v, w);
        }
    }
}


int main() {
    int numVertices, numArestas, vertice;
    cin >> numVertices >> numArestas >> vertice;
    Graph* g = create_graph(numVertices);

    for (int i = 0; i < numArestas; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        setEdge(g, a, b, w);
    }

    Dijkstra(g, vertice);

    for (int i = 0; i < numVertices; i++) {
        if (g->distance[i] == infinite) {
            cout << -1 << " ";
        } else {
            cout << g->distance[i] << " ";
        }
    }
    cout << endl;

    delete g;
    return 0;
}