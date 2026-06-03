/*Escreva um programa que leia dois nu´meros inteiros M (1 ≤ M ≤ 100) e N (1 ≤ N ≤100) indicando, 
respectivamente, o número de linhas e de colunas de uma matriz e, em
seguida, leia e armazene uma matriz de M × N nu´meros inteiros e imprima a matriz
transposta, separando as colunas por um espa¸co em branco e as linhas por uma quebra
de linha.*/ 

#include <stdio.h>
#define MAX 100

int main(){
    int  M, N, matriz[MAX][MAX], i, j;
    scanf("%d %d", &M, &N);
    for (i=0; i<M; i++){ //Laço para as linhas
        for (j=0; j<N; j++){ //Laço para colunas
            scanf("%d", &matriz[i][j]); 
        }
    }
    //Matriz Transposta
    for (i=0; i<N; i++){ //Laço para as colunas
        printf("\n");
        for (j=0; j<M; j++){ //Laço para linhas
            printf("%d ", matriz[j][i]); 
        }
    }
    return 0;
}
