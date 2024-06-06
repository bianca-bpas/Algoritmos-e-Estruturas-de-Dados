// implemente uma árvore binária de busca para números inteiros
#include <iostream>
using namespace std;

typedef struct NodeTree{
    int dado;
    struct NodeTree *esquerda;
    struct NodeTree *direita;
}NodeTree;

NodeTree* insere(NodeTree *raiz, int dado);
void imprimirPreorder(NodeTree *raiz);
void imprimirInorder(NodeTree *raiz);
void imprimirPostorder(NodeTree *raiz);


int main(){
    NodeTree *raiz = NULL;
    long int n; // número de operações
    string operacao;
    long long int numero;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> operacao;
        if (operacao == "insert"){
            cin >> numero;
            raiz = insere(raiz, numero);
        } else if (operacao == "pre"){
            imprimirPreorder(raiz);
            cout << endl;
        } else if (operacao == "in"){
            imprimirInorder(raiz);
            cout << endl;
        } else if (operacao == "post"){
            imprimirPostorder(raiz);
            cout << endl;
        }
    }

}

NodeTree* insere(NodeTree *raiz, int dado){
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
