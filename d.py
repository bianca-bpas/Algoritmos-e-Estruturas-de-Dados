N, Q = map(int, input().split(" "))
S = " "+input()

for query in range(Q):
    count = 0
    l, r = map(int, input().split(" "))

    for i in range(l+1, r+1):
        if (S[i] == S[i-1]):
            count += 1

    print(count)
