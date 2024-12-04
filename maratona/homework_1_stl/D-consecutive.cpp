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
            prefixSum.push_back(1);
        } else {
            prefixSum.push_back(0);
        }
    }

    for (int i = 0; i < queries; i++){
        cin >> left >> right;
        auto itLeft = prefixSum.begin() + left;
        auto itRight = prefixSum.begin() + right;

        int contagem = accumulate(itLeft, itRight, 0);
        cout << contagem << endl;
    }

    return 0;
}