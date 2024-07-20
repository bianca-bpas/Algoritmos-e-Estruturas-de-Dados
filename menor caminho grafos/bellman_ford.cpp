#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int infinite = INT_MAX;

struct Graph {
    vector<string> Mark;
    vector<vector<int>> matrix;
    int numEdge;
    int numVertices;
    vector<int> distances;
    vector<int> predecessor;
};

Graph* create_graph(int n) {
    Graph* g = new Graph;
    g->Mark.resize(n, "UNVISITED");
    g->matrix.resize(n, vector<int>(n, 0));
    g->numEdge = 0;
    g->numVertices = n;
    g->distances.resize(n, infinite);
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
    } else {
        cout << "Erro: índice fora do limite" << endl;
    }
}

int weight(Graph *g, int i, int j) {
    return g->matrix[i][j];
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

void BellmanFord(Graph *g, int s){
  for (int i = 0; i < g->numVertices; i++){
    g->distances[i] = infinite;
    g->distances[s] = 0;
  }
  int j;
  for (int k = 0; k < g->numVertices-1; k++){
    for (int i = 0; i < g->numVertices; i++){
      j = first(g, i);
      while (j < g->numVertices){
        if (g->distances[j] > g->distances[i] + weight(g, i, j)){
          g->distances[j] = g->distances[i] + weight(g, i, j);
        } 
        j = next(g, i, j);
      }
    }
  }
  for (int i = 0; i < g->numVertices; i++){
    j = first(g, i);
    while (j < g->numVertices){
      if (g->distances[j] > g->distances[i] + weight(g, i, j)){
        cout << "Negative cycle detected" << endl;
      }
      j = next(g, i, j);
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

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    BellmanFord(g, source);

    // Imprimir as distâncias
    for (int i = 0; i < numVertices; i++) {
        if (g->distances[i] == infinite) {
            cout << "INF ";
        } else {
            cout << g->distances[i] << " ";
        }
    }
    cout << endl;

    delete g;
    return 0;
}
