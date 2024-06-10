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

NodeTree* rotacaoEsquerda(NodeTree* raiz){
    NodeTree *filho_direita, *f;

    filho_direita = raiz->direita;
    f = filho_direita->esquerda;

    filho_direita->esquerda = raiz;
    raiz->direita = f;

    raiz->altura = maiorSubarvore(alturaNode(raiz->esquerda), alturaNode(raiz->direita)) + 1;
    filho_direita->altura = maiorSubarvore(alturaNode(filho_direita->esquerda), alturaNode(filho_direita->direita)) + 1;

    return filho_direita;
}

NodeTree* rotacaoDireita(NodeTree* raiz){
    NodeTree *filho_esquerda, *f;

    filho_esquerda = raiz->esquerda;
    f = filho_esquerda->direita;

    filho_esquerda->direita = raiz;
    raiz->esquerda = f;

    raiz->altura = maiorSubarvore(alturaNode(raiz->esquerda), alturaNode(raiz->direita)) + 1;
    filho_esquerda->altura = maiorSubarvore(alturaNode(filho_esquerda->esquerda), alturaNode(filho_esquerda->direita)) + 1;

    return filho_esquerda;

}