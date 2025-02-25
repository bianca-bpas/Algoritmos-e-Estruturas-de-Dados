#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template <typename T>
class LinkedList {
    private:
        class Node {
            public:
                T data;
                Node* next;
                Node(const T& value) : data(value), next(nullptr) {}
                ~Node = default;
        };

        Node* head;
        Node* tail;
        size_t count;

    public:
        LinkedList() : head(nullptr), tail(nullptr), count(0) {}
        ~LinkedList() { clear(); }

        void push_front(const T& value){
            Node* new_node = new Node(value);
            new_node->next = head;
            head = new_node;
            if (tail == nullptr){
                tail = new_node;
            }
            count++;
        }

        void push_back(const T& value){
            Node* new_node = new Node(value);
            if (tail == nullptr){
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
            count++;
        }

        void insert(const T& value, size_t pos){
            if (pos > count){
                throw std::out_of_range("Index out of range.");
            }
            if (pos == 0){
                push_front(value);
            } else if (pos == count){
                push_back(value);
            } else {
                Node * new_node = new Node(value);
                Node* current = head;
                for (size_t i = 0; i < pos-1; i++){
                    current = current->next;
                }
                new_node->next = current->next;
                current->next = new_node;
                count++;
            }
        }

        void pop_front(){
            if (head){
                Node* temp = head;
                head = head->next;
                if (head == nullptr){
                    tail = nullptr;
                }
                delete temp;
                count--;
            }
        }

        void pop_back(){
            if (head == nullptr){
                return;
            }
            if (head == tail){
                delete head;
                head = tail = nullptr;
            } else {
                Node* current = head;
                while (current->next != tail){
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
            count--;
        }

        T front() const {
            if (head == nullptr){
                throw std::runtime_error("List is empty.")
            }
            return head->data;
        }

        T back() const {
            if (tail == nullptr){
                throw std::runtime_error("List is empty.");
            }
            return tail->data;
        }

        bool is_empty() const {
            return head == nullptr;
        }

        size_t size() const {
            return count;
        }

        void clear(){
            while (head != nullptr){
                pop_front();
            }
        }

        

};

#endif