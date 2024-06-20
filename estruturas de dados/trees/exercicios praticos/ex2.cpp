#include <iostream>
using namespace std;

typedef struct Produto{
    int ID;
    string nome;
    float preco;
}Produto;

typedef struct Node{
    Produto produto;
    struct Node *esquerda;
    struct Node *direita;
}Node;

typedef struct ArvoreBinaria{
    Node *raiz = NULL;
    int altura = 0;
}ArvoreBinaria;

// LIDANDO COM AS ESTRUTURAS
Produto criarProduto(){
    Produto p;
    cin >> p.ID >> p.nome >> p.preco;
    return p;
}

void imprimirProduto(Produto p){
    cout << endl << "ID: " << p.ID << endl << "Nome: " << p.nome << endl << "Preco: " << p.preco << endl;
}

// CRIANDO NOVO Nó
Node* criarNode(Produto *x){
    Node *ptr = new Node;
    if (ptr != NULL){
        ptr->produto = x;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        ptr.
    }
}