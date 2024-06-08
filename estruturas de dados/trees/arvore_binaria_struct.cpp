#include <iostream>
using namespace std;

typedef struct Pessoa{
    string nome;
    int cpf;
}Pessoa;

typedef struct NodeTree{
    Pessoa pessoa;
    struct NodeTree *direita;
    struct NodeTree *esquerda;
}NodeTree;

// cria estrutura pessoa
Pessoa criarPessoa();
// imprime estrutura pessoa
void imprimirPessoa(Pessoa p);

// inserção com retorno e com recursão
NodeTree* inserir(NodeTree *raiz, Pessoa p);
// inserção sem retorno e com recursão
void inserirEficiente(NodeTree **raiz, Pessoa p);
// inserção sem retorno e sem recursão
void inserirMaisEficiente(NodeTree **raiz, Pessoa p);

// busca com recursão
NodeTree* search(NodeTree* raiz, int cpf);
// busca sem recursão
NodeTree* searchEficiente(NodeTree* raiz, int cpf);

// verificar altura da árvore
int alturaTree(NodeTree *raiz);
// verificar quantidade de nós na árvore
int quantidadeNodes(NodeTree *raiz);
// verificar quantidade de folhas na árvore
int quantidadeFolhas(NodeTree *raiz);

// remover nó (folha, 1 filho, 2 filhos)
NodeTree* removerNode(NodeTree* raiz, int chave);

// raiz-esquerda-direita
void imprimirPreorder(NodeTree *raiz);
// esquerda-raiz-direita
void imprimirInorder(NodeTree *raiz);
// esquerda-direita-raiz
void imprimirPostorder(NodeTree *raiz);


int main(){
    NodeTree *raiz = NULL;
    NodeTree *busca = NULL;
    int opcao, valor;
    do{
        cout << endl << "0 - Sair" << endl << "1 - Inserir" << endl << "2 - Imprimir" << endl << "3 - Buscar" << endl << "4 - Altura" << endl << "5 - Tamanho" << endl  << "6 - Folhas" << endl << "7 - Remover" << endl << endl;
        cin >> opcao;

        switch (opcao){
        case 1:
            inserirMaisEficiente(&raiz, criarPessoa());
            break;
        case 2:
            cout << endl << "Preorder:" << endl;
            imprimirPreorder(raiz);
            cout << endl << "Inorder:" << endl;
            imprimirInorder(raiz);
            cout << endl << "Postorder:" << endl;
            imprimirPostorder(raiz);
            cout << endl;
            break;
        case 3:
            cout << endl << "Digite o CPF a ser procurado: ";
            cin >> valor;
            busca = searchEficiente(raiz, valor);
            if (busca != NULL){
                cout << endl << "Valor encontrado: " << endl;
                imprimirPessoa(busca->pessoa);
            } else {
                cout << endl << "Valor nao encontrado!" << endl;
            }
            break;
        case 4:
            cout << endl << "Altura da arvore: " << alturaTree(raiz) << endl;
            break;
        case 5:
            cout << endl << "Quantidade de nos: " << quantidadeNodes(raiz) << endl;
            break;
        case 6:
            cout << endl << "Quantidade de folhas: " << quantidadeFolhas(raiz) << endl;
            break;
        case 7:
            cout << endl;
            imprimirInorder(raiz);
            cout << endl;
            cout << endl << "Digite o CPF a ser removido: ";
            cin >> valor;
            raiz = removerNode(raiz, valor);
            break;
        default:
            if (opcao != 0){
                cout << endl << "Opcao invalida!!!" << endl;
            }
        }

    } while (opcao != 0);

    return 0;
}



// FUNÇÕES PARA ESTRUTURAS

Pessoa criarPessoa(){
    Pessoa p;
    cout << endl << "Digite o nome: ";
    cin >> p.nome;
    cout << endl << "Digite o CPF: ";
    cin >>p.cpf;
    return p;
}

void imprimirPessoa(Pessoa p){
    cout << endl << "Nome: " << p.nome << endl << "CPF: " << p.cpf << endl;
}

NodeTree* inserir(NodeTree *raiz, Pessoa p){
    if (raiz == NULL){
        NodeTree *ptr = new NodeTree;
        ptr->pessoa = p;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        return ptr;
    } else {
        if (p.cpf < raiz->pessoa.cpf){
            raiz->esquerda = inserir(raiz->esquerda, p);
        } else {
            raiz->direita = inserir(raiz->direita, p);
        }
        return raiz;
    }
}

void inserirEficiente(NodeTree **raiz, Pessoa p){
    if (*raiz == NULL){
        *raiz = new NodeTree;
        (*raiz)->pessoa = p;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else {
        if (p.cpf < (*raiz)->pessoa.cpf){
            inserirEficiente(&((*raiz)->esquerda), p);
        } else {
            inserirEficiente(&((*raiz)->direita), p);
        }
    }
}

void inserirMaisEficiente(NodeTree **raiz, Pessoa p){
    NodeTree *ptr = *raiz;
    while (ptr != NULL){
        if (p.cpf < ptr->pessoa.cpf){
            raiz = &ptr->esquerda;
        } else {
            raiz = &ptr->direita;
        }
        ptr = *raiz;
    }
    ptr = new NodeTree;
    ptr->pessoa = p;
    ptr->esquerda = NULL;
    ptr->direita = NULL;
    *raiz = ptr;
}

NodeTree* search(NodeTree* raiz, int cpf){
    if (raiz != NULL){
        if (cpf == raiz->pessoa.cpf){
            return raiz;
        } else if (cpf < raiz->pessoa.cpf){
            return search(raiz->esquerda, cpf);
        } else {
            return search(raiz->direita, cpf);
        }
    }
    return NULL;
}

NodeTree* searchEficiente(NodeTree* raiz, int cpf){
    while (raiz != NULL){
        if (cpf < raiz->pessoa.cpf){
            raiz = raiz->esquerda;
        } else if (cpf > raiz->pessoa.cpf){
            raiz = raiz->direita;
        } else {
            return raiz;
        }
    }
    return NULL;
}

int alturaTree(NodeTree *raiz){
    if (raiz == NULL){
        return -1;
    } else {
        int esq = alturaTree(raiz->esquerda);
        int dir = alturaTree(raiz->direita);
        if (esq > dir){
            return esq + 1;
        } else {
            return dir +1;
        }
    }
}

int quantidadeNodes(NodeTree *raiz){
    if (raiz == NULL){
        return 0;
    } else {
        return (1 + quantidadeNodes(raiz->esquerda) + quantidadeNodes(raiz->direita));      
    }
    // implementando com operador ternário
    return (raiz ==NULL) ? 0 : (1 + quantidadeNodes(raiz->esquerda) + quantidadeNodes(raiz->direita));
}

int quantidadeFolhas(NodeTree *raiz){
    if (raiz == NULL){
        return 0;
    } else if (raiz->esquerda == NULL && raiz->direita == NULL){
        return 1;
    } else {
        return quantidadeFolhas(raiz->esquerda) + quantidadeFolhas(raiz->direita);
    }
}

NodeTree* removerNode(NodeTree* raiz, int chave){
    if (raiz == NULL){
        cout << "Valor nao encontrado!" << endl;
        return NULL;
    } else { // procura o nó a remover
        if (raiz->pessoa.cpf == chave){
            // remove nós folhas sem filhos
            if (raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                cout << "Elemento folha removido: " << chave << "!" << endl;
                return NULL;
            } else {
                // remover nós que possuem 2 filhos
                if (raiz->esquerda != NULL && raiz->direita != NULL){
                    Pessoa p;
                    NodeTree *ptr = raiz->esquerda;
                    while (ptr->direita != NULL){
                        ptr = ptr->direita;
                    }
                    p = raiz->pessoa;
                    raiz->pessoa = ptr->pessoa;
                    ptr->pessoa = p;
                    cout << endl << "Elemento trocado: " << chave << "!" << endl;
                    raiz->esquerda = removerNode(raiz->esquerda, chave);
                    return raiz;
                } else {
                    // remover nós que possuem apenas 1 filho
                    NodeTree *ptr;
                    if (raiz->esquerda != NULL){
                        ptr = raiz->esquerda;
                    } else {
                        ptr = raiz->direita;
                    }
                    free(raiz);
                    cout << endl << "Elemento com 1 filho removido: " << chave << "!" << endl;
                    return ptr;
                }
            }
        } else {
            if (chave < raiz->pessoa.cpf){
                raiz->esquerda = removerNode(raiz->esquerda, chave);
            } else {
                raiz->direita = removerNode(raiz->direita, chave);
            }
            return raiz;
        }
    }
}

void imprimirPreorder(NodeTree *raiz){
    if (raiz != NULL){
        imprimirPessoa(raiz->pessoa);
        imprimirPreorder(raiz->esquerda);
        imprimirPreorder(raiz->direita);
    }
}

void imprimirInorder(NodeTree *raiz){
    if (raiz != NULL){
        imprimirInorder(raiz->esquerda);
        imprimirPessoa(raiz->pessoa);
        imprimirInorder(raiz->direita);
    }
}

void imprimirPostorder(NodeTree *raiz){
    if (raiz != NULL){
        imprimirPostorder(raiz->esquerda);
        imprimirPostorder(raiz->direita);
        imprimirPessoa(raiz->pessoa);
    }
}