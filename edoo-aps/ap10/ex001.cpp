#include <iostream>
using namespace std;

class Stack {
    private:
        struct Node {
            int element;
            Node* next;

            Node(int it, Node* nextval) : next(nextval), element(it) {}

            Node(Node* nextval) : next(nextval) {}

            ~Node() { delete next; }
        };

        Node* top; // reference to the first element
        int size; // number of elements

    public:
        Stack() : top(nullptr), size(0) {}

        ~Stack() { delete top; }

        void push(int it) {
            top = new Node(it, top);
            size++;
        }

        int pop(int x) {
            if (top == nullptr) {
                throw std::out_of_range("Stack is empty");
            }
            int soma=0;
            for (int i = 0; i < x; i++){
                int it = top->element;
                top = top->next;
                size--;
                soma += it;
            }
            return soma;
        }
};

int main() {
    int c;
    cin >> c;

    for (int i = 1; i <= c; i++){
        cout << "Caso " << i << ":" << endl;
        Stack stack;
        string op;
        while (cin >> op && op != "end"){
            int x;
            cin >> x;
            if (op == "push"){
                stack.push(x);
            } else if (op == "pop"){
                cout << stack.pop(x) << endl;
            }
        }
    }

    return 0;
}