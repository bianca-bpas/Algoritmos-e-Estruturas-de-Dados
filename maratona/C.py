S = input()
N = len(S)

lista = S.split("|")
res = []

for i in range(1, len(lista)-1):
    temp = lista[i].split(" ")
    res.append(len(temp[0]))

for n in res:
    print(n, end=" ")