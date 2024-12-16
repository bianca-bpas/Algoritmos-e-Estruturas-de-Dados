#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Graph {
    vector<vector<int>> adjList;
    int numEdge;
    vector<int> num_predecessors;
    int numVertices;
} Graph;

Graph* create_graph(int n) {
    Graph *g = new Graph;
    g->adjList.resize(n);
    g->num_predecessors.resize(n, 0);
    g->numEdge = 0;
    g->numVertices = n;
    return g;
}

void setEdge(Graph *g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    g->adjList[i - 1].push_back(j - 1);
    g->num_predecessors[j - 1]++; 
    g->numEdge++;
}

vector<int> TopologicalSort(Graph *g) {
    vector<int> topologicalOrder;
    priority_queue<int, vector<int>, greater<int>> fila_zero_predecessors;

    for (int i = 0; i < g->numVertices; i++) {
        if (g->num_predecessors[i] == 0) {
            fila_zero_predecessors.push(i);
        }
    }

    while (!fila_zero_predecessors.empty()) {
        int u = fila_zero_predecessors.top(); 
        fila_zero_predecessors.pop();
        topologicalOrder.push_back(u + 1); 

        for (int v : g->adjList[u]) {
            g->num_predecessors[v]--;
            if (g->num_predecessors[v] == 0) {
                fila_zero_predecessors.push(v);
            }
        }
    }

    if (topologicalOrder.size() != g->numVertices) {
        return {};
    }

    return topologicalOrder;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_cursos, num_requisitos; 
    cin >> num_cursos >> num_requisitos; 
    Graph* g = create_graph(num_cursos); 
    int a, b;

    for (int i = 0; i < num_requisitos; i++) {
        cin >> a >> b;
        setEdge(g, a, b, 1);
    }

    vector<int> result = TopologicalSort(g);

    if (result.empty()) {
        cout << "IMPOSSIBLE" << endl; 
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }

    delete g;
    return 0;
}
