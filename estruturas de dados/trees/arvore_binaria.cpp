#include <iostream>
using namespace std;

typedef struct NodeTree{
    int dado;
    struct NodeTree *direita;
    struct NodeTree *esquerda;
}NodeTree;

// inserção com retorno e com recursão
NodeTree* inserir(NodeTree *raiz, int dado);
// inserção sem retorno e com recursão
void inserirEficiente(NodeTree **raiz, int dado);
// inserção sem retorno e sem recursão
void inserirMaisEficiente(NodeTree **raiz, int dado);
// 
// raiz-esquerda-direita
void imprimirPreorder(NodeTree *raiz);
// esquerda-raiz-direita
void imprimirInorder(NodeTree *raiz);
// esquerda-direita-raiz
void imprimirPostorder(NodeTree *raiz);


int main(){
    NodeTree *raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30);
    inserirEficiente(&raiz, 70);
    inserirEficiente(&raiz, 60);
    inserirMaisEficiente(&raiz, 90);
    inserirMaisEficiente(&raiz, 80);
    cout << "Preorder (raiz-esquerda-direita):" << endl;
    imprimirPreorder(raiz);
    cout << endl << "Inorder (esquerda-raiz-direita)" << endl;
    imprimirInorder(raiz);
    cout << endl << "Postorder (esquerda-direita-raiz)" << endl;
    imprimirPostorder(raiz);

    return 0;
}


NodeTree* inserir(NodeTree *raiz, int dado){
    if (raiz == NULL){
        NodeTree *ptr = new NodeTree;
        ptr->dado = dado;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        return ptr;
    } else {
        if (dado < raiz->dado){
            raiz->esquerda = inserir(raiz->esquerda, dado);
        } else {
            raiz->direita = inserir(raiz->direita, dado);
        }
        return raiz;
    }
}

void inserirEficiente(NodeTree **raiz, int dado){
    if (*raiz == NULL){
        *raiz = new NodeTree;
        (*raiz)->dado = dado;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else {
        if (dado < (*raiz)->dado){
            inserirEficiente(&((*raiz)->esquerda), dado);
        } else {
            inserirEficiente(&((*raiz)->direita), dado);
        }
    }
}

void inserirMaisEficiente(NodeTree **raiz, int dado){
    NodeTree *ptr = *raiz;
    while (ptr != NULL){
        if (dado < ptr->dado){
            raiz = &ptr->esquerda;
        } else {
            raiz = &ptr->direita;
        }
        ptr = *raiz;
    }
    ptr = new NodeTree;
    ptr->dado = dado;
    ptr->esquerda = NULL;
    ptr->direita = NULL;
    *raiz = ptr;
}

void imprimirPreorder(NodeTree *raiz){
    if (raiz != NULL){
        cout << raiz->dado << " ";
        imprimirPreorder(raiz->esquerda);
        imprimirPreorder(raiz->direita);
    }
}

void imprimirInorder(NodeTree *raiz){
    if (raiz != NULL){
        imprimirInorder(raiz->esquerda);
        cout << raiz->dado << " ";
        imprimirInorder(raiz->direita);
    }
}

void imprimirPostorder(NodeTree *raiz){
    if (raiz != NULL){
        imprimirPostorder(raiz->esquerda);
        imprimirPostorder(raiz->direita);
        cout << raiz->dado << " ";
    }
}
