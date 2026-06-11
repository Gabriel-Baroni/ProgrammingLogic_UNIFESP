// Escreva um procedimento recursivo que receba como parametros um numero inteiro N
// e uma sequencia de N numeros inteiros e imprima essa sequencia em ordem inversa,
// separando cada elemento por um espa¸co. Escreva um programa que leia um numero
// inteiro N (1 ≤ N ≤ 100) indicando o tamanho de uma sequencia e, em seguida, leia e
// armazene uma sequencia de N numeros inteiros e, utilizando esse procedimento, imprima
// essa sequencia em ordem inversa a da leitura.

#include <stdio.h>
#define MAX 100
void inverso(int N, int vetor[MAX]){ 
    if(N==0){
        printf("%d ", vetor[N]);
    } else {
        printf("%d ", vetor[N]); 
        inverso(N-1, vetor);
        
    }
}

int main(){
    int i, N, vetor[MAX];
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &vetor[i]);
    }
    inverso(N-1, vetor); 
    return 0; 
}