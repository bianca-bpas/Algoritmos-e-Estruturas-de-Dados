// SELECTION SORT

#include <stdio.h>

int main(){
    int lista[] = {89, 45, 68, 90, 29, 34, 17};
    int n=sizeof(lista)/sizeof(lista[0]), min, temp;

    printf("Lista inicial: ");
    for(int item=0; item < n; item++){
        printf("%d ", lista[item]);
    }

    for(int i=0; i < n-1; i++){
        min = i;
        for(int j=i+1; j < n; j++){
            if(lista[j] < lista[min]){
                min = j;
            }
        
        }

        temp = lista[min];
        lista[min] = lista[i];
        lista[i] = temp;
            
    }

    printf("\nLista ordenada: ");
    for(int item=0; item < n; item++){
        printf("%d ", lista[item]);
    }

    return 0;
}