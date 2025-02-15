#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include <stdexcept>

template <typename T>
class ArrayList {
    private:
        int maxSize; // capacity
        int listSize; // number of elements
        int curr; // position of the cursor
        T* listArray; // array with values

    public:
        ArrayList(int s) : maxSize(s), listSize(0), curr(0) {
            listArray = new T[s];
        }

        ~ArrayList() {
            delete[] listArray;
        }

        void insert(T& item) {
            if (listSize >= maxSize) {
                throw std::out_of_range("List is full");
            }
            int i = listSize;
            while (i > curr) {
                listArray[i] = listArray[i - 1];
                i--;
            }
            listArray[curr] = item;
            listSize++;
        }

        void moveToStart() {
            curr = 0;
        }

        void moveToEnd() {
            curr = listSize;
        }

        void prev() {
            if (curr != 0) {
                curr--;
            }
        }

        void next() {
            if (curr < listSize) {
                curr++;
            }
        }

        T remove() {
            if (curr < 0 || curr >= listSize) {
                throw std::out_of_range("Index out of bounds");
                return nullptr;
            }
            T item = listArray[curr];
            int i = curr;
            while (i < listSize - 1) {
                listArray[i] = listArray[i + 1];
                i++;
            }
            listSize--;
            return item;
        }

        bool find(T& item) {
            moveToStart();
            while (curr < listSize) {
                if (item == listArray[curr]) {
                    return true;
                }
                next();
            }
            return false;
        }

        void clear() {
            listSize = 0;
        }

        void append(T& item) {
            if (listSize >= maxSize) {
                throw std::out_of_range("List is full");
            }
            listArray[listSize++] = item;
        }
        
        void moveToPos(int pos) {
            if (pos < 0 || pos >= listSize) {
                throw std::out_of_range("Position out of range");
            }
            curr = pos;
        }
};

#endif // ARRAY_LIST_HPP
