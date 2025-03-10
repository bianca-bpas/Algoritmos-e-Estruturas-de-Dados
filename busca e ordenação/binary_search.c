// QUICK SORT

#include <stdio.h>

void quicksort(int lista[], int inicio, int fim){
    if (inicio < fim){
        int split;
        split = partition(lista, inicio, fim);
        quicksort(lista, inicio, split-1);
        quicksort(lista, split+1, fim);
    }
}


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
    int lista[] = {89, 45, 68, 90, 29, 34, 17, 59}, chave, posicao;
    int n = sizeof(lista)/sizeof(lista[0]);

    quicksort(lista, 0, n-1);

    printf("\nDigite a chave: "); // Chave = K de Bob
    scanf("%d", &chave);

    posicao = binary_search(chave, lista, 0, n-1);
    
    printf("%d", lista[n-1-posicao]);

    return 0;
}
