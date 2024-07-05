// BUBBLE SORT

#include <stdio.h>

int main(){
    int lista[] = {89, 45, 68, 90, 29, 34, 17};
    int n = sizeof(lista)/sizeof(lista[0]), temp=0;

    printf("Lista inicial: ");
    for (int elem=0; elem < n; elem++){
        printf("%d ", lista[elem]);
    }

    for (int i=0; i < n; i++){
        for (int j=0; j < n-1; j++){
            if (lista[j+1] < lista[j]){
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }

    }

    printf("\nLista ordenada: ");
    for (int elem=0; elem < n; elem++){
        printf("%d ", lista[elem]);
    }
    
    return 0;
}