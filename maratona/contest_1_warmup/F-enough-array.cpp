#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, K;
    cin >> N >> K;
    
    // Manteremos o array de soma de prefixos, que é uma boa ideia
    vector<ll> prefixSum(N + 1, 0);  // Adicionamos um elemento extra no início
    
    // Calculamos a soma de prefixos começando do índice 1
    for (ll i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        prefixSum[i] = prefixSum[i-1] + x;
    }
    
    // Usaremos dois ponteiros em vez do loop aninhado
    ll res = 0;
    ll left = 0;
    
    // Para cada posição right, encontramos a posição left mais à direita
    // tal que a soma do subarray [left, right] seja >= K
    for (ll right = 1; right <= N; right++) {
        while (left < right && prefixSum[right] - prefixSum[left] >= K) {
            left++;
        }
        // Se encontramos uma soma válida, adicionamos o número de subarrays
        // que começam antes de left e terminam em right
        if (prefixSum[right] - prefixSum[left-1] >= K) {
            res += left;
        }
    }
    
    cout << res << '\n';
    return 0;
}