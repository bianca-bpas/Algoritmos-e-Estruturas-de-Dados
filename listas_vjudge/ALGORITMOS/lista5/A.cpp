#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
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
    g->numEdge = 0;
    g->numVertices = 0;
    return g;
}

void setVertice(string contestant, Graph* g) {
    if (find(g->contestants.begin(), g->contestants.end(), contestant) == g->contestants.end()) {
        g->contestants.push_back(contestant);
        g->vetor.push_back(list<string>());
        g->numVertices++;
        g->Mark.push_back("UNVISITED");
    }
}

void setEdge(Graph *g, string i, string j) {
    int index = 0;
    for (; index < g->contestants.size(); ++index) {
        if (g->contestants[index] == i) {
            break;
        }
    }
    list<string> &lista = g->vetor[index];
    if (find(lista.begin(), lista.end(), j) == lista.end()) {
        g->vetor[index].push_back(j);
        g->numEdge++;
    }
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

void setMark(Graph* g, int v, string mark) {
    g->Mark[v] = mark;
}

string getMark(Graph *g, int v) {
    return g->Mark[v];
}

int getIndex(Graph *g, string name) {
    for (int i = 0; i < g->contestants.size(); i++) {
        if (g->contestants[i] == name) {
            return i;
        }
    }
    return -1;
}

vector<string> BFS_shortest_path(Graph *g, string start, string end) {
    int startIndex = getIndex(g, start);
    int endIndex = getIndex(g, end);

    if (startIndex == -1 || endIndex == -1) {
        return {};
    }

    queue<int> Q;
    vector<int> predecessor(g->numVertices, -1);
    vector<string> path;
    bool found = false;

    fill(g->Mark.begin(), g->Mark.end(), "UNVISITED");

    Q.push(startIndex);
    setMark(g, startIndex, "VISITED");
    while (!Q.empty() && !found) {
        int v = Q.front();
        Q.pop();
        for (auto it = g->vetor[v].begin(); it != g->vetor[v].end(); ++it) {
            int adjIndex = getIndex(g, *it);
            if (getMark(g, adjIndex) == "UNVISITED") {
                setMark(g, adjIndex, "VISITED");
                predecessor[adjIndex] = v;
                if (adjIndex == endIndex) {
                    found = true;
                    break;
                }
                Q.push(adjIndex);
            }
        }
    }

    if (found) {
        for (int at = endIndex; at != -1; at = predecessor[at]) {
            path.insert(path.begin(), g->contestants[at]);
        }
    }

    return path;
}

int main() {
    int num_casos;
    cin >> num_casos;
    int num_equipes;
    string c1, c2, c3;
    for (int caso = 0; caso < num_casos; caso++) {
        Graph *g = create_graph();
        cin >> num_equipes;
        for (int equipe = 0; equipe < num_equipes; equipe++) {
            cin >> c1 >> c2 >> c3;
            setVertice(c1, g);
            setVertice(c2, g);
            setVertice(c3, g);
            setEdge(g, c1, c2);
            setEdge(g, c1, c3);
            setEdge(g, c2, c1);
            setEdge(g, c2, c3);
            setEdge(g, c3, c1);
            setEdge(g, c3, c2);
        }

        vector<pair<string, int>> results;

        for (const string& name : g->contestants) {
            vector<string> path = BFS_shortest_path(g, "Ahmad", name);
            if (!path.empty()) {
                results.push_back(make_pair(name, path.size() - 1));
            } else {
                if (name == "Ahmad") {
                    results.push_back(make_pair(name, 0));
                } else {
                    results.push_back(make_pair(name, -1));
                }
            }
        }

        sort(results.begin(), results.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            if (a.second == -1) return false;
            if (b.second == -1) return true;
            return a.second < b.second;
        });

        cout << g->numVertices << endl;
        for (const auto& result : results) {
            cout << result.first << " ";
            if (result.second == -1) {
                cout << "undefined" << endl;
            } else {
                cout << result.second << endl;
            }
        }

        delete g;
    }

    return 0;
}
