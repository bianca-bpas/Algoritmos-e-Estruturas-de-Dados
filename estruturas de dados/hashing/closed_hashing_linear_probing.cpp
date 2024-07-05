/* Implemente uma tabela de dispersão para strings e use linear probing para tratar colisões. Utilize o algoritmo fold como função hash */
#include <iostream>
using namespace std;

int fold(string key, int m);
void inicializarTabela(string *tabela, int m);
void add(string key, string *tabela, int m);
int search(string key, string *tabela, int m);
void remove(string key, string *tabela, int m);


int main(){
    int m;
    cin >> m; // quantidade de espaços no array
    string tabela[m];
    inicializarTabela(tabela, m);
    string temp, x;

    for (int i = 0; i < m; i++){
        cin >> temp >> x;
        if (temp == "add"){
            add(x, tabela, m);
        } else if (temp == "rmv"){
            remove(x, tabela, m);
        } else if (temp == "sch"){
            int pos = search(x, tabela, m);
            cout << x << " " << pos << endl;
        }
    }
    return 0;
}

int fold(string key, int m){
    int s, sum=0;
    s = key.length();
    for (int  i = 0; i < s; i++){
        sum += key[i];
    }
    return abs(sum)%m;
}

void inicializarTabela(string *tabela, int m){
    for (int i = 0; i < m; i++){
        tabela[i] = "-1";
    }
}

void add(string key, string *tabela, int m){
    int indice = fold(key, m);
    while (tabela[indice] != "-1"){
        indice = abs(indice+1) % m;

    }
    tabela[indice] = key;
}

int search(string key, string *tabela, int m){
    int indice = fold(key, m);
    while (tabela[indice] != "-1"){
        if (tabela[indice] == key){
            return indice;
        } else {
            indice = abs(indice+1) % m;
        }
    }
    return -1;
}

void remove(string key, string *tabela, int m){
    int indice = fold(key, m);
    while (tabela[indice] != "-1"){
        if (tabela[indice] == key){
            tabela[indice] = "-1";
        } else {
            indice = abs(indice+1) % m;
        }
    }
}
