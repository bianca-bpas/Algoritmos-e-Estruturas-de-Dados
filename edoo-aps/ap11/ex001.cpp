#include <iostream>
#include <vector>
using namespace std;

class HashTable{
    private:
        int m;
        int cnt;
        vector<vector<int>> H;

        int h(int key){
            return key % m;
        }
    
    public:
        HashTable(int size) : m(size), cnt(0) {
            H.resize(m);
        }
        ~HashTable() = default;

        bool find(int k){
            int idx = h(k);

            for (int value : H[idx]){
                if (value == k){
                    return true;
                }
            }
            return false;
        }

        void insert(int k, int e){
            if (!find(k)){
                int idx = h(k);
                H[idx].push_back(e);
            }
        }

        void print(){
            for (int i = 0; i < m; i++){
                cout << i;
                for (int value : H[i]){
                    cout << " " << value;
                }
                cout << "\n";
            }
        }
};

int main(){
    int n, v;
    cin >> n;
    HashTable table(10);

    for (int i = 0; i < n; i++){
        cin >> v;
        table.insert(v, v);
    }

    table.print();

    return 0;
}