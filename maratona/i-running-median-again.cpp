#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int search(vector<int> *lista, int inicio, int fim){
    int meio = (int)((inicio + fim) / 2);

}


int main(){
    int t, n, meio; cin >> t;
    vector<int> lista;

    for (int i = 0; i < t; i++){
        if (n > 0){
            lista.push_back(n);
        } else if (n == -1){
            if (!lista.empty()){
                meio = (int)((0 + lista.size()-1) / 2);
                while (iterator it != lista.end()){

                }
                lista = lista.erase(meio);
            }
        }
    }

    return 0;
}