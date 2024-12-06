#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int t, n, total1, total2, total3; cin >> t;
    string palavra;
    map<string, bool> p1, p2, p3;
    

    for (int caso = 0; caso < t; caso++){
        cin >> n;

        for (int i = 0; i < n; i++){
            cin >> palavra;
            p1[palavra] = false;
        }
        for (int j = 0; j < n; j++){
            cin >> palavra;
            p2[palavra] = false;
        }
        for (int k = 0; k < n; k++){
            cin >> palavra;
            p3[palavra] = false;
        }

        total1 = total2 = total3 = (n*3);

        for (auto [p, visited] : p1){
            p1[p] = true;
            if (p2.contains(p)){
                p2[p] = true;
                if (p3.contains(p)){
                    total1 -= 3; total2 -= 3; total3 -= 3;
                    p3[p] = true;
                } else {
                    total1 -= 2; total2 -= 2;
                }
            } else {
                if (p3.contains(p)){
                    total1 -= 2; total3 -= 2;
                    p3[p] = true;
                }
            }
        }

        for (auto [p, visited] : p2){
            if (!p2[p]){
                p2[p] = true;
                if (p1.contains(p)){
                    p1[p] = true;
                    if (p3.contains(p)){
                        total1 -= 3; total2 -= 3; total3 -= 3;
                        p3[p] = true;
                    } else {
                        total1 -= 2; total2 -= 2;
                    }
                } else {
                    if (p3.contains(p)){
                        total2 -= 2; total3 -= 2;
                        p3[p] = true;
                    }
                }
            }
        }

        for (auto [p, visited] : p3){
            if (!p3[p]){
                p3[p] = true;
                if (p1.contains(p)){
                    p1[p] = true;
                    if (p2.contains(p)){
                        total1 -= 3; total2 -= 3; total3 -= 3;
                        p2[p] = true;
                    } else {
                        total1 -= 2; total3 -= 2;
                    }
                } else {
                    if (p2.contains(p)){
                        total2 -= 2; total3 -= 2;
                        p2[p] = true;
                    }
                }
            }
        }

        cout << total1 << " " << total2 << " " << total3 << endl;

        p1.clear(); p2.clear(); p3.clear();
    }

    return 0;
}