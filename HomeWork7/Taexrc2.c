/*
 * Exercício: Frequência de Números em um Conjunto
 * * Descrição:
 * 1. Lê um número inteiro N (1 <= N <= 100) para o tamanho do conjunto.
 * 2. Lê e armazena N números inteiros em um vetor.
 * 3. Imprime cada número lido seguido da quantidade de vezes que ele 
 * se repete no conjunto.
 * * Formato da Saída:
 * - Dois números por linha, separados por um espaço:
 * [Número] [Frequência]
 */
#include <stdio.h>
#define MAX 100
int main () {
    int N, n, conjunto[MAX], i, qtd[MAX], c=0;
    int conjuntoLido[MAX];  //Um vetor booleano
    scanf("%d", &N);
    if(N>=1 && N<=MAX){
        for(i=0; i<N; i++){
            scanf("%d", &n);
            conjunto[i] = n;
            conjuntoLido[i]=0;
        }
        while(c<N){
            if (conjuntoLido[c]==0){
                qtd[c]=0;
                for(i=0; i<N; i++){
                    if(conjunto[c] == conjunto[i]){
                        qtd[c]+=1;
                        if(i>c){
                            conjuntoLido[i] = 1;
                        }
                    }
                }
                printf("%d %d\n", conjunto[c], qtd[c]);
            }
            c++;
        }
    }
    return 0; 
}