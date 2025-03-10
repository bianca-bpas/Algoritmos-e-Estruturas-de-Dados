#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    private:
        int m;
        int cnt;
        vector<string> H;

        int h(string key){
            int n = key.length();
            int sum = 0;
            for (int i = 0; i < n; i++){
                sum += ((int)key[i])*(i+1);
            }
            return 19*sum;

        }

        int hash(string key){
            return h(key) % m;
        }
    
        public:
            HashTable(int size) : m(size), cnt(0) {
                H.resize(m, "");
            }
            ~HashTable() = default;

            int find(string key){
                int idx = hash(key);
                if (H[idx] == ""){
                    return -1;
                }
                if (H[idx] == key){
                    return idx;
                }
                for (int i = 1; i <= 19; i++){
                    int idx = (hash(key) + i*i + 23*i) % m;
                    if (H[idx] == ""){
                        return -1;
                    }
                    if (H[idx] == key){
                        return idx;
                    }
                }
                return -1;
            }

            void insert(string key){
                if (find(key) == -1){
                    int idx = hash(key);
                    if (H[idx] == "" | H[idx] == "DELETED"){
                        H[idx] = key;
                        cnt++;
                        return;
                    }
                    for (int i = 1; i <= 19; i++){
                        int idx = (hash(key) + i*i + 23*i) % m;
                        if (H[idx] == "" || H[idx] == "DELETED"){
                            H[idx] = key;
                            cnt++;
                            break;
                        }
                    }
                }
            }

            void remove(string key){
                int idx = find(key);
                if (idx != -1){
                    H[idx] = "DELETED";
                    cnt--;
                }
            }

            void display(){
                cout << cnt << '\n';
                for (int i = 0; i < m; i++){
                    if (H[i] != "" && H[i] != "DELETED"){
                        cout << i << ":" << H[i] << '\n';
                    }
                }
            }
};

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        // cada test case
        HashTable table(101);
        int n;
        cin >> n;
        cin.ignore();
        for (int j = 0; j < n; j++){
            // cada operação
            string line;
            getline(cin, line);
            string op = line.substr(0, 3);
            string x = line.substr(4, string::npos);
            
            if (op == "ADD"){
                table.insert(x);
            } else if (op == "DEL"){
                table.remove(x);
            }
        }
        table.display();
    }

    return 0;
}