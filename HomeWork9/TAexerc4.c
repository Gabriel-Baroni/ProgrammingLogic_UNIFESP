//  Escreva um procedimento que receba como parametros um numero inteiro N e uma
// sequencia de N numeros inteiros e imprima essa sequencia em ordem inversa, separando
// cada elemento por um espaco. Escreva um programa que leia um numero inteiro N
// (1 ≤ N ≤100) indicando o tamanho de uma sequencia e, em seguida, leia e armazene
// uma sequencia de N numeros inteiros e, utilizando esse procedimento, imprima essa
// sequencia em ordem inversa a da leitura.

#include <stdio.h>
#define MAX 100
//Procedimento que imprime o vetor passado no parametro na ordem inversa
void inverso (int vet[], int N){
    int i;
    for(i=N-1; i>=0; i--){
        printf("%d ", vet[i]);
    }
}

int main(){
    int N, i, vet[MAX];
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &vet[i]);
    }
    inverso(vet, N); //Chamo o procedimento
    return 0;
}