//  Na teoria dos sistemas, define-se o elemento MINMAX de uma matriz, composta de
// elementos distintos, como sendo o maior elemento da linha onde se encontra o menor
// elemento da matriz. Escreva um programa que leia dois números inteiros M (1 ≤ M ≤
// 100) e N (1 ≤ N ≤ 100) indicando, respectivamente, o n´umero de linhas e de colunas
// de uma matriz e, em seguida, leia e armazene uma matriz de M ×N números inteiros e
// encontre a posição do seu elemento MINMAX, imprimindo o índice da linha e da coluna
// desse elemento, separando-os com um espa¸co em branco
#include <stdio.h>
#define MAX 100
int main(){
    int M, N, matriz[MAX][MAX], i, j, minMaxL=0, minMaxC=0, menor=0, minMax=0;
    scanf("%d %d", &M, &N);
    //Uso esse laço para preencher a matriz e verficar qual é o menor valor e sua linha
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] < menor){
                menor = matriz[i][j];
                minMaxL= i;
            }
        }
    }
    //Nesse outro laço eu percorro somente a linha do menor valor e vejo o MINMAX
    for(j=0; j<=N; j++){
        if(matriz[minMaxL][j] > minMax){
            minMax = matriz[minMaxL][j]; 
            minMaxC = j; 
        }
    }
    printf("%d %d", minMaxL, minMaxC);
    return 0;
}