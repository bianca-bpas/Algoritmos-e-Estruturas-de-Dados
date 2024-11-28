#include <bits/stdc++.h>
using namespace std;

bool findSubset(vector<int> C, int S, vector<int>& subset, int index) {
    int n = C.size();
    if (S == 0) {
        return true;
    }
    if (index >= n || S < 0) {
        return false;
    }

    subset.push_back(C[index]);
    if (findSubset(C, S - C[index], subset, index + 1)) {
        return true;
    }
    subset.pop_back();

    if (findSubset(C, S, subset, index + 1)) {
        return true;
    }

    return false;
}

int main(){
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++){
        int n; 
        cin >> n;
        vector<int> conj(n);
        for (int j = 0; j < n; j++){
            cin >> conj[j];
        }
        int d;
        cin >> d;

        vector<int> subset;
        bool found = findSubset(conj, d, subset, 0);

        cout << "Caso " << i << ": ";

        if (!found){
            cout << -1 << endl;
        } else {
            cout << "{";
            for (int num = 0; num < subset.size(); num++){
                if (num != subset.size()-1){
                    cout << subset[num] << ",";
                } else {
                    cout << subset[num];
                }
            }
            cout << "}" << endl;
        }
    }

    return 0;
}