meses = [""]
resp = 0

for mes in range(1, 13):
    temp = input()
    meses.append(temp)

for mes in range(1, 13):
    if len(meses[mes]) == mes:
        resp += 1

print(resp)
