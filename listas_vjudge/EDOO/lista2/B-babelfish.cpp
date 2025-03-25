#include <iostream>
#include <vector>
using namespace std;

class HashTable{
    private:
        int m;
        int cnt;
        vector<vector<pair<string, string>>> H;

        int sfold(string key){
            int intLength = key.length() / 4;
            long long sum = 0;
            for (int i = 0; i < intLength; i++) {
                string part = key.substr(i * 4, 4);
                long long mult = 1;
                for (int j = 0; j < part.length(); j++) {
                    sum += part[j] * mult;
                    mult *= 256;
                }
            }

            string remaining = key.substr(intLength * 4);
            long long mult = 1;
            int s = remaining.length();
            for (int j = 0; j < s; j++) {
                sum += remaining[j] * mult;
                mult *= 256;
            }
            return abs(sum) % m;
        }

    public:
        HashTable(int size) : m(size), cnt(0) {
            H.resize(m);
        }
        ~HashTable() = default;

        string find(string k){
            int idx = sfold(k);

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
                int idx = sfold(k);
                H[idx].push_back({k, e});
                cnt++;
            }
        }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
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