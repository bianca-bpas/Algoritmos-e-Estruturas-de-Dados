#include <iostream>
#include <cmath>
using namespace std;

class Pair {
    public:
        int key;
        int value;

        Pair() : key(-1), value(-1) {}
        ~Pair() = default;
};

class HashTable {
    private:
        int m;
        int cnt;
        Pair* table;
        int* perm;
        
        int h(int key) {
            int temp = (int) floor(((double) key) / ((double) m));
            return (key - (m * temp)); 
        }
        
        int hash_function(int key) {
            int indice = h(key);
            int pos = perm[indice] % m;
            return pos;
        }

    public:
        HashTable(int size, int* permutacao) : m(size) {
            table = new Pair[m];
            perm = new int[m - 1];
            
            for (int i = 0; i < m - 1; i++) {
                perm[i] = permutacao[i];
            }
        }
        ~HashTable() {
            delete[] table;
            delete[] perm;
        }
        
        void insert(int key, int value) {
            int indice = hash_function(key);
            for (int i = 0; i < m; i++) {
                if (table[indice].key == -1) {
                    table[indice].key = key;
                    table[indice].value = value;
                    cnt++;
                    return;
                } else {
                    indice = hash_function(indice + 1);
                }
            }
        }

        void display() {
            for (int i = 0; i < m; i++) {
                cout << i << ": ";
                if (table[i].key != -1) {
                    cout << "(" << table[i].key << ", " << table[i].value << ")";
                }
                cout << endl;
            }
        }
        
        int search(int key) {
            for (int i = 0; i < m; i++) {
                int indice = hash_function(key);
                if (table[indice].key == key) {
                    return table[indice].value;
                } else {
                    indice = hash_function(indice + 1);
                }
            }
            return -1;
        }

        bool deleteKey(int key) {
            for (int i = 0; i < m; i++) {
                int indice = hash_function(key);
                if (table[indice].key == key) {
                    table[indice].key = -1;
                    table[indice].value = -1;
                    cnt--;
                    return true;
                } else {
                    indice = hash_function(indice + 1);
                }
            }
            return false;
        }
};

int main() {
    int m, n;
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
            
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> operacao;
                if (operacao == "add") {
                    cin >> key >> value;
                    tabela.insert(key, value);
                } else if (operacao == "find") {
                    cin >> key;
                    int resultado = tabela.search(key);
                    if (resultado != -1) {
                        cout << resultado << " " << resultado << endl;
                    } else {
                        cout << resultado << endl;
                    }
                }
            }
        }
    }
    
    return 0;
}