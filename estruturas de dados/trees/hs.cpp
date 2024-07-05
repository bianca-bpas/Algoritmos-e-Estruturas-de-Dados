#include <iostream>
using namespace std;

void criaHeap(int *H, int i, int f){
    int aux = H[i];
    int j = 2*i+1;
    while (j <= f){
        if (j < f && H[j] < H[j+1]){
            j++;
        }
        if (aux < H[j]){
            H[i] = H[j];
            i = j;
            j = 2*i+1;
        } else {
            j = f + 1;
        }
    }
    H[i] = aux;
}

void heapSort(int *H, int n){
    for (int i = (n-1)/2; i >= 0; i--){
        criaHeap(H, i, n-1);
    }
    for (int i = n-1; i > 0; i--){
        swap(H[0], H[i]);
        criaHeap(H, 0, i-1);
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