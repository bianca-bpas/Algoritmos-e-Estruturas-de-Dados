#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q, N; 
    cin >> Q;
    string operation;
    bool reverse = false;
    deque<int> fila;

    for (int consulta = 0; consulta < Q; consulta++){
        cin >> operation;

        if (operation == "reverse"){
            reverse = !reverse;
        } else {
            if (operation == "push_back"){
                cin >> N;
                if (reverse){
                    fila.push_front(N);
                } else {
                    fila.push_back(N);
                }
            } else if (operation == "toFront"){
                cin >> N;
                if (reverse){
                    fila.push_back(N);
                } else {
                    fila.push_front(N);
                }
            } else {
                if (!fila.empty()){
                    if (operation == "back"){
                        if (reverse){
                            cout << fila.front() << endl;
                            fila.pop_front();
                        } else {
                            cout << fila.back() << endl;
                            fila.pop_back();
                        }
                    } else if (operation == "front"){
                        if (reverse){
                            cout << fila.back() << endl;
                            fila.pop_back();
                        } else {
                            cout << fila.front() << endl;
                            fila.pop_front();
                        }
                    }
                } else {
                    cout << "No job for Ada?" << endl;
                }
            }
        }
    }
    return 0;
}
