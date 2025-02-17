#include <iostream>
using namespace std;

class Queue {
    private:
        struct Node {
            int element;
            Node* next;

            Node(int& it, Node* nextval) : next(nextval), element(it) {}

            Node(Node* nextval) : next(nextval) {}

            ~Node() { delete next; }
        };

        Node* front;
        Node* rear;
        int size;

    public:
        Queue() : front(new Node(nullptr)), rear(new Node(nullptr)), size(0) {}

        ~Queue() { delete front; delete rear; }

        void enqueue(int& it) {
            rear->next = new Node(it, nullptr);
            rear = rear->next;
            if (front->next == nullptr) {
                front->next = rear;
            }
            size++;
        }

        int* deque() {
            if (size == 0) {
                return nullptr;
            }
            int it = front->next->element;
            front->next = front->next->next;
            if (front->next == nullptr){
                rear = front;
            }
            size--;
            return &it;
        }

        int* frontValue(){
            if (size == 0){
                return nullptr;
            }
            return &front->next->element;
        }

        int length(){
            return size;
        }
};

class Balsa{
    private:
        int capacidade;
        Queue* fila_left;
        Queue* fila_right;
        string margem_atual;
        int num_travessias;
    
    public:
        Balsa(int c) : capacidade(c), fila_left(new Queue), fila_right(new Queue), margem_atual("left"), num_travessias(0) {}
        ~Balsa() = default;

        void entrarNaFila(int c, string m){
            if (m == "left"){
                fila_left->enqueue(c);
            } else if (m == "right"){
                fila_right->enqueue(c);
            }
        }

        int travessia(){
            while (fila_left->length() > 0 || fila_right->length() > 0){
                atravessar();
            }
            return num_travessias;
        }

        void atravessar(){
            int atual=capacidade;
            if (margem_atual == "left"){
                while (fila_left->length() > 0 && *fila_left->frontValue() <= atual){
                    atual -= *fila_left->frontValue();
                    fila_left->deque();
                }
                margem_atual = "right";
                num_travessias++;
            } else if (margem_atual == "right"){
                while (fila_right->length() > 0 && *fila_right->frontValue() <= atual){
                    atual -= *fila_right->frontValue();
                    fila_right->deque();
                }
                margem_atual = "left";
                num_travessias++;
            }
        }
};

int main(){
    int c;
    cin >> c;

    for (int i = 1; i <= c; i++){
        int l, m;
        cin >> l >> m;
        l *= 100;
        Balsa b(l);

        for (int j = 1; j <= m; j++){
            int l_carro; cin >> l_carro;
            string margem; cin >> margem;
            b.entrarNaFila(l_carro, margem);
        }
        cout << b.travessia() << endl;
    }

    return 0;
}