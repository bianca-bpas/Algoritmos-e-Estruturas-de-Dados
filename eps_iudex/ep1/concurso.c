#include <stdio.h>
#include <stdlib.h>


void selection_sort(int *arr, int len);
int binary_search(int *arr, int key, int inicio, int fim);

int main(){
    int c, i, v, nota, idade;
    int *notas, *notas_temp;
    char *nomes[5000];
    int *idades;


    for (int f=0; f<5001; f++){
        nomes[f] = malloc(31 * sizeof(char*));
    }

    scanf("%d", &c); // Quantidade de cargos

    for (int cont=0; cont < c; cont++){
        scanf("%d", &i); // Quantidade de inscritos
        i = 3;
        scanf("%d", &v); // Quantidade de vagas

        notas = (int*) malloc(i * sizeof(int));
        notas_temp = (int*) malloc(i * sizeof(int));
        idades = (int*) malloc(i * sizeof(int));
        //nomes = (char*) malloc(i * sizeof(char));
    

        for (int cont2=0; cont2 < i; cont2++){
            scanf("%s%d%d", nomes[cont2], &notas[cont2], &idades[cont2]);
        }


        for (int cont3=0; cont3 < sizeof(notas)/sizeof(int); cont3++){
            notas_temp[cont3] = notas[cont3];
        }

        

        selection_sort(notas_temp, sizeof(notas)/sizeof(int));
        int posicao_primeiro = binary_search(notas_temp, notas[0], 0, i-1);

        for (int cont4=0; cont4 < i; cont4++){
            if (cont4 <= sizeof(notas)/sizeof(notas[0])){
                printf("%s",nomes[cont4]);
            }
            
        }

        
    }

