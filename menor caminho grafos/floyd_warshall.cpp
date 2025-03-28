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
    vector<vector<int>> distances;
    vector<int> predecessors;
};

Graph* create_graph(int n) {
    Graph* g = new Graph;
    g->Mark.resize(n, "UNVISITED");
    g->matrix.resize(n, vector<int>(n, 0));
    g->numEdge = 0;
    g->numVertices = n;
    g->distances.resize(n, vector<int>(n));
    g->predecessors.resize(n, -1); // Inicializar com -1 para indicar ausência de predecessors
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

void Floyd_Warshall(Graph *g){
  for (int i = 0; i < g->numVertices; i++){
    for (int j = 0; j < g->numVertices; j++){
      if (i == j){
        g->distances[i][j] = weight(g, i, j);
      } else if (weight(g, i, j) != 0){
        g->distances[i][j] = weight(g, i, j);
      } else {
        g->distances[i][j] = infinite;
      }
    }
  }
  for (int k = 0; k < g->numVertices; k++){
    for (int i = 0; i < g->numVertices; i++){
      for (int j = 0; j < g->numVertices; j++){
        if (g->distances[i][k] != infinite && g->distances[k][j] != infinite && g->distances[i][j] > g->distances[i][k] + g->distances[k][j]){
          g->distances[i][j] = g->distances[i][k] + g->distances[k][j];
        }
      }
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

    Floyd_Warshall(g);

    // Imprimir a matriz de distâncias
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (g->distances[i][j] == infinite) {
                cout << "INF ";
            } else {
                cout << g->distances[i][j] << " ";
            }
        }
        cout << endl;
    }

    delete g;
    return 0;
}
