#include <iostream>
using namespace std;

typedef struct Node{
    int dado;
    struct Node*prox;
}Node;

typedef struct LinkedList{
    Node *inicio;
    Node *fim;
    Node *cursor;
    int size;
}LinkedList;

void inicializarList(LinkedList *l);
void insere(int dado, LinkedList *l);
int remove(LinkedList *l);
void imprimeLista(LinkedList *l);


int main(){
    LinkedList *lista = new LinkedList;
    inicializarList(lista);
    imprimeLista(lista);
    insere(10, lista);
    imprimeLista(lista);
    insere(20, lista);
    imprimeLista(lista);
    insere(30, lista);
    imprimeLista(lista);
    cout << "Tamanho da lista: " << lista->size << endl;

    return 0;
}


void inicializarList(LinkedList *l){
    l->inicio = new Node;
    l->inicio->prox = NULL;
    l->fim = l->inicio;
    l->cursor = l->inicio;
    l->size = 0;
    return;
}

void insere(int dado, LinkedList *l){
    Node *ptr = new Node;
    if (ptr == NULL){
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = l->cursor->prox;
        l->cursor->prox = ptr;
        l->cursor = ptr;
        if (ptr->prox == NULL){
            l->fim = ptr;
        }
        l->size++;
        return;
    }
}

int remove(LinkedList *l){
    if (l->cursor->prox == NULL){
        return -1;
    } else {
        Node *ptr = l->cursor->prox;
        int dado;
        l->cursor->prox = NULL;
        l->fim = l->cursor;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprimeLista(LinkedList *l){
    Node *ptr = l->inicio;
    if (ptr->prox != NULL){
        while (ptr->prox != NULL){
            cout << ptr->prox->dado << " ";
            ptr = ptr->prox;
        }
        cout << endl;
        return;
    } else {
        return;
    }
}