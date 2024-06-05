// SEQUENTIAL SEARCH

#include <stdio.h>

int sequential_search(int lista[0], int K, int n){
    int i=0;
    while (i < n && lista[i] != K){
        i = i + 1;
    }
    if (i < n){
        return i;
    }else{
        return -1;
    }
}

int main(){
    int lista[] = {89, 45, 68, 90, 29, 34, 17};
    int n = sizeof(lista)/sizeof(lista[0]);
    int K;

    printf("Digite the key: ");
    scanf("%d", &K);
    K = sequential_search(lista, K, n);
    if (K != -1){
        printf("A chave foi encontrada na posicao %d", K);
    }else{
        printf("A chave nao foi encontrada na lista!");
    }

    return 0;
}