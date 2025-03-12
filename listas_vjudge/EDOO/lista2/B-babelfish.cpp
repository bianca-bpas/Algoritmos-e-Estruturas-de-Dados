// recebe até 100.000 entrada, uma newline e n palavras de busca key-value

#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    private:
        int m;
        int cnt;
        vector<pair<string, string>> H;

        int h(string key){
            int s = key.length();
            int sum = 0;
            for (int i = 0; i < s; i++){
                sum += key[i];
            }
            return abs(sum)%m;
        }
    public:
        HashTable(int size) : m(size), cnt(0) {
            H.resize(m, {"", ""});
        }
        ~HashTable() = default;

        void insert(string k, string v){
            int idx = h(k);
            if (H[idx].first == "" || H[idx].first == "DELETED"){
                H[idx].first = k;
                H[idx].second = v;
                cnt++;
            } else {
                int i = 1;
                while (i < m){
                    int newIdx = (idx + i) % m;
                    if (H[newIdx].first == "" || H[newIdx].first == "DELETED"){
                        H[newIdx].first = k;
                        H[newIdx].second = v;
                        cnt++;
                        break;
                    }
                    i++;
                }
            }
        }

        string find(string key){
            int idx = h(key);  // Fixed: was using 'k' instead of 'key'
            int i = 0;

            while (i < m){
                int currIdx = (idx + i) % m;

                if (H[currIdx].first == ""){
                    // Empty slot means key was never inserted
                    return "NOT FOUND";
                }

                if (H[currIdx].first == key){
                    return H[currIdx].second;
                }
                
                // Continue probing
                i++;
            }
            return "NOT FOUND";
        }
};


int main(){
    HashTable table(100001);
    string line;
    while (getline(cin, line) && !line.empty()){
        string word, key, value;
        for (char letter : line){
            if (letter != ' '){
                word.push_back(letter);
            } else {
                key = word;
                word.clear();
            }
        }
        value = word;
        table.insert(key, value);
    }

    while (cin >> line){
        cout << table.find(line) << endl;
    }

    return 0;
}