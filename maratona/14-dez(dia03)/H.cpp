#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int mais_popular(map<int, int>& cursos);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> cursos_popularidade;
    multiset<set<int>> sequencias_populares;
    int n=-1, curso;
    while (n != 0){
        cin >> n;
        if (n != 0){
            for (int i = 0; i < n; i++){
                set<int> seq;
                for (int c = 0; c < 5; c++){
                    cin >> curso;
                    cursos_popularidade[curso]++;
                    seq.insert(curso);
                }
                sequencias_populares.insert(seq);
            }
        }

        set<int> seq_wanted;

        for (int i = 0; i < 5; i++){
            seq_wanted.insert(mais_popular(cursos_popularidade));
        }

        cout << sequencias_populares.count(seq_wanted) << endl;
        sequencias_populares.clear();
        seq_wanted.clear();
    
    }

    return 0;
}

int mais_popular(map<int, int>& cursos){
        int maior = 0;
        int curso = -1;
        for (auto [chave, valor] : cursos){
            if (valor > maior){
                maior = valor;
                curso = chave;
            }
        }
        cursos.erase(curso);
        return curso;
}