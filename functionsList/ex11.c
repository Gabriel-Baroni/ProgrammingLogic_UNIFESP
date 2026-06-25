// Implemente um jogo da velha utilizando uma matriz 3 × 3.
// Crie funções para inicializar o tabuleiro, imprimir o tabuleiro, realizar jogada, verificar vitória e
// verificar empate.

#include <stdio.h>

void imprimirTabuleiro(char tab[3][3]){
    int i, j; 
    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%c ", tab[i][j]); 
        }
        printf("\n");
    }
}

void realizarJogada (char tab[3][3], int i, int j, char jogada){
    tab[i][j] = jogada; 
}

int vitoria(char tab[3][3]){
    int i, j; 
    int vitoria = 1; //Booelan
    //Verifica vitoria por linha
    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            if(tab[i][j] != tab[i][j+1] || tab[i][j] == '_'){ //Se na linha tiver algum marcador diferente ou vazio, nao tem vitoria
                vitoria = 0; 
            }
        }
        if(vitoria==1){
            return 1; 
        } 
        vitoria = 1; //Reseta a variavel booleana
    }
    //Verifica vitoria por coluna
    for(j=0; j<3; j++){
        for(i=0; i<2; i++){
            if(tab[i][j] != tab[i+1][j] || tab[i][j] == '_'){//Se na coluna tiver algum marcador diferente ou vazio, nao tem vitoria
                vitoria= 0; 
            }
        }
        if(vitoria==1){
            return 1; 
        }
        vitoria =1; //Reseta a variavel booleana
    } 
    //Verifica vitoria por diagonal principal
    for(i=0; i<2; i++){
        if(tab[i][i] != tab[i+1][i+1] || tab[i][i] == '_'){//Se na diagonal principal tiver algum marcador diferente ou vazio, nao tem vitoria
            vitoria = 0; 
        }
    } 
    if(vitoria==1){
        return 1; 
    }
    //Verifica vitoria por diagonal secundaria
    for(i=0; i<0; i++){
        if(tab[i][2-i] != tab[i+1][2-(i+1)] || tab[i][i] == '_'){//Se na diagonal secundaria tiver algum marcador diferente ou vazio, nao tem vitoria
            vitoria = 0; 
        }
    } 
    if(vitoria==1){
        return 1; 
    }

    //Se ninguem ganhou ainda, retorna 0
    return 0; 
    
}


int empate(char tab[3][3]){
    int i, j;
    int empate = 1; 
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if (tab[i][j] == '_'){ //Se ainda tiver espaço vazio, nao deu empate ainda
                empate = 0;
            }
        }
    }
    return empate; 
}

int main(){
    char tab[3][3] = { //Inicializa os espacos vazios
    {'_', '_', '_'}, 
    {'_', '_', '_'},
    {'_', '_', '_'}  
    }, jogada;
    int i, j; 

    while(vitoria(tab) == 0 && empate(tab) ==0){ //Enquanto nao tiver vitoria ou empate
        imprimirTabuleiro(tab);
        printf("\njogador faça sua jogada digitando nº linha, nºcoluna e a letra (X ou O): \n");
        scanf(" %c %d %d", &jogada, &i, &j);
        realizarJogada(tab, i, j, jogada); 
    }
    if(vitoria(tab) == 1){
        printf("Temos um vencedor!");
    } else {
        printf("Deu velha!"); 
    }

}