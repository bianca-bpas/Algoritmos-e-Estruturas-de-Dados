#include <iostream>
using namespace std;

class Queue {
    private:
        struct Node {
            char element;
            Node* next;

            Node(char& it, Node* nextval) : next(nextval), element(it) {}

            Node(Node* nextval) : next(nextval) {}

            ~Node() = default;
        };

        Node* front;
        Node* rear;
        char size;

    public:
        Queue() : front(new Node(nullptr)), rear(new Node(nullptr)), size(0) {}

        ~Queue() = default;

        void enqueue(char it) {
            rear->next = new Node(it, nullptr);
            rear = rear->next;
            if (front->next == nullptr) {
                front->next = rear;
            }
            size++;
        }

        char* deque() {
            if (size == 0) {
                size--;
                return nullptr;
            }
            char it = front->next->element;
            front->next = front->next->next;
            if (front->next == nullptr){
                rear = front;
            }
            size--;
            return &it;
        }

        char* frontValue(){
            if (size == 0){
                return nullptr;
            }
            return &front->next->element;
        }

        int length(){
            return size;
        }
};

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        Queue parenteses;
        Queue colchetes;
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++){
            if (s[j] == '('){
                parenteses.enqueue(')');
            } else if (s[j] == '['){
                colchetes.enqueue(']');
            } else if (s[j] == ')'){
                parenteses.deque();
            } else if (s[j] == ']'){
                colchetes.deque();
            }
        }

        if (parenteses.length() != 0 || colchetes.length() != 0){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }

    }

    return 0;
}