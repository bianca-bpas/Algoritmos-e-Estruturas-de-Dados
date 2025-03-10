#include <iostream>
#include <vector>
using namespace std;

/* Dado o conjunto C de inteiros, encontre um subconjunto de C cuja soma de seus elementos é igual a S.
 */

bool findSubset(vector<int> C, int S, vector<int>& subset, int index) {
    int n = C.size();
    if (S == 0) {
        return true;
    }
    if (index >= n || S < 0) {
        return false;
    }

    subset.push_back(C[index]);
    if (findSubset(C, S - C[index], subset, index + 1)) {
        return true;
    }
    subset.pop_back();

    if (findSubset(C, S, subset, index + 1)) {
        return true;
    }

    return false;
}

int main() {
    int n, S;
    cout << "Digite a quantidade de elementos e a soma desejada: ";
    cin >> n >> S;

    vector<int> C(n);
    cout << "Digite os elementos do conjunto: ";
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    vector<int> subset;
    if (findSubset(C, S, subset, 0)) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "Nenhum subconjunto encontrado" << endl;
    }

    return 0;
}
