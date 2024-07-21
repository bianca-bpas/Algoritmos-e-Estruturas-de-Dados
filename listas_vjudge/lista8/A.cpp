#include <iostream>
#include <vector>
using namespace std;

int Knapsack(int n, int W, vector<int> w, vector<int> v, vector<vector<int>> &F) {
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= W; j++){
            if (i == 0 || j == 0){
                F[i][j] = 0;
            } else if (w[i] <= j){
                F[i][j] = max(F[i-1][j], v[i]+F[i-1][j-w[i]]);
            } else {
                F[i][j] = F[i-1][j];
            }
        }
    }
    return F[n][W];
}

int main(){
    int S, N;
    cin >> S >> N;

    vector<int> weights(N+1);
    vector<int> values(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> F(N+1, vector<int>(S+1, -1));

    int res = Knapsack(N, S, weights, values, F);
    cout << res << endl;

    return 0;
}