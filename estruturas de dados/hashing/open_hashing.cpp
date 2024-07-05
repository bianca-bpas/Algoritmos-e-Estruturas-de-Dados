// adaptado para a AP6
#include <iostream>
using namespace std;
#define m 10

typedef struct Node {
    int dado;
    struct Node *prox;
}Node;

typedef struct LinkedList{
    Node *inicio;
    Node *fim;
    int size;
}LinkedList;

LinkedList *tabela[m];

LinkedList* create_list();
void inicializarTable();
void insereLista(int dado, LinkedList *lista);
Node* buscarNode(int key, Node *inicio);
void imprimirLista(Node *inicio);
int hashFunction(int k);
void insereTabela(int dado);
int* buscarDado(int key);
void imprimirTabela();


int main(){
    int n;
    long int v;
    inicializarTable();

    cin >> n; // quantidade de elementos que devem ser adicionados na tabela de dispersão
    for (int i = 0; i < n; i++){
        cin >> v; // número que deve ser inserido na tabela 
        insereTabela(v);
    }
    imprimirTabela();

    return 0;
}

LinkedList* create_list(){
    LinkedList *l = new LinkedList;
    l->inicio = NULL;
    l->fim = l->inicio;
    l->size = 0;
    return l;
}

void inicializarTable(){
    for (int i = 0; i < m; i++){
        tabela[i] = create_list();
    }
}

void insereLista(int dado, LinkedList *lista){
    Node *ptr = new Node;
    ptr->dado = dado;
    ptr->prox = NULL;
    if (lista->inicio == NULL){
        lista->inicio = ptr;
    } else {
        lista->fim->prox = ptr; 
    }
    lista->fim = ptr;
    lista->size++;
}

Node* buscarNode(int key, Node *inicio){
    Node *ptr = inicio;
    while (ptr != NULL){
        if (ptr->dado == key){
            return ptr;
        } else {
            ptr = ptr->prox;
        }
    }
    return NULL;
}

void imprimirLista(Node *inicio){
    Node *ptr = inicio;
    while (ptr != NULL){
        cout << ptr->dado << " ";
        ptr = ptr->prox;
    }
}

int hashFunction(int k){
    return abs(k)%m;
}

void insereTabela(int dado){
    int indice = hashFunction(dado);
    insereLista(dado, tabela[indice]);
}

int* buscarDado(int key){
    int indice = hashFunction(key);
    Node *ptr = buscarNode(key, tabela[indice]->inicio);
    if (ptr != NULL){
        return &ptr->dado;
    } else {
        return NULL;
    }
}

void imprimirTabela(){
    for (int i = 0; i < m; i++){
        cout << i << " ";
        imprimirLista(tabela[i]->inicio);
        cout << endl;
    }
}