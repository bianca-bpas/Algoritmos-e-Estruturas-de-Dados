#include <iostream>
#include <stdlib.h>
using namespace std;

/* Implementando uma lista COM head, onde todos os itens são alocados dinamicamente */

// struct para um item da lista que possui um inteiro
typedef struct Item{
    int dado;
    struct Item *prox;
}Item;

// protótipos
void imprime(Item *cabeca);
void insereFim(int valor, Item* cabeca);
void libera(Item *cabeca);

int main(){
    // cria a cabeça da lista
    Item cabeca;
    cabeca.prox = NULL;

    cout << "Tamanho do nó: " << sizeof(Item) << endl;

    // insere ao final da lista um item alocado dinamicamente
    cout << "Inserindo itens Itemvos na lista..." << endl;
    insereFim(15, &cabeca);
    insereFim(125, &cabeca);
    insereFim(155, &cabeca);

    // aguarda o usuário pressionar uma tecla
    system("pause");

    // uma função para imprimir os itens da lista
    cout << endl << "Imprimindo itens da lista..." << endl;
    imprime(&cabeca);

    // aguarda o usuário pressionar uma tecla
    system("pause");

    // uma função para liberar a memória
    cout << endl << "Liberando memória dos itens da lista..." << endl;
    libera(&cabeca);

    system("pause");
    return 0;
}

// função para inserção de item
void insereFim(int valor, Item* cabeca){
    // cria um ponteiro para novo item e aloca dinamicamente
    Item *novo = (Item*)malloc(sizeof(Item));

    // inicializa o novo item
    novo->prox = NULL;
    novo->dado = valor;

    cout << "Item de valor " << novo->dado << "alocado no endereço " << novo << endl;

    // varre a lista do começo para chegar na última posição
    Item *atual = cabeca;
    while (atual->prox != NULL){
        atual = atual->prox;
    }

    // chegando na última posição, adiciona o novo elemento
    atual->prox = novo;
}

void imprime(Item *cabeca){
    // este item aponta para o item atual que está sendo impresso
    // como o item do inicio é a cabeça, a impressão começa no próximo item
    Item *atual = cabeca->prox;

    // laço que executa até o último item
    int i = 0;
    while(atual != NULL){
        cout << "Valor do item: " << atual->dado << endl;
        i++;
        // faz o atual mover para o próximo item
        atual = atual->prox;
    }

    cout << "Total de itens na lista: " << i << endl;
}

void libera(Item * cabeca){
    // ponteiro para o início da lista
    Item *atual = cabeca->prox;

    // ponteiro para o item a ser liberado
    Item *liberado;

    // parte do início da lista, eliminando todos os itens
    while(atual != NULL){
        // o liberado recebe o enderço do atual a ser liberado
        liberado = atual;
        // o atual recebe o endereço do próximo a ser liberado
        atual = atual->prox;
        cout << "Liberando o item de valor " << liberado->dado << "na posição " << liberado<< endl;
        //libera o atual
        free(liberado);
    }
}