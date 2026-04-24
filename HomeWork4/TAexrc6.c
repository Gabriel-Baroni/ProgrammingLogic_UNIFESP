/*Escreva um programa que leia o valor da hora aula, o número de horas de aula dadas
no mês e o percentual de desconto do INSS e imprima o salário líquido de um professor*/

#include <stdio.h>

int main(){
    double valorH, horasM, INSS, salario;
    scanf("%lf %lf %lf", &valorH, &horasM, &INSS);
    salario = (valorH * horasM) *(1-(INSS/100));
    printf("%lf", salario);
    return 0; 
}