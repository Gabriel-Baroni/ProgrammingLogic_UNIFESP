// Escreva uma funcao recursiva que receba como parametros um numero inteiro N e
// um conjunto de N numeros inteiros e retorne o valor do maior elemento desse conjunto.
// Escreva um programa que leia um numero inteiro N (1 ≤ N ≤ 100) indicando o tamanho
// de um conjunto e, em seguida, leia e armazene um conjunto de N numeros inteiros e,
// utilizando essa funcao, encontre e imprima o maior deles.

#include <stdio.h>
#define MAX 100
int maiorV(int N, int vetor[MAX]){
    int maior=0; 
    if(N==0){ //Se o numero de elementos no vetor for 1 retorna o proprio numero
        return vetor[N]; 
    } else {
        maior= maiorV(N-1, vetor); //O maior numero será o maior entre os valores do vetor N-1
        if(vetor[N] > maior){ 
            return vetor[N]; 
        } else{
            return maior; 
        }
    }
}
int main(){
    int i, N, vetor[MAX];
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &vetor[i]);
    }
    printf("%d",maiorV(N-1, vetor)); 
}
