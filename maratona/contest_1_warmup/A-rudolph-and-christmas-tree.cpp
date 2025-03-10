#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n, d, h; cin >> n >> d >> h;
        vector<int> numbers(n);
        for (int j = 0; j < n; j++){
            cin >> numbers[j];
        }
        float area_base = (float)(d * h) / 2;
        float soma = 0;
        if (n == 1){
            soma = area_base;
        } else {
            for (int j = 0; j < n-1; j++){
                if (abs(numbers[j]-numbers[j+1]) >= h){
                    soma += area_base;
                } else {
                    float altura_coberta = abs(numbers[j] - numbers[j+1]);
                    float base_coberta = d - altura_coberta+1;
                    float area_coberta = (float)(base_coberta * altura_coberta) / 2;
                    soma += (area_base + area_base - area_coberta);
                }
            }
        }
        cout << soma << endl;
    }

    return 0;
}