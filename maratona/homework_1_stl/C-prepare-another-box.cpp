#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int N, toy, box; cin >> N;
    long long buy;
    priority_queue<long long> A, B;

    for (int i = 0; i < N; i++){
        cin >> toy;
        A.push(toy);
    }

    for (int j = 0; j < N-1; j++){
        cin >> box;
        B.push(box);
    }

    while (!B.empty()){
        if (B.top() >= A.top()){
            A.pop(); B.pop();
        } else {
            B.push(A.top());
            if (B.size() <= A.size()){
                buy = A.top();
            } else {
                buy = -1;
                break;
            }
        }
    }

    cout << buy << endl;

    return 0;
}