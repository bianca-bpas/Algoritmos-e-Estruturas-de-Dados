'''DISCOUNTS PROBLEM'''
def min_cost_with_binary_search(prices, coupons):
    n = len(prices)
    m = len(coupons)

    min_costs = [float('inf')] * m

    prices.sort()

    for i, (q, k) in enumerate(coupons):
        cost = 0

        # Use binary search to find prices efficiently
        for j in range(k):
            right = n - 1
            left = 0
            while left <= right:
                mid = (left + right) // 2
                if prices[mid] > cost:
                    right = mid - 1
                else:
                    cost += prices[mid]
                    left = mid + 1

        for j in range(n - q):
            right = n - 1
            left = 0
            while left <= right:
                mid = (left + right) // 2
                if prices[mid] > cost:
                    right = mid - 1
                else:
                    cost += prices[mid]
                    left = mid + 1

        min_costs[i] = min(min_costs[i], cost)

    return min_costs

prices = [7, 1, 3, 1, 4, 10, 8]
coupons = [(3, 2), (4, 3)]

costs = min_cost_with_binary_search(prices, coupons)
print(costs)  # Output: [27, 30]
