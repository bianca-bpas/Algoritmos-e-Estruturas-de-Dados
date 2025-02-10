
#include "LinkedList.hpp"
#include <iostream>
#include <cassert>

void testPushFront() {
    LinkedList<int> list;
    list.pushFront(10);
    assert(list.front() == 10);
    list.pushFront(20);
    assert(list.front() == 20);
    std::cout << "testPushFront passed\n";
}

void testPushBack() {
    LinkedList<int> list;
    list.pushBack(10);
    assert(list.front() == 10);
    list.pushBack(20);
    assert(list.getSize() == 2);
    std::cout << "testPushBack passed\n";
}

void testPopFront() {
    LinkedList<int> list;
    list.pushFront(10);
    list.pushFront(20);
    list.popFront();
    assert(list.front() == 10);
    list.popFront();
    assert(list.isEmpty());
    std::cout << "testPopFront passed\n";
}

void testInsertAt() {
    LinkedList<int> list;
    list.pushBack(10);
    list.pushBack(30);
    list.insertAt(1, 20);
    assert(list.contains(20));
    std::cout << "testInsertAt passed\n";
}

void testRemoveAt() {
    LinkedList<int> list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.removeAt(1);
    assert(!list.contains(20));
    std::cout << "testRemoveAt passed\n";
}

void testContains() {
    LinkedList<int> list;
    list.pushBack(10);
    list.pushBack(20);
    assert(list.contains(10));
    assert(!list.contains(30));
    std::cout << "testContains passed\n";
}

void testClear() {
    LinkedList<int> list;
    list.pushBack(10);
    list.pushBack(20);
    list.clear();
    assert(list.isEmpty());
    std::cout << "testClear passed\n";
}

int main() {
    testPushFront();
    testPushBack();
    testPopFront();
    testInsertAt();
    testRemoveAt();
    testContains();
    testClear();
    std::cout << "All tests passed!\n";
    return 0;
}