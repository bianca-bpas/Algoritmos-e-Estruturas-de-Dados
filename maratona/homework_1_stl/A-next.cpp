#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, temp;
    cin >> N;
    set<int> A;

    for (int i = 1; i <= N; i++){
        cin >> temp;
        A.insert(temp);
    }

    auto resp = A.rbegin(); ++resp;
    cout << *resp << endl;

    return 0;
}
