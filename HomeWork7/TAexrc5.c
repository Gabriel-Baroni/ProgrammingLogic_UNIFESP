/*
 * -----------------------------------------------------------------------------
 * PROBLEMA: Inversão de Sequência de Tamanho N
 * -----------------------------------------------------------------------------
 * Descrição:
 * 1. Lê um inteiro N (1 <= N <= 100).
 * 2. Lê e armazena uma sequência de N números inteiros em um vetor.
 * 3. Imprime a sequência na ordem inversa à da leitura.
 * 4. Os elementos devem ser separados por um único espaço.
 * -----------------------------------------------------------------------------
 */
#include <stdio.h>
#define MAX 100 
int main(){
    int N, vetor[MAX], i;
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &vetor[i]);
    }
    for(i= N-1; i>=0; i--){
        printf("%d ", vetor[i]);
    }
    return 0; 
}