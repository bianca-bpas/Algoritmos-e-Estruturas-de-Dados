#include <iostream>
using namespace std;

typedef struct Object{
    int id;
    string name;
}Object;

typedef struct BSTNode{
    int key;
    Object object;
    int height;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode;

BSTNode* create_bstnode(int k, Object o){
    BSTNode *n = new BSTNode;
    n->key = k;
    n->object = o;
    n->left = n->right = NULL;
    return n;
}

typedef struct BST{
    BSTNode *root;
    int nodecount;
}BST;

BST* create_bst(){
    BST *bst = new BST;
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

Object* findhelp(BSTNode *rt, int k){
    if (rt == NULL){
        return NULL;
    } else {
        if (rt->key > k){
            return findhelp(rt->left, k);
        } else if (rt->key == k){
            return &(rt->object);
        } else {
            return findhelp(rt->right, k);
        }
    }
}

Object* find(BST *bst, int k){
    return findhelp(bst->root, k);
}


// INSERTHELP DA BST SEM AVL

/* BSTNode* inserthelp(BSTNode *rt, int k, Object o){
    if (rt == NULL){
        return create_bstnode(k, o);
    }
    if (rt->key > k){
        rt->left = inserthelp(rt->left, k, o);
    } else {
        rt->right = inserthelp(rt->right, k, o);
    }
    return rt;
} */


// Funções auxiliares da AVL
int h(BSTNode *rt){
    if (rt == NULL){
        return -1;
    }
    return rt->height;
}

int getBalance(BSTNode *rt){
    if (rt == NULL){
        return 0;
    }
    return (h(rt->left)-h(rt->right));
}

BSTNode* rightRotate(BSTNode *rt){
    BSTNode *l = rt->left;
    BSTNode *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

BSTNode* leftRotate(BSTNode *rt){
    BSTNode *r = rt->right;
    BSTNode *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}

BSTNode* inserthelp(BSTNode *rt, int k, Object o){
    if (rt == NULL){
        return create_bstnode(k, o);
    }
    if (rt->key > k){
        rt->left = inserthelp(rt->left, k, o);
    } else {
        rt->right = inserthelp(rt->right, k, o);
    }
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    if (balance < -1 && k >= rt->right->key){
        return leftRotate(rt);
    }
    if (balance > 1 && k < rt->left->key){
        return rightRotate(rt);
    }
    if (balance > 1 && k >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 && k < rt->right->key){
        rt->right = rightRotate(rt);
    }
    return rt;
}
// ATÉ AQUI


void insert(BST *bst, int k, Object o){
    bst->root = inserthelp(bst->root, k, o);
    bst->nodecount++;
}

BSTNode* getmin(BSTNode *rt){
    if (rt->left == NULL){
        return rt;
    }
    return getmin(rt->left);
}

BSTNode* deletemin(BSTNode *rt){
    if (rt->left == NULL){
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;
}

BSTNode* removehelp(BSTNode *rt, int k){
    if (rt == NULL){
        return NULL;
    }
    if (rt->key > k){
        rt->left = removehelp(rt->left, k);
    } else if (rt->key < k){
        rt->right = removehelp(rt->right, k);
    } else {
        if (rt->left == NULL){
            return rt->right;
        } else if (rt->right == NULL){
            return rt->left;
        } else {
            BSTNode *temp = getmin(rt->right);
            rt->object = temp->object;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}


Object* remove(BST *bst, int k){
    Object *temp = findhelp(bst->root, k);
    if (temp != NULL){
        bst->root = removehelp(bst->root, k);
        bst->nodecount--;
    }
    return temp;
}

void imprimirObject(Object o){
    cout << o.id << " " << o.name << endl;
}

void preorder(BSTNode *rt){
    if (rt != NULL){
        imprimirObject(rt->object);
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode *rt){
    if (rt != NULL){
        inorder(rt->left);
        imprimirObject(rt->object);
        inorder(rt->right);
    }
}

void posorder(BSTNode *rt){
    if (rt != NULL){
        posorder(rt->left);
        posorder(rt->right);
        imprimirObject(rt->object);
    }
}






























int main() {
    BST *bst = create_bst();
    
    // Inserir produtos
    Object obj1 = {1, "Produto A"};
    Object obj2 = {2, "Produto B"};
    Object obj3 = {3, "Produto C"};
    Object obj4 = {4, "Produto D"};
    Object obj5 = {5, "Produto E"};
    
    insert(bst, obj1.id, obj1);
    insert(bst, obj2.id, obj2);
    insert(bst, obj3.id, obj3);
    insert(bst, obj4.id, obj4);
    insert(bst, obj5.id, obj5);
    
    // Buscar produtos
    Object* found = find(bst, 3);
    if (found) {
        cout << "Found object: ";
        imprimirObject(*found);
    } else {
        cout << "Object not found" << endl;
    }
    
    // Listar produtos em ordem crescente de ID (in-order traversal)
    cout << "In-order traversal:" << endl;
    inorder(bst->root);
    
    // Remover produtos
    remove(bst, 3);
    remove(bst, 5);
    
    // Listar produtos após remoções
    cout << "In-order traversal after removals:" << endl;
    inorder(bst->root);
    
    return 0;
}
