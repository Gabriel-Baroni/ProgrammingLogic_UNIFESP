/*Escreva um programa utilizando a linguagem C para ler uma sequência de números inteiros terminada por zero, calcular a 
média aritmética desses números e mostrar a média e qtd. de números da sequência*/
#include <stdio.h>
int main(){
    int num, qtd = 0;
    double avg, soma= 0.0;
    do{
        printf("Digite um número: ");
        scanf("%d", &num);
        if(num != 0){
            qtd ++;
            soma += num;
        }
    } while (num != 0);
    if(qtd >0){
        avg = soma/qtd;
        printf("A média dos números é: %lf e a quantidade de números é: %d", avg, qtd);
    } 
    else {
        printf("Nenhum número digitado.");
    }
    return 0;
}