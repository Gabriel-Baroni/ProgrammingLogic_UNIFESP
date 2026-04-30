/* Escreva um programa que leia um número inteiro n e calcule f(n), ou seja, o valor do
n-ésimo termo da série de Fibonacci, o qual é dado por: fórmula*/

#include <stdio.h>

int main(){
    int n, i;
    scanf("%d", &n);
    int fibonacci[n+1];
    fibonacci[0] = 0;
    fibonacci[1] = 1; 
    for(i=2; i<=n; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    if(n==0){
        printf("%d", fibonacci[0]);
    } else if(n==1){
       printf("%d", fibonacci[1]); 
    } else {
        printf("%d", fibonacci[n]);
    }
    return 0; 
}