#include <iostream>
using namespace std;

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct PILHA{
    NO *topo;
}PILHA;

void inicializarPilha(PILHA *p);
void empilha(int dado, PILHA *p);
int desempilha(PILHA *p);
void limpaPilha(PILHA *p);
void imprimePilha(PILHA *p);

int main(){
    PILHA *p1 = new PILHA;
    if (p1 == NULL){
        cout << "Erro de alocação da pilha!" << endl;
        exit(0);
    } else {
        cout << "Inicializando pilha..." << endl;
        inicializarPilha(p1);
        cout << "Empilhando..." << endl;
        empilha(10, p1);
        cout << "Empilhando..." << endl;
        empilha(20, p1);
        cout << "Empilhando..." << endl;
        empilha(30, p1);
        cout << "Imprimindo pilha..." << endl;
        imprimePilha(p1);
        cout << "Tentando desempilhar: " << desempilha(p1) << endl;
        cout << "Imprimindo pilha..." << endl;
        imprimePilha(p1);
        cout << "Tentando desempilhar: " << desempilha(p1) << endl;
        cout << "Imprimindo pilha..." << endl;
        imprimePilha(p1);
        cout << "Tentando desempilhar: " << desempilha(p1) << endl;
        cout << "Imprimindo pilha..." << endl;
        imprimePilha(p1);
        cout << "Empilhando..." << endl;
        empilha(10, p1);
        cout << "Empilhando..." << endl;
        empilha(20, p1);
        cout << "Empilhando..." << endl;
        empilha(30, p1);
        cout << "Imprimindo pilha..." << endl;
        imprimePilha(p1);
        limpaPilha(p1);
        cout << "Imprimindo pilha..." << endl;
        imprimePilha(p1);
    }

    return 0;
}

void inicializarPilha(PILHA *p){
    p->topo = NULL;
}

void empilha(int dado, PILHA *p){
    NO *ptr = new NO;
    if (ptr == NULL){
        cout << "Erro de alocação de nó" << endl;
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }

}

int desempilha(PILHA *p){
    NO *ptr = p->topo;
    int dado;
    if (ptr == NULL){
        cout << "Pilha vazia!" << endl;
        return -1;
    } else {
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void limpaPilha(PILHA *p){
    NO *ptr = p->topo;
    if (ptr == NULL){
        cout << "Pilha ja esta vazia!" << endl;
        return;
    } else {
        cout << "Esvaziando pilha..." << endl;
        while (ptr > 0){
            ptr--;
        }
        free(ptr);
        return;
    }
}

void imprimePilha(PILHA *p){
    NO * ptr = p->topo;
    if (ptr == NULL){
        cout << "Pilha vazia!" << endl;
        return;
    } else {
        while (ptr != NULL){
            cout << ptr->dado << " ";
            ptr = ptr->prox;
        }
        cout << endl;
    }
}
