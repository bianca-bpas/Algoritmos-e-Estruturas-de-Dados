#include <bits/stdc++.h>

using namespace std;

class SocialNetwork {
public:
    map<string, vector<string>> graph;
    set<string> people;

    void add_person(string person) {
        people.insert(person);
        if (graph.find(person) == graph.end()) {
            graph[person] = {};
        }
    }

    void add_relation(string person1, string person2) {
        if (people.find(person1) != people.end() && people.find(person2) != people.end()) {
            graph[person1].push_back(person2);
            graph[person2].push_back(person1);
            return;
        }
        cout << "Person not found in the network." << endl;
    }

    int get_size() {
        int size = 0;
        for (const auto& people : graph) {
            size += graph[people.first].size();
        }
        return size;
    }
};

int main() {
    SocialNetwork network;

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; ++i) {
        int num_relations;
        cin >> num_relations;

        for (int j = 0; j < num_relations; ++j) {
            string person1, person2;
            cin >> person1 >> person2;
            network.add_person(person1);
            network.add_person(person2);
            network.add_relation(person1, person2);
            
            cout << network.people.size() << endl;
        }
    }

    return 0;
}