#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdexcept>
#include <memory>

template <typename T>
class LinkedList {
private:
    // Node structure to hold data and pointer to next node
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        
        // Constructor for creating a new node
        Node(const T& value) : data(value), next(nullptr) {}
    };

    std::shared_ptr<Node> head;  // Points to the first node in the list
    std::size_t size;           // Tracks the number of elements in the list

public:
    // Constructor - initializes an empty list
    LinkedList() : head(nullptr), size(0) {}

    // Destructor - shared_ptr handles memory cleanup automatically
    ~LinkedList() = default;

    // Returns the current size of the list
    std::size_t getSize() const {
        return size;
    }

    // Checks if the list is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Inserts a new element at the beginning of the list
    void pushFront(const T& value) {
        auto newNode = std::make_shared<Node>(value);
        newNode->next = head;
        head = newNode;
        ++size;
    }

    // Removes the first element from the list
    void popFront() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot pop from empty list");
        }
        head = head->next;
        --size;
    }

    // Returns the first element in the list
    T& front() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

    // Returns the first element in the list (const version)
    const T& front() const {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

    // Inserts a new element at the end of the list
    void pushBack(const T& value) {
        auto newNode = std::make_shared<Node>(value);
        
        if (isEmpty()) {
            head = newNode;
        } else {
            auto current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++size;
    }

    // Checks if a value exists in the list
    bool contains(const T& value) const {
        auto current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Clears all elements from the list
    void clear() {
        head = nullptr;
        size = 0;
    }

    // Insert a value at a specific position
    void insertAt(std::size_t position, const T& value) {
        if (position > size) {
            throw std::out_of_range("Position out of range");
        }

        if (position == 0) {
            pushFront(value);
            return;
        }

        auto newNode = std::make_shared<Node>(value);
        auto current = head;
        for (std::size_t i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        ++size;
    }

    // Remove a value at a specific position
    void removeAt(std::size_t position) {
        if (position >= size) {
            throw std::out_of_range("Position out of range");
        }

        if (position == 0) {
            popFront();
            return;
        }

        auto current = head;
        for (std::size_t i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        
        current->next = current->next->next;
        --size;
    }
};

#endif // LINKED_LIST_HPP