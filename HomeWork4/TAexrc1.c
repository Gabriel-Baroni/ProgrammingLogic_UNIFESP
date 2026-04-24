/******************************************************************************
Escreva um programa que leia uma temperatura em Celsius e imprima a temperatura
em Fahrenheits.
*******************************************************************************/

#include <stdio.h>

int main()
{
    double temperatura;
    scanf("%lf", &temperatura);
    temperatura = temperatura * 9/5 + 32;
    printf("%lf", temperatura);
    
    return 0;
}