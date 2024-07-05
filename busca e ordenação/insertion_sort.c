// INSERTION SORT

#include <stdio.h>

int main(){
    int lista[] = {89, 45, 68, 90, 29, 34, 17};
    int n = sizeof(lista)/sizeof(lista[0]), j, v;

    printf("Lista inicial: ");
    for (int elem=0; elem < n; elem++){
        printf("%d ", lista[elem]);
    }

    if (n>1){
        for (int i=1; i < n; i++){
            j = i-1;
            v = lista[i];
            while(j >= 0 && lista[j] > v){
                lista[j+1] = lista[j];
                j--;
            lista[j+1] = v;
            }
        }
    }
    
    printf("\nLista ordenada: ");
    for (int elem=0; elem < n; elem++){
        printf("%d ", lista[elem]);
    }

    return 0;
}