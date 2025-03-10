#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
    private:
        struct Node {
            T element;
            Node* next;

            Node(T& it, Node* nextval) : next(nextval), element(it) {}

            Node(Node* nextval) : next(nextval) {}

            ~Node() { delete next; }
        };

        Node* front;
        Node* rear;
        int size;

    public:
        Queue() : front(new Node(nullptr)), rear(new Node(nullptr)), size(0) {}

        ~Queue() { delete front; delete rear; }

        void enqueue(T& it) {
            rear->next = new Node(it, nullptr);
            rear = rear->next;
            size++;
        }

        T deque() {
            if (size == 0) {
                throw std::out_of_range("Queue is empty");
            }
            T it = front->next->element;
            front->next = front->next->next;
            if (front->next == nullptr){
                rear = front;
            }
            size--;
            return it;
        }

        void clear(){
            delete front;
            front = new Node(nullptr);
            rear = front;
            size = 0;
        }

        T frontValue(){
            if (size == 0){
                throw std::out_of_range("Queue is empty");
            }
            return front->next->element;
        }

        int length(){
            return size;
        }
};

#endif