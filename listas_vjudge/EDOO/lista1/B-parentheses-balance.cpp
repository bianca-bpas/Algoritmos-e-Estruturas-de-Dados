#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T element;
        Node* next;
        Node(T it, Node* nextval = nullptr) : element(it), next(nextval) {}
    };

    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(T it) {
        top = new Node(it, top);
        size++;
    }

    T pop() {
        if (top == nullptr) {
            // Esse retorno não deve ocorrer se a verificação de pilha vazia for feita corretamente
            return 'e';
        }
        T it = top->element;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return it;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

bool is_correct(const string &s) {
    Stack<char> stack;
    for (char c : s) {
        if (c == '(' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == ']') { // Só processa caracteres de fechamento
            if (stack.isEmpty())
                return false;
            char top = stack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '['))
                return false;
        }
    }
    return stack.isEmpty();
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Descarta o '\n' após ler o número de casos
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s); // Lê a linha inteira, permitindo espaços se houver
        cout << (is_correct(s) ? "Yes" : "No") << endl;
    }
    return 0;
}

