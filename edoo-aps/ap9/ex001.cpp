#include <iostream>
using namespace std;

class ArrayList {
    private:
        int maxSize; // capacity
        int listSize; // number of elements
        int curr; // position of the cursor
        int* listArray; // array with values

    public:
        ArrayList(int s) : maxSize(s), listSize(0), curr(0) {
            listArray = new int[s];
        }

        ~ArrayList() {
            delete[] listArray;
        }

        void insert(int item) {
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

        int* remove() {
            if (curr < 0 || curr > listSize) {
                throw std::out_of_range("Index out of bounds");
                return nullptr;
            }
            int item = listArray[curr];
            int i = curr;
            while (i < listSize - 1) {
                listArray[i] = listArray[i + 1];
                i++;
            }
            listSize--;
            return &item;
        }

        int count(int item) {
            int count = 0;
            for (int i = 0; i < listSize; i++) {
                if (listArray[i] == item) {
                    count++;
                }
            }
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
        ArrayList list(n);
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