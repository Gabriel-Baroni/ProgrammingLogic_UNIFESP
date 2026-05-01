/*Escreva um programa que leia um número inteiro e imprima “sim” caso esse número
 seja primo ou “nao” caso contrário.*/ 

#include <stdio.h>
int main (){
    int num, i = 2; // Começo com 2, pois todo número é divísivel por 1, assim, sempre daria "nao"
    int teste = 1; // Variável booleana
    scanf("%d", &num);
    while(i<=num && teste != 0){
        if(num%i == 0 && i != num){
            teste = 0;
            i++;
        } else {
            teste = 1;
            i++;
        }
    }
    if(teste==0){
        printf("nao");
    } else {
        printf("sim");
    }
    return 0; 

}