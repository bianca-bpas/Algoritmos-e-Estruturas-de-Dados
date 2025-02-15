#include <iostream>
using namespace std;

class LinkedList {
    private:
        struct Node {
            int element;
            Node* next;

            Node(int& it, Node* nextval) : next(nextval), element(it) {}

            Node(Node* nextval) : next(nextval) {}

            ~Node() { delete next; }
        };

        Node* head;
        Node* tail;
        Node* curr;
        int cnt; // list size

    public:
        LinkedList() : head(new Node(nullptr)), tail(head), curr(tail), cnt(0) {}

        ~LinkedList() {
            delete head; 
            delete tail; 
            delete curr;
        }

        void insert(int& it){
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

        void next() {
            if (curr->next != nullptr) {
                curr = curr->next;
            }
        }

        int* remove() {
            if (curr->next == nullptr) {
                return nullptr;
            }
            int it = curr->next->element;
            if (tail == curr->next) {
                tail = curr;
            }
            curr->next = curr->next->next;
            cnt--;
            return &it;
        }

        int count(int x){
            int count = 0;
            Node* temp = head->next;
            while (temp != nullptr){
                if (temp->element == x){
                    count++;
                }
                temp = temp->next;
            }
            delete temp;
            return count;
        }
};

int main() {
    int c;
    cin >> c;

    for (int i = 1; i <= c; i++){
        cout << "Caso " << i << ":" << endl;
        int n;
        cin >> n;
        LinkedList list;
        for (int j = 0; j < n; j++){
            string op;
            cin >> op;
            if (op == "insert"){
                int x;
                cin >> x;
                list.insert(x);
            } else if (op == "remove"){
                list.remove();
            } else if (op == "count"){
                int x;
                cin >> x;
                cout << list.count(x) << endl;
            } else if (op == "prev"){
                list.prev();
            } else if (op == "next"){
                list.next();
            }
        }
    }
    return 0;
}