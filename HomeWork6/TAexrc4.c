/*Um número N inteiro positivo é perfeito se for igual a soma de seus divisores positivos
diferentes de N (por exemplo, 6 é perfeito, pois 1 + 2 + 3 = 6). Escreva um programa
que leia um número inteiro e imprima “sim” caso esse número seja perfeito ou “nao”
caso contrário*/

#include <stdio.h>
 int main(){
    int n, i, soma = 0;
    scanf("%d", &n);
    for (i=1; i<n; i++){
        if(n%i == 0){
            soma+= i;
        }
    }
    if(soma == n && n>0){
        printf("sim");
    } else {
        printf("nao");
    }
    return 0; 
 }