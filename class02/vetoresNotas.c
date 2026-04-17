/*Escreva um algoritmo para ler uma lista de 100 notas armazenando-as em um vetor denominado NOTA e calcular a média aritmética 
dessas notas e mostrar a média e as notas que estão abaixo da média*/

#include <stdio.h>
#define MAX 100
int main(){
    double NOTA[MAX], AVG, SOMA = 0.0;
    int i;
    for (i=0; i < MAX; i++){
        printf("Digite uma nota: ");
        scanf("%lf", &NOTA[i]);
        SOMA += NOTA[i];
    }
    AVG = SOMA/MAX;
    printf("A média das notas é: %lf\n", AVG);
    for (i=0; i<MAX; i++){
        if(NOTA[i] < AVG){
            printf("Nota abaixo da média -> %lf\n", NOTA[i]);
        }
    }
    return 0; 

}