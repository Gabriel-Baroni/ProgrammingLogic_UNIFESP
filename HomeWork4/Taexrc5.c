/*Escreva um programa que leia o preço à prazo de um produto e imprima o seu preço à
vista, que tem um desconto de 9%.*/
#include <stdio.h>

int main(){
    double preco;
    scanf("%lf", &preco);
    preco *= 0.91;
    printf("%lf", preco);
    return 0;

}