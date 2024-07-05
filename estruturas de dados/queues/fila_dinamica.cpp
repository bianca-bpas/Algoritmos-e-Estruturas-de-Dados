#include <iostream>
using namespace std;

typedef struct Node{
    int dado;
    struct Node *prox;
}Node;

typedef struct Fila{
    Node *inicio;
    Node *fim;
}Fila;

void inicializaFila(Fila *f);
void enfileira(int dado, Fila *f);
int desenfileira(Fila *f);
void imprimeFila(Fila *f);

int main(){
    Fila *f1 = new Fila;
    if (f1 == NULL){
        cout << "Erro de alocação." << endl;
        exit(-1);
    } else {
        inicializaFila(f1);
        enfileira(10, f1);
        enfileira(20, f1);
        enfileira(30, f1);
        imprimeFila(f1);
        desenfileira(f1);
        imprimeFila(f1);
    }
    return 0;
}

void inicializaFila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileira(int dado, Fila *f){
    Node *ptr = new Node;
    if (ptr == NULL){
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = NULL;
        if (f->inicio == NULL){
            f->inicio = ptr;
        } else {
            f->fim->prox = ptr;
        }
        f->fim = ptr;
        return;
    }
}

int desenfileira(Fila *f){
    Node *ptr = f->inicio;
    int dado;
    if (ptr != NULL){
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if (f->inicio == NULL){
            f->fim = NULL;
        }
        return dado;
    } else {
        return -1;
    }
}

void imprimeFila(Fila *f){
    Node *ptr = f->inicio;
    if (ptr != NULL){
        while (ptr != NULL){
            cout << ptr->dado << " ";
            ptr = ptr->prox;
        }
        cout << endl;
    } else {
        return;
    }
}