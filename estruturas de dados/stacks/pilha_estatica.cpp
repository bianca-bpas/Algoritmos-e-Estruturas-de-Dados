#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;

#define N 3
typedef struct PILHA{
    int dados[N];
    int topo;
}PILHA;

void inicializarPilha(PILHA *p){
    cout << "Inicializando pilha..." << endl;
    for (int i = 0; i < N; i++){
        p->dados[i] = 0;
    }
    p->topo = 0;
}

void empilha(int dado, PILHA *p){
    if (p->topo == N){
        cout << "Pilha cheia!" << endl;
        return;
    } else {
        cout << "Empilhando o valor " << dado << endl;
        p->dados[p->topo] = dado;
        p->topo++;
        return;
    }
}

int desempilha(PILHA *p){
    if (p->topo == 0){
        cout << "Pilha vazia!" << endl;
        return -1;
    } else {
        p->topo--;
        return p->dados[p->topo];
    }
}

void limparPilha(PILHA *p){
    if (p->topo == 0){
        cout << "Pilha ja esta vazia!" << endl;
        return;
    } else {
        cout << "Esvaziando pilha..." << endl;
        while (p->topo > 0){
            p->topo--;
        }
    }
}

int valorTopo(PILHA *p){
    if (p->topo == 0){
        cout << "A pilha esta vazia!" << endl;
        return -1;
    } else {
        return p->dados[(p->topo)-1];
    }
}

int tamanhoPilha(){
    return N;
}

void imprimePilha(PILHA *p){
    cout << "Imprimindo pilha..." << endl;
    for (int i = 0; i < p->topo; i++){
        cout << p->dados[i] << " ";
    }
    cout << endl;
}

int main(){
    setlocale(LC_ALL, "Portuguese"); 
    PILHA p1;
    inicializarPilha(&p1);
    cout << endl;
    empilha(10,&p1);
    empilha(20, &p1);
    cout << "Valor do topo atual: " << valorTopo(&p1) << endl;
    empilha(30, &p1);
    empilha(40, &p1);
    cout << "Valor do topo atual: " << valorTopo(&p1) << endl;
    imprimePilha(&p1);
    cout << "Desempilhando: " << desempilha(&p1) << endl;
    cout << "Valor do topo atual: " << valorTopo(&p1) << endl;
    cout << "Desempilhando: " << desempilha(&p1) << endl;
    cout << "Desempilhando: " << desempilha(&p1) << endl;
    cout << "Desempilhando: " << desempilha(&p1) << endl;
    empilha(10,&p1);
    empilha(20, &p1);
    empilha(30, &p1);
    empilha(40, &p1);
    imprimePilha(&p1);
    limparPilha(&p1);
    imprimePilha(&p1);
    limparPilha(&p1);
    cout << "Valor do topo atual: " << valorTopo(&p1) << endl;
    cout << "Tamanho da pilha: " << tamanhoPilha() << endl;

    return 0;
}