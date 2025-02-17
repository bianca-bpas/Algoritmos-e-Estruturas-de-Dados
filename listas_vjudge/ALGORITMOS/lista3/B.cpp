#include <iostream>
using namespace std;

typedef struct NodeTree{
    long int dado;
    struct NodeTree *esquerda;
    struct NodeTree *direita;
}NodeTree;

void insere(NodeTree **raiz, int dado);
void imprimirPreorder(NodeTree *raiz);
void imprimirInorder(NodeTree *raiz);
void imprimirPostorder(NodeTree *raiz);


int main(){
    NodeTree *raiz = NULL;
    int n; // quantidade de numeros a ser adicionada
    long int p; // numero a ser adicionado
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p;
        insere(&raiz, p);
    }
    cout << "Pre order : ";
    imprimirPreorder(raiz);
    cout << endl;
    cout << "In order  : ";
    imprimirInorder(raiz);
    cout << endl; 
    cout << "Post order: ";
    imprimirPostorder(raiz);
    return 0;
}

void insere(NodeTree **raiz, int dado){
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