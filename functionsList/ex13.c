// Implemente um sistema para classificação de equipes.
// A ordenação deve obedecer:
// 1. Maior número de pontos;
// 2. Maior número de vitórias;
// 3. Maior saldo de gols;
// 4. Maior número de gols pró.

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

            //Primeiro cirterio, maior numero de pontos
            if(lista[j].pontos < lista[j+1].pontos){
                aux = lista[j];
                lista[j] = lista[j+1]; 
                lista[j+1] = aux; 
            } 
            //Se tiver a mesma quantidade de pontos
            else if(lista[j].pontos == lista[j+1].pontos){

                //Segundo criterio, maior numero de vitorias
                if(lista[j].vitorias < lista[j+1].vitorias){
                    aux = lista[j];
                    lista[j] = lista[j+1]; 
                    lista[j+1] = aux;
                } 
                //Se tiver o mesmo numero de vitorias
                else if (lista[j].vitorias == lista[j+1].vitorias){

                    //Terceiro criterio, saldo de gols
                     if(lista[j].saldoGols < lista[j+1].saldoGols){
                        aux = lista[j];
                        lista[j] = lista[j+1]; 
                        lista[j+1] = aux; 
                    } 
                    //Se tiver o mesmo saldo de gols
                    else if(lista[j].saldoGols == lista[j+1].saldoGols){

                        //Quarto criterio, maior numero de gols a favor do time
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
    //Preenche com os dados de cada equipe
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
    //Chama o procedimento
    ordenarEquipes(lista, nEquipes); 
    return 0; 
}