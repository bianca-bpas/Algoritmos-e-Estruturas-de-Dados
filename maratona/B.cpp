#include <iostream>
using namespace std;

int coordenada_inicial(int COORD);
int coordenada_final(int COORD, int M);

int main(){
    // dimensões do grid
    int N, M;
    cin >> N >> M;
    int grid[N][M];

    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= M; j++){
            grid[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }


    // numero de sensores
    int S;
    cin >> S;

    int X, Y, R;
    for (int sensor = 1; sensor <= S; sensor++){
        cin >> X >> Y >> R;
        int x_inicial = coordenada_inicial(X);
        int x_final = coordenada_final(X, M);
        cout << x_inicial << " " << x_final << endl;
        int y_inicial = coordenada_inicial(Y);
        int y_final = coordenada_final(Y, M);
        cout << y_inicial << " " << y_final << endl;

        for (int i = y_inicial; i <= y_final; i++){
            for (int j = x_inicial; j <= x_final; j++){
                cout << i << " " << j << endl;
                grid[i][j] = grid[i][j] + 1;
                //cout << grid[i][j] << " ";
            }
        }
    }




    return 0;
}

int coordenada_inicial(int COORD){
    int temp = COORD;
    while (temp >= 1){
        temp--;
    }
    return temp;
}

int coordenada_final(int COORD, int M){
    int temp = COORD;
    while (temp <= M){
        temp++;
    }
    return temp;
}