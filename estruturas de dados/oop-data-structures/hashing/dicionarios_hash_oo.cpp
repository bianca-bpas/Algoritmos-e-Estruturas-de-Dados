#include <bits/stdc++.h>
using namespace std;

class HashTable {
private:
    struct Par {
        int key;
        int value;
    };

    Par* tabela;
    int m;
    int* perm;
    
    int h(int key) const {
        int temp = (int) floor((((double) key) / ((double) m)));
        return (key - (m * temp)); 
    }
    
    int hash_function(int key) const {
        int indice = h(key);
        int pos = perm[indice] % m;
        return pos;
    }

public:
    HashTable(int tamanho, int* permutacao) : m(tamanho) {
        tabela = new Par[m];
        perm = new int[m - 1];
        
        // Copiar array de permutação
        for (int i = 0; i < m - 1; i++) {
            perm[i] = permutacao[i];
        }
        
        // Inicializar tabela
        for (int i = 0; i < m; i++) {
            tabela[i].key = -1;
            tabela[i].value = -1;
        }
    }
    
    ~HashTable() {
        delete[] tabela;
        delete[] perm;
    }
    
    void inserir(int key, int value) {
        int indice = hash_function(key);
        for (int i = 0; i < m; i++) {
            if (tabela[indice].key == -1) {
                tabela[indice].key = key;
                tabela[indice].value = value;
                return;
            } else {
                indice = hash_function(indice + 1);
            }
        }
    }
    
    pair<int, int> buscar(int key) {
        for (int i = 0; i < m; i++) {
            int indice = hash_function(key);
            if (tabela[indice].key == key) {
                return {indice, tabela[indice].value};
            } else {
                indice = hash_function(indice + 1);
            }
        }
        return {-1, -1};
    }
};

int main() {
    int m = -1, n;
    string operacao;
    int key, value;
    
    while (true) {
        cin >> m;
        if (m == 0) break;
        
        if (m > 1) {
            int perm[m - 1];
            for (int i = 0; i < m - 1; i++) {
                cin >> perm[i];
            }
            
            HashTable tabela(m, perm);
            
            cin >> n; // número de operações
            for (int j = 0; j < n; j++) {
                cin >> operacao;
                if (operacao == "add") {
                    cin >> key >> value;
                    tabela.inserir(key, value);
                } else if (operacao == "find") {
                    cin >> key;
                    pair<int, int> resultado = tabela.buscar(key);
                    if (resultado.first != -1) {
                        cout << resultado.first << " " << resultado.second << endl;
                    } else {
                        cout << resultado.first << endl;
                    }
                }
            }
        }
    }
    
    return 0;
}