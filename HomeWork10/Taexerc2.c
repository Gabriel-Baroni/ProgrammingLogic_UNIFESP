// Na teoria dos sistemas, define-se o elemento MINMAX de uma matriz, composta de
// elementos distintos, como sendo o maior elemento da linha onde se encontra o menor
// elemento da matriz. Escreva uma fun¸c˜ao que receba como parˆametros dois nu´meros
// inteiros M e N, uma matriz de M × N nu´meros inteiros e os endere¸cos de duas vari´aveis
// inteiras, por exemplo, linha e coluna, e deposite nessas vari´aveis a posi¸c˜ao do seu
// elemento MINMAX e retorne o valor do elemento MINMAX dessa matriz. Escreva um
// programa que leia dois nu´meros inteiros M (1 ≤ M ≤ 100) e N (1 ≤ N ≤ 100) indicando,
// respectivamente, o nu´mero de linhas e de colunas de uma matriz e, em seguida, leia e
// armazene uma matriz de M × N nu´meros inteiros e, utilizando essa fun¸c˜ao, imprima
// a posi¸c˜ao (isto ´e, os ´ındice da linha e da coluna) e o valor do seu elemento MINMAX,
// separando-os com um espa¸co em branco.

#include <stdio.h>
#define MAX 100
int minMax(int M, int N, int matriz[][MAX], int *linha, int *coluna){
    int i, j, menor=matriz[0][0], maior = 0;
    for (i=0; i<M; i++){
        for(j=0; j<N; j++){
            if(matriz[i][j] < menor){ //Verifica a linha do menor elemento
                menor = matriz[i][j];
                *linha = i; 
                maior = matriz[i][0];
                *coluna=0;
            }
        }
    }
    for(i=0; i<N; i++){ //Verifica, dentro da linha do menor, qual é o maior elemento
        if (matriz[*linha][i] > maior){
            maior = matriz[*linha][i]; 
            *coluna = i;
        }
    }
    return maior;
}

int main(){
    int i, j, M, N, matriz[MAX][MAX], linha = 0 , coluna = 0;
    scanf("%d %d", &M, &N);
    for (i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d",&matriz[i][j]); 
        }
    }
    printf("%d %d %d", linha, coluna, minMax(M, N, matriz, &linha, &coluna) ); 
}