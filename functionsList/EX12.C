#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char nome [50];
    int matricula ;
    float notas [3];
    float media ;
    int faltas ;
} Aluno ;

void cadastrar(Aluno lista[MAX], int nAlunos){
    int  i, j;
    float soma = 0.0; 
    for(i=0; i<nAlunos; i++){
        soma = 0.0; 
        printf("\nDigite o nome do aluno: ");
        scanf("%s", lista[i].nome);
        printf("\nDigite a matricula do aluno: ");
        scanf("%d", &lista[i].matricula);
        for(j=0; j<3; j++){
            printf("\nDigite a nota %d do aluno %s", j+1, lista[i].nome);
            scanf("%f", &lista[i].notas[j]);
            soma += lista[i].notas[j]; 
        }
        lista[i].media = soma/3; 
        printf("\nDigite as faltas do aluno: ");
        scanf("%d", &lista[i].faltas);
    }
}

float mediaGeralRecursiva (Aluno lista[MAX], int tam){
    if(tam==0){
        return lista[0].media; 
    } else{
        return lista[tam].media + mediaGeralRecursiva(lista, tam-1); 
     
    } 
}

void maiorMenorMedia(Aluno lista[MAX],  int tam){
    int i, indiceMin=0, indiceMax=0;
    float maior = lista[0].media, menor = lista[0].media;
    for(i=1; i<tam; i++){
        if(lista[i].media > maior){
            maior = lista[i].media; 
            indiceMax = i; 
        }
        if(lista[i].media < menor){
            menor = lista[i].media; 
            indiceMin = i; 
        }
    }

    printf("O aluno %s possui a maior media: %f", lista[indiceMax].nome, lista[indiceMax].media);
    printf("O aluno %s possui a menor media: %f", lista[indiceMin].nome, lista[indiceMin].media);
}

void ordenarMedia(Aluno lista[MAX], int tam){
    int i, j;
    Aluno aux = lista[0];
    for(i=0; i<tam-1; i++){
        for(j=0; j<tam-1; j++){
            if(lista[j].media > lista[j+1].media){
                aux = lista[j+1];
                lista[j+1] = lista[j]; 
                lista[j] = aux; 
            }
        }
    } 
    for(i=0; i<tam; i++){
        printf("\n%s, media: %f", lista[i].nome, lista[i].media); 
    }
}

void listarAprovados_Reprovados(Aluno lista[MAX], int tam){
    Aluno aprovados[MAX], reprovados[MAX];
    int i, apro = 0, repro =0;
    for(i=0; i<tam; i++){
        if(lista[i].media>=6.0 && lista[i].faltas <=15){
            aprovados[apro] = lista[i];
            apro+=1;
        } else {
            reprovados[repro] = lista[i];
            repro+=1; 
        }
    }
    printf("Os seguintes alunos estão aprovados:\n");
    for(i=0; i<apro; i++){
        printf("%s matricula: %d", aprovados[i].nome, aprovados[i].matricula);
    }
    printf("Os seguintes alunos estão reprovados:\n");
    for(i=0; i<repro; i++){
        printf("%s matricula: %d", reprovados[i].nome, reprovados[i].matricula);
    }
}

void alterarNota(Aluno lista[MAX], int tam){ //Utilizar uma vetor como parametro é o mesmo que um ponteiro
    int matricula, i, Nnota;
    float Vnota=0.0;  
    printf("\nDigite a matricula do aluno que deseja alterar a nota: "); 
    scanf("%d", &matricula); 
    for(i=0; i<tam; i++){
        if(lista[i].matricula == matricula){
            printf("\nDigite a número da nota que deseja alterar e o novo valor: ");
            scanf("%d %f", &Nnota, &Vnota); 
            lista[i].notas[Nnota-1] = Vnota; 
            lista[i].media = (lista[i].notas[0] + lista[i].notas[1] + lista[i].notas[2])/3;
        }
    }
}

int main(){
    Aluno minhaLista[MAX];
    int nAlunos;
    printf("\nQuantos alunos deseja cadastrar: "); 
    scanf("%d", &nAlunos);
    cadastrar(minhaLista, nAlunos); 
    printf("\nA média geral dos alunos é: %f", mediaGeralRecursiva(minhaLista, nAlunos-1)/nAlunos);
    printf("\nOrdem crescente dos alunos por media:\n");
    ordenarMedia(minhaLista, nAlunos);
    printf("\nLista dos aprovados e reprovados: ");
    listarAprovados_Reprovados(minhaLista, nAlunos); 
    printf("Menor e maior média");
    maiorMenorMedia(minhaLista, nAlunos); 
    printf("-----Alterar nota de aluno-----");
    alterarNota(minhaLista, nAlunos); 
    return 0; 


}
