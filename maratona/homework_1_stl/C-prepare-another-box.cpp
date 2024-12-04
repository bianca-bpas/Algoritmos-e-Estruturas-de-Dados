#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    long long N, toy, box; cin >> N;
    long long buy=-1;
    priority_queue<long long> A, B;

    for (long long i = 0; i < N; i++){
        cin >> toy;
        A.push(toy);
    }

    for (long long j = 0; j < N-1; j++){
        cin >> box;
        B.push(box);
    }

    while (!B.empty()){
        if (B.top() >= A.top()){
            A.pop(); B.pop();
        } else if (B.top() < A.top()) {
            B.push(A.top());
            if (B.size() <= A.size()){
                buy = A.top();
            } else {
                buy = -1;
                break;
            }
        }
        if (B.empty() && buy == -1){
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