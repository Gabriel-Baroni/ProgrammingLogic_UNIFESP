//  Escreva um programa que leia dois números inteiros M (1 ≤ M ≤ 100) e N (1 ≤ N ≤
// 100) indicando, respectivamente, o número de linhas e de colunas de uma matriz e, em
// seguida, leia e armazene uma matriz de M×N números inteiros e calcule e imprima a
// soma dos elementos de cada linha, separando-os com um espaço em branco

#include <stdio.h>
#define MAX 100
int main(){
    int M, N, matriz[MAX][MAX], i, j, soma=0;
    scanf("%d %d", &M, &N);
     for(i=0; i<M; i++){ //Laço para a linha
        for(j=0; j<N; j++){ //Laço para a coluna
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            soma += matriz[i][j];
        }
        printf("%d ", soma);
        soma=0; 
    }
    return 0; 
}