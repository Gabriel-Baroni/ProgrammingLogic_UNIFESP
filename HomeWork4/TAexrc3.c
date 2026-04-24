/******************************************************************************
Escreva um programa que leia 2 nu´meros inteiros e imprima a soma do quociente e do
resto da divis˜ao do primeiro (dividendo) pelo segundo (divisor)
*******************************************************************************/

#include <stdio.h>

int main()
{
    int num1, num2, soma; 
    scanf("%d %d", &num1, &num2);
    soma = (num1/num2) + (num1 % num2);
    printf("%d", soma);
    
    return 0;
}