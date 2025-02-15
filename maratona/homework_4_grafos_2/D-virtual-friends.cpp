#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
        map<string, vector<string>> adjList;
        set<string> people;
        map<string, bool> visited;

    public:
        void addPerson(string person){
            people.insert(person);
            if (adjList.find(person) == adjList.end()){
                adjList[person] = {};
            }
            visited[person] = false;
        }
        void setEdge(string a, string b) {
            if (people.find(a) != people.end() && people.find(b) != people.end()){
                adjList[a].push_back(b);
                adjList[b].push_back(a);
            }
        }
        int BFS(string start){
            queue<string> q;
            q.push(start);

            int count = 0;
            while (!q.empty()){
                string s = q.front();
                visited[s] = true;
                q.pop();
                count++;
                for (string v : adjList[s]){
                    if (!visited[v]){
                        q.push(v);
                    }
                }
            }
            return count;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0; i < t; i++){
        Graph g;
        int F; cin >> F;
        for (int j = 1; j <= F; j++){
            string a, b; cin >> a >> b;
            g.addPerson(a);
            g.addPerson(b);
            g.setEdge(a, b);
            
            cout << g.BFS(b) << '\n';
        }
    }
    return 0;
}