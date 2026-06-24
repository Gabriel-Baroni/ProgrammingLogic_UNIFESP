#include <stdio.h>
#define N 5

int contarBombasVizinhas ( int campo [ N ][ N ] , int linha , int coluna ){
    int bombas = 0;
    if(linha+1 <5 && campo[linha+1][coluna] == -1){
        bombas+=1; 
    }
    if(linha-1 >=0 && campo[linha-1][coluna] == -1){
        bombas+=1; 
    }
    if(coluna+1 <5 && campo[linha][coluna+1] == -1){
        bombas+=1; 
    }
    if(coluna-1 >=0 && campo[linha][coluna-1] == -1){
        bombas+=1; 
    }
    if(coluna+1 <5 && linha+1 <5 && campo[linha+1][coluna+1] == -1){
        bombas+=1; 
    }
    if(coluna-1 >=0  && linha-1 >=0 && campo[linha-1][coluna-1] == -1){
        bombas+=1; 
    }
    if(coluna+1 <5  && linha-1 >=0 && campo[linha-1][coluna+1] == -1){
        bombas+=1; 
    }
    if(coluna-1 >=0  && linha+1 <5 && campo[linha+1][coluna-1] == -1){
        bombas+=1; 
    }
    return bombas; 

}

void calcularNumeros ( int campo [ N ][ N ]){
    int i, j;
    for (i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(campo[i][j] == 0){
                campo[i][j] = contarBombasVizinhas(campo, i, j); 
            }
        }
    }
}


void revelar ( int campo [N ][N] , int visivel [ N ][ N ], int linha, int coluna ){
    if(linha>=5 || linha <0 || coluna>=5 || coluna <0){
        return; 
    }
    if(visivel[linha][coluna] ==1){
        return;  
    } 
    if(campo[linha][coluna] == -1){
        return; 
    }
    visivel[linha][coluna] = 1; 
    if(campo[linha][coluna] > 0){
        return ; 
        }
    if(campo[linha][coluna] == 0){
        revelar(campo, visivel, linha-1, coluna);
        revelar(campo, visivel, linha+1, coluna);
        revelar(campo, visivel, linha, coluna-1);
        revelar(campo, visivel, linha, coluna+1);

        revelar(campo, visivel, linha-1, coluna-1);
        revelar(campo, visivel, linha-1, coluna+1);
        revelar(campo, visivel, linha+1, coluna+1);
        revelar(campo, visivel, linha+1, coluna-1); 
    }
}

void imprimirTabuleiro (int campo[N][N], int visivel[N][N]){
    int i, j; 
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(visivel[i][j] == 0){
                printf("[#]"); 
            }
            else{
                if(campo[i][j] == -1){
                    printf("[*]");
                }
                else if (campo[i][j]==0){
                    printf("[ ]");
                }
                else{
                    printf("[%d]", campo[i][j]); 
                }
            }
        }
        printf("\n"); 
    }
}

int main(){
    int linha, coluna, casasSeguras=22, i, j, abertas=0;
    int fimJogo = 0;
    int campo[N][N] = {
        { 0, -1,  0,  0,  0},
        { 0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0},
        { 0,  0,  0, -1, -1},
        { 0,  0,  0,  0,  0}
    };
    int visivel[N][N] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    calcularNumeros(campo); 

    while(fimJogo == 0){
        imprimirTabuleiro(campo, visivel);
        printf("\nDigite a linha e a coluna desejada: ");
        scanf("%d %d", &linha, &coluna); 
        if(linha <0 || linha>=N || coluna<0 || coluna>=N){
            printf("Coordenada invalida, tente novamente");
            continue; 
        }
        if(campo[linha][coluna] == -1){
            visivel[linha][coluna] = 1; 
            imprimirTabuleiro(campo, visivel);
            printf("BOOMMMM!, Morreu");
            fimJogo =1;
        } else{
            revelar(campo, visivel, linha, coluna); 
            abertas =0; 
            for(i=0; i<N; i++){
                for(j=0; j<N; j++){
                    if(visivel[i][j] == 1){
                        abertas++;
                    }
                }
            }
            if(abertas == casasSeguras){
                printf("Parabéns, você venceu o jogo!");
                fimJogo =1; 
            }
        }
    } 
    return 0; 
}