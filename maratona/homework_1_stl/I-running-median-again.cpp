    #include <bits/stdc++.h>
    #define endl "\n"
    using namespace std;

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long casos, n; cin >> casos;
        priority_queue<long long> left; priority_queue<long long, vector<long long>, greater<long long>> right;

        for (long long caso = 0; caso < casos; caso++){
            n=-2;
            while (n != 0){
                cin >> n;
                if (n > 0){
                    if (left.empty() || n <= left.top()){
                        left.push(n);
                    } else {
                        right.push(n);
                    }
                } else if (n == -1){
                    if (left.size() >= right.size()){
                        cout << left.top() << endl;
                        left.pop();
                    } else {
                        cout << right.top() << endl;
                        right.pop();
                    }  
                }
                if (left.size() > right.size() + 1){
                    right.push(left.top()); left.pop();
                } else if (right.size() > left.size()){
                    left.push(right.top()); right.pop();
                }
            }
            while (!left.empty()){
                left.pop();
            }
                
            while (!right.empty()) {
                right.pop();
                }
        }

        return 0;
    }