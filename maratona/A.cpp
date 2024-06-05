#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

// BINARY SEARCH
int binary_search(int chave, int lista[], int inicio, int fim){
    int posicao = -1, meio;

    while (inicio <= fim){
        meio = (int)((inicio + fim) / 2);
        if (chave == lista[meio]){
            posicao = meio;
        } 
        if (chave < lista[meio]){
            fim = meio-1;
        }else{
            inicio = meio + 1;
        }
    }

    return posicao;
}


int main(){
    int N, K;
    
    cin >> N >> K;
    K = sqrt(K);

    int arr[2*N];

    // criando array
    for (int i=1; i<=2*N; i++){
        arr[i-1] = i;
    }

    // encontrando a outra extremidade
    int posicao;
    int tam = 2*N;
    posicao = binary_search(K, arr, 0, tam-1);
    
    long long res = arr[tam-1-posicao]*arr[tam-1-posicao];
    cout << res << endl;

    return 0;
}