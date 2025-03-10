#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int infinite = INT_MAX;

int StoneRow(vector<int> alturas, int K) {
    int n = alturas.size();
    vector<int> F(n, infinite);
    F[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= K && i + j < n; j++) {
            F[i + j] = min(F[i + j], F[i] + abs(alturas[i] - alturas[i + j]));
        }
    }

    return F[n - 1];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> alturas(N);
    for (int i = 0; i < N; i++) {
        cin >> alturas[i];
    }
  
    int cost = StoneRow(alturas, K);
    cout << cost << endl;

    return 0;
}
