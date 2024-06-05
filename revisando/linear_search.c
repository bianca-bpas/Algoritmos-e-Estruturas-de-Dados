#include <stdio.h>
#include <stdlib.h>

int linear_search_int(int key, int *numeros, int n);
int linear_search_char(char key, char *palavra, int n);

int main(){
    /*int n, *numeros;

    printf("Quantos numeros serao lidos? ");
    scanf("%d", &n);

    numeros = (int*) malloc(n * sizeof(int));

    printf("Digite os numeros: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &numeros[i]);
    }

    int posicao = linear_search_int(5, numeros, n);
    if (posicao != -1){
        printf("O valor 5 esta na posicao: %d.\n", posicao);
    } else {
        printf("O valor 5 nao esta presente na lista.\n");
    }

    free(numeros);*/

    char *palavra;
    int n;

    printf("Quantas letras serao lidas? ");
    scanf("%d", &n);

    palavra = (char*) malloc(n * sizeof(char));

    printf("Digite a palavra: ");
    for (int i = 0; i < n; i++){
        scanf("%c", &palavra[i]);
    }

    int posicao = linear_search_char('a', palavra, n);
    if (posicao != -1){
        printf("A letra \'a\' esta na posicao: %d.\n", posicao);
    } else {
        printf("A letra \'a\' nao esta presente na palavra.\n");
    }

    free(palavra);

    return 0;
}

int linear_search_int(int key, int *numeros, int n){
    for (int i = 0; i < n; i++){
        if (numeros[i] == key){
            return i;
        }
    }
    return -1;
}

int linear_search_char(char key, char *palavra, int n){
    for (int i = 0; i < n; i++){
        printf("%c ", palavra[i]);
        if (palavra[i] == key){
            return i;
        }
    }
    return -1;
}