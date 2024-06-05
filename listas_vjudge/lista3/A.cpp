#include <iostream>
using namespace std;
#define m 101
int count;

void inicializarTabela(string *tabela);
int hashFunction(string key);
int searchTabela(string key, string *tabela);
void insereTabela(string key, string *tabela);
void removeTabela(string key, string *tabela);
void printTabela(string *tabela);

int main(){
    string tabela[m];
    int t, n1;
    string temp, operation, word;
    cin >> t; // número de casos de teste
    for (int i = 0; i < t; i++){
        inicializarTabela(tabela);
        cin >> n1; // número de operações
        for (int j = 0; j < n1; j++){
            cin >> temp;
            operation = temp.substr(0, 3);
            word = temp.substr(4);
            if (operation == "ADD"){
                insereTabela(word, tabela);
            } else if (operation == "DEL"){
                removeTabela(word, tabela);
            } else {
                j--;
            }  
        }
        cout << count << endl;
        printTabela(tabela);
    }

    return 0;
}

void inicializarTabela(string *tabela){
    for (int i = 0; i < m; i++){
        tabela[i] = "-1";
    }
    count = 0;
}

int hashFunction(string key){
    int sum = 0;
    for (int i = 1; i <= (int)key.length(); i++){
        sum += (int)key[i-1]*i;
    }
    
    sum *= 19;
    return abs(sum) % m;
}

int searchTabela(string key, string *tabela){
    int indice = hashFunction(key);
    int originalIndice = indice;
    int j = 1;
    while (tabela[indice] != "-1"){
        if (tabela[indice] == key){
            return indice;
        } else {
            indice = originalIndice;
            indice += (j * j + 23 * j);
            indice %= m;
            j++;
            if (indice == originalIndice) {
                break;
            }
        }
    }
    return -1;
}

void insereTabela(string key, string *tabela){
    int pos = searchTabela(key, tabela);
    if (pos == -1){
        int j = 1;
        int indice = hashFunction(key);
        int originalIndice = indice;
        while (tabela[indice] != "-1"){
            if (j <= 19){
                indice = originalIndice;
                indice += (j * j + 23 * j);
                indice %= m;
                j++;
                if (indice == originalIndice) {
                    break;
                }
            } else {
                break;
            }  
        }
        if (tabela[indice] == "-1"){
            tabela[indice] = key;
            count++;
        }
    }
}

void removeTabela(string key, string *tabela) {
    int pos = searchTabela(key, tabela);
    if (pos != -1) {
        tabela[pos] = "-1";
        count--;
    }
}

void printTabela(string *tabela){
    for (int i = 0; i < m; i++){
        if (tabela[i] != "-1"){
            cout << i << ":" << tabela[i] << endl;
        }
    }
}