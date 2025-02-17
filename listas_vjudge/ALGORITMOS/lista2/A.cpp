#include <iostream>
using namespace std;

typedef struct Node{
    char dado;
    struct Node*prox;
}Node;

typedef struct LinkedList{
    Node *inicio;
    Node *fim;
    Node *cursor;
    int size;
}LinkedList;

void inicializarList(LinkedList *l);
void insere(char dado, LinkedList *l);
char remove(LinkedList *l);
void imprimeLista(LinkedList *l);
void moveToStart(LinkedList *l);
void moveToEnd(LinkedList *l);
void limpaLista(LinkedList *l);


int main(){
    LinkedList *lista = new LinkedList;
    inicializarList(lista);
    string text;

    while(getline(cin, text)){
        for (int i = 0; i < text.length(); i++){
            char ch = text[i];
            if (ch == '['){
                moveToStart(lista);
            } else if (ch == ']'){
                moveToEnd(lista);
            } else {
                insere(ch, lista);
            }
        }
        imprimeLista(lista);
        limpaLista(lista);
    }

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

void insere(char dado, LinkedList *l){
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

char remove(LinkedList *l){
    if (l->cursor->prox == NULL){
        return -1;
    } else {
        Node *ptr = l->cursor->prox;
        char dado;
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
            cout << ptr->prox->dado << "";
            ptr = ptr->prox;
        }
        cout << endl;
        return;
    } else {
        return;
    }
}

void moveToStart(LinkedList *l){
    l->cursor = l->inicio;
    return;
}

void moveToEnd(LinkedList *l){
    l->cursor = l->fim;
    return;
}

void limpaLista(LinkedList *l){
    if (l->inicio->prox == NULL){
        return;
    } else {
        l->cursor = l->inicio;
        while (l->cursor->prox != NULL){
            remove(l);
        }
    }
}