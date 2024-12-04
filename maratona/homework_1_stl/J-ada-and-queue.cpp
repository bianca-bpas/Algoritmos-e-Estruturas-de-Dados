#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void reversing(deque<int>& fila);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q, N; 
    cin >> Q;
    string operation;
    deque<int> fila;

    for (int consulta = 0; consulta < Q; consulta++){
        cin >> operation;
        if (operation == "push_back"){
            cin >> N;
            fila.push_back(N);
        } else if (operation == "toFront"){
            cin >> N;
            fila.push_front(N);
        } else if (operation == "reverse"){
            if (!fila.empty()){
                reversing(fila);
            }
        } else {
            if (!fila.empty()){
                if (operation == "back"){
                    cout << fila.back() << endl;
                    fila.pop_back();
                } else if (operation == "front"){
                    cout << fila.front() << endl;
                    fila.pop_front();
                }
            } else {
                cout << "No job for Ada?" << endl;
            }
        }
    }
    return 0;
}

void reversing(deque<int>& fila){
    unsigned int left = 0, right = fila.size()-1; 

    while (left < right){
        swap(fila[left], fila[right]);
        left++; right--;
    }
}