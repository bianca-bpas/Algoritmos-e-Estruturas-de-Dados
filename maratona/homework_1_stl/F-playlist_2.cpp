#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> numbers(n);
    map<int, int> last_seen;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int maximum = 1;  
    last_seen[numbers[0]] = 0;                
    int start = 0;                    

    for (int j = 1; j < n; j++) {
        if (last_seen.find(numbers[j]) != last_seen.end()){
            if (last_seen[numbers[j]] >= start){
                start = last_seen[numbers[j]] + 1;
            }
        }
        maximum = max(maximum, j - start + 1);
        last_seen[numbers[j]] = j;
    }

    cout << maximum << endl;

    return 0;
}
