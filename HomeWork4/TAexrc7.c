/*Escreva um programa que leia dois números reais referentes a altura (h) e o raio (r) de
uma lata de óleo e imprima o seu volume (V = 3.14 · h · r2).*/

#include <stdio.h>
#include <math.h>

int main(){
    double h, r, v;
    scanf("%lf %lf", &h, &r );
    v = 3.14 * h * pow(r, 2);
    printf("%lf", v);
    return 0; 
}