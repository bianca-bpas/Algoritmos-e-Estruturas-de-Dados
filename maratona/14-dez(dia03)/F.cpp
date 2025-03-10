#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n; cin >> n;
    vector<char> nova(n.size(), '\0');
    bool impossible = false;
    map<char, int> restantes;

    for (int i = 0; i < n.length(); i++){
        restantes[n[i]]++;
    }

    for (int i = 0; i < n.size()/2; i++){
        if (n[i] == n[n.size()-i-1]){
            if (restantes[n[i]] > 1){
                nova[i] = nova[n.size()-i-1] = n[i];
                restantes[n[i]]-=2;
            } else {
                char temp='\0';
                for (auto [chave, valor] : restantes){
                    if (valor >= 2 && nova[i] == '\0'){
                        nova[i] = nova[n.size()-i-1] = chave;
                        restantes[chave]-=2;
                        temp = chave;
                    }
                }
                if (temp == '\0'){
                    cout << "NO SOLUTION" << endl;
                    impossible = true;
                    break;
                }
            }
        } else {
            char primeiro, segundo;
            primeiro = n[i]; segundo = n[n.size()-i-1];
            if (restantes[primeiro] >= restantes[segundo]){
                if (restantes[n[i]] > 1){
                    nova[i] = n[i];
                    nova[n.size()-i-1] = n[i];
                    restantes[n[i]] -= 2;
                } else {
                    char temp='\0';
                    for (auto [chave, valor] : restantes){
                        if (valor >= 2 && nova[i] == '\0'){
                            nova[i] = nova[n.size()-i-1] = chave;
                            restantes[chave]-=2;
                            temp = chave;
                        }
                    }
                    if (temp == '\0'){
                        cout << "NO SOLUTION" << endl;
                        impossible = true;
                        break;
                    }
                }
            } else {
                if (restantes[n[n.size()-i-1]] > 1){
                    nova[i] = n[n.size()-i-1];
                    nova[n.size()-i-1] = n[n.size()-i-1];
                    restantes[n[n.size()-i-1]]-=2;
                } else {
                    char temp='\0';
                    for (auto [chave, valor] : restantes){
                        if (valor >= 2 && nova[i] == '\0'){
                            nova[i] = nova[n.size()-i-1] = chave;
                            restantes[chave]-=2;
                            temp = chave;
                            
                        }
                    }
                    if (temp == '\0'){
                        cout << "NO SOLUTION" << endl;
                        impossible = true;
                        break;
                    }
                }
            }
        }
    }
    bool preenchido = false;
    auto vazio = find(nova.begin(), nova.end(), '\0');
    if (vazio == nova.end()){
        preenchido = true;
    }
    for (auto [chave, valor] : restantes){
        if (valor > 0){
            if (!preenchido){
                auto vazio = find(nova.begin(), nova.end(), '\0');
                if (vazio != nova.end()){
                    int idx = distance(nova.begin(), vazio);
                    nova[idx] = chave;
                    restantes[chave]--;
                } else {
                    preenchido = true;
                }
            } else {
                cout << "NO SOLUTION" << endl;
                impossible = true;
                break;
            }
        }
    }

    if (!impossible){
        for (auto letra : nova){
            cout << letra;
        }
        cout << endl;
    }

    return 0;
}