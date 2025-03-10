#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool subsetSum(vector<ll>& numbers, ll target);
void findSubsets(vector<ll>& numbers, vector<vector<bool>>& dp, ll n, ll target, vector<ll>& current, vector<vector<ll>>& resultado);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_estudantes;
    ll minimum_sum, diff_maior_menor, skill;
    cin >> num_estudantes >> minimum_sum >> diff_maior_menor;
    vector<ll> skills;

    for (int estudante = 0; estudante < num_estudantes; estudante++){
        cin >> skill;
        skills.push_back(skill);
    }
    if(!subsetSum(skills, minimum_sum)){
        cout << 0 << endl;
    }

    return 0;
}

bool subsetSum(vector<ll>& numbers, ll target){
    int n = numbers.size();
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

    for (int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= target; j++){
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

    for (auto subset : resultado){
        for (auto num : subset){
            cout << num << " ";
        }
        cout << endl;
    }
    
    return true;
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
        current.push_back(numbers[n-1]);
        findSubsets(numbers, dp, n-1, target-numbers[n-1], current, resultado);
        current.pop_back();
    }

}
