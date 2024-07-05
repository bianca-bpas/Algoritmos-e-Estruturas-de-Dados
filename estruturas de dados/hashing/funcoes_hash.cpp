#include <bits/stdc++.h>
using namespace std;

// Hash functions for integers
int trivial_mod(int K, int m);
int mid_square(int K, int m);

// Hash functions for strings
int fold(string K, int m);
int sfold(string K, int m);


int main(){
    int m = 100, K = 4567, h = 0;
    string Ks = "ALGORITHMS";
    // trivial mod
    h = trivial_mod(K, m);
    cout << h << endl;
    // mid square
    h = mid_square(K, m);
    cout << h << endl;
    // fold
    m = 1000;
    h = fold(Ks, m);
    cout << h << endl;
    // sfold
    h = sfold(Ks, m);
    cout << h << endl;

    return 0;
}

int trivial_mod(int K, int m){
    // Calcula o valor absoluto do resto da divisão de K por m
    return abs(K % m);
}

int mid_square(int K, int m){
    // Calcula o quadrado do valor de entrada K
    long int temp = K * K;
    // Determina o número de dígitos r no módulo m
    int r = (int)(floor(log10(m + 1)));
    // Converte o quadrado em uma string para facilitar a manipulação dos dígitos
    string square = to_string(temp);
    // Obtém o comprimento da string que representa o quadrado
    int sqr_length = square.length();
    // Calcula a posição inicial dos r dígitos centrais
    int start_pos = (sqr_length - r) / 2;
    // Extrai os r dígitos centrais e converte de volta para um número inteiro
    int middle = stoi(square.substr(start_pos, r));
    // Retorna o valor dos dígitos centrais como o hash
    return middle;
}

int fold(string K, int m){
    // Obtém o comprimento da string K
    int s = K.length();
    // Inicializa a soma dos valores dos caracteres
    int sum = 0;
    // Itera sobre cada caractere da string K
    for (int i = 0; i <= s - 1; i++){
        // Adiciona o valor ASCII do caractere à soma
        sum += K[i];
    }
    // Retorna o valor absoluto do módulo da soma por m
    return abs(sum % m);
}

int sfold(string K, int m) {
    // Calcula o número de blocos de 4 caracteres
    int Length = K.length() / 4;
    // Inicializa a soma dos valores dos blocos
    int sum = 0;
    // Variável auxiliar para multiplicação exponencial
    int mult;
    // Processa cada bloco de 4 caracteres
    for (int i = 0; i <= Length - 1; i++) {
        // Extrai um bloco de 4 caracteres
        string sub = K.substr(i * 4, 4);
        // Inicializa mult para multiplicação exponencial
        mult = 1;
        // Itera sobre os caracteres do bloco
        for (int j = 0; j <= 3; j++) {
            // Adiciona o valor do caractere multiplicado por mult à soma
            sum += sub[j] * mult;
            // Multiplica mult por 256 para a próxima posição
            mult *= 256;
        }
    }
    // Processa os caracteres restantes que não formam um bloco completo de 4 caracteres
    string sub = K.substr(Length * 4);
    // Inicializa mult novamente para multiplicação exponencial
    mult = 1;
    // Itera sobre os caracteres restantes
    for (int j = 0; j <= (int)sub.length() - 1; j++) {
        // Adiciona o valor do caractere multiplicado por mult à soma
        sum += sub[j] * mult;
        // Multiplica mult por 256 para a próxima posição
        mult *= 256;
    }
    // Retorna o valor absoluto do módulo da soma por m
    return abs(sum % m);
}