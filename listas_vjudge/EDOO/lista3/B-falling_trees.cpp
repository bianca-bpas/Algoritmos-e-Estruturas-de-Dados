#include <iostream>
#include <stack>
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
                cout << rt->element;
                preorder(rt->left);
                preorder(rt->right);
            }
        }

        void clear(){
            root = clearhelp(root);
            nodecount = 0;
        }

        BSTNode* clearhelp(BSTNode* rt){
            if (rt == nullptr){
                return nullptr;
            }
            clearhelp(rt->left);
            clearhelp(rt->right);
            delete rt;
            return nullptr;
        }
};


int main(){
    BST<char, char> bst;
    string leaves;
    stack<string> s;
    while (cin >> leaves){
        if (leaves == "*" || leaves == "$"){
            while (!s.empty()){
                for (auto c : s.top()){
                    bst.insert(c, c);
                }
                s.pop();
            }
            bst.preorder(bst.getroot());
            cout << endl;
            bst.clear();
            if (leaves == "$"){
                break;
            }
        } else {
            s.push(leaves);
        }
    }

    return 0;
}