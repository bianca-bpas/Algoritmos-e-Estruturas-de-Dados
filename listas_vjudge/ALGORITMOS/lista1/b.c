#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int key, int start, int end);
void quicksort(int *arr, int start, int end);
int partition(int *arr, int start, int end);

int main(){
    int *arr;
    int n, k, pairs=0, position;

    scanf("%d%d", &n, &k);

    arr = (int*) malloc(n * sizeof(int));

    for (int i=0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1);

    for (int j=0; j < n; j++){
        position = binary_search(arr, arr[j]+k, 0, n-1);
        if (position != -1){
            pairs++;
        }
    }
    
    printf("%d\n", pairs);

    free(arr);

    return 0;
}

int binary_search(int *arr, int key, int start, int end){
    int middle;

    if (start <= end){
        middle = (int)(start + end) / 2;
        if (arr[middle] == key){
            return middle;
        }else if (arr[middle] > key){
            binary_search(arr, key, start, middle-1);
        }else if (arr[middle] < key){
            binary_search(arr, key, middle+1, end);
        }
    }else{
        return -1;
    }
}

void quicksort(int *arr, int start, int end){
    int pivot;

    if (start < end){
        pivot = partition(arr, start, end);
        quicksort(arr, start, pivot-1);
        quicksort(arr, pivot+1, end);
    }   

}

int partition(int *arr, int start, int end){
    int pivot, i, temp;

    pivot = end;; 

    i = start;

    for (int j = start; j < end; j++){
        if (arr[j] <= arr[pivot]){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;

        }
    }

    temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;

    return i;
}