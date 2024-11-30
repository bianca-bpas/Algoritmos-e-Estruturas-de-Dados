#include <bits/stdc++.h>
using namespace std;

bool coin(string caminho, long long posicao){
    if (caminho[posicao] == '@'){
        return true;
    } else {
        return false;
    }
}

bool thorn(string caminho, long long posicao){
    if (caminho[posicao] == '*'){
        return true;
    } else{
        return false;
    }
}

int main(){
    long long casos, tamanho, pos, moedas;
    string path;
    cin >> casos;

    for (long long caso = 1; caso <= casos; caso++){
        cin >> tamanho;
        cin >> path;
        pos = 0; moedas = 0;
        while (pos+1 < tamanho){
            if (thorn(path, pos+1)){
                if (thorn(path, pos+2)){
                    break;
                }
                pos+=2;

            } else {
                pos++;
            }
            if (coin(path, pos)){
                moedas++;
            }
        }
        if (caso != casos){
            cout << moedas << endl;
        } else {
            cout << moedas;
        }
    }

    return 0;
}