from random import *

def lista_aleatoria():
    lista = []

    for i in range(randint(0, 11)):
        lista.append(randint(0, 100))

    print(lista)

    return lista
