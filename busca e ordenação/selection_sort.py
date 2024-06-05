'''Sorts a given array by selection sort'''
# Input: An array A[0..n-1] of orderable elements
# Output: Array A[0...n-1] sorted in nondecreasing order

def selection_sort(A):
    n = len(A)
    for i in range(0, n):
        min = i
        for j in range(i+1, n):
            if (A[j] < A[min]):
                A[min], A[j] = A[j], A[min]

    return A

A = [89, 45, 68, 90, 29, 34, 17]
ordered_A = selection_sort(A)
print(ordered_A)


