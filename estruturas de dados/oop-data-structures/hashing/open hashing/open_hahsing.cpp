#include <iostream>
using namespace std;

class Pair {
    public:
        int key;
        int value;
        Pair(int k, int v) : key(k), value(v) {}
        ~Pair() = default;
};

class Node {
    public:
        Pair* pair;
        Node* next;
        Node(Pair* p) : pair(p), next(nullptr) {}
        ~Node() = default;
};

class LinkedList {
    private:
        Node* head;
    
    public:
        LinkedList() : head(nullptr) {}
        ~LinkedList() {
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        void append(Pair* p) {
            Node* newNode = new Node(p);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        void display() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->pair->key << " " << current->pair->value << endl;
                current = current->next;
            }
        }
        bool search(int key) {
            Node* current = head;
            while (current != nullptr) {
                if (current->pair->key == key) {
                    return true;
                }
                current = current->next;
            }
            return false;
        }
        void deleteKey(int key) {
            Node* current = head;
            Node* prev = nullptr;
            while (current != nullptr) {
                if (current->pair->key == key) {
                    if (prev == nullptr) {
                        head = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
};


class HashTable {
    private:
        int m;
        int cnt;
        LinkedList* table;

        int hash(int key) {
            return key % m;
        }

    public:
        HashTable(int size=101) : m(size), cnt(0) {
            table = new LinkedList[size];
        }
        ~HashTable() {
            delete[] table;
        }
        void insert(int key, int value) {
            int index = hash(key);
            Pair* p = new Pair(key, value);
            table[index].append(p);
            cnt++;
        }
        void display() {
            for (int i = 0; i < m; i++) {
                cout << i << ": ";
                table[i].display();
            }
        }
        bool search(int key) {
            int index = hash(key);
            return table[index].search(key);
        }
        void deleteKey(int key) {
            int index = hash(key);
            table[index].deleteKey(key);
            cnt--;
        }
};

int main() {
    HashTable dict(10);
    dict.insert(1, 10);
    dict.insert(2, 20);
    dict.insert(3, 30);
    dict.insert(4, 40);
    dict.insert(5, 50);
    dict.insert(6, 60);
    dict.insert(7, 70);
    dict.insert(8, 80);
    dict.insert(9, 90);
    dict.insert(10, 100);
    dict.display();
    cout << dict.search(5) << endl;
    dict.deleteKey(5);
    dict.display();
    cout << dict.search(5) << endl;
    return 0;
}