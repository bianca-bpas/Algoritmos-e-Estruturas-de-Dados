// recebe até 100.000 entrada, uma newline e n palavras de busca key-value

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
            H.resize(m, vector<pair<string, string>>(1, pair<string, string>({"", ""})));
        }
        ~HashTable() = default;

        string find(string k){
            int idx = fold(k);

            for (auto [key, value] : H[idx]){
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
    HashTable table(5);
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