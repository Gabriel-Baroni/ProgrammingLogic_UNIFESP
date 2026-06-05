//  Uma matriz de ordem N e dita formar um quadrado magico quando a soma dos elementos
// de cada linha ´e igual `a soma dos elementos de cada coluna e igual `a soma dos elementos
// da diagonal principal e igual, tamb´em, `a soma dos elementos da diagonal secund´aria.
// Escreva uma fun¸c˜ao que receba como parˆametros um n´umero inteiro N e uma matriz
// de N ×N n´umeros inteiros e e verifique se essa matriz forma um quadrado m´agico,
// retornando o valor do quadrado (ou seja, a soma de uma de suas linhas) caso afirmativo
// ou 0 caso contr´ario. Escreva um programa que leia um n´umero inteiro N (1 ≤ N ≤ 100)
// indicando a ordem de uma matriz e, em seguida, leia e armazene uma matriz de N ×N
// n´umeros inteiros e, utilizando essa fun¸c˜ao, verifique se a matriz forma um quadrado
// m´agico, imprimindo o valor do quadrado (ou seja, a soma de uma de suas linhas) caso
// afirmativo ou 0 caso contr´ario.

#include <stdio.h>
#define MAX 100
int quadradoMagico(int N, int matriz[][MAX]){
    int i, j, soma=0, aux=0; 
    int equadrado = 1; //Boolean
    for(i=0; i<N; i++){ //Verificando a soma das linhas
        soma =0; //
        for(j=0; j<N; j++){
            soma += matriz[i][j];
        }
        if(i==0){
            aux=soma;
            soma=0;
        } else{
            if(aux != soma){
                equadrado = 0; 
            } else{
                aux = soma;
                soma =0;
            }
        }
    }

    for(i=0; i<N; i++){ //Verificando a soma das colunas
        soma = 0;
        for(j=0; j<N; j++){
            soma += matriz[j][i];
        }
        if(soma!= aux){ //Compara com a soma das linhas
            equadrado =0;
        }
    }
    soma = 0;
    for(i=0; i<N; i++){ //Verificando a soma da diagonal principal
        soma += matriz[i][i];
    }
    if(soma!= aux){ //Compara com a soma das linhas
        equadrado =0;
    }
    soma = 0;
    for(i=N-1; i>=0; i--){ //Verificando a soma da diagonal secundaria
        soma += matriz[i][i];
    }
    if(soma!= aux){ //Compara com a soma das linhas
        equadrado =0;
    }
    if(equadrado){
        return aux;
    } else {
        return equadrado; 
    }
}

int main(){
    int N, matriz[MAX][MAX], i, j;
    scanf("%d", &N);

    for(i=0; i<N; i++){ //Preenchendo a matriz
        for(j=0; j<N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("%d", quadradoMagico(N, matriz)); 
    return 0;
}