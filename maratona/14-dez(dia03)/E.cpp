#include "bits/stdc++.h"
#define endl "\n"
#define ll long long
using namespace std;

bool subsetSum(vector<ll>& numbers, ll target);
void findSubsets(vector<ll>& numbers, vector<vector<bool>>& dp, ll n, ll target, vector<ll>& current, vector<vector<ll>>& resultado);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, temp; cin >> n >> x;
    vector<ll> numbers;
    for (ll i = 0; i < n; i++){
        cin >> temp; numbers.push_back(temp);
    }

    if (!subsetSum(numbers, x)){
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

bool subsetSum(vector<ll>& numbers, ll target){
    ll n = numbers.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (ll i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= target; j++){
            if (j < numbers[i-1]){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j-numbers[i-1]] || dp[i-1][j];
            }
        }
    }

    if (!dp[n][target]){
        return false;
    }

    vector<ll> current;
    vector<vector<ll>> resultado;
    findSubsets(numbers, dp, n, target, current, resultado);
    bool two_size_subset = false;

    for (ll i = 0; i < resultado.size(); i++){
        for (ll j = 0; j < resultado[i].size(); j++){
            if (resultado[i].size() == 3){
                cout << resultado[i][j] << " ";
                two_size_subset = true;
            }
        }
    }
    
    if (two_size_subset){
        cout << endl;
        return true;
    } else {
        return false;
    }
}

void findSubsets(vector<ll>& numbers, vector<vector<bool>>& dp, ll n, ll target, vector<ll>& current, vector<vector<ll>>& resultado){
    if (target == 0){
        resultado.push_back(current);
        return;
    }
    if (n == 0 || target < 0){
        return;
    }

    if (dp[n-1][target]){
        findSubsets(numbers, dp, n-1, target, current, resultado);
    }

    if (target >= numbers[n-1] && dp[n-1][target-numbers[n-1]]){
        current.push_back(n);
        findSubsets(numbers, dp, n-1, target-numbers[n-1], current, resultado);
        current.pop_back();
    }
}
