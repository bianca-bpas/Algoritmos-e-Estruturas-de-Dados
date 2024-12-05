#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int t, n; cin >> t;
    string palavra;
    map<string, int> pessoa1, pessoa2, pessoa3;
    

    for (int caso = 0; caso < t; caso++){
        cin >> n;

        for (int i = 0; i < n; i++){
            cin >> palavra;
            pessoa1[palavra] = 3;
        }
        for (int j = 0; j < n; j++){
            cin >> palavra;
            pessoa2[palavra] = 3;
        }
        for (int k = 0; k < n; k++){
            cin >> palavra;
            pessoa3[palavra] = 3;
        }

        stack<string> p1, p2, p3;
        vector<string> l1, l2, l3;
        for (auto [chave, valor] : pessoa1){
            p1.push(chave);
            l1.push_back(chave);
        }
        for (auto [chave, valor] : pessoa2){
            p2.push(chave);
            l2.push_back(chave);
        }
        for (auto [chave, valor] : pessoa3){
            p3.push(chave);
            l3.push_back(chave);
        }

        for (int p = 0; p < n; p++){
            if (!p1.empty() && !p2.empty()){
                if (p1.top() == p2.top()){
                    if (!p3.empty()){
                        if (p1.top() == p3.top()){
                            pessoa1[p1.top()] -= 3; pessoa2[p2.top()] -= 3; pessoa3[p3.top()] -= 3;
                            p1.pop(); p2.pop(); p3.pop();
                        } else {
                            if (!p1.empty() && !p2.empty()){
                                pessoa1[p1.top()] -= 2; pessoa2[p2.top()] -= 2;
                                p1.pop(); p2.pop();
                            }
                        }
                    }
                } 
            if (!p2.empty() && !p3.empty()){
                if (p2.top() == p3.top()){
                        pessoa2[p2.top()] -= 2; pessoa3[p3.top()] -= 2;
                        p2.pop(); p3.pop();
                    } 
                    if (!p1.empty() && !p3.empty()){
                        if (p1.top() == p3.top()){
                            pessoa1[p1.top()] -= 2; pessoa3[p3.top()] -= 2;    
                            p1.pop(); p3.pop();            
                        }
                        if (!p2.empty() && !p3.empty()){
                            if (p2.top() == p3.top()){
                                pessoa2[p2.top()] -= 2; pessoa3[p3.top()] -= 2;
                                p2.pop(); p3.pop();
                            }
                        }
                    }
                }

            }
        }

        int res1 = 0;
        for (int j = 0; j < n; j++){
            res1 += pessoa1[l1[j]];
        }
        cout << res1 << " ";

        int res2 = 0;
        for (int j = 0; j < n; j++){
            res2 += pessoa2[l2[j]];
        }
        cout << res2 << " ";

        int res3 = 0;
        for (int j = 0; j < n; j++){
            res3 += pessoa3[l3[j]];
        }
        cout << res3 << " ";
        cout << endl;

        pessoa1.clear(); pessoa2.clear(); pessoa3.clear();
        l1.clear(); l2.clear(); l3.clear();

    }

    return 0;
}