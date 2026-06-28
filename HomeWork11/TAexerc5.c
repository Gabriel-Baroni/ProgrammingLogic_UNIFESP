//  O Comitˆe Ol´ımpico Internacional (COI) est´a visitando as cidades candidatas a sediar as
// Olimp´ıadas de 2016. O Rio de Janeiro ´e uma das cidades concorrentes, mas a competi¸c˜ao
// ´e muito acirrada.
// OCOI tem um conjunto de exigˆencias que devem ser obedecidas pelas cidades candida
// tas, como boas arenas para os jogos (gin´asios, campos de futebol, pistas de atletismo,
// parque aqu´atico, ...), bons alojamentos, um plano para o tr´afego de ve´ıculos durante
// os jogos, etc. Durante sua visita ao Rio de Janeiro, o COI colocou ainda mais uma
// exigˆencia: a demonstra¸c˜ao da qualidade dos sistemas de inform´atica. Especificamente,
// o COI quer que a organiza¸c˜ao local demonstre a sua capacidade em inform´atica produ
// zindo um programa que gere a classifica¸c˜ao final dos pa´ıses, considerando o n´umero de
// medalhas recebidas pelos atletas de cada pa´ıs.
// Escreva um programa que, dada a informa¸c˜ao dos pa´ıses que receberam medalhas de
// ouro, prata e bronze em cada modalidade, gere a lista de classifica¸c˜ao dos pa´ıses na
// competi¸c˜ao. Nesta tarefa, os pa´ıses ser˜ao identificados por n´umeros inteiros. O melhor
// colocado deve ser o pa´ıs que conseguiu o maior n´umero de medalhas de ouro. Se houver
// empate entre pa´ıses no n´umero de medalhas de ouro, o melhor colocado entre esses ´e o
// pa´ıs que conseguiu o maior n´umero de medalhas de prata. Se houver empate tamb´em
// no n´umero de medalhas de prata, o melhor colocado entre esses ´e o pa´ıs que recebeu o
// maior n´umero de medalhas de bronze. Se ainda assim houver empate entre dois pa´ıses,
// o melhor classificado ´e o que tem o menor n´umero de identifica¸c˜ao.
// A primeira linha da entrada cont´em dois n´umeros inteiros N e M, separados por um
// espa¸co em branco, indicando respectivamente o n´umero de pa´ıses (1 ≤ N ≤ 100) e
// n´umero de modalidades esportivas envolvidas na competi¸c˜ao (1 ≤ M ≤ 100). Os pa´ıses
// s˜ao identificados por n´umeros inteiros de 1 a N. Cada uma das M linhas seguintes
// cont´em trˆes n´umeros inteiros O, P e B, separados por um espa¸co em branco, represen
// tando os pa´ıses cujos atletas receberam respectivamente medalhas de ouro (1 ≤ O ≤ N),
// prata (1 ≤ P ≤ N) e bronze (1 ≤ B ≤ N). Assim, se uma das M linhas cont´em os
// n´umeros 3 2 1, significa que nessa modalidade a medalha de ouro foi ganha pelo pa´ıs 3,
// a de prata pelo pa´ıs 2 e a de bronze pelo pa´ıs 1. Seu programa deve imprimir uma linha
// contendo N n´umeros, separados por um espa¸co em branco, representando os pa´ıses na
// ordem decrescente de classifica¸c˜ao (o primeiro n´umero representa o pa´ıs que ´e o primeiro
// colocado, o segundo n´umero representa o pa´ıs que ´e o segundo colocado, e assim por
// diante).


#include <stdio.h>
#define MAX 100

 typedef struct {
    int id;
    int ouro;
    int prata;
    int bronze; 
 } Pais;

 //Faco um procedimento para ordenar as medalhas 
 void verificarMedalhas(int vencedor[3], Pais paises[MAX], int j, int N){
    int k;
    for(k=0; k<N; k++){
        if(vencedor[j] == paises[k].id){ //Se o vencedor for igual ao id do pais
            if(j==0){ //Se for medalha de ouro
                paises[k].ouro += 1; 
            } else if (j==1){ //Se for medalha de prata
                paises[k].prata +=1; 
            } else { //Se for de bronze
                paises[k].bronze +=1;
            }
        } 
    }
}

//Procedimento para classificarPaises
void classificarPaises(Pais paises[MAX], int N){
    int i, j;
    Pais aux; 
    //Use ordenacao por bubble sort
    for(i=0; i<N-1; i++){ //Repito a verificacao de dentro N vezes
        for(j=0; j<N-1; j++){ //Verifico em pares qual e maior e qual e o menor 
            if(paises[j].ouro < paises[j+1].ouro){ //Condicao de medalhas de ouro
                aux = paises[j];
                paises[j] = paises[j+1];
                paises[j+1] = aux;  

            } else if (paises[j].ouro == paises[j+1].ouro){ //Condicao de medalhas de ouro iguais
                if(paises[j].prata < paises[j+1].prata){ //Condicao de medalhas de prata
                    aux = paises[j];
                    paises[j] = paises[j+1];
                    paises[j+1] = aux;  
                    
                }  else if (paises[j].prata == paises[j+1].prata){//Condicao de medalhas de prata iguais
                    if(paises[j].bronze < paises[j+1].bronze){//Condicao de medalhas de bronze
                        aux = paises[j];
                        paises[j] = paises[j+1];
                        paises[j+1] = aux;  

                    } else if (paises[j].bronze == paises[j+1].bronze){//Condicao de medalhas de bronze iguais
                        if(paises[j].id > paises[j+1].id){ //Condicao de menor id em primeiro
                            aux = paises[j];
                            paises[j] = paises[j+1];
                            paises[j+1] = aux;  

                        }
                    }
                }    
            }   
        }        
    }

    for(i=0; i<N; i++){
        printf("%d ", paises[i].id);
    }
}
 
 
int main(){
    Pais paises[MAX];
    int N, M, i, j, k, vencedor[3];
    scanf("%d %d", &N, &M); 
    //Inicializo o vetor de paises com valores padrao
    for(i=0; i<N; i++){
        paises[i].id = i+1;
        paises[i].ouro = 0;
        paises[i].prata = 0;
        paises[i].bronze = 0; 
    }
    //Faco um looping que repitira M vezes (o numero de modalidades) a declaracao de medalhas para cada pais
    for(i=0; i<M; i++){
        for(j=0; j<3; j++){ //Como sao tres medalhas, para cada modalidade sera 3 valores de entrada
            scanf("%d", &vencedor[j]);
            verificarMedalhas(vencedor, paises, j, N); //Chamo a fuincao para atribuir essa medalha a algum pais do vetor paises
        }
    }
    classificarPaises(paises, N); 
    return 0; 
}