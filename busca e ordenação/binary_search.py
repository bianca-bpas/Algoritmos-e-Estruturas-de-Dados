'''BINARY SEARCH'''
from modules.utils import lista_aleatoria
from modules.insertion_sort import insertion_sort

def binary_search(chave, lista, inicio=0, fim=None):
    if (fim is None):
        fim = len(lista)-1

    posicao = -1
    while (inicio <= fim):
        meio = (inicio + fim)//2

        if (lista[meio] is chave):
            posicao = meio
        if (lista[meio] > chave):
            fim = meio-1
        else:
            inicio = meio+1

    return posicao


array = lista_aleatoria() # LEMBRAR DE ORDENAR O VETOR ANTES DE CHAMAR O BINARY SEARCH
array = insertion_sort(array)
print(array)
print([x for x in range(0, len(array))])
chave = int(input("Digite a chave: "))
posicao_chave = binary_search(chave, array)

if (posicao_chave != -1):
    print(f"A chave {chave} está na posição {posicao_chave}.")
else:
    print("A chave digitada não esá contida na lista.")
