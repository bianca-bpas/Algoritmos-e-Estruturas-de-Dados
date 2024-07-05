// IMPLEMENTAÇÃO COM ADJACENCY_matrix E BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Graph {
    vector<vector<int>> matrix;
    vector<string> Mark;
    int numEdges;
    int numVertices;
} Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->matrix.resize(n, vector<int>(n, 0));
    g->Mark.resize(n, "UNVISITED");
    g->numEdges = 0;
    g->numVertices = n;
}

void setEdge(Graph *g, int i, int j, int wt){
    if (wt == 0){
        return;
    }
    if (g->matrix[i][j] == 0){
        g->numEdges++;
    }
    g->matrix[i][j] = wt;
}

void setMark(Graph *g, int v, int val){
    g->Mark[v] = val;
}

string getMark(Graph *g, int v){
    return g->Mark[v];
}