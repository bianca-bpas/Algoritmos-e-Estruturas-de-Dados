#include <bits/stdc++.h>
using namespace std;

void HeapBottomUp(int *H, int n){
    for (int i = (n/2); i >= 1; i--){
        int k = i;
        int v = H[k];
        bool heap = false;
        while (!heap && 2 * k <= n){
            int j = 2 * k; // Filho esquerdo
            if (j < n && H[j] < H[j + 1]){
                j++; // Filho direito
            }
            if (v >= H[j]){
                heap = true;
            } else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

void heapSort(int *H, int n){
    // Construir o heap
    HeapBottomUp(H, n);
    // Repetidamente extrair o máximo do heap e ajustar o heap
    for (int i = n; i > 1; i--){
        swap(H[1], H[i]);
        HeapBottomUp(H, i - 1); // Reajustar o heap excluindo o último elemento
    }
}

int main(){
    int vet[] = {0, 4, 3, 2, 10, 12, 1, 5, 6}; // Adiciona um 0 para usar índices baseados em 1
    int N = sizeof(vet) / sizeof(vet[0]) - 1; // Ajusta o tamanho para ignorar o primeiro elemento
    heapSort(vet, N);
    for (int i = 1; i <= N; i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}