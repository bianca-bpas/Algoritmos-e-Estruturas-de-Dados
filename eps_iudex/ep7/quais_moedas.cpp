#include <bits/stdc++.h>
using namespace std;

vector<int> CoinRow(vector<int> C){
    int n = C.size();
    vector <int> F(n);
    vector <int> res;
    F[0] = 0;
    F[1] = C[1];
    
    for (int i = 2; i < n; i++){
        F[i] = max(C[i]+F[i-2], F[i-1]);
    }

    for (int i = n-1; i > 3; i--){
        if (F[i] != F[i-1]){
            int x = F[i]-F[i-2];
            bool found = false;
            for (int f : C){
                if (f==x){
                    found = true;
                }
            }
            if (found){
                res.push_back(x);
            }
            
        } 
    }
    res.push_back(F[1]);

    return res;
} 


int main(){
    int c;
    cin >> c;
    
    for (int i = 1; i <= c; i++){
        int n; // número de moedas
        cin >> n;
        vector<int> moedas(n+1);
        moedas[0] = -1;

        for (int j = 1; j <= n; j++){
            cin >> moedas[j];
        }

        vector<int> res = CoinRow(moedas);
        int maior = 0;
        for (int x : res){
            maior += x;
        }

        cout << "Caso " << i << ": ";
        for (int num = res.size()-1; num >= 0; num--){
            if (num != 0){
                cout << res[num] << "+";
            } else {
                cout << res[num] << "=";
            }
            
        }
        cout << maior << endl;

    }

    return 0;
}