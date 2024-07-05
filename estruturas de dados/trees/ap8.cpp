#include <iostream>
using namespace std;

typedef struct NodeTree {
    int dado;
    struct NodeTree *esquerda;
    struct NodeTree *direita;
    int altura;
} NodeTree;

NodeTree* novoNode(int x) {
    NodeTree* novo = new NodeTree;

    if (novo != NULL) {
        novo->dado = x;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->altura = 0;
    } else {
        cout << endl << "ERRO ao alocar no!" << endl;
    }
    return novo;
}

int maiorSubarvore(int a, int b) {
    return (a > b) ? a : b;
}

int alturaNode(NodeTree *no) {
    if (no == NULL) {
        return -1;
    } else {
        return no->altura;
    }
}

int fatorBalanceamento(NodeTree *no) {
    if (no != NULL) {
        return (alturaNode(no->esquerda) - alturaNode(no->direita));
    } else {
        return 0;
    }
}

NodeTree* rotacaoEsquerda(NodeTree* raiz) {
    NodeTree *filho_direita, *f;

    filho_direita = raiz->direita;
    f = filho_direita->esquerda;

    filho_direita->esquerda = raiz;
    raiz->direita = f;

    raiz->altura = maiorSubarvore(alturaNode(raiz->esquerda), alturaNode(raiz->direita)) + 1;
    filho_direita->altura = maiorSubarvore(alturaNode(filho_direita->esquerda), alturaNode(filho_direita->direita)) + 1;

    return filho_direita;
}

NodeTree* rotacaoDireita(NodeTree* raiz) {
    NodeTree *filho_esquerda, *f;

    filho_esquerda = raiz->esquerda;
    f = filho_esquerda->direita;

    filho_esquerda->direita = raiz;
    raiz->esquerda = f;

    raiz->altura = maiorSubarvore(alturaNode(raiz->esquerda), alturaNode(raiz->direita)) + 1;
    filho_esquerda->altura = maiorSubarvore(alturaNode(filho_esquerda->esquerda), alturaNode(filho_esquerda->direita)) + 1;

    return filho_esquerda;
}

NodeTree* rotacaoEsquerdaDireita(NodeTree *raiz) {
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
}

NodeTree* rotacaoDireitaEsquerda(NodeTree *raiz) {
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
}

NodeTree* balancear(NodeTree* raiz) {
    int fb = fatorBalanceamento(raiz);

    if (fb < -1 && fatorBalanceamento(raiz->direita) <= 0) {
        raiz = rotacaoEsquerda(raiz);
    } else if (fb > 1 && fatorBalanceamento(raiz->esquerda) >= 0) {
        raiz = rotacaoDireita(raiz);
    } else if (fb > 1 && fatorBalanceamento(raiz->esquerda) < 0) {
        raiz = rotacaoEsquerdaDireita(raiz);
    } else if (fb < -1 && fatorBalanceamento(raiz->direita) > 0) {
        raiz = rotacaoDireitaEsquerda(raiz);
    }

    return raiz;
}

NodeTree* inserir(NodeTree *raiz, int x) {
    if (raiz == NULL) {
        return novoNode(x);
    } else {
        if (x < raiz->dado) {
            raiz->esquerda = inserir(raiz->esquerda, x);
        } else if (x > raiz->dado) {
            raiz->direita = inserir(raiz->direita, x);
        } else {
            cout << endl << "Insercao nao realizada!" << endl << "O elemento " << x << " ja existe!" << endl;
        }

        raiz->altura = maiorSubarvore(alturaNode(raiz->esquerda), alturaNode(raiz->direita)) + 1;
        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimirPreorder(NodeTree *raiz) {
    if (raiz != NULL) {
        cout << raiz->dado << " ";
        imprimirPreorder(raiz->esquerda);
        imprimirPreorder(raiz->direita);
    }
}

void imprimirInorder(NodeTree *raiz) {
    if (raiz != NULL) {
        imprimirInorder(raiz->esquerda);
        cout << raiz->dado << " ";
        imprimirInorder(raiz->direita);
    }
}

void imprimirPostorder(NodeTree *raiz) {
    if (raiz != NULL) {
        imprimirPostorder(raiz->esquerda);
        imprimirPostorder(raiz->direita);
        cout << raiz->dado << " ";
    }
}

int main() {
    int n, x;
    string operacao;
    NodeTree *raiz = NULL;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> operacao;
        if (operacao == "insert") {
            cin >> x;
            raiz = inserir(raiz, x);
        } else if (operacao == "pre") {
            imprimirPreorder(raiz);
            cout << endl;
        } else if (operacao == "in") {
            imprimirInorder(raiz);
            cout << endl;
        } else if (operacao == "post") {
            imprimirPostorder(raiz);
            cout << endl;
        }
    }
    return 0;
}
