#include <iostream>
using namespace std;

typedef struct Node{
    int t_entrada;
    int t_limite;
    struct Node *prox;
}Node;

typedef struct Fila{
    Node *inicio;
    Node *fim;
}Fila;

void inicializarFila(Fila *f);
void enfileira(int t_entrada, int t_limite, Fila *f);
void desenfileira(Fila *f);
Node* acessarEstudante(Fila *f);


int main(){
    int num_casos, num_estudantes, t_entrada, t_limite, t_contador;
    Fila *fila = new Fila;
    
    cin >> num_casos;
    for (int caso = 1; caso <= num_casos; caso++){
        inicializarFila(fila);
        cin >> num_estudantes;
        for (int estudante = 1; estudante <= num_estudantes; estudante++){
            cin >> t_entrada >> t_limite;
            enfileira(t_entrada, t_limite, fila);
        }
        t_contador = fila->inicio->t_entrada;

        Node *atual = acessarEstudante(fila);
        while(atual != NULL){
            if (t_contador < atual->t_entrada){
                t_contador++;
            } else if (atual->t_limite >= t_contador){
                cout << t_contador << " ";
                t_contador++;
                desenfileira(fila);
                atual = acessarEstudante(fila);
            } else {
                cout << 0 << " ";
                desenfileira(fila);
                atual = acessarEstudante(fila);
            }
        }
        cout << endl;
    }

    return 0;
}

void inicializarFila(Fila *f){
    f->inicio = NULL;
    f->fim = f->inicio;
}

void enfileira(int t_entrada, int t_limite, Fila *f){
    Node *ptr = new Node;
    if (ptr != NULL){
        ptr->t_entrada = t_entrada;
        ptr->t_limite = t_limite;
        ptr->prox = NULL;
        if (f->inicio == NULL){
            f->inicio = ptr;
        } else {
            f->fim->prox = ptr;
        }
        f->fim = ptr;
        return;
    } else {
        return;
    }
}

void desenfileira(Fila *f){
    Node *ptr = f->inicio;
    if (ptr != NULL){
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        free(ptr);
        if (f->inicio == NULL){
            f->fim = NULL;
        }
        return;
    } else {
        return;
    }
}

Node* acessarEstudante(Fila *f){
    Node *ptr = f->inicio;
    if (ptr != NULL){
        return ptr;
    } else {
        return nullptr;
    }
}