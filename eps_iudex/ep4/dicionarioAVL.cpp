#include <iostream>
using namespace std;

typedef struct BSTNode{
    int chave;
    struct BSTNode *esquerda;
    struct BSTNode *direita;
    int altura;
}BSTNode;

typedef struct BST{
    BSTNode *raiz;
    int numero_nos;
}BST;

BSTNode* create_node(int chave);
BST* create_bst();
BSTNode* rightRotate(BSTNode *rt);
BSTNode* leftRotate(BSTNode *rt);
int h(BSTNode *rt);
int getBalance(BSTNode *rt);
BSTNode* inserthelp(BSTNode *rt, int chave);
void insert(BST *bst, int chave);
void preorder(BSTNode *rt);


int main(){
    int c; // numero de casos
    int n; // quantidade de chaves
    int chave;
    cin >> c;
    for (int i = 0; i < c; i++){
        BST *bst = create_bst();
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> chave;
            insert(bst, chave);
        }
        preorder(bst->raiz);
        cout << "END" << endl;
    }

    return 0;
}

BSTNode* create_node(int chave){
    BSTNode *n = new BSTNode;
    n->chave= chave;
    n->esquerda = n->direita = NULL;
    n->altura = 0;
    return n;
}

BST* create_bst(){
    BST *bst = new BST;
    bst->raiz = NULL;
    bst->numero_nos = 0;
    return bst;
}

BSTNode* rightRotate(BSTNode *rt){
    BSTNode *l = rt->esquerda;
    BSTNode *lr = l->direita;
    l->direita = rt;
    rt->esquerda = lr;
    rt->altura = max(h(rt->esquerda), h(rt->direita)) + 1;
    l->altura = max(h(l->esquerda), h(l->direita)) + 1;
    return l;
}

BSTNode* leftRotate(BSTNode *rt){
    BSTNode *r = rt->direita;
    BSTNode *rl = r->esquerda;
    r->esquerda = rt;
    rt->direita = rl;
    rt->altura = max(h(rt->esquerda), h(rt->direita)) + 1;
    r->altura = max(h(r->esquerda), h(r->direita)) + 1;
    return r;
}

int h(BSTNode *rt){
    if (rt == NULL){
        return -1;
    }
    return rt->altura;
}

int getBalance(BSTNode *rt){
    if (rt == NULL){
        return 0;
    }
    return h(rt->esquerda)-h(rt->direita);
}

BSTNode* inserthelp(BSTNode *rt, int chave){
    if (rt == NULL){
        return create_node(chave);
    }
    if (rt->chave > chave){
        rt->esquerda = inserthelp(rt->esquerda, chave);
    } else {
        rt->direita = inserthelp(rt->direita, chave);
    }
    rt->altura = 1 + max(h(rt->esquerda), h(rt->direita));
    int balance = getBalance(rt);
    if (balance < -1 && chave >= rt->direita->chave){
        return leftRotate(rt);
    } else if (balance > 1 && chave < rt->esquerda->chave){
        return rightRotate(rt);
    } else if (balance > 1 && chave >= rt->esquerda->chave){
        rt->esquerda = leftRotate(rt->esquerda);
        return rightRotate(rt);
    } else if (balance < -1 && chave < rt->direita->chave){
        rt->direita = rightRotate(rt->direita);
        return leftRotate(rt);
    }
    return rt;

}

void insert(BST *bst, int chave){
    bst->raiz = inserthelp(bst->raiz, chave);
    bst->numero_nos++;
}

void preorder(BSTNode *rt){
    if (rt != NULL){
        cout << rt->chave << endl;
        preorder(rt->esquerda);
        preorder(rt->direita);
    }
}
