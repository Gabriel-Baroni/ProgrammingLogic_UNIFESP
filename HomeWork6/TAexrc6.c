/*
 * Exercício: Estatísticas de Desempenho de um Time de Futebol
 * * Descrição:
 * Leia o número total de jogos no campeonato. Para um número de partidas 
 * analisadas (menor ou igual ao total), leia o número de gols feitos e tomados.
 * O valor -1 indica o fim da lista de partidas analisadas.
 * * Estatísticas a serem impressas (uma por linha):
 * 1. Porcentagem de partidas analisadas.
 * 2. Porcentagem de vitórias nas partidas analisadas.
 * 3. Porcentagem de empates nas partidas analisadas.
 * 4. Porcentagem de derrotas nas partidas analisadas.
 * 5. Saldo de gols (Total Feitos - Total Tomados).
 * 6. Maior número de gols tomados em uma derrota. 
 * (Se não houver derrotas: "Nao houve derrotas.")
 * 7. Maior número de gols feitos em uma vitória. 
 * (Se não houver vitórias: "Nao houve vitorias.")
 */
 
 
#include <stdio.h>
int main(){
    int NJogosCamp, gols=0, golsT=0, c=0, TotalG=0, TotalGT=0, vitorias=0, derrotas=0, empates=0, recordG=0, recordGT=0; 
    scanf("%d", &NJogosCamp);
    while(c < NJogosCamp ){
        scanf("%d", &gols);
        if (gols == -1){
            break;
        }
        scanf("%d", &golsT);
        if (golsT == -1){
            break;
        }
        if(gols > golsT){
            vitorias++;
            if(gols > recordG){
                recordG = gols; 
            }
        } else if (gols == golsT){
            empates++; 
        } else {
            derrotas++; 
            if(golsT > recordGT){
                recordGT = golsT;
            }
        }
        TotalG += gols;
        TotalGT += golsT;
        c++;
    }
    //Porcentagem de partidas analisadas
    printf("%lf\n", (c*100.0)/NJogosCamp);
    //Porcentagem de vitorias nas partidas analisadas
    printf("%lf\n", (vitorias*100.0)/c);
    //Porcentagem de empates nas partidas analisadas
    printf("%lf\n", (empates*100.0)/c);
    //Porcentagem de derrota nas partidas analisadas
    printf("%lf\n", (derrotas*100.0)/c);
    //Saldo de gols
    printf("%d\n", TotalG - TotalGT); 
    if (derrotas > 0){
        printf("%d\n", recordGT);
    } else {
        printf("Nao houve derrotas.\n");
    }
    if (vitorias > 0){
        printf("%d\n", recordG);
    } else {
        printf("Nao houve vitorias.\n");
    }
 
    return 0; 
}