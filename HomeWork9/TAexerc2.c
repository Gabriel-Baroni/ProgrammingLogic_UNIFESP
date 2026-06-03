//  Escreva um programa que leia um número inteiro n e imprima o valor do n-esimo termo
// da serie de Fibonacci. Para isso, seu programa deve usar uma funcao que receba como
// parametro um numero inteiro n e retorne f(n), ou seja, o valor do n-esimo termo da
// serie de Fibonacci
#include <stdio.h>

int fibonacci (int num){
    int i, f1=1, f0=0, fn;
    if(num == 1){
        fn = 1;
    }
    if (num == 0){
        fn=0;
    }
    for(i=2; i<=num; i++){
        fn=f1+f0;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", fibonacci(n)); //chama a função
    return 0; 
}