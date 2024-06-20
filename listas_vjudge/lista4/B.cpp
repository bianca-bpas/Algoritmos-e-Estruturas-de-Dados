#include <iostream>
using namespace std;

void criaHeap(int *H, int n);
void heapSort(int *H, int n);
int minimumCost(int *H, int n);

int main(){
    int N;
    cin >> N;
    while (N != 0){
        int *H = new int[N];
        
        for (int i = 0; i < N; i++){
            cin >> H[i];
        }
        heapSort(H, N);
        int cost = minimumCost(H, N);
        cout << cost << endl;

        delete[] H;

        cin >> N;
    }

    return 0;
}

void criaHeap(int *H, int n){
    for (int i = (n/2); i >= 1; i--){
        int k = i;
        int v = H[k];
        bool heap = false;
        while (!heap && 2 * k <= n){
            int j = 2 * k;
            if (j < n && H[j] < H[j + 1]){
                j++;
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
    criaHeap(H, n);
    for (int i = n; i > 1; i--){
        swap(H[1], H[i]);
        criaHeap(H, i - 1);
    }
}

int minimumCost(int *H, int n){
    int sum = H[0];
    int cost = 0;

    for (int i = 1; i < n; i++) {
        sum += H[i];
        cost += sum;
    }

    return cost;
}
