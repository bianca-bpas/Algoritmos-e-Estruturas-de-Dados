#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

typedef struct Node{
    int frequencia_cardiaca;
    struct Node* esquerda;
    struct Node* direita;
}Node;

typedef struct ArvoreBinaria {
    Node *raiz = NULL;
} ArvoreBinaria;

Node* criarNode(int x) {
    Node* ptr = new Node;
    if (ptr != NULL) {
        ptr->frequencia_cardiaca = x;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
    }
    return ptr;
}

Node* inserir(Node* raiz, int dado) {
    if (raiz == NULL) {
        raiz = criarNode(dado);
    } else {
        if (dado < raiz->frequencia_cardiaca) {
            raiz->esquerda = inserir(raiz->esquerda, dado);
        } else {
            raiz->direita = inserir(raiz->direita, dado);
        }
    }
    return raiz;
}

int altura(Node* raiz){
    if (raiz == NULL){
        return -1;
    } else {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if (esq > dir){
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}

int main() {
    ifstream infile("tests.txt");
    ofstream outfile("output.txt");
    string linha;

    if (!infile) {
        cerr << "Erro ao abrir o arquivo de entrada" << endl;
        return 1;
    }
    
    if (!outfile) {
        cerr << "Erro ao abrir o arquivo de saída" << endl;
        return 1;
    }

    while (getline(infile, linha)) {
        if (linha.empty()) continue;
        
        istringstream iss(linha);
        int N;
        iss >> N;

        ArvoreBinaria frequencia_pacientes;

        getline(infile, linha);
        istringstream iss_frequencias(linha);
        for (int i = 0; i < N; i++) {
            int frequencia;
            iss_frequencias >> frequencia;
            frequencia_pacientes.raiz = inserir(frequencia_pacientes.raiz, frequencia);
        }

        int saida = altura(frequencia_pacientes.raiz);
        outfile << saida << endl;
    }

    infile.close();
    outfile.close();

    // Verificação das saídas
    ifstream outfile_verif("output.txt");
    ifstream expectedfile("expected_output.txt");

    if (!outfile_verif) {
        cerr << "Erro ao abrir o arquivo de saida para verificacao" << endl;
        return 1;
    }

    if (!expectedfile) {
        cerr << "Erro ao abrir o arquivo de saidas esperadas" << endl;
        return 1;
    }

    string output_line, expected_line;
    int test_case = 1;
    bool all_tests_passed = true;

    while (getline(outfile_verif, output_line) && getline(expectedfile, expected_line)) {
        if (output_line != expected_line) {
            cerr << "Erro no caso de teste " << test_case << ": esperado " << expected_line << ", obtido " << output_line << endl;
            all_tests_passed = false;
        }
        test_case++;
    }

    // Verifica se há um número diferente de linhas em output.txt e expected_output.txt
    if ((getline(outfile_verif, output_line) && !getline(expectedfile, expected_line)) ||
        (!getline(outfile_verif, output_line) && getline(expectedfile, expected_line))) {
        cerr << "Numero de casos de teste diferentes entre os arquivos de saida e esperados" << endl;
        all_tests_passed = false;
    }

    if (all_tests_passed) {
        cout << "Todos os casos de teste passaram!" << endl;
    }

    outfile_verif.close();
    expectedfile.close();

    return 0;
}
