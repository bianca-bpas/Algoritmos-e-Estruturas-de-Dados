#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Graph {
    vector<vector<int>> matrix;
    int numEdge;
    vector<int> Mark;
    int numVertices;
} Graph;

Graph* create_graph(int n) {
    Graph *g = new Graph;
    g->matrix.resize(n, vector<int>(n, 0));
    g->Mark.resize(n, 0);
    g->numEdge = 0;
    g->numVertices = n;
    return g;
}

void setEdge(Graph *g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    if (g->matrix[i - 1][j - 1] == 0) {
        g->numEdge++;
    }
    g->matrix[i - 1][j - 1] = wt;
    g->Mark[j - 1]++;
}

vector<int> TopologicalSort(Graph *g) {
    vector<int> topologicalOrder;
    priority_queue<int, vector<int>, greater<int>> zeroMarkQueue;

    for (int i = 0; i < g->numVertices; i++) {
        if (g->Mark[i] == 0) {
            zeroMarkQueue.push(i);
        }
    }

    while (!zeroMarkQueue.empty()) {
        int u = zeroMarkQueue.top();
        zeroMarkQueue.pop();
        topologicalOrder.push_back(u + 1);

        for (int v = 0; v < g->numVertices; v++) {
            if (g->matrix[u][v] != 0) {
                g->Mark[v]--;
                if (g->Mark[v] == 0) {
                    zeroMarkQueue.push(v);
                }
            }
        }
    }

    if (topologicalOrder.size() != g->numVertices) {
        return {};
    }

    return topologicalOrder;
}

int main() {
    int numVertices, numArestas;
    cin >> numVertices >> numArestas;
    Graph* g = create_graph(numVertices);

    for (int i = 0; i < numArestas; i++){
        int x, y;
        cin >> x >> y;
        setEdge(g, x, y, 1);
    }
    
    vector<int> result = TopologicalSort(g);

    if (result.empty()) {
        cout << "Sandro fails." << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    delete g;
    return 0;
}
