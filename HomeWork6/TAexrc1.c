/*Escreva um programa que leia dois números inteiros e efetue a multiplicação desses
números utilizando apenas operações de soma e subtração*/

#include <stdio.h>
 
int main(){
    int num1, num2, i, mul = 0;
    int Temnegativo = 0; //Será usado como booleano
    scanf("%d %d", &num1, &num2);
    if(num1 < 0 && num2 <0){
        num1 = -num1;
        num2= -num2;
    }
    if(num1<0){
        num1 = -num1;
        Temnegativo = 1;
    }
    if(num2<0){
        num2 = -num2;
        Temnegativo = 1; 
    }
    for (i=0; i<num2; i++){
        mul+=num1;
    }
    if(Temnegativo ==1){
        mul = -mul; 
    }
    printf("%d", mul);
    return 0; 
}