#include <bits/stdc++.h>
using namespace std;
const int infinite = INT_MAX;

struct Graph{
    vector <list<pair<int, int>>> adjList;
    int numEdge;
    vector<string> Mark;
    int numVertice;
    vector<int> distance;
    vector<int> Vprim;
};

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->adjList.resize(n);
    g->numEdge = 0;
    g->Mark.resize(n, "UNVISITED");
    g->numVertice = n;
    g->distance.resize(n, infinite);
    g->Vprim.resize(n, -1);
    return g;
}

int first(Graph* g, int v) {
    if (!g->adjList[v].empty()) {
        return g->adjList[v].front().first;
    }
    return g->numVertice;
}

int next(Graph* g, int v, int w) {
    if (!g->adjList[v].empty()) {
        for (auto it = g->adjList[v].begin(); it != g->adjList[v].end(); it++) {
            if (it->first == w) {
                ++it;
                if (it != g->adjList[v].end()) {
                    return it->first;
                }
                break;
            }
        }
    }
    return g->numVertice;
}

bool isEdge(Graph* g, int i, int j){
    bool found = false;
    for (auto it = g->adjList[i].begin(); it != g->adjList[i].end(); it++){
        if (it->first == j){
            found = true;
            break;
        }
    }
    return found;
}

void setEdge(Graph* g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    if (!isEdge(g, i, j)) {
        g->adjList[i].push_back({ j, wt });
        g->adjList[j].push_back({ i, wt });
        g->numEdge++;
    }
}

int weight(Graph *g, int i, int j){
    for (auto it = g->adjList[i].begin(); it != g->adjList[i].end(); it++){
        if (it->first == j){
            return it->second;
        }
    }
    return 0;
}

void setMark(Graph *g, int v, string val){
    g->Mark[v] = val;
}

string getMark(Graph *g, int v){
    return g->Mark[v];
}


void Prim(Graph *g){
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > minHeap;
    
    minHeap.push(make_tuple(0, 0, 0));
    g->distance[0] = 0;

    int p, v, w;
    for (int i = 0; i < g->numVertice; i++){
        do{
            if (minHeap.empty()){
                return;
            }
            tuple<int, int, int> top = minHeap.top();
            p = get<1>(top);
            v = get<2>(top);
            minHeap.pop();
        } while (getMark(g, v) == "VISITED");
        setMark(g, v, "VISITED");
        g->Vprim[v] = p;
        w = first(g, v);

        while (w < g->numVertice){
            if (getMark(g, w) != "VISITED" && g->distance[w] > weight(g, v, w)){
                g->distance[w] = weight(g, v, w);
                minHeap.push(make_tuple(g->distance[w], v, w));
            }
            w = next(g, v, w);
        }
    }
}

int main(){
    int numCidades, numObras;
    cin >> numCidades >> numObras;
    int numCaso = 1;
    Graph *grafo;

    while (numCidades > 0){
        if (numObras >= 0){
            grafo = create_graph(numCidades);

            int i, j, preco;
            for (int k = 0; k < numObras; k++){
                cin >> i >> j >> preco;
                if (i >= 0 && i < numCidades){
                    if (j >= 0 && j < numCidades){
                        if (preco > 0 && preco <= 100){
                            setEdge(grafo, i, j, preco);

                        }
                    }

                }
        
            }

            Prim(grafo);
            
            int sum = 0;
            for (int d = 0; d < grafo->numVertice; d++){
                sum += grafo->distance[d];
            }

            cout << "Caso " << numCaso << ": " << sum << endl;

            delete grafo;

        cin >> numCidades >> numObras;
        numCaso++;
        }


    }
    return 0;
}