#include <iostream>
using namespace std;

class Pair {
    public:
        int key;
        int value;
        bool isOccupied;
        
        Pair() : key(-1), value(-1), isOccupied(false) {}
        ~Pair() = default;
};

class HashTable {
    private:
        int m;
        int cnt;
        Pair* table;
        
        int hash(int key) {
            return key % m;
        }
        
    public:
        HashTable(int size=101) : m(size), cnt(0) {
            table = new Pair[size];
        }
        
        ~HashTable() {
            delete[] table;
        }
        
        void insert(int key, int value) {
            if (cnt >= m) {
                cout << "Tabela cheia!" << endl;
                return;
            }
            
            int index = hash(key);
            
            int i = 0;
            while (i < m) {
                int currentIndex = (index + i) % m;
                
                if (!table[currentIndex].isOccupied) {
                    table[currentIndex].key = key;
                    table[currentIndex].value = value;
                    table[currentIndex].isOccupied = true;
                    cnt++;
                    return;
                } else if (table[currentIndex].key == key) {
                    table[currentIndex].value = value;
                    return;
                }
                
                i++;
            }
        }
        void display() {
            for (int i = 0; i < m; i++) {
                cout << i << ": ";
                if (table[i].isOccupied) {
                    cout << "(" << table[i].key << ", " << table[i].value << ")";
                }
                cout << endl;
            }
        }
        int search(int key) {
            int index = hash(key);
            
            for (int i = 0; i < m; i++) {
                int currentIndex = (index + i) % m;
                
                if (!table[currentIndex].isOccupied) {
                    return -1;
                }
                
                if (table[currentIndex].isOccupied && table[currentIndex].key == key) {
                    return table[currentIndex].value;
                }
            }
            
            return -1;
        }
        
        bool deleteKey(int key) {
            int index = hash(key);
            
            for (int i = 0; i < m; i++) {
                int currentIndex = (index + i) % m;
                
                if (!table[currentIndex].isOccupied) {
                    return false;
                }
                
                if (table[currentIndex].isOccupied && table[currentIndex].key == key) {
                    table[currentIndex].isOccupied = false;
                    cnt--;
                    return true;
                }
            }
            
            return false;
        }
        
};

int main() {
    HashTable dict(10);
    
    dict.insert(1, 10);
    dict.insert(2, 20);
    dict.insert(3, 30);
    dict.insert(4, 40);
    dict.insert(5, 50);
    dict.insert(6, 60);
    dict.insert(7, 70);
    dict.insert(8, 80);
    dict.insert(9, 90);
    dict.insert(10, 100);
    dict.insert(11, 110);
    dict.insert(21, 210);
    
    cout << "Tabela após inserções:" << endl;
    dict.display();
    
    int result = dict.search(5);
    cout << "\nBuscando chave 5: ";
    if (result != -1) {
        cout << "Encontrado com valor " << result << endl;
    } else {
        cout << "Não encontrado" << endl;
    }
    
    cout << "\nRemovendo chave 5..." << endl;
    dict.deleteKey(5);
    
    cout << "Tabela após remoção:" << endl;
    dict.display();
    
    result = dict.search(5);
    cout << "\nBuscando chave 5 após remoção: ";
    if (result != -1) {
        cout << "Encontrado com valor " << result << endl;
    } else {
        cout << "Não encontrado" << endl;
    }
    
    return 0;
}