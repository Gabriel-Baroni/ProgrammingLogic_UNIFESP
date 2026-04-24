/*Escreva um programa que leia dois números inteiros referentes a hora atual (ou seja,
hora com os minutos, como por exemplo 13 horas e 30 minutos) e imprima quantos
minutos se passaram desde o início do dia.
*/
#include <stdio.h>

int main(){
    int hora, min, TotalMin;
    scanf("%d %d", &hora, &min);
    TotalMin = hora * 60 + min;
    printf("%d", TotalMin);
    return 0;

}