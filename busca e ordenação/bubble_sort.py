'''Sort a given array by bubble sort'''
# Input: An array A[0...n-1] of orderable elements
# Output: Array A[0...n-1] sorted nondecrasing order

def bubble_sort(A):
    n = len(A)
    for i in range(0, n):
        for j in range(0, n-i-1):
            if(A[j+1] < A[j]):
                A[j], A[j+1] = A[j+1], A[j]

    return A

A = [89, 45, 68, 90, 29, 34, 17]
ordered_A = bubble_sort(A)
print(ordered_A)

