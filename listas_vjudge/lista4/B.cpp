#include <iostream>
using namespace std;

void criaHeap(int *H, int i, int f);
void heapSort(int*H, int n);
int minimumCost(int *H, int n);

int main(){
    int N;
    cin >> N;
    while (N != 0){
        int *H = new int[N];
        
        for (int i = 0; i < N; i++){
            cin >> H[i];
        }
        int cost = minimumCost(H, N);
        cout << cost << endl; 

        delete[] H;

        cin >> N;
    }

    return 0;
}

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
            j = f+1;
        }
    }
    H[i] = aux;
}

void heapSort(int*H, int n){
    for (int i = (n-1)/2; i >= 0; i--){
        criaHeap(H, i, n-1);
    }
    for (int i = n-1; i > 0; i--){
        swap(H[0], H[i]);
        criaHeap(H, 0, i-1);
    }
}

int minimumCost(int *H, int n){
    heapSort(H, n);
    int tot_cost = 0;
    int sum = H[0] + H[1];
    int cost = sum;
    tot_cost += cost;

    int i = 2;
    while (i < n){
        sum = cost + H[i];
        cost = sum;
        tot_cost += cost;
        i++;
    }

    return tot_cost;
}
