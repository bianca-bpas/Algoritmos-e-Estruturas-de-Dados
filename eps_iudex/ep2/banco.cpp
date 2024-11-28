#include <iostream>
using namespace std;

typedef struct Node{
    int id;
    struct Node *prox;
}Node;

typedef struct Fila{
    Node *inicio;
    Node *fim;
    int size;
}Fila;


void inicializarFila(Fila *f);
void enfileira(int id, Fila *f);
int desenfileira(Fila *f);
void imprimeFila(Fila *f);


int main(){
    Fila *pendentes = new Fila;
    Fila *resolvidas = new Fila;
    inicializarFila(pendentes);
    inicializarFila(resolvidas);

    string entrada = "0";
    int num_add;
    while (entrada != "end"){
        cin >> entrada;
        if (entrada == "add"){
            cin >> num_add;
            enfileira(num_add, pendentes);
        } else {
            if (entrada == "solve"){
                int temp = desenfileira(pendentes);
                if (temp != -1){
                    enfileira(temp, resolvidas);
                }
            } else if (entrada == "print"){
                imprimeFila(pendentes);
            } else if (entrada == "stats"){
                cout << resolvidas->size << " " << pendentes->size << endl;
            }
        }

    }

    return 0;
}

void inicializarFila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
    return;
}

void enfileira(int id, Fila *f){
    Node *ptr = new Node;
    ptr->id = id;
    ptr->prox = NULL;
    if (f->inicio == NULL){
        f->inicio = ptr;
    } else {
        f->fim->prox = ptr;
    }
    f->fim = ptr;
    f->size++;
    return;
}



int desenfileira(Fila *f){
    if (f->inicio == NULL){
        return -1;
    } else {
        Node *ptr = f->inicio;
        int dado = ptr->id;
        f->inicio = f->inicio->prox;
        ptr->prox = NULL;
        f->size--;
        free(ptr);
        return dado;
    }
}

void imprimeFila(Fila *f){
    if (f->inicio == NULL){
        cout << "x" << endl;
        return;
    } else {
        Node *ptr = f->inicio;
        while (ptr != NULL){
            cout << ptr->id;
            ptr = ptr->prox;
            if (ptr != NULL){
                cout << " ";
            }
        }
        cout << endl;
        return;
    }
}