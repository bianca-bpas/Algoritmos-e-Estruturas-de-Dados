#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;

typedef struct LISTA{
    int tamanhoMaximo;
    int tamanhoLista;
    int posicaoAtual;
    int *dados;
}LISTA;

LISTA* inicializarLista(LISTA *p, int tamanho){
    cout << "Inicializando lista..." << endl;
    p->tamanhoMaximo = tamanho;
    p->tamanhoLista = p->posicaoAtual = 0;
    p->dados = new int[tamanho];
    return p;
}

/*LISTA* createList(int size){
    LISTA* l = (LISTA*) malloc (sizeof(LISTA));
    l->tamanhoMaximo = size;
    l->tamanhoLista = l->posicaoAtual = 0;
    l->dados = (int*) malloc(size * sizeof(int));
    return l;
}*/

void insere(int dado, LISTA *p){
    if (p->tamanhoLista == p->tamanhoMaximo){
        cout << "Lista cheia!" << endl;
        return;
    } else {
        cout << "Inserindo o dado: " << dado << endl;
        int i = p->tamanhoLista;
        while (i > p->posicaoAtual){
            p->dados[i] = p->dados[i-1];
            i--;
        }
        p->dados[p->posicaoAtual] = dado;
        p->tamanhoLista++;
        return;
    }
}

void irInicio(LISTA *p){
    cout << "Indo para o início!" << endl;
    p->posicaoAtual = 0;
}

void irFinal(LISTA *p){
    cout << "Indo para o final!" << endl;
    p->posicaoAtual = p->tamanhoLista;
}

void irAnterior(LISTA *p){
    cout << "Indo para a posição anterior!" << endl;
    if (p->posicaoAtual != 0){
        p->posicaoAtual--;
    }
}

void irProximo(LISTA *p){
    cout << "Indo para a próxima posição!" << endl;
    if (p->posicaoAtual < p->tamanhoLista){
        p->posicaoAtual++;
    }
}

int remove(LISTA *p){
    if (p->posicaoAtual < 0 || p->posicaoAtual >= p->tamanhoLista){
        cout << "Não foi possível remover o elemento na posição atual!" << endl;
        return -1;
    } else {
        int dado = p->dados[p->posicaoAtual], i = p->posicaoAtual;
        while (i < (p->tamanhoLista)-1){
            p->dados[i] = p->dados[i+1];
            i++;
        }
        p->tamanhoLista--;
        cout << "Removendo o dado: " << dado << endl;
        return dado;
    }
}

void imprimeLista(LISTA *p){
    cout << "Imprimindo lista..." << endl;
    for (int i = 0; i < p->tamanhoLista; i++){
        cout << p->dados[i] << " ";
    }
    cout << endl;
}

void limparLista(LISTA *p){
    if (p->tamanhoLista == 0){
        cout << "A lista já está vazia!" << endl;
        return;
    } else {
        cout << "Limpando a lista..." << endl;
        for(int i = 0; i < p->tamanhoLista; i++){
            p->posicaoAtual = i;
            remove(p);
        }
        cout << "Lista limpa!" << endl;
    }
}

void appendLista(int dado, LISTA *p){
    cout << "Appending o dado: " << dado << endl;
    irFinal(p);
    insere(dado, p);
}

int lengthLista(LISTA *p){
    return p->tamanhoLista;
}

int currentPosition(LISTA *p){
    return p->posicaoAtual;
}

void moveToPos(int posicao, LISTA *p){
    if (posicao < 0 || posicao > p->tamanhoLista){
        cout << "Posição inválida!" << endl;
        return;
    } else {
        cout << "Movendo para a posição: " << posicao << endl;
        p->posicaoAtual = posicao;
        return;
    }
}

int getValue(LISTA *p){
    if (p->posicaoAtual < 0 || p->posicaoAtual > p->tamanhoLista){
        cout << "Posição atual inválida!" << endl;
        return -1;
    } else {
        cout << "Obtendo o valor da posição atual..." << endl;
        return p->dados[p->posicaoAtual];
    }
}

int main(){
    setlocale(LC_ALL, "pt-BR");

    LISTA lista1;
    inicializarLista(&lista1, 5);
    insere(10, &lista1);
    insere(20, &lista1);
    insere(30, &lista1);
    insere(40, &lista1);
    imprimeLista(&lista1);
    irInicio(&lista1);
    remove(&lista1);
    imprimeLista(&lista1);
    irFinal(&lista1);
    remove(&lista1);
    imprimeLista(&lista1);
    irAnterior(&lista1);
    remove(&lista1);
    imprimeLista(&lista1);
    irProximo(&lista1);
    remove(&lista1);
    imprimeLista(&lista1);
    limparLista(&lista1);
    imprimeLista(&lista1);
    insere(50, &lista1);
    imprimeLista(&lista1);
    appendLista(60, &lista1);
    imprimeLista(&lista1);
    cout << "Tamanho da lista: " << lengthLista(&lista1) << endl;
    cout << "Posição atual: " << currentPosition(&lista1) << endl;
    moveToPos(50, &lista1);
    moveToPos(0, &lista1);
    cout << "Posição atual: " << currentPosition(&lista1) << endl;
    cout << getValue(&lista1) << endl;

    return 0;
}