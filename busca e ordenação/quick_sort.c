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

int main(){
    int lista[] = {89, 45, 68, 90, 29, 34, 17};
    int n = sizeof(lista)/sizeof(lista[0]);

    quicksort(lista, 0, n-1);


    return 0;
}