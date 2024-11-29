#include <bits/stdc++.h>
using namespace std;

typedef struct Par{
    int key;
    int value;
}Par;

int h(int key, int mod) {
    int temp = (int) floor((((double) key) / ((double) mod))); return (key - (mod * temp)); 
}

int hash_function(int key, int m, int *perm){
    int indice = h(key, m);
    int pos = perm[indice]%m;
    return pos;
}

void inicializarTabela(Par *tabela, int m){
    for (int i = 0; i < m;i++){
        tabela[i].key = -1;
        tabela[i].value = -1;
    }
}

void insereTabela(int key, int value, Par *tabela, int m, int *perm){
        int indice = hash_function(key, m, perm);
        for (int i = 0; i < m; i++){
            if (tabela[indice].key == -1){
                if (tabela[indice].key != key){
                    tabela[indice].key = key;
                    tabela[indice].value = value;
                }

            } else {
                indice = hash_function(indice+1, m, perm);
            }
        }
}

int findTabela(int key, int value, Par *tabela, int m, int *perm){
    for (int i = 0; i < m; i++){
        int indice = hash_function(key, m, perm);
        if (tabela[indice].key == key){
            return indice;
        } else {
            indice = hash_function(indice+1, m, perm);
        }
    }
    return -1;
}

int main(){
    int m = -1, n;
    string operacao;
    int key, value;
    while (m != 0){
        cin >> m;
        Par tabela[m];
        inicializarTabela(tabela, m);
        int perm[m-1];
        if (m > 1){
            for (int i = 0; i < m-1; i++){
                cin >> perm[i];
            }
            cin >> n; // numero de operações
            for (int j = 0; j < n; j++){
                cin >> operacao;
                if (operacao == "add"){
                    Par par;
                    cin >> par.key >> par.value;
                    insereTabela(par.key, par.value, tabela, m, perm);
                } else if (operacao == "find"){
                    cin >> key;
                    int value;
                    for (int v = 0; v < m; v++){
                        if (tabela[v].key == key){
                            value = tabela[v].value;
                        }
                    }
                    int indice = findTabela(key, value, tabela, m, perm);
                    if (indice != -1){
                        cout << indice << " " << tabela[indice].value << endl;
                    } else {
                        cout << indice << endl;
                    }
                }
            }

        }
        
    }


    return 0;
}