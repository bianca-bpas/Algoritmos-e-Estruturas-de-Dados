#include <iostream>
#include <vector>
#include <list>
#include <stack> //DFS
#include <queue> //BFS
using namespace std;

typedef struct GraphMatrix{
    vector<vector<int>> adjacencyMatrix;
    vector<string> Mark;
    int numEdges;
    int numVertices;
}GraphMatrix;

GraphMatrix* create_graphMatrix(int n){
    GraphMatrix *g = new GraphMatrix;
    g->Mark.resize(n, "UNVISITED");
    g->adjacencyMatrix.resize(n, vector<int>(n, 0));
    g->numEdges = 0;
    g->numVertices = n;
    return g;
}

typedef struct GraphList{
    vector<list<int>> adjacencyList;
    vector<string> Mark;
    int numEdges;
    int numVertices;
}GraphList;

GraphList* create_graphList(int n){
    GraphList *g = new GraphList;
    g->Mark.resize(n, "UNVISITED");
    g->adjacencyList.resize(n);
    g->numEdges = 0;
    g->numVertices = n;
    return g;
}

int firstMatrix(GraphMatrix* g, int v){
    for (int i = 0; i < g->numVertices; i++){
        if (g->adjacencyMatrix[v][i] != 0){
            return i;
        }
    }
    return g->numVertices;
}

int nextMatrix(GraphMatrix* g, int v, int w){
    for (int i = w+1; i < g->numVertices; i++){
        if (g->adjacencyMatrix[v][i] != 0){
            return i;
        }
    }
    return g->numVertices;
}

int firstList(GraphList* g, int v){
    if (!g->adjacencyList[v].empty()){
        return g->adjacencyList[v].front();
    } else {
        return g->numVertices;
    }
}

int nextList(GraphList* g, int v, int w){
    list<int> adjList = g->adjacencyList[v];
    for (auto it = adjList.begin(); it != adjList
    .end(); it++){
        if (*it > w){
            return *it;
        }
    }
    return g->numVertices;
}

void setEdgeMatrix(GraphMatrix* g, int i, int j, int wt){
    if (wt == 0){
        return;
    }
    if (g->adjacencyMatrix[i][j] == 0){
        g->numEdges++;
    }
    g->adjacencyMatrix[i][j] = wt;
}

void delEdgeMatrix(GraphMatrix* g, int i, int j){
    if (g->adjacencyMatrix[i][j] != 0){
        g->numEdges--;
    }
    g->adjacencyMatrix[i][j] = 0;
}

bool isEdgeList(GraphList* g, int i, int j){
    list<int> adjList = g->adjacencyList[i];
    bool found = false;
    for (auto it = adjList.begin(); it != adjList.end() && !found; it++){
        if (*it == j){
            found = true;
        }
    }
    return found;
}
void setEdgeList(GraphList* g, int i, int j, int wt){
    if (wt == 0){
        return;
    }
    if (!isEdgeList(g, i, j)){
        g->adjacencyList[i].push_back(j);
        g->numEdges++;
    }
}

void delEdgeList(GraphList *g, int i, int j){
    if (isEdgeList(g, i, j)){
        g->adjacencyList[i].remove(j);
        g->numEdges--;
    }
}

void setMark(GraphMatrix *g, int v, string val){
    g->Mark[v] = val;
}

string getMark(GraphMatrix *g, int v){
    return g->Mark[v];
}

void DFS(GraphMatrix *g, int v){
    cout << g->adjacencyMatrix[v].front() << " ";
    setMark(g, v, "VISITED");
    int w = firstMatrix(g, v);
    while (w < g->numVertices){
        if (getMark(g, w) == "UNVISITED"){
            DFS(g, w);
        }
        w = nextMatrix(g, v, w);
    }
    cout << g->adjacencyMatrix[v].front() << endl;
}

void BFS(GraphMatrix *g, int start){
    queue<int> Q;
    Q.push(start);
    setMark(g, start, "VISITED");
    while (Q.size() > 0){
        int v = Q.front();
        Q.pop();
        cout << g->adjacencyMatrix[v].front() << " ";
        int w = firstMatrix(g, v);
        while (w < g->numVertices){
            if (getMark(g, w) == "UNVISITED"){
                setMark(g, w, "VISITED");
                Q.push(w);
            }
            w = nextMatrix(g, v, w);
        }
        cout << g->adjacencyMatrix[v].front() << endl;
    }
}

void graphTraverse(GraphMatrix* g){
    for (int v = 0; v < g->numVertices; v++){
        setMark(g, v, "UNVISITED");
    }
    for (int v = 0; v < g->numVertices; v++){
        if (getMark(g, v) == "UNVISITED"){
            DFS(g, v);
        }
    }
}

void toposort(GraphMatrix* g, int v, stack<int>s){
    setMark(g, v, "VISITED");
    int w = firstMatrix(g, v);
    while (w < g->numVertices){
        if (getMark(g, w) == "UNVISITED"){
            toposort(g, w, s);
        }
        w = nextMatrix(g, v, w);
    }
    s.push(v);
}

vector<int> shortest_path(GraphMatrix *g, int start, int end){
    queue<int> Q;
    vector<int> predecessor(g->numVertices, -1);
    vector<int> path;
    bool found = false;
    Q.push(start);
    setMark(g, start, "VISITED");
    while (Q.size() > 0 && !found){
        int v = Q.front();
        Q.pop();
        int w = firstMatrix(g, v);
        while (w < g->numVertices){
            if (getMark(g, w) == "UNVISITED"){
                setMark(g, w, "VISITED");
                predecessor[w] = v;
                if (w == end){
                    found = true;
                    break;

                }
                Q.push(w);
            }
            w = nextMatrix(g, v, w);
        }
    }
    if (found){
        for (int i = end; i != -1; i = predecessor[i]){
            path.insert(path.begin(), i);
        }
    }
    return path;
}

int main(){
    int numVertices = 6;
    GraphMatrix *g = create_graphMatrix(numVertices);
    setEdgeMatrix(g, 0, 4, 1);
    setEdgeMatrix(g, 0, 4, 1);
    setEdgeMatrix(g, 0, 4, 1);
    setEdgeMatrix(g, 0, 4, 1);
    setEdgeMatrix(g, 1, 2, 1);
    setEdgeMatrix(g, 0, 2, 1);
    setEdgeMatrix(g, 1, 5, 1);
    setEdgeMatrix(g, 2, 0, 1);
    setEdgeMatrix(g, 2, 1, 1);
    setEdgeMatrix(g, 2, 3, 1);
    setEdgeMatrix(g, 2, 5, 1);
    setEdgeMatrix(g, 3, 2, 1);
    setEdgeMatrix(g, 3, 5, 1);
    setEdgeMatrix(g, 4, 0, 1);
    setEdgeMatrix(g, 4, 5, 1);
    setEdgeMatrix(g, 5, 1, 1);
    setEdgeMatrix(g, 5, 2, 1);
    setEdgeMatrix(g, 5, 3, 1);
    setEdgeMatrix(g, 5, 4, 1);

    for (int v = 0; v < g->numVertices; v++){
        setMark(g, v, "UNVISITED");
    }
    vector<int> path = shortest_path(g, 0, 5);
    for (int v : path){
        cout << v << " ";
    }
    cout << endl;

    delete g;
    return 0;
}
