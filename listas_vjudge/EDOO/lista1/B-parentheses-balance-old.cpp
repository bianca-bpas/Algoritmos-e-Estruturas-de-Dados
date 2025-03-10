#include <iostream>
using namespace std;

template <typename T>
class Stack {
    private:
        struct Node {
            T element;
            Node* next;

            Node(T& it, Node* nextval = nullptr) : next(nextval), element(it) {}
        };

        Node* top;
        int size;

    public:
        Stack() : top(nullptr), size(0) {}

        ~Stack() {
            while (top != nullptr){
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }

        void push(T& it) {
            top = new Node(it, top);
            size++;
        }

        T pop() {
            if (top != nullptr) {
                T it = top->element;
                Node* temp = top;
                top = top->next;
                size--;
                delete temp;
                return it;
            }
        }

        bool isEmpty(){
            return size == 0;
        }
};

int main(){
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++){
        Stack<char> temp;
        string s;
        getline(cin, s);

        bool isCorrect = true;
        for (int j = 0; j < s.length(); j++){
            char t = s[j];
            if (t == '(' || t == '['){
                temp.push(t);
            } else if (t == ')' || t == ']'){
                if (!temp.isEmpty()){
                    char top = temp.pop();
                    if ((t == ')' && top != '(') || (t == ']' && top != '[')){
                        isCorrect = false;
                        break;
                    }
                } else {
                    isCorrect = false;
                    break;
                }
            }
        }

        if (isCorrect && temp.isEmpty()){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }    
    return 0;
}