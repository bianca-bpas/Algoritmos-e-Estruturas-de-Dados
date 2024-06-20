#include <bits/stdc++.h>
using namespace std;

void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = 2*i+1;
    while (j <= f){
        if (j < f && vet[j] < vet[j+1]){
            j++;
        }
        if (aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2*i+1;
        } else {
            break;
        }
    }
    vet[i] = aux;
}

void heapSort(int *vet, int N){
    for (int i = (N-1)/2; i >= 0; i--){
        criaHeap(vet, i, N-1);
    }
    for (int i = N-1; i > 0; i--){
        swap(vet[0], vet[i]);
        criaHeap(vet, 0, i-1);
    }
}

int main(){
    int vet[] = {4, 3, 2, 10, 12, 1, 5, 6};
    int N = sizeof(vet)/sizeof(vet[0]);
    heapSort(vet, N);
    for (int i = 0; i < N; i++){
        cout << vet[i] << " ";
    }

    return 0;
}