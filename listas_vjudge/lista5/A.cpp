#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef struct Graph {
    vector<list<string>> vetor;
    vector<string> contestants;
    int numEdge;
    vector<string> Mark;
    int numVertices;
} Graph;

Graph* create_graph() {
    Graph *g = new Graph;
    g->Mark.resize(0);
    g->vetor.resize(0);
    g->contestants.resize(0);
    g->numEdge = 0;
    g->numVertices = 0;
    return g;
}

void setVertice(string contestant, Graph* g) {
    if (g->contestants.empty()) {
        g->contestants.resize(1);
        g->contestants.push_back(contestant);
        g->Mark.resize(1);
        g->vetor.resize(1);
        g->numVertices++;
    } else {
        bool found = false;
        for (auto it = g->contestants.begin(); it != g->contestants.end(); it++) {
            if (*it == contestant) {
                found = true;
                break;
            }
        }
        if (!found) {
            int size = g->contestants.size();
            g->contestants.resize(size + 1);
            g->contestants.push_back(contestant);
            g->Mark.resize(size + 1);
            g->vetor.resize(size + 1);
            g->numVertices++;
        }
    }
}

void setEdge(Graph *g, string i, string j) {
    int index = 0;
    for (auto it = g->contestants.begin(); it != g->contestants.end(); it++) {
        if (*it == i) {
            break;
        } else {
            index++;
        }
    }
    g->vetor[index].push_back(j);
    g->numEdge++;
}

void printGraph(const Graph *g) {
    for (size_t i = 0; i < g->contestants.size(); i++) {
        cout << g->contestants[i] << ": ";
        for (auto adj : g->vetor[i]) {
            cout << adj << " ";
        }
        cout << endl;
    }
}

int main() {
    int num_casos;
    cin >> num_casos;
    int num_equipes;
    string c1, c2, c3;
    for (int caso = 0; caso < num_casos; caso++) {
        cout << "Caso: " << caso << endl;
        Graph *g = create_graph();
        cin >> num_equipes;
        for (int equipe = 0; equipe < num_equipes; equipe++) {
            cout << "Equipe: " << equipe << endl;
            cin >> c1 >> c2 >> c3;
            setVertice(c1, g);
            cout << "Adicionado o vertice: " << c1 << endl;
            setVertice(c2, g);
            cout << "Adicionado o vertice: " << c2 << endl;
            setVertice(c3, g);
            cout << "Adicionado o vertice: " << c3 << endl;
            setEdge(g, c1, c2);
            setEdge(g, c1, c3);
            setEdge(g, c2, c1);
            setEdge(g, c2, c3);
            setEdge(g, c3, c1);
            setEdge(g, c3, c2);
        }
        // Print the adjacency list for this graph
        cout << "Caso " << caso + 1 << ":" << endl;
        printGraph(g);
        delete g; // Libera a memória alocada para o grafo
    }

    return 0;
}
