#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos, capacidade, atual, qtd_carros, tamanho, vezes; cin >> casos;
    string origem;
    queue<int> fila_left, fila_right;

    for (int caso = 0; caso < casos; caso++){
        cin >> capacidade >> qtd_carros;
        capacidade *= 100;
        vezes = 0;

        for (int carro = 0; carro < qtd_carros; carro++){
            cin >> tamanho >> origem;
            if (origem == "left"){
                fila_left.push(tamanho);
            } else if (origem == "right"){
                fila_right.push(tamanho);
            }
        }

        while (!fila_left.empty() || !fila_right.empty()){
            atual = capacidade;
            if (!fila_left.empty() || !fila_right.empty()){
                while (!fila_left.empty() && fila_left.front() <= atual){
                    atual -= fila_left.front();
                    fila_left.pop();
                }
                atual = capacidade;
                vezes++;
            }
            if (!fila_right.empty() || !fila_left.empty()){
                while (!fila_right.empty() && fila_right.front() <= atual){
                    atual -= fila_right.front();
                    fila_right.pop();
                }
                vezes++;
            }
        }

        cout << vezes << endl;

    }

    return 0;
}