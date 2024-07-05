// MERGE SORT

#include <stdio.h>

void merge(int lista[], int inicio, int fim, int n){
    int lista_temp[7];

    for (int i=inicio; i <= fim; i++){
        lista_temp[i] = lista[i];

    }

    for (int elem=0; elem < n; elem++){
        printf("%d ", elem);
    }
    printf("\nTeste\n");

    

    /*meio = (fim-inicio)/2;
    i1 = inicio;
    i2 = meio+1;*/

}

void mergesort(int lista[], int inicio, int fim, int n){
    int meio;


    meio = (fim-inicio)/2;
    mergesort(lista, inicio, meio, n);
    mergesort(lista, meio+1, fim, n);
    merge(lista, inicio, fim, n);

}


int main(){
    int lista[] = {89, 45, 68, 90, 29, 34, 17};
    int n = sizeof(lista)/sizeof(lista[0]);

    mergesort(lista, 0, n-1, n);

    return 0;
}