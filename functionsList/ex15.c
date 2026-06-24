#include <stdio.h>
# define MAX_ALUNOS 20
# define MAX_AMIGOS 10

typedef struct {
    char nome [50];
    int amigos [ MAX_AMIGOS ];
    int qtdAmigos ;
} Aluno ;

int existeLigacao (Aluno rede [], int origem, int destino, int visitado []){
    int i, indiceAmigo=0; 
    if(origem == destino){
        return 1;
    }
    if(visitado[origem] == 1){
        return 0; 
    }
    visitado[origem] =1; 
    for(i=0; i<rede[origem].qtdAmigos; i++){
        indiceAmigo = rede[origem].amigos[i]; 
        if(existeLigacao(rede, indiceAmigo, destino, visitado) == 1){
            return 1; 
        }
    }
    return 0; 
}

int main(){
    Aluno rede[MAX_ALUNOS]; 
    int visitados[MAX_ALUNOS] = {0}, nAlunos, nAmigos, i, j, origem, destino;
    printf( "Digite quantos alunos quer cadastrar");
    scanf("%d", &nAlunos);
    for(i=0; i<nAlunos; i++){
        printf("\nDigite o nome do Aluno: ");
        scanf("%s", rede[i].nome); 
        printf("\nDigite quantos amigos esse aluno tem: ");
        scanf("%d", &nAmigos); 
        for(j=0; j<nAmigos; j++){
            printf("\nDigite o indice do amigo na rede: ");
            scanf("%d", &rede[i].amigos[j]);
        }
        rede[i].qtdAmigos = nAmigos; 
    }
    printf("\nDigite a origem e o destino: ");
    scanf("%d %d", &origem, &destino); 
    if(existeLigacao(rede, origem, destino, visitados)){
        printf("Existe ligação entre %s e %s", rede[origem].nome, rede[destino].nome);
    } else {
        printf("Não existe ligação"); 
    }
}