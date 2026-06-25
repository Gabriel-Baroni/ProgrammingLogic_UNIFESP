// Considere uma matriz quadrada N × N representando um campo minado.
// Inicialmente, cada posição da matriz contém:
// • −1: bomba;
// • 0: posição vazia.
// Implemente uma função que preencha a própria matriz com a quantidade de bombas existentes
// nas oito posições vizinhas de cada célula.
// Uma célula com bomba deve permanecer com valor −1.
// Considere N = 5.
// # define N 5
// void calcularNumeros ( int campo [ N ][ N ]) ;
// int contarBombasVizinhas ( int campo [ N ][ N ] , int linha , int coluna ) ;
// Depois, implemente uma função recursiva para revelar posições do campo.
// void revelar ( int campo [ N ][ N ] ,
// int visivel [ N ][ N ] ,
// int linha ,
// int coluna ) ;
// A matriz visivel deve armazenar:
// • 0: posição ainda escondida;
// • 1: posição já revelada.
// Regras da função revelar:
// 1. Se a posição estiver fora da matriz, a função deve parar.
// 2. Se a posição já estiver revelada, a função deve parar.
// 3. Se a posição contiver uma bomba, a função deve apenas revelá-la e parar.
// 4. Se a posição contiver um número maior que zero, a função deve revelá-la e parar.
// 5. Se a posição contiver zero, a função deve revelá-la e chamar recursivamente as oito posições
// vizinhas.

#include <stdio.h>
#define N 5

int contarBombasVizinhas ( int campo [ N ][ N ] , int linha , int coluna ){
    int bombas = 0;
    //Verifica se acima da posicao selecionada tem bomba
    if(linha+1 <5 && campo[linha+1][coluna] == -1){
        bombas+=1; 
    }
    //Verifica se abaixo da posicao selecionada tem bomba
    if(linha-1 >=0 && campo[linha-1][coluna] == -1){
        bombas+=1; 
    }
    //Verifica se ao lado direito da posicao seleciona tem bomba
    if(coluna+1 <5 && campo[linha][coluna+1] == -1){
        bombas+=1; 
    }
    //Verifica se ao lado esquerdo da posicao selecionada tem bomba
    if(coluna-1 >=0 && campo[linha][coluna-1] == -1){
        bombas+=1; 
    }
    //Verifica se na diagonal de cima a direita tem bomba
    if(coluna+1 <5 && linha+1 <5 && campo[linha+1][coluna+1] == -1){
        bombas+=1; 
    }
    //Verifica se na diagonal de baixo a esquerda tem bomba
    if(coluna-1 >=0  && linha-1 >=0 && campo[linha-1][coluna-1] == -1){
        bombas+=1; 
    }
    //Verifica se na diagonal de baixo a direita tem bomba
    if(coluna+1 <5  && linha-1 >=0 && campo[linha-1][coluna+1] == -1){
        bombas+=1; 
    }
    //Verifica se na diagonal de cima a esquerda tem bomba
    if(coluna-1 >=0  && linha+1 <5 && campo[linha+1][coluna-1] == -1){
        bombas+=1; 
    }
    return bombas; 

}

void calcularNumeros ( int campo [ N ][ N ]){
    int i, j;
    for (i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(campo[i][j] == 0){ //Se o campo nao for uma bomba
                campo[i][j] = contarBombasVizinhas(campo, i, j); //Calcula a quantidade de bombas proximas
            }
        }
    }
}


void revelar ( int campo [N ][N] , int visivel [ N ][ N ], int linha, int coluna ){
    if(linha>=5 || linha <0 || coluna>=5 || coluna <0){ //Se a posicao jogada estiver fora dos limites da matriz, ja para
        return; 
    }
    if(visivel[linha][coluna] ==1){ //Se ja foi revelada, ja para
        return;  
    } 
    if(campo[linha][coluna] == -1){ //Se for uma bomba, para
        return; 
    }
    visivel[linha][coluna] = 1; //Se nao for nada disso, vai marcar a posicao como visitada
    if(campo[linha][coluna] > 0){ // Se for maior que zero vai parar
        return ; 
        }
    if(campo[linha][coluna] == 0){ //Se for igual a zero vai chamadas recursivas para cada posicao proxima
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
                    printf("[*]"); //Simbolo da bomba
                }
                else if (campo[i][j]==0){
                    printf("[ ]"); //Simbolo de vazio
                }
                else{
                    printf("[%d]", campo[i][j]); //Valor da dica
                }
            }
        }
        printf("\n"); 
    }
}

int main(){
    int linha, coluna, casasSeguras=22, i, j, abertas=0;
    int fimJogo = 0; //Boolean 
    int campo[N][N] = { //Inicializa o campo
        { 0, -1,  0,  0,  0},
        { 0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0},
        { 0,  0,  0, -1, -1},
        { 0,  0,  0,  0,  0}
    };
    int visivel[N][N] = { //Inicializa o visivel
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
        if(linha <0 || linha>=N || coluna<0 || coluna>=N){ //Verifica a coordenada
            printf("Coordenada invalida, tente novamente");
            continue; 
        }
        if(campo[linha][coluna] == -1){
            visivel[linha][coluna] = 1; 
            imprimirTabuleiro(campo, visivel);
            printf("BOOMMMM!, Morreu");
            fimJogo =1;
        } else{
            revelar(campo, visivel, linha, coluna); //Chama a funcao recursiva
            abertas =0; 
            for(i=0; i<N; i++){ 
                for(j=0; j<N; j++){
                    if(visivel[i][j] == 1){ //Verifica quantas posicoes ja foram abertas
                        abertas++;
                    }
                }
            }
            if(abertas == casasSeguras){ //Se for a mesma quantidade de posicoes seguras, o jogador venceu 
                printf("Parabéns, você venceu o jogo!");
                fimJogo =1; 
            }
        }
    } 
    return 0; 
}