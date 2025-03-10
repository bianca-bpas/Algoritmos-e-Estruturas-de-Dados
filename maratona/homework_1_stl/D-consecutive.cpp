#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int tamanho, queries, left, right;
    cin >> tamanho >> queries;

    string palavra; cin >> palavra;
    vector<int> prefixSum;

    prefixSum.push_back(0);
    for (int i = 1; i < palavra.length(); i++){
        if (palavra[i] == palavra[i-1]){
            prefixSum.push_back(prefixSum[i-1]+1);
        } else {
            prefixSum.push_back(prefixSum[i-1]);
        }
    }

    for (int i = 0; i < queries; i++){
        cin >> left >> right;
        
        if (prefixSum[left-1] != prefixSum[left]){
            left--;
        }
        if(prefixSum[right-1] != prefixSum[right]){
            right--;
        } 

        int contagem = prefixSum[right] - prefixSum[left];
        
        cout << contagem << endl;
    }

    return 0;
}