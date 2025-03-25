#include <iostream>
using namespace std;

template <typename Key, typename E>
class BST {
    private:
        class BSTNode {
            public:
                Key key;
                E element;
                BSTNode* left;
                BSTNode* right;

                BSTNode(Key k, E e) : key(k), element(e), left(nullptr), right(nullptr) {}
                ~BSTNode() = default;
        };
        BSTNode* root;
        int nodecount;

    public:
        BST() : root(nullptr), nodecount(0) {}
        ~BST() = default;
        
        void insert(Key k, E e){
            root = inserthelp(root, k, e);
            nodecount++;
        }

        BSTNode* inserthelp(BSTNode* rt, Key k, E e){
            if (rt == nullptr){
                return new BSTNode(k, e);
            }
            if (rt->key > k){
                rt->left = inserthelp(rt->left, k, e);
            } else {
                rt->right = inserthelp(rt->right, k, e);
            }
            return rt;
        }

        BSTNode* getroot(){
            return root;
        }

        void preorder(BSTNode* rt){
            if (rt != nullptr){
                cout << " " << rt->element;
                preorder(rt->left);
                preorder(rt->right);
            }
        }

        void inorder(BSTNode* rt){
            if (rt != nullptr){
                inorder(rt->left);
                cout << " " << rt->element;
                inorder(rt->right);
            }
        }

        void postorder(BSTNode* rt){
            if (rt != nullptr){
                postorder(rt->left);
                postorder(rt->right);
                cout << " " << rt->element;
            }
        }
};


int main(){
    BST<int, int> bst;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        bst.insert(x, x);
    }
    cout << "Pre order :";
    bst.preorder(bst.getroot());
    cout << endl;
    cout << "In order  :";
    bst.inorder(bst.getroot());
    cout << endl;
    cout << "Post order:";
    bst.postorder(bst.getroot()); 
    
    return 0;
}