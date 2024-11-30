def fatorial(n):
    f = 1
    while (n > 0):
        f *= n
        n -= 1
    print(f)
    return f

zeros = 0
n = int(input())
fat = fatorial(n)

temp = str(fat)

i = len(temp)-1

while (i >= 0):
    print(temp[i])
    if (temp[i] == '0'):
        zeros += 1
    else:
        break

    i -= 1

print(zeros)
