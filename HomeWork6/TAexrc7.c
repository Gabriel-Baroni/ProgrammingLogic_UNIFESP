/*
 * Exercício: Pesquisa de Audiência de TV
 * * Descrição:
 * O programa analisa a audiência de diferentes canais de TV (17, 18, 19, 20 e 22).
 * Para cada casa, lê-se o número do canal e o número de pessoas assistindo.
 * * Canais:
 * - 17: Globo
 * - 18: SBT
 * - 19: Record
 * - 20: Bandeirantes
 * - 22: Cultura
 * * Condição de Parada:
 * - O programa encerra quando o canal digitado for 0 (zero).
 * * Saída:
 * - Calcular e imprimir o percentual de audiência de cada canal.
 * - Imprimir apenas os canais que possuem audiência (percentual > 0).
 * - Exibir um valor por linha, seguindo a ordem crescente dos canais.
 */

#include <stdio.h>
#define MAX 100
int main(){
    int canal, pessoas, pesquisa[MAX][2], c=0, i, audT=0 , aud17=0, aud18=0, aud19=0, aud20=0, aud22=0;
    scanf("%d %d", &canal, &pessoas);
    audT = pessoas;
    //Crio a Matriz de pesquisa com as respostas
    while(canal != 0 && c < MAX){
        pesquisa[c][0] = canal;
        pesquisa[c][1] = pessoas;
        scanf("%d", &canal);
        if(canal != 0){
            scanf("%d", &pessoas);
            audT += pessoas;
        }
        c++;
    }    
    //Percorro essa Matriz identificando as audiências dos canais
    for (i=0; i<c; i++){
        switch (pesquisa[i][0]){
            case 17:
                aud17+=pesquisa[i][1];
                break;
            case 18:
                aud18+=pesquisa[i][1];
                break;
            case 19:
                aud19+=pesquisa[i][1];
                break;
            case 20:
                aud20+=pesquisa[i][1];
                break;
            case 22:
                aud22+=pesquisa[i][1];
                break;
        }
    }
    if(aud17 > 0){
        printf("17 %lf\n", (aud17*100.0)/audT);
    }
    if(aud18 > 0){
        printf("18 %lf\n", (aud18*100.0)/audT);
    }
    if(aud19 > 0){
        printf("19 %lf\n", (aud19*100.0)/audT);
    }
    if(aud20 > 0){
        printf("20 %lf\n", (aud20*100.0)/audT);
    }
    if(aud22 > 0){
        printf("22 %lf\n", (aud22*100.0)/audT);
    }
    return 0; 
}