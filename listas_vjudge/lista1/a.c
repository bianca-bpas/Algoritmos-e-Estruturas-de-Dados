#include <stdio.h>
#include <stdlib.h>

#define MAX_BARS 100000  // Maximum number of chocolate bars
#define MAX_COUPONS 1000  // Maximum number of coupons

int cmp(const void* a, const void* b);

// Function to find the minimum cost using a coupon
int minCostWithCoupon(int prices[], int n, int q, int k) {
    // Sort the prices in ascending order
    qsort(prices, n, sizeof(int), cmp);

    // Calculate the total cost using the coupon
    int cost = 0;
    for (int i = 0; i < k; i++) {
        cost += prices[q - k + i];
    }

    // Pay full price for remaining bars
    for (int i = n - q; i > 0; i--) {
        cost += prices[i - 1];
    }

    return cost;
}

// Function to compare two integers for sorting
int cmp(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;
    return *x - *y;
}

int main() {
    // Read the number of chocolate bars
    int n;
    scanf("%d", &n);

    // Read the prices of chocolate bars
    int prices[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    // Read the number of coupons
    int m;
    scanf("%d", &m);

    // Read the coupons
    int coupons[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &coupons[i][0], &coupons[i][1]);
    }

    // Calculate minimum costs for each coupon
    int minCosts[m];
    for (int i = 0; i < m; i++) {
        minCosts[i] = minCostWithCoupon(prices, n, coupons[i][0], coupons[i][1]);
    }

    // Print the minimum costs
    for (int i = 0; i < m; i++) {
        printf("%d ", minCosts[i]);
    }

    return 0;
}
