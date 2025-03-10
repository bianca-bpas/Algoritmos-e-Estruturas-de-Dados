#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n;

    vector<int> numbers;
    map<int, bool> visited;
    unordered_map<int, int> last_seen;

    for (int i = 0; i < n; i++) {
        cin >> k;
        numbers.push_back(k);
        visited[k] = false;
    }

    int maximum = 1;
    visited[numbers[0]] = true;
    last_seen[numbers[0]] = 0;

    for (int j = 1; j < n; j++) {
        if (!visited[numbers[j]]) {
            maximum++;
            visited[numbers[j]] = true;
            last_seen[numbers[j]] = j;
        } else {
            int distancia = last_seen[numbers[j]] - j;
            if (distancia >= maximum){
                maximum = distancia;
                last_seen[numbers[j]] = j;
            }
        }
    }

    cout << maximum << endl;

    return 0;
}
