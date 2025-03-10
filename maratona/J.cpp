#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, num_messages, phone_charge, consumo_por_tempo, consumo_on_off, momento;
    string possible = "NO";
    cin >> t;

    for (int caso = 1; caso <= t; caso++){
        int tempo = 0;
        cin >> num_messages >> phone_charge >> consumo_por_tempo >> consumo_on_off;
        for (int m = 1; m <= num_messages; m++){
            cin >> momento;
            if (tempo < momento){
                phone_charge -= consumo_on_off;
                tempo++;
                while (tempo < momento){
                    tempo++;
                    phone_charge -= consumo_por_tempo;
                }

            }

            while (phone_charge > 0){
                if (phone_charge-((momento)* consumo_por_tempo)> 0){
                    possible = "YES";
                    break;
                } else {
                    phone_charge -= consumo_on_off;
                    tempo++;
                }
            }
            if (phone_charge <= 0){
                break;
            }
        }
        cout << possible << endl;
    }

    return 0;
}