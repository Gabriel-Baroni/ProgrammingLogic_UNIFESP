// Escreva um procedimento recursivo que receba como parâmetro um número natural
// e imprima esse número em representacao binaria. Escreva um programa que leia um
// numero natural e, utilizando esse procedimento, imprima a representacao binaria desse
// numero.

#include <stdio.h>
 void binario(int n){
    int aux = 0; 
    aux = n/2;
    if(aux > 0){ //Se a divisao de N/2 for maior que zero, significa que as divisões ainda nao chegaram no final
        binario(aux); //Chama a própia função com o valor n/2 
        printf("%d", n%2); //Só será impresso quando as chamadas posteriores forem encerradas
    } else{
        printf("%d", n%2); 
    }
 }

 int main(){
    int n;
    scanf("%d", &n);
    binario(n); 
    return 0; 
 }