// Na teoria dos sistemas, define-se o elemento MINMAX de uma matriz, composta de
// elementos distintos, como sendo o maior elemento da linha onde se encontra o menor
// elemento da matriz. Escreva uma funcao que receba como parametros dois numeros
// inteiros M e N e uma matriz de M × N numeros inteiros e retorne o valor do elemento
// MINMAX dessa matriz. Escreva um programa que leia dois numeros inteiros M (1 ≤
// M ≤100) e N (1 ≤ N ≤ 100) indicando, respectivamente, o numero de linhas e de
// colunas de uma matriz e, em seguida, leia e armazene uma matriz de M × N numeros
// inteiros e, utilizando essa funcao, imprima o valor do seu elemento MINMAX.


#include <stdio.h>
#define MAX 100
int minmax (int M, int N, int matriz[][MAX]){
    int i, j, menor=0, menorL=0, maior=0;
    for(i=0; i<M; i++){ //Laco para percorrer a matriz e achar a linha do menor elemento
        for(j=0; j<N; j++){
            if(i==0 && j==0){
                menor = matriz[i][j];
            } else{
                if(matriz[i][j] < menor){
                    menor = matriz[i][j];
                    menorL= i;
                }
            }
        }
    }
    for(j=0; j<N; j++){ //Laco para percorrer a linha do menor elemento e pegar o maior 
        if(j == 0 ){
            maior = matriz[menorL][j];
        } else {
            if(matriz[menorL][j]> maior){
                maior = matriz[menorL][j];
            }
        }
    }
    return maior;
}

int main(){
    int M, N, i, j, matriz[MAX][MAX];
    scanf("%d %d", &M, &N);
    for(i=0; i<M; i++){ //Laco para preencher a matriz
        for(j=0; j<N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("%d", minmax(M, N, matriz));
    return 0;
}