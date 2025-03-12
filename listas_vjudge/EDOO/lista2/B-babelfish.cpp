#include <iostream>
#include <vector>
using namespace std;

class HashTable{
    private:
        int m;
        int cnt;
        vector<vector<pair<string, string>>> H;

        int fold(string k){
            int s = k.length();
            int sum = 0;

            for (int i = 0; i < s; i++){
                sum += k[i];
            }
            return abs(sum)%m;
        }

    public:
        HashTable(int size) : m(size), cnt(0) {
            H.resize(m);
        }
        ~HashTable() = default;

        string find(string k){
            int idx = fold(k);

            for (auto par : H[idx]){
                string key = par.first;
                string value = par.second;
                if (key == k){
                    return value;
                }
            }
            return "eh";
        }

        void insert(string k, string e){
            
            if (find(k) == "eh"){
                int idx = fold(k);
                H[idx].push_back({k, e});
                cnt++;
            }
        }
};


int main(){
    HashTable table(100000);
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
        table.insert(value, key);
    }

    while (cin >> line){
        cout << table.find(line) << endl;
    }

    return 0;
}