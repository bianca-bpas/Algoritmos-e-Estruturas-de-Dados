#include "bits/stdc++.h"
#define endl "\n"
#define ll long long
using namespace std;

bool subsetSum(vector<ll>& numbers, ll target);
void findSubsets(vector<ll>& numbers, vector<bool>& dp, ll n, ll target, vector<ll>& current, vector<vector<ll>>& resultado);

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
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (ll i = 1; i < n; i++){
        for (ll j = target; j >= numbers[i]; j--){
            dp[j] = dp[j] || dp[j - numbers[i]];
        }
    }

    if (!dp[target]){
        return false;
    }

    vector<ll> current;
    vector<vector<ll>> resultado;
    findSubsets(numbers, dp, n, target, current, resultado);
    bool two_size_subset = false;

    for (auto subset : resultado){
        if (subset.size() == 2){
            for (ll num : subset){
                cout << num << " ";
            }
            two_size_subset = true;
        }
    }
    
    if (two_size_subset){
        cout << endl;
        return true;
    } else {
        return false;
    }
}

void findSubsets(vector<ll>& numbers, vector<bool>& dp, ll n, ll target, vector<ll>& current, vector<vector<ll>>& resultado){
    if (target == 0){
        resultado.push_back(current);
        return;
    }
    if (n == 0 || target < 0){
        return;
    }

    if (dp[target]){
        findSubsets(numbers, dp, n-1, target, current, resultado);
    }

    if (target >= numbers[n-1] && dp[target - numbers[n-1]]){
        current.push_back(n);
        findSubsets(numbers, dp, n-1, target - numbers[n-1], current, resultado);
        current.pop_back();
    }
}
