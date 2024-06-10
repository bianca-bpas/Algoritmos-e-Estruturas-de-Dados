#include <iostream>
using namespace std;

typedef struct NodeTree{
    int dado;
    struct NodeTree *direita;
    struct NodeTree *esquerda;
}NodeTree;

// inserção com retorno e com recursão
NodeTree* inserir(NodeTree *raiz, int dado);
// inserção sem retorno e com recursão
void inserirEficiente(NodeTree **raiz, int dado);
// inserção sem retorno e sem recursão
void inserirMaisEficiente(NodeTree **raiz, int dado);

// busca com recursão
NodeTree* search(NodeTree* raiz, int dado);
NodeTree* searchNivel(NodeTree* raiz, int dado, int nivel);
// busca sem recursão
NodeTree* searchEficiente(NodeTree* raiz, int dado);

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
void imprimirInorderNiveis(NodeTree *raiz, int nivel);
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
            cout << endl << "Digite um valor: ";
            cin >> valor;
            inserirMaisEficiente(&raiz, valor);
            break;
        case 2:
            cout << endl << "Preorder:" << endl;
            imprimirPreorder(raiz);
            cout << endl << "Inorder:" << endl;
            imprimirInorder(raiz);
            cout << endl;
            imprimirInorderNiveis(raiz, 0);
            cout << endl << "Postorder:" << endl;
            imprimirPostorder(raiz);
            cout << endl;
            break;
        case 3:
            cout << endl << "Digite o valor a ser procurado: ";
            cin >> valor;
            busca = searchEficiente(raiz, valor);
            if (busca != NULL){
                cout << endl << "Valor encontrado: " << busca->dado << endl;
            } else {
                cout << endl << "Valor nao encontrado!" << endl;
            }
            busca = searchNivel(raiz, valor, 0);
            if (busca != NULL){
                cout << endl << "Valor encontrado: " << busca->dado << endl;
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
            cout << endl << "Digite o valor a ser removido: ";
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


NodeTree* inserir(NodeTree *raiz, int dado){
    if (raiz == NULL){
        NodeTree *ptr = new NodeTree;
        ptr->dado = dado;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        return ptr;
    } else {
        if (dado < raiz->dado){
            raiz->esquerda = inserir(raiz->esquerda, dado);
        } else {
            raiz->direita = inserir(raiz->direita, dado);
        }
        return raiz;
    }
}

void inserirEficiente(NodeTree **raiz, int dado){
    if (*raiz == NULL){
        *raiz = new NodeTree;
        (*raiz)->dado = dado;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else {
        if (dado < (*raiz)->dado){
            inserirEficiente(&((*raiz)->esquerda), dado);
        } else {
            inserirEficiente(&((*raiz)->direita), dado);
        }
    }
}

void inserirMaisEficiente(NodeTree **raiz, int dado){
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

NodeTree* search(NodeTree* raiz, int dado){
    if (raiz != NULL){
        if (dado == raiz->dado){
            return raiz;
        } else if (dado < raiz->dado){
            return search(raiz->esquerda, dado);
        } else {
            return search(raiz->direita, dado);
        }
    }
    return NULL;
}

NodeTree* searchNivel(NodeTree* raiz, int dado, int nivel){
    if (raiz != NULL){
        if (dado == raiz->dado){
            cout << endl << "Nivel: " << nivel << endl;
            return raiz;
        } else if (dado < raiz->dado){
            return searchNivel(raiz->esquerda, dado, nivel+1);
        } else {
            return searchNivel(raiz->direita, dado, nivel+1);
        }
    }
    return NULL;
}

NodeTree* searchEficiente(NodeTree* raiz, int dado){
    while (raiz != NULL){
        if (dado < raiz->dado){
            raiz = raiz->esquerda;
        } else if (dado > raiz->dado){
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
        if (raiz->dado == chave){
            // remove nós folhas sem filhos
            if (raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                cout << "Elemento folha removido: " << chave << "!" << endl;
                return NULL;
            } else {
                // remover nós que possuem 2 filhos
                if (raiz->esquerda != NULL && raiz->direita != NULL){
                    NodeTree *ptr = raiz->esquerda;
                    while (ptr->direita != NULL){
                        ptr = ptr->direita;
                    }
                    raiz->dado = ptr->dado;
                    ptr->dado = chave;
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
            if (chave < raiz->dado){
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

void imprimirInorderNiveis(NodeTree *raiz, int nivel){
    if (raiz != NULL){
        imprimirInorderNiveis(raiz->esquerda, nivel + 1);
        cout << raiz->dado << "(" << nivel << ") ";
        imprimirInorderNiveis(raiz->direita, nivel + 1);
    }
}

void imprimirPostorder(NodeTree *raiz){
    if (raiz != NULL){
        imprimirPostorder(raiz->esquerda);
        imprimirPostorder(raiz->direita);
        cout << raiz->dado << " ";
    }
}
