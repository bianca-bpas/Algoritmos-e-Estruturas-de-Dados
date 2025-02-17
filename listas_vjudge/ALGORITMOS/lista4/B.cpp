#include <iostream>
#include <vector>
using namespace std;

void criaHeap(vector<int>& H, int i, int f) {
    int raiz = i;
    int filho_esquerda = 2*i+1;
    int filho_direita = 2*i+2;

    if (filho_esquerda < f && H[filho_esquerda] < H[raiz]) {
        raiz = filho_esquerda;
    }
    if (filho_direita < f && H[filho_direita] < H[raiz]) {
        raiz = filho_direita;
    }
    if (raiz != i) {
        swap(H[i], H[raiz]);
        criaHeap(H, raiz, f);
    }
}

void heapSort(vector<int>& H) {
    int n = H.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        criaHeap(H, i, n);
    }
}

int minimumCost(vector<int>& H) {
    heapSort(H);
    int custo_total = 0;

    while (H.size() > 1) {
        int primeiro = H[0];
        swap(H[0], H[H.size() - 1]);
        H.pop_back();
        criaHeap(H, 0, H.size());

        int segundo = H[0];
        swap(H[0], H[H.size() - 1]);
        H.pop_back();
        criaHeap(H, 0, H.size());

        int soma = primeiro + segundo;
        custo_total += soma;

        H.push_back(soma);
        int i = H.size() - 1;
        while (i != 0 && H[(i - 1) / 2] > H[i]) {
            swap(H[i], H[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    return custo_total;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<int> numeros(N);
        for (int i = 0; i < N; i++) {
            cin >> numeros[i];
        }

        int cost = minimumCost(numeros);
        cout << cost << endl;
    }

    return 0;
}
