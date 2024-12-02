#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int tamanho, queries, left, right, contagem;
    char letter;
    cin >> tamanho >> queries;

    vector <char> S;
    for (int i = 0; i < tamanho; i++){
        cin >> letter;
        S.push_back(letter);
    }

    for (int i = 0; i < queries; i++){
        cin >> left >> right;
        contagem = 0;
        for (int j = left; j <= right; j+=2){
            if (S[j] == S[j-1]){
                contagem++;
            }
        }
        cout << contagem << endl;
    }

    return 0;
}