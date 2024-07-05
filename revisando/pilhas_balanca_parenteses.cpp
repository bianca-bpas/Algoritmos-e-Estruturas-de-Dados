#include <iostream>
using namespace std;

typedef struct Node {
  char dado;
  struct Node *prox;
} Node;

typedef struct Pilha {
  Node *topo;
} Pilha;

void inicializarPilha(Pilha *p) {
  p->topo = NULL;
}

void empilha(char dado, Pilha *p) {
  Node *ptr = new Node;
  ptr->dado = dado;
  ptr->prox = p->topo;
  p->topo = ptr;
}

void desempilha(Pilha *p) {
  if (p->topo == NULL) {
    return;
  } else {
    Node *temp = p->topo; 
    p->topo = p->topo->prox;
    temp->prox = NULL;
    free(temp);
  }
}

int buscaParenteses(Pilha *p) {
  int contA = 0, contB = 0;
  Node *ptr = p->topo;
  while (ptr != NULL) {
    if (ptr->dado == ')') {
      contB++;
    } else if (ptr->dado == '(') {
      contA++;
    }
    ptr = ptr->prox;
  }
  if (contA == contB) {
    return 1;
  } else {
    return 0;
  }
}

void limparPilha(Pilha *p) {
  while (p->topo != NULL) {
    desempilha(p);
  }
}

int main() {
  Pilha *pilha = new Pilha;
  inicializarPilha(pilha);
  char temp;
  while (true) {
    temp = getchar();
    if (temp == '\n') {
      int res = buscaParenteses(pilha);
      if (res == 1) {
        cout << "correct";
      } else {
        cout << "incorrect";
      }
      cout << endl;
      limparPilha(pilha);
    } else if (cin.eof()) {
        break;
    } else {
      empilha(temp, pilha);
    }
  }
  return 0;
}
