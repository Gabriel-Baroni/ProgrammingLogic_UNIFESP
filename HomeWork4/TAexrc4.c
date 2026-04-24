/*Escreva um programa que leia um número inteiro de 3 dígitos e mostre o algarismo da
casa das dezenas.*/

#include <stdio.h> 
int main (){
    int num;
    scanf("%d", &num);
    num /= 10;
    num %= 10;
    printf("%d", num);
    return 0;
}

/* OUTRA FORMA DE FAZER
#include <stdio.h> 
int main (){
    int num;
    char str[3];
    scanf("%d", &num);
    sprintf(str, "%d", num);
    printf("%c", str[1]);
    return 0;
}
*/