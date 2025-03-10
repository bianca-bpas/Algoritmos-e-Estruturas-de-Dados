// Computes gcd(m, n) by Euclid's algortithm
// Input: Two nonnegative, not-both-zero integers m and n
// Output: Greatest common divisor of m and n

#include <stdio.h>

int main(){
    int m=60, n=24, r;

    while(n!=0){
        r = m%n;
        m = n;
        n = r;
    }
    printf("gdc(60, 24) = %d", m);

    return 0;
}

