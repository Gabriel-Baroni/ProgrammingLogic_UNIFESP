/*Escreva um programa que leia um número inteiro e imprima “sim” caso esse número
 seja primo ou “nao” caso contrário.*/ 

#include <stdio.h>
int main (){
    int num, i;
    int teste = 0; // Variável booleana
    scanf("%d", &num);
    for(i=2; i<=num; i++){
        if(num%i == 0 &&  i != num){
            teste = 0;
            break;
        } else {
            teste = 1;
        }
    }
    if(teste==0){
        printf("nao");
    } else {
        printf("sim");
    }
    return 0; 

}