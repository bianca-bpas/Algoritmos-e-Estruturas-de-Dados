#include <iostream>
#include <vector>
using namespace std;

// strings, linear probing, fold
class HashTable {
    private:
        int m;
        int cnt;
        vector<string> H;

        int fold(string key){
            int s = key.length();
            int sum = 0;
            for (int i = 0; i < s; i++){
                sum += key[i];
            }
            return h(sum);
        }

        int h(int s){
            return abs(s)%m;
        }
    
    public:
        HashTable(int size) : m(size), cnt(0) {
            H.resize(m, "");
        }
        ~HashTable() = default;

        void insert(string k, string e){
            int idx = fold(k);
            if (H[idx] == ""){
                H[idx] = e;
                cnt++;
            } else {
                // Linear probing
                int i = 1;
                while (i < m) {
                    int newIdx = (idx + i) % m;
                    if (H[newIdx] == "") {
                        H[newIdx] = e;
                        cnt++;
                        break;
                    }
                    i++;
                }
            }
        }

        
};

int main(){
    int m;
    cin >> m;
    
    string op, x;
    while (cin >> op && op != "fim"){
        cin >> x;
        if (op == "add"){

        } else if (op == "rmv"){

        } else if (op == "sch"){

        }
    }


    return 0;
}