/*Escreva um programa que leia um número inteiro N (1 ≤ N ≤ 100) indicando a ordem
de uma matriz e, em seguida, leia e armazene uma matriz de N × N números inteiros
e verifique se a matriz é simétrica, imprimindo o número 1 caso afirmativo ou 0 caso
contrário.*/
#include <stdio.h>
#define MAX 100

int main()
{
    int N, matriz[MAX][MAX], matrizT[MAX][MAX], i, j, simetria=1;
    scanf("%d", &N);
    for(i=0; i<N; i++){ //Laço para a linha
        for(j=0; j<N; j++){ //Laço para a coluna
            scanf("%d", &matriz[i][j]);
        }
    }
    //Faz a transposta
    for(i=0; i<N; i++){ //Laço para a linha
        for(j=0; j<N; j++){ //Laço para a coluna
            matrizT[i][j] = matriz[j][i];
        }
    }
    
    //Compara as duas
    for(i=0; i<N; i++){ //Laço para a linha
        for(j=0; j<N; j++){ //Laço para a coluna
            if(matrizT[i][j] != matriz[i][j]){
                simetria = 0;
            }
        }
    }   
    printf("%d", simetria);

    return 0; 
}