//  Escreva uma funcao que receba como parametros um numero inteiro N e um conjunto
// de N numeros inteiros e retorne o valor do maior elemento desse conjunto. Escreva um
// programa que leia um numero inteiro N (1 ≤ N ≤ 100) indicando o tamanho de um
// conjunto e, em seguida, leia e armazene um conjunto de N n´umeros inteiros e, utilizando
// essa funcao, encontre e imprima o maior deles.
#include <stdio.h>
#define MAX 100
int maior (int vet[], int N){
    int maior = 0, i=0;
    for(i=0; i<N; i++){
        if(i==0){
            maior = vet[i];
        } else {
            if(vet[i]> maior){
                maior= vet[i];
            }
        }
    } 
    return maior;
}

int main(){
    int N, i, vet[MAX];
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &vet[i]);
    }
    printf("%d", maior(vet, i));

    return 0; 
}