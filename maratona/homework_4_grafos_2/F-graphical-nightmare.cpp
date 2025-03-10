#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, int>
using namespace std;

class Graph{
    private:
        int numVertices;
        vector<vector<pair<int, ll>>> adjList;
        vector<bool> visited;
        vector<vector<int>> adjListMST;

    public:
        Graph(int n) : numVertices(n) {
            adjList.resize(n);
            visited.resize(n, false);
        }

        void setEdge(int a, int b, ll c){
            if (a-1 < numVertices && b-1 < numVertices){
                adjList[a-1].push_back(make_pair(b-1, c));
                adjList[b-1].push_back(make_pair(a-1, c));
            }
        }
        ll Prim(int start){
            priority_queue <pi, vector<pi>, greater<pi>> minHeap;
            minHeap.push(make_pair(0, start-1));

            ll cost = 0;
            while (!minHeap.empty()){
                auto [w, u] = minHeap.top();
                minHeap.pop();

                if (visited[u] == false){
                    visited[u] = true;
                    cost += w;
                    

                    for (auto [v, c] : adjList[u]){
                        if (visited[v] == false){
                            minHeap.push(make_pair(c, v));
                        }
                    }
                }
            } 
            return cost;
        }
        void DFS(int start){
            stack<int> s;
            s.push(start-1);
            int h = 0;

            while (!s.empty()){
                int u = s.top();
                visited[u] = true;
                s.pop();
                int count = 0;

                for (int v : adjList[u]){
                    if (!visited[v]){
                        s.push(v);
                        count++;
                    }
                }
                h = max(h, count);
            }
        }
        
};

int main(){
    int n, m; cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++){
        int u, v;
        ll c;
        cin >> u >> v >> c;
        g.setEdge(u, v, c);
    }
    cout << g.Prim(1) << '\n';
    cout << g.alturaMST() << '\n';

    return 0;
}