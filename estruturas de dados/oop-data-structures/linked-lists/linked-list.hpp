#ifndef LIST_H
#define LIST_H

template <typename T>
class LinkedList {
    private:
        struct Node {
            T element;
            Node* next;

            Node(T& it, Node* nextval) : next(nextval), element(it) {}

            Node(Node* nextval) : next(nextval) {}

            ~Node() { delete next; }
        };

        Node* head;
        Node* tail;
        Node* curr;
        int cnt; // list size

    public:
        LinkedList() : head(Node(nullptr)), tail(head), curr(tail), cnt(0) {}

        ~LinkedList() {
            delete head; 
            delete tail; 
            delete curr;
        }

        void insert(T& it){
            curr->next = new Node(it, curr->next);
            if (tail == curr){
                tail = curr->next;
            }
            cnt++;   
        }

        void moveToStart() { curr = head; }

        void prev() {
            if (curr == head) {
                return;
            }
            Node* temp = head;
            while (temp->next != curr) {
                temp = temp->next;
            }
            curr = temp;
            delete temp;
        }

        T remove() {
            if (curr->next == nullptr) {
                return nullptr;
            }
            T it = curr->next->element;
            if (tail == curr->next) {
                tail = curr;
            }
            curr->next = curr->next->next;
            cnt--;
            return it;
        }
};

#endif