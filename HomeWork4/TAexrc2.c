/******************************************************************************
Escreva um programa que leia um nu´mero real e imprima a ter¸ca parte deste nu´mero.
*******************************************************************************/

#include <stdio.h>

int main()
{
    double num;
    scanf("%lf", &num);
    num /= 3;
    printf("%lf", num);
    
    return 0;
}