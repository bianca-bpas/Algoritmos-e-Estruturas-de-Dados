#ifndef LIST_H
#define LIST_H

#include <memory>

class Node {
    private:
        int value;
        std::unique_ptr<Node> prox;

    public:
        Node(int v=-1) : value(v), prox(nullptr) {}
        ~Node() = default;
};

class LinkedList {
    private:
        std::unique_ptr<Node> head, tail, cursor;
        int size;

    public:
        LinkedList() : head(new Node), tail(nullptr), cursor(nullptr), size(0) {
            head->prox = NULL;

        }

};

#endif