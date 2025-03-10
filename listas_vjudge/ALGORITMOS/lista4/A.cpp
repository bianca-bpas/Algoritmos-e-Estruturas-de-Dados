#include <iostream>
#include <vector>
using namespace std;

typedef struct Object{
    int numero;
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

void insert(BST *bst, int k, Object o){
    bst->root = inserthelp(bst->root, k, o);
    bst->nodecount++;
}

void adicionarObject(Object o, vector <int> *v){
    v->push_back(o.numero);
}

void inorder(BSTNode *rt, vector <int> *v){
    if (rt != NULL){
        inorder(rt->left, v);
        adicionarObject(rt->object, v);
        inorder(rt->right, v);
    }
}

int find_index(vector <int> v, int x, int Q){
    for (int i = 0; i < Q; i++){
        if (x == v[i]){
            return i;
        }
    }
}


int main() {
    BST *bst = create_bst();
    vector <int> v;
    int Q, consulta, x;
    cin >> Q;
    for (int i = 1; i <= Q; i++){
        cin >> consulta >> x;
        Object obj = {x};
        if (consulta == 1){
            insert(bst, obj.numero, obj);
        } else if (consulta == 2){
            Object* found = find(bst, x);
            if (found){
                v.clear();
                v.push_back(-1);
                inorder(bst->root, &v);
                int index = find_index(v, x, Q);
                cout << index << endl;
            } else {
                cout << "Data tidak ada" << endl;
            }
            
        }
    }
    
    return 0;
}
