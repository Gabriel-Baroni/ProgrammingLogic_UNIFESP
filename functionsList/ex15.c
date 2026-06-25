// Considere uma pequena rede social formada por alunos.
// Cada aluno possui um nome e uma lista de amigos. Cada amizade é representada pelo índice de
// outro aluno no vetor da rede.
// Considere as constantes:
// # define MAX_ALUNOS 20
// # define MAX_AMIGOS 10
// E o registro:
// typedef struct {
// char nome [50];
// int amigos [ MAX_AMIGOS ];
// int qtdAmigos ;
// } Aluno ;
// Implemente uma função recursiva que determine se existe uma sequência de amizades ligando dois
// alunos.
// int existeLigacao ( Aluno rede [] ,
// int origem ,
// int destino ,
// int visitado []) ;

// A função deve retornar:
// • 1, se existir uma ligação entre origem e destino;
// • 0, caso contrário.
// O vetor visitado deve ser usado para evitar chamadas recursivas infinitas.
// Exemplo conceitual:
// Ana -> Bruno -> Carlos -> Daniel
// Nesse caso, existe uma ligação entre Ana e Daniel, mesmo que eles não sejam amigos diretamente.

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
    if(origem == destino){ //Se a origem ficou igual ao destino, chegamos em quem procuravamos
        return 1;
    }
    if(visitado[origem] == 1){ //Se a pessoa ja foi verificada, retorna 
        return 0; 
    }
    visitado[origem] =1; 
    for(i=0; i<rede[origem].qtdAmigos; i++){
        indiceAmigo = rede[origem].amigos[i]; 
        if(existeLigacao(rede, indiceAmigo, destino, visitado) == 1){ //Para cada amigo da pessoa verifica se tem conexao com o destino
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
    //Preenche a informacao de cada aluno
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
    return 0; 
}