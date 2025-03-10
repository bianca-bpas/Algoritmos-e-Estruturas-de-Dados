#include <stdio.h>
#include <stdlib.h>

typedef struct Date{
    int dia, mes, ano;
    char* nome_mes;
} Date;


Date* initDate(int day, int month, int year){
    Date *date = (Date*) malloc(sizeof(Date));
    char* nomeM = (char*) malloc(10*sizeof(char));
    date->dia = day; date->mes = month; date->ano = year; date->nome_mes = nomeM;
    return date; 
}

void setDay(int d, Date* data){
    data->dia = d;
}

void nameMonth(Date* data){
    switch (data->mes){
    case 1:
        data->nome_mes = "janeiro";
        break;
    
    default:
        break;
    }
}

void printDate(Date* data){
    printf("----------- DATA ------------\n");
    printf("Dia: %d\n", data->dia); 
    printf("Mes: %d\n", data->mes);
    printf("Ano: %d\n", data->ano);
    printf("Nome do Mes: %s\n", data->nome_mes);
}

int main(){
    int d, m, a;
    printf("Dia: "); scanf("%d", &d);
    printf("Mes: "); scanf("%d", &m);
    printf("Ano: "); scanf("%d", &a);
    Date* data = initDate(d, m, a);

    printDate(data);
    scanf("%d", &d);
    setDay(d, data);
    printDate(data);
    nameMonth(data);

    return 0;
}