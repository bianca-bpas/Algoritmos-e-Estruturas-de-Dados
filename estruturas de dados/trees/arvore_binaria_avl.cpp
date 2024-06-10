#include <iostream>
using namespace std;

typedef struct NodeTree{
    int dado;
    struct NodeTree *direita;
    struct NodeTree *esquerda;
    int altura;
}NodeTree;

NodeTree* novoNode(int x){
    NodeTree* novo = new NodeTree;

    if (novo != NULL){
        novo->dado = x;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->altura = 0;
    } else {
        cout << endl << "ERRO ao alocar no!" << endl;
    }
    return novo;
}

int maiorSubarvore(int a, int b){
    return (a > b) ? a : b;
}

int alturaNode(NodeTree *no){
    if (no == NULL){
        return -1;
    } else {
        return no->altura;
    }
}

int fatorBalanceamento(NodeTree *no){
    if (no != NULL){
        return (alturaNode(no->esquerda) - alturaNode(no->direita));
    } else {
        return 0;
    }
}

NodeTree* rotacaoEsquerda(NodeTree* r){
    NodeTree *y, *f;

    y = r->direita;
    f = y->esquerda;

    y->esquerda = r;
    r->direita = f;

    r->altura = maiorSubarvore(alturaNode(r->esquerda), alturaNode(r->direita)) + 1;
    y->altura = maiorSubarvore(alturaNode(y->esquerda), alturaNode(y->direita)) + 1;

    return y;
}