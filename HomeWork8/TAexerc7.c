#include <stdio.h>
#define MAX 100
int main(){
    int M, N, K, L, C, i, j, navios=0;
    char tabuleiro[MAX][MAX];
    scanf("%d %d", &M, &N);
    //Preenchendo o tabuleiro
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf(" %c", &tabuleiro[i][j]);
        }
    }
    //Pegando o numero de disparos
    scanf(" %d", &K);
    //Pegando a coordenada de cada disparo e verificando se atingiu
    for (i=0; i<K; i++){
        scanf("%d %d", &L, &C);
        if(tabuleiro[L-1][C-1] == '#' && tabuleiro[L-1][C] != '#' && tabuleiro [L-1][C-2] != '#' && tabuleiro[L][C-1] != '#' && tabuleiro[L-2][C-1] != '#'){
            navios+=1;
            tabuleiro[L-1][C-1] == '.'; 
        } else{
            tabuleiro[L-1][C-1] == '.';
        }
    }
    printf("%zu", sizeof(navios)); 

    return 0; 
}