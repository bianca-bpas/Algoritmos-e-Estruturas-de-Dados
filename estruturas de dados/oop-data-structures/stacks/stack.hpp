#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
    private:
        struct Node {
            T element;
            Node* next;

            Node(T& it, Node* nextval) : next(nextval), element(it) {}

            Node(Node* nextval) : next(nextval) {}

            ~Node() { delete next; }
        };

        Node* top; // reference to the first element
        int size; // number of elements

    public:
        Stack() : top(nullptr), size(0) {}

        ~Stack() { delete top; }

        void push(T& it) {
            top = new Node(it, top);
            size++;
        }

        T pop() {
            if (top == nullptr) {
                throw std::out_of_range("Stack is empty");
            }
            T it = top->element;
            top = top->next;
            size--;
            return it;
        }

        void clear() {
            delete top;
            top = nullptr;
            size = 0;
        }

        T topValue() {
            if (top == nullptr) {
                throw std::out_of_range("Stack is empty");
            }
            return top->element;
        }

        T length() {
            return size;
        }
};

#endif