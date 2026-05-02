/*
 * -----------------------------------------------------------------------------
 * PROBLEMA: Multiplicação de dois vetores de tamanho N
 * -----------------------------------------------------------------------------
 * Descrição:
 * 1. Lê um inteiro N (1 <= N <= 100).
 * 2. Lê dois vetores de N números inteiros.
 * 3. Multiplica os elementos de mesmo índice e armazena em um terceiro vetor.
 * 4. Exibe o vetor resultante em uma única linha separado por espaços.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#define MAX 100
int main(){
    int N, vetor1[MAX], vetor2[MAX], vetor3[MAX], i;
    scanf("%d", &N);
    for (i=0; i<N; i++){
        scanf("%d", &vetor1[i]);
    }
    for (i=0; i<N; i++){
        scanf("%d", &vetor2[i]);
    }
    for (i=0; i<N; i++){
        vetor3[i] = vetor1[i] * vetor2[i];
        printf("%d ", vetor3[i]);
    }
    return 0; 

}