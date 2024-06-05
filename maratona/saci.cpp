#include <iostream>
using namespace std;

int main() {
         long int num_lojas;
         int tabaco_saci, paradas=0;
         cin >> num_lojas >> tabaco_saci;
         long int lojas[num_lojas+1][2]; 

        lojas[0][0] = 0;
        lojas[0][0] = 0;
         for (int i = 1; i <= num_lojas; i++){
            cin >> lojas[i][0]; // recebendo distancia
        }
        for (int i = 1; i <= num_lojas; i++){
            cin >> lojas[i][1]; // recebendo unidades de tabaco disponiveis
        }
            
         for (int loja = 1; loja <= num_lojas; loja++){
            if (tabaco_saci >= lojas[loja][0] - lojas[loja-1][0]){
                tabaco_saci -= lojas[loja][0];
            } else {
                tabaco_saci += lojas[loja][1];
                paradas++;
                if (tabaco_saci >= lojas[loja][0] - lojas[loja-1][0]){
                    tabaco_saci -= lojas[loja][0];
                } else {
                    paradas = -1;
                    break;
                }
            }
        }
         cout << paradas << endl;
         
    return 0;
}