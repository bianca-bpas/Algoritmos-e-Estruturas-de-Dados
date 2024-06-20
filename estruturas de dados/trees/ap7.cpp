// implemente uma árvore binária de busca para números inteiros
#include <iostream>
using namespace std;

typedef struct BSTNode{
    int key;
    int element;
    BSTNode *left;
    BSTNode *right;
}BSTNode;

BSTNode* create_bstnode(int k, int e);

typedef struct BST{
    BSTNode *root;
    int nodecount;
}BST;


BST* create_bst();
void insert(BST *bst, int k, int e);
BSTNode* inserthelp(BSTNode *rt, int k, int e);
void preorder(BSTNode *rt);
void inorder(BSTNode* rt);
void postorder(BSTNode *rt);


int main(){
    int n; // número de operações
    string op;
    int x;
    BST* bst = create_bst();
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> op;
        if (op == "insert"){
            cin >> x;
            insert(bst, x, x);
        } else if (op == "pre"){
            preorder(bst->root);
            cout << endl;
        } else if (op == "in"){
            inorder(bst->root);
            cout << endl;
        } else if (op == "post"){
            postorder(bst->root);
            cout << endl;
        }
    }

    return 0;
}

BSTNode* create_bstnode(int k, int e){
    BSTNode *n = new BSTNode;
    n->key = k;
    n->element = e;
    n->left = n->right = NULL;
    return n;
}

BST* create_bst(){
    BST * bst = new BST;
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

void insert(BST *bst, int k, int e){
    bst->root = inserthelp(bst->root, k, e);
    bst->nodecount++;
}

BSTNode* inserthelp(BSTNode *rt, int k, int e){
    if (rt == NULL){
        return create_bstnode(k, e);
    }
    if (rt->key > k){
        rt->left = inserthelp(rt->left, k, e);
    } else {
        rt->right = inserthelp(rt->right, k, e);
    }
    return rt;
}

void preorder(BSTNode *rt){
    if (rt != NULL){
        cout << rt->element << " ";
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode* rt){
    if (rt != NULL){
        inorder(rt->left);
        cout << rt->element << " ";
        inorder(rt->right);
    }
}

void postorder(BSTNode *rt){
    if (rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        cout << rt->element << " ";
    }
}