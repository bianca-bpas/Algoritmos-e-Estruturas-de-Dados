#include <iostream>
using namespace std;

typedef struct NodeTree{
    long int dado;
    struct NodeTree *esquerda;
    struct NodeTree *direita;
}NodeTree;

NodeTree* insere(NodeTree *raiz, long int dado);
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
        raiz = insere(raiz, p);
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

NodeTree* insere(NodeTree *raiz, long int dado){
    if (raiz == NULL){
        NodeTree *ptr = new NodeTree;
        ptr->dado = dado;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        return ptr;
    } else {
        if (dado < raiz->dado){
            raiz->esquerda = insere(raiz->esquerda, dado);
        } else {
            raiz->direita = insere(raiz->direita, dado);
        }
        return raiz;
    }
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