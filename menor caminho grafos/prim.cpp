#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>
using namespace std;

const int infinite = INT_MAX;

struct Graph {
    vector<string> Mark;
    vector<vector<int>> matrix;
    int numEdge;
    int numVertices;
    vector<int> distances;
    vector<int> predecessors;
    vector<int> vMST;
};

Graph* create_graph(int n) {
    Graph* g = new Graph;
    g->Mark.resize(n, "UNVISITED");
    g->matrix.resize(n, vector<int>(n, 0));
    g->numEdge = 0;
    g->numVertices = n;
    g->distances.resize(n, infinite);
    g->predecessors.resize(n, -1); // Inicializar com -1 para indicar ausência de predecessors
    g->vMST.resize(n, -1);
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

int weight(Graph *g, int i, int j) {
    return g->matrix[i][j];
}

void setMark(Graph* g, int v, string val) {
    g->Mark[v] = val;
}

string getMark(Graph *g, int v) {
    return g->Mark[v];
}

int first(Graph *g, int v) {
    for (int i = 0; i < g->numVertices; i++) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->numVertices;
}

int next(Graph *g, int v, int w) {
    for (int i = w + 1; i < g->numVertices; i++) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->numVertices;
}

void Prim(Graph *g){
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > minHeap;
    minHeap.push(make_tuple(0, 0, 0));
    g->distances[0] = 0;
    int p;
    int v;
    for (int i = 0; i < g->numVertices; i++){
        do {
            tuple <int, int, int> top = minHeap.top();
            p = get<1>(top);
            v = get<2>(top);
            minHeap.pop();
        } while (getMark(g, v) == "VISITED");
        setMark(g, v, "VISITED");
        g->vMST[v] = p;
        int w = first(g, v);
        while (w < g->numVertices){
            if (getMark(g, w) != "VISITED" && g->distances[w] > weight(g, v, w)){
                g->distances[w] = weight(g, v, w);
                minHeap.push(make_tuple(g->distances[w], v, w));
            }
            w = next(g, v, w);
        }
    }
}

int main() {
    int numVertices, numArestas;
    cin >> numVertices >> numArestas;
    Graph* g = create_graph(numVertices);

    for (int i = 0; i < numArestas; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        setEdge(g, a, b, w);
    }

    Prim(g);

    int sum = 0;
    for (int i = 0; i < numVertices; i++) {
        if (g->distances[i] == infinite) {
            cout << -1 << " ";
        } else {
            cout << g->distances[i] << " ";
            sum += g->distances[i];
        }
    }
    cout << endl;
    cout << "Soma das distâncias: " << sum << endl;

    delete g;
    return 0;
}