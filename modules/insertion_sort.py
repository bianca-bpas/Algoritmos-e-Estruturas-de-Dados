'''Sorts a given array by insertion sort'''
#Input: An array A[0..n − 1] of n orderable elements
#Output: Array A[0..n − 1] sorted in nondecreasing order

def insertion_sort(A):
    n = len(A)
    for i in range(1, n):
        v = A[i]
        j = i-1
        while (j>=0 and A[j] > v):
            A[j+1] = A[j]
            j = j - 1
        A[j+1] = v

    return A

