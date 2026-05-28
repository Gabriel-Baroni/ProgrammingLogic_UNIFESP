// Escreva um programa que leia dois números inteiros M (1 ≤ M ≤ 100) e N (1 ≤ N ≤
// 100) indicando, respectivamente, o número de linhas e de colunas de uma matriz e, em
// seguida, leia e armazene uma matriz de M×N números inteiros e encontre a posiçao do
// maior elemento, imprimindo o índice da linha e da coluna desse elemento, separando-os
// com um espaço em branco.

#include <stdio.h>
#define MAX 100
int main(){
    int M, N, matriz[MAX][MAX], i, j, maior=0, indiceL=0, indiceC=0;
    scanf("%d %d", &M, &N); 
    for (i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] > maior){
                maior = matriz[i][j]; 
                indiceL=i;
                indiceC=j;
            }
        }
    }
    
    printf("%d %d", indiceL, indiceC); 
    return 0; 
}