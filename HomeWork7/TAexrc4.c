/*
 * -----------------------------------------------------------------------------
 * PROBLEMA: Busca de Elemento X em Vetor de Tamanho N
 * -----------------------------------------------------------------------------
 * Descrição:
 * 1. Lê um inteiro N (1 <= N <= 100) para o tamanho do vetor.
 * 2. Lê e armazena N números inteiros em um vetor.
 * 3. Lê um número inteiro X (valor a ser procurado).
 * 4. Saída: 
 * - Quantas vezes X aparece no vetor.
 * - Os índices (posições) onde X foi encontrado, um por linha.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#define MAX 100
int main () {
    int N, vetor[MAX], x, i, posicoes[MAX], qtd = 0;
    scanf("%d", &N);
    for (i=0; i<N; i++){
        scanf("%d", &vetor[i]);
    }
    scanf("%d", &x);
    for(i=0; i<N; i++){
        if(vetor[i] == x){
            posicoes[qtd] = i;
            qtd+= 1;
        }
    }
    printf("%d\n", qtd);
    for(i=0; i<qtd; i++){
        printf("%d\n", posicoes[i]);
    }
    return 0; 
}