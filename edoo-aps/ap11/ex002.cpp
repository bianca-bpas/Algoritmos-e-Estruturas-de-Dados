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
            if (H[idx] == "" || H[idx] == "DELETED"){
                H[idx] = e;
                cnt++;
            } else {
                // Linear probing
                int i = 1;
                while (i < m) {
                    int newIdx = (idx + i) % m;
                    if (H[newIdx] == "" || H[newIdx] == "DELETED") {
                        H[newIdx] = e;
                        cnt++;
                        break;
                    }
                    i++;
                }
            }
        }

        void remove(string k){
            int idx = fold(k);
            int i = 0;

            int s = search(k);
            if (s != -1){
                H[s] = "DELETED";
                cnt--;
            }
        }

        int search(string k) {
            int idx = fold(k);
            int i = 0;
            
            while (i < m) {
                int currIdx = (idx + i) % m;
                
                if (H[currIdx] == "") {
                    return -1;
                }
                
                if (H[currIdx] == k) {
                    return currIdx;
                }
                
                i++;
            }
            
            return -1;
        }

};

int main(){
    int m;
    cin >> m;
    
    HashTable table(m);
    string op, x;
    while (cin >> op && op != "fim"){
        cin >> x;
        if (op == "add"){
            table.insert(x, x);
        } else if (op == "rmv"){
            table.remove(x);
        } else if (op == "sch"){
            int s = table.search(x);
            if (s != -1) {
                cout << x << " " << s << endl;
            } else {
                cout << x << " " << -1 << endl;
            }
        }
    }

    return 0;
}