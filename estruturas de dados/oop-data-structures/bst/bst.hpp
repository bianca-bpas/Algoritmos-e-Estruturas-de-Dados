#ifndef BST_HPP
#define BST_HPP

template <typename Key, typename E>
class BST {
    private:
        class BSTNode {
            private:
                Key key;
                E element;
                BSTNode* left;
                BSTNode* right;
        
            public:
                BSTNode(Key k, E e) : key(k), element(e), left(nullptr), right(nullptr) {}
                ~BSTNode() = default;
        
        };
        BSTNode* root;
        int nodecount;

    public:
        BST() : root(nullptr), nodecount(0);
        ~BST() = default;

        E find(Key k){
            return findhelp(root, k);
        }

        E findhelp(BSTNode rt, Key k){
            if (rt == nullptr){
                return nullptr;
            }
            if (rt.key > k){
                return findhelp(rt.left, k);
            } else if (rt.key == k){
                return rt.element;
            } else {
                return findhelp(rt.right, k);
            }
        }

        void insert(Key k, E e){
            root = inserthelp(root, k, e);
            nodecount++;
        }

        BSTNode inserthelp(BSTNode rt, Key k, E e){
            if (rt == nullptr){
                return new BSTNode(k, e);
            }
            if (rt.key > k){
                rt.left = inserthelp(rt.left, k, e);
            } else {
                rt.right = inserthelp(rt.right, k, e);
            }
            return rt;
        }

        E remove(Key k){
            E temp = findhelp(root, k);
            if (temp != nullptr){
                root = removehelp(root, k);
                nodecount--;
            }
            return temp;
        }

        BSTNode removehelp(BSTNode rt, Key k){
            if (rt == nullptr){
                return nullptr;
            }
            if (rt.key > k){
                rt.left = removehelp(rt.left, k);
            } else if (rt.key < k){
                rt.right = removehelp(rt.right, k);
            } else {
                if (rt.left == nullptr){
                    return rt.right;
                } else if (rt.right == nullptr){
                    return rt.left;
                } else {
                    BSTNode temp = getmin(rt.right);
                    rt.element = temp.element;
                    rt.key = temp.key;
                    rt.right = deletemin(rt.right);
                }
            }
            return rt;
        }

        BSTNode getmin(BSTNode rt){
            if (rt.left == nullptr){
                return rt;
            }
            return getmin(rt.left);
        }

        BSTNode deletemin(BSTNode rt){
            if (rt.left == nullptr){
                return rt.right;
            }
            rt.left = deletemin(rt.left);
            return rt;
        }

        void preorder(BSTNode rt){
            if (rt != nullptr){
                // do something with rt
                preorder(rt.left);
                preorder(rt.right);
            }
        }

        void inorder(BSTNode rt){
            if (rt != nullptr){
                inorder(rt.left);
                // do something with rt
                inorder(rt.right);
            }
        }

        void postorder(BSTNode rt){
            if (rt != nullptr){
                postorder(rt.left);
                postorder(rt.right);
                // do something with rt
            }
        }
};


#endif