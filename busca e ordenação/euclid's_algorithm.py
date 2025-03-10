def gcd(m, n):
    if (n == 0):
        return m
    else:
        r = m%n
        m = n
        n = r
        return gcd(m, n)

mdc = gcd(int(input()), int(input()))
print(mdc)

