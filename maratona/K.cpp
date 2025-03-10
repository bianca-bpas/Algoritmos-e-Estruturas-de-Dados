#include <bits/stdc++.h>
using namespace std;

int winner(vector<int> vetor){
    vector<int>::iterator maior = max_element(vetor.begin(), vetor.end());
    cout << find(vetor.begin(), vetor.end(), *maior) << endl;

    return 0;
}

int main(){
    int N, M, temp, res;
    cin >> N >> M;

    vector<int> A;
    A.push_back(-1);

    for (int i = 1; i <= N; i++){
        A.push_back(0);
    }

    for (int i = 1; i <= M; i++){
        cin >> temp;
        A.at(temp)++;
        res = winner(A);
        cout << res << endl;
    }

    return 0;
}