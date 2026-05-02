/*
 * Exercício: Encontrar o Maior Elemento de um Conjunto
 * * Descrição:
 * O programa lê um número inteiro N (1 <= N <= 100) que representa 
 * o tamanho de um conjunto. Em seguida, lê e armazena N números 
 * inteiros em um vetor, identifica o maior valor entre eles e o imprime.
 * * Entrada:
 * - Um inteiro N (tamanho do conjunto).
 * - N números inteiros.
 * * Saída:
 * - O maior número encontrado no conjunto.
 */

#include <stdio.h>
#define MAX 100
int main(){
    int N, conjunto[MAX], i, n, maior=0;
    scanf("%d", &N);
    for (i=0; i<N; i++){
        scanf("%d", &n);
        conjunto[i] = n;
        if(i>0){
            if(n>maior){
                maior=n;
            }
        } else{
            maior = n;
        }
    }
    printf("%d", maior);
    return 0; 

}