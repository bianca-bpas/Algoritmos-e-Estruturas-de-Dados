#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Graph {
    vector<vector<int>> adjList;
    int numVertices, numEdges;
    vector<bool> visited;
    vector<int> team;
} Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->adjList.resize(n);
    g->numEdges = 0; g->numVertices = n;
    g->visited.resize(n, false);
    g->team.resize(n);
    return g;
}

void setEdge(Graph *g, int i, int j, int wt){
    if (wt == 0){
        return;
    }
    g->adjList[i-1].push_back(j-1); g->adjList[j-1].push_back(i-1);
    g->numEdges++;
}

bool DFS(Graph *g, int v){
    g->visited[v] = true;
    for (auto vizinho : g->adjList[v]){
        if (!g->visited[vizinho]){
            int time_v = g->team[v];
            if (time_v == 1){
                g->team[vizinho] = 2; 
            } else if (time_v == 2){
                g->team[vizinho = 1];
            }
            if (DFS(g, vizinho) == false){
                return false;
            }
        } else if (g->team[vizinho] == g->team[v]){
            return false;
        }
    }
    return true;

}

int main(){
    int num_alunos, num_amizades; cin >> num_alunos >> num_amizades;
    Graph *g = create_graph(num_alunos);
    for (int i = 0; i < num_amizades; i++){
        int a, b; cin >> a >> b;
        setEdge(g, a, b, 1);
    }

    bool possible = true;
    for (int v = 0; v < g->numVertices; v++){
        if (!g->visited[v]){
            g->team[v] = 1;
            if (DFS(g, v) == false){
                cout << "IMPOSSIVEL" << endl;
                possible = false;
                break;
            }

        }
    }

    if (possible){
        for (auto time : g->team){
            cout << time << " ";
        }
    }

    return 0;
}