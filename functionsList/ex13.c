#include <stdio.h>
#define MAX 100
typedef struct {
    char nome [50];
    int pontos;
    int vitorias;
    int empates;
    int derrotas;
    int golsPro;
    int golsContra;
    int saldoGols;
} Equipe;

void ordenarEquipes(Equipe lista[MAX], int tam){
    int i, j;
    Equipe aux = lista[0]; 
    for(i=0; i<tam-1; i++){
        for(j=0; j<tam-1; j++){

            if(lista[j].pontos < lista[j+1].pontos){
                aux = lista[j];
                lista[j] = lista[j+1]; 
                lista[j+1] = aux; 
            } 
            else if(lista[j].pontos == lista[j+1].pontos){

                if(lista[j].vitorias < lista[j+1].vitorias){
                    aux = lista[j];
                    lista[j] = lista[j+1]; 
                    lista[j+1] = aux;
                } 
                else if (lista[j].vitorias == lista[j+1].vitorias){

                     if(lista[j].saldoGols < lista[j+1].saldoGols){
                        aux = lista[j];
                        lista[j] = lista[j+1]; 
                        lista[j+1] = aux; 
                    } 
                    else if(lista[j].saldoGols == lista[j+1].saldoGols){

                        if(lista[j].golsPro < lista[j+1].golsPro){
                            aux = lista[j];
                            lista[j] = lista[j+1]; 
                            lista[j+1] = aux; 
                        }
                    }
                }
            }
        }
    }
    printf("----------CLASSIFICAÇÃO DAS EQUIPES--------");
    for(i=0; i<tam; i++){
        printf("\n%s - Pontos: %d, Vitórias: %d, Empates: %d, Derrotas: %d, Gols feitos: %d, Gols sofridos: %d, Saldo de Gols: %d", lista[i].nome, lista[i].pontos, lista[i].vitorias, lista[i].empates, lista[i].derrotas, lista[i].golsPro, lista[i].golsContra, lista[i].saldoGols);

    }
}

int main(){
    Equipe lista[MAX]; 
    int nEquipes, i; 
    printf("Digite quantas equipes deseja cadastrar: ");
    scanf("%d", &nEquipes); 
    for(i=0; i<nEquipes; i++){
        printf("\nDigite o nome da equipe: ");
        scanf("%s", lista[i].nome);
        printf("\nDigite as vitorias da equipe: "); 
        scanf("%d", &lista[i].vitorias);
        printf("\nDigite os empates da equipe: "); 
        scanf("%d", &lista[i].empates);
        printf("\nDigite as derrotas da equipe: "); 
        scanf("%d", &lista[i].derrotas);
        printf("\nDigite os gols feitos pela equipe: "); 
        scanf("%d", &lista[i].golsPro);
        printf("\nDigite os gols tomados pela equipe: "); 
        scanf("%d", &lista[i].golsContra);
        lista[i].saldoGols = lista[i].golsPro - lista[i].golsContra; 
        lista[i].pontos = (3 * lista[i].vitorias) + lista[i].empates; 
    }
    ordenarEquipes(lista, nEquipes); 


    return 0; 
}