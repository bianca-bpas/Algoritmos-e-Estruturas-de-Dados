N, M = map(int, input().split(" ")) 
candidatos = [[-1, -1]]
for i in range(1, N+1):
    candidatos.append(0)

def winner(lista, posicao):
    l = lista[1:posicao+1]
    sorted(l)
    temp = max(lista[1:posicao+1])
    

votos = [0]
votos += map(int, input().split(" "))
for voto in votos[1:]:
    candidatos[voto] += 1
    print(winner(candidatos), voto)

