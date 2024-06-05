# Implements the sieve of Eratosthenes
# Input: A positive integer n > 1
# Output: Array L of all prime numbers less than or equal to n
from math import *

def sieve(lista, idx, n):
    if (idx == len(lista)):
        return lista
    else:
        num = lista[idx]
        for i in range(num, n+1, num):
            if (i/num != 1):
                try:
                    lista.remove(i)
                except:
                    pass
    
        return sieve(lista, idx+1, n)
    

n = 25
initial_list = [x for x in range(2, n+1)]
primes = sieve(lista=initial_list, idx=0, n=n)
print(primes)

