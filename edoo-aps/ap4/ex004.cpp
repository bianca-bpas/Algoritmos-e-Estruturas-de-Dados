#include <iostream>
#include <vector>
using namespace std;

// Function to find prime numbers using Sieve of Eratosthenes
void sieveOfEratosthenes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print primes and count them
    int primeCount = 0;
    cout << "Prime numbers less than " << limit << ":\n";
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
            primeCount++;
        }
    }
    cout << "\n\nTotal prime numbers less than " << limit << ": " << primeCount << endl;
}

int main() {
    int limit = 1000;
    sieveOfEratosthenes(limit);
    return 0;
}
