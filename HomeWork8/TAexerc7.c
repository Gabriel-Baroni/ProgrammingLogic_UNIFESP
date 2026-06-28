// Pedro e Paulo gostam muito de jogar batalha naval; apesar de serem grandes amigos,
// Pedro desconfia que Paulo n˜ao esteja jogando honestamente. Para tirar essa du´vida,
// Pedro decidiu usar um programa de computador para verificar o resultado do jogo, mas
// Pedro n˜ao sabe programar e por isso pediu a sua ajuda.
// O jogo de batalha naval ´e jogado em um tabuleiro retangular com M linhas e N colunas.
// Cada posi¸c˜ao deste tabuleiro ´e um quadrado que pode conter ´agua ou uma parte de um
// navio. Dizemos que dois quadrados s˜ao vizinhos se estes possuem um lado em comum.
// Se duas partes de navio est˜ao em posi¸c˜oes vizinhas, ent˜ao essas duas partes pertencem
// ao mesmo navio. A regra do jogo pro´ıbe que os quadrados de duas partes de navios
// distintos tenham um canto em comum (em outras palavras, que quadrados de duas
// partes de navios distintos compartilhem um v´ertice).
// Cada disparo que um jogador faz deve ser feito em um dos quadrados do tabuleiro do
// outro jogador. Um jogador informa ao outro a coluna e a linha do quadrado alvo do
// disparo. Para que um navio seja destru´ıdo, o jogador deve acertar todas as partes deste
// navio. O jogador n˜ao pode atirar no mesmo lugar mais de uma vez.
// Escreva um programa que, dadas a configura¸c˜ao do tabuleiro e uma sequˆencia de disparos feitos por um jogador, determina o nu´mero de navios do outro jogador que foram
// destru´ıdos. A primeira linha da entrada cont´em dois nu´meros inteiros M (1 ≤ M ≤ 100)
// e N (1 ≤ N ≤ 100) indicando, respectivamente, o nu´mero de linhas e de colunas do tabuleiro. As M linhas seguintes correspondem ao tabuleiro do jogo. Cada uma dessas
// linhas cont´em N caracteres. Cada caractere indica o conteu´do da posi¸c˜ao correspondente no tabuleiro. Se esse caractere for ‘.’, essa posi¸c˜ao cont´em ´agua; se for ‘#’, essa
// posi¸c˜ao cont´em uma parte de um navio. A pr´oxima linha cont´em um nu´mero inteiro K
// (1 ≤ K ≤ M ×N) que ´e o nu´mero de disparos feitos pelo jogador. As pr´oximas K linhas
// indicam os disparos feitos pelo jogador. Cada linha cont´em dois inteiros L (1 ≤ L ≤ M)
// e C (1 ≤ C ≤ N), indicando a linha e a coluna do disparo feito pelo outro jogador. Seu
// programa deve imprimir uma u´nica linha contendo um u´nico nu´mero inteiro, o nu´mero
// de navios destru´ıdos.
// Exemplo:
// basgalupp@ubuntu:∽$ ./tarefa08
// 5 5 {Nu´mero de linhas e colunas do tabuleiro}
// ..#.# {Primeira linha}
// #.... {Segunda linha}
// ...#. {Terceira linha}
// #.... {Quarta linha}
// ...#. {Quinta linha}
// 5 {Nu´mero de disparos}
// 1 3 {Posi¸c˜ao do primeiro disparo}
// 1 4 {Posi¸c˜ao do segundo disparo}
// 1 5 {Posi¸c˜ao do terceiro disparo}
// 2 1 {Posi¸c˜ao do quarto disparo}
// 4 {Nu´mero de navios destru´ıdos}
 
 
#include <stdio.h>
#define MAX 100
int main(){
    int M, N, K, L, C, i, j, z, navios=0, colunaAtual, linhaAtual;
    int comVida = 0; //boolean
    char tabuleiro[MAX][MAX];
    scanf("%d %d", &M, &N);
    //Preenchendo o tabuleiro
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf(" %c", &tabuleiro[i][j]);
        }
    }
    //Pegando o numero de disparos
    scanf("%d", &K);
    //Pegando a coordenada de cada disparo e marca as partes atingidas
    for (i=0; i<K; i++){
        scanf("%d %d", &L, &C);
        if(tabuleiro[L-1][C-1] == '#'){
            tabuleiro[L-1][C-1] = 'X'; 
        }
    }
 
    //Verificando os navios destruidos
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            if(tabuleiro[i][j] != '.'){ //Siginifica qeu achou ou uma parte atingida X ou uma parte intacta #
                colunaAtual = j; 
            
                while(colunaAtual <N && tabuleiro[i][colunaAtual] != '.'){ //A partir do indice da parte atingida ou intacta, verifica se tem alguma parte intacta na mesma linha (para direita)
                    if(tabuleiro[i][colunaAtual] == '#'){
                        comVida = 1; 
                    }
                    tabuleiro[i][colunaAtual] = '.';
                    colunaAtual++; 
 
                }
                linhaAtual = i + 1; //i+1 pois o while de cima ja passou pela posicao i j  
                while(linhaAtual <M && tabuleiro[linhaAtual][j] != '.'){ //A partir do indice da parte atingida ou intacta, verifica se tem alguma parte intacta na mesma coluna (para baixo)
                    if(tabuleiro[linhaAtual][j] == '#'){
                        comVida = 1; 
                    }
                    tabuleiro[linhaAtual][j] = '.';
                    linhaAtual++; 
 
                }
                //Se o navio foi completamente destruido, soma mais 1
                if(comVida == 0){
                    navios++; 
                }
                comVida = 0;
            }
        }
    }
    printf("%d", navios); 
 
    return 0; 
}