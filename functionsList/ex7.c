// Uma matriz 5 × 4 armazena as notas de desempenho de 5 atletas em 4 partidas.
// Implemente funções para:
// a) Média de cada atleta;
// b) Média de cada partida;
// c) Atleta mais regular;
// d) Melhor nota da matriz e sua posição.

#include <stdio.h>
void mediaAtleta(float matriz[5][4], float notas[5]){ // Lembrar que uma matriz e um vetor funcionam como ponteiro 
    int i, j;
    float soma = 0.0;
    for(i=0; i<5; i++){ //Percorro a matriz e somo cada linha (1 atleta)
        for(j=0; j<4; j++){
            soma += matriz[i][j]; 
        }
        notas[i] = soma/4.0; //Faco a media da linha (1 atleta) e coloco no vetor (notas)
        printf("%f\n", notas[i]); 
        soma = 0.0; 
    }
}

void mediaPartida (float matriz[5][4], float notas[4]){ // Lembrar que uma matriz e um vetor funcionam como ponteiro 
    int i, j;
    float soma = 0.0; 
    for(j=0; j<4; j++){ //Percorro a matriz e somo cada coluna (1 partida)
        for(i=0; i<5; i++){
            soma += matriz[i][j]; 
        }
        notas[j] = soma/5.0; //Faco a media da coluna (1 partida) e coloco no vetor (notas)
        printf("%f\n", notas[j]); 
        soma = 0.0; 
    }
}

void atletaRegular(float matriz[5][4], float notasAtletas[5]){
    int i, j, maisRegular = 0; 
    float menoarVariancia = 0.0; 
    float diferenca = 0, somaDiferenca = 0.0, varianciaAtual = 0.0; 

    for(i=0; i<5; i++){
        somaDiferenca = 0.0;
        for(j=0; j<4; j++){
            //Faz a nota da partida - media do jogador
            diferenca = matriz[i][j] - notasAtletas[i]; 
            somaDiferenca+= diferenca * diferenca;  //Evita valores negativos elevando ao quadrado
        } 

        varianciaAtual = somaDiferenca / 4.0; //Essa é a variancia de 1 atleta
         if(i==0){
            menoarVariancia = varianciaAtual;
            maisRegular = 0; 

         } else if (varianciaAtual< menoarVariancia){ //A menor variancia é o mais regular
            menoarVariancia = varianciaAtual; 
            maisRegular = i; 
         }
    }
    printf("O atleta mais regular e o Atleta %d (Variancia de: %f)\n", maisRegular + 1, menoarVariancia);
}

void melhorNota(float matriz[5][4]){
    int i, j, linha = 0, coluna = 0;
    float maior = matriz[0][0];
    for(i=0; i<5; i++){ //Percorre a matriz e encontra a maior nota e sua posicao
        for(j=0; j<4; j++){
            if(matriz[i][j] >=  maior){
                linha = i; 
                coluna = j; 
                maior = matriz[i][j]; 
            }
        }
    }  
    printf("A maior nota é %f na posicao: %d - %d", maior, linha, coluna); 
}
int main(){
    int  i, j;
    float matriz[5][4], notasAtletas[5], notasPartidas[4]; 
    for(i=0; i<5; i++){ //Preenche a matriz
        for(j=0; j<4; j++){
            scanf("%f", &matriz[i][j]); 
        }
    }

    //Chamada de funções
    mediaAtleta(matriz, notasAtletas); 
    mediaPartida(matriz, notasPartidas); 
    atletaRegular(matriz, notasAtletas); 
    melhorNota(matriz); 
}