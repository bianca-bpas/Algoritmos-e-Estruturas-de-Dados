#include <iostream>
using namespace std;

typedef struct Pessoa{
    string nome;
    int idade;
    int cpf;
}Pessoa;

typedef struct NodeTree{
    Pessoa *pessoa;
    NodeTree *direita;
    NodeTree *esquerda;
    int altura;
} NodeTree;


NodeTree* novoNode(int x);
int maiorSubarvore(int a, int b);
int alturaNode(NodeTree *no);
int fatorBalanceamento(NodeTree *no);
NodeTree* rotacaoEsquerda(NodeTree* raiz);
NodeTree* rotacaoDireita(NodeTree* raiz);
NodeTree* rotacaoEsquerdaDireita(NodeTree *raiz);
NodeTree* rotacaoDireitaEsquerda(NodeTree *raiz);
NodeTree* balancear(NodeTree* raiz);
NodeTree* inserir(NodeTree *raiz, Pessoa *x);
NodeTree* removerNode(NodeTree* raiz, int chave);
void imprimir(NodeTree *raiz, int nivel);


int main(){
    NodeTree *raiz = NULL;
    int opcao, valor;
    Pessoa *p;

    do{
        cout << endl << "0 - Sair" << endl << "1 - Inserir" << endl << "2 - Imprimir" << endl  << "3 - Remover" << endl << endl;
        cin >> opcao;

        switch (opcao){
        case 0:
            cout << "Finalizando..." << endl;
            break;
        case 1:
            p = new Pessoa;
            cout << endl << "Digite o nome: ";
            cin >> p->nome;
            cout << "Digite o CPF: ";
            cin >> p->cpf;
            cout << "Digite a idade: ";
            cin >> p->idade;
            raiz = inserir(raiz, p);
            break;
        case 2:
            imprimir(raiz, 1);
            cout << endl << endl;
            break;
        case 3:
            cout << endl << endl << "Digite o CPF a ser removido: ";
            cin >> valor;
            raiz = removerNode(raiz, valor);
            break;
        default:
            cout << endl << "Opcao invalida!!!" << endl;
        }

    } while (opcao != 0);

    return 0;
}


NodeTree* novoNode(Pessoa *x){
    NodeTree* novo = new NodeTree;

    if (novo != NULL){
        novo->pessoa = x;
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

NodeTree* rotacaoEsquerdaDireita(NodeTree *raiz){
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
}

NodeTree* rotacaoDireitaEsquerda(NodeTree *raiz){
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
}

NodeTree* balancear(NodeTree* raiz){
    int fb = fatorBalanceamento(raiz);

    if (fb < -1 && fatorBalanceamento(raiz->direita) <= 0){
        raiz = rotacaoEsquerda(raiz);
    } else if (fb > 1 && fatorBalanceamento(raiz->esquerda) >= 0){
        raiz = rotacaoDireita(raiz);
    } else if (fb > 1 && fatorBalanceamento(raiz->esquerda) < 0){
        raiz = rotacaoEsquerdaDireita(raiz);
    } else if (fb < -1 && fatorBalanceamento(raiz->direita) > 0){
        raiz = rotacaoDireitaEsquerda(raiz);
    }

    return raiz;
}

NodeTree* inserir(NodeTree *raiz, Pessoa *x){
    if (raiz == NULL){
        return novoNode(x);
    } else {
        if (x->cpf < raiz->pessoa->cpf){
            raiz->esquerda = inserir(raiz->esquerda, x);
        } else if (x->cpf > raiz->pessoa->cpf){
            raiz->direita = inserir(raiz->direita, x);
        } else {
            cout << endl << "Insercao nao realizada!" << endl << "O elemento " << x->cpf << " ja existe!" << endl;
        }

        raiz->altura = maiorSubarvore(alturaNode(raiz->esquerda), alturaNode(raiz->direita)) + 1;
        raiz = balancear(raiz);

        return raiz;
    }
}

NodeTree* removerNode(NodeTree* raiz, int chave){
    if (raiz == NULL){
        cout << "Valor nao encontrado!" << endl;
        return NULL;
    } else {
        if (raiz->pessoa->cpf == chave){
            if (raiz->esquerda == NULL && raiz->direita == NULL){
                delete raiz;
                cout << "Elemento folha removido: " << chave << "!" << endl;
                return NULL;
            } else if (raiz->esquerda != NULL && raiz->direita != NULL){
                NodeTree *ptr = raiz->esquerda;
                while (ptr->direita != NULL){
                    ptr = ptr->direita;
                }
                Pessoa *pessoaAux;
                pessoaAux = raiz->pessoa;
                raiz->pessoa = ptr->pessoa;
                ptr->pessoa = pessoaAux;
                cout << endl << "Elemento trocado: " << chave << "!" << endl;
                raiz->esquerda = removerNode(raiz->esquerda, chave);
                return raiz;
            } else {
                NodeTree *ptr;
                if (raiz->esquerda != NULL){
                    ptr = raiz->esquerda;
                } else {
                    ptr = raiz->direita;
                }
                delete raiz;
                cout << endl << "Elemento com 1 filho removido: " << chave << "!" << endl;
                return ptr;
            }
        } else {
            if (chave < raiz->pessoa->cpf){
                raiz->esquerda = removerNode(raiz->esquerda, chave);
            } else {
                raiz->direita = removerNode(raiz->direita, chave);
            }
        }

        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        raiz->altura = maiorSubarvore(alturaNode(raiz->esquerda), alturaNode(raiz->direita)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimirPessoa(Pessoa *pessoa){
    cout << "Nome: " << pessoa->nome << " CPF: " << pessoa->cpf << " Idade: " << pessoa->idade << endl;
}

void imprimir(NodeTree *raiz, int nivel){
    if (raiz != NULL){
        imprimir(raiz->direita, nivel+1);
        cout << endl << endl;
        for (int i = 0; i < nivel; i++){
            cout << "\t";
        }
        imprimirPessoa(raiz->pessoa);
        imprimir(raiz->esquerda, nivel + 1);
    }
}