#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Graph {
    int numVertices, numEdges;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> ciclo;
} Graph;

Graph* create_graph(int n) {
    Graph* g = new Graph;
    g->numVertices = n; g->numEdges = 0;
    g->adjList.resize(n);
    g->visited.resize(n, false);
    return g;
}

void setEdge(Graph *g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    g->adjList[i-1].push_back(j-1);
    g->adjList[j-1].push_back(i-1);
    g->numEdges++;
}

int DFS(Graph *g, int atual, int anterior, int &inicioCiclo) {
    if (g->visited[atual]) {
        inicioCiclo = atual; // Armazena o início do ciclo
        return atual;        // Retorna o vértice que iniciou o ciclo
    }

    g->visited[atual] = true;

    for (int next : g->adjList[atual]) {
        if (next != anterior) { 
            int fim = DFS(g, next, atual, inicioCiclo);

            if (fim != -1) {
                if (fim != inicioCiclo || g->ciclo.empty()) { 
                    g->ciclo.push_back(atual + 1); // Adiciona o vértice atual ao ciclo
                }

                if (fim == atual) { 
                    return -2; // Sinaliza que o ciclo foi fechado
                }
                if (fim == -2) return -2; // Propaga o fechamento do ciclo
                return fim; // Continua retornando até atingir o início do ciclo
            }
        }
    }

    return -1; // Não encontrou ciclo
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    Graph* g = create_graph(n);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        setEdge(g, a, b, 1);
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (!g->visited[i]) {
            int start_ciclo = -1;
            if (DFS(g, i, -1, start_ciclo) != -1) {
                g->ciclo.push_back(g->ciclo[0]);
                if (g->ciclo.size() >= 4){
                    cout << g->ciclo.size() << endl;
                    for (int x : g->ciclo) cout << x << " ";
                    cout << endl;
                    found = true; break;
                } else {
                    break;
                }
            }
        }
    }

    if (!found){
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;

}