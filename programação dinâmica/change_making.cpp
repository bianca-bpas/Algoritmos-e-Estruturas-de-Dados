#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int infinite = INT_MAX;

int ChangeMaking(vector<int> D, int n){
    int m = D.size();
    vector<int> F(n+1, infinite);
    F[0] = 0;
    for (int i = 1; i <= n; i++){
        int temp = infinite;
        int j = 1;
        while (j <= m && i >= D[j]){
            temp = min(F[i-D[j]], temp);
            j = j+1;
        }
        F[i] = temp + 1;
    }

    return F[n];
}

int main() {
    int c;
    cout << "Digite o número de casos: ";
    cin >> c;

    for (int i = 0; i < c; i++) {
        int n;
        cout << "Digite o valor do troco: ";
        cin >> n;

        int d;
        cout << "Digite a quantidade de tipos de moedas: ";
        cin >> d;

        vector<int> denominations(d+1);
        denominations[0] = -1;
        cout << "Digite as moedas: ";
        
        for (int i = 1; i <= d; i++){
            cin >> denominations[i];
        }

        int troco = ChangeMaking(denominations, n);
        cout << troco << endl;
    }

    return 0;
}
