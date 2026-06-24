// Leia os dados de 8 atletas.
// Implemente funções para:
// a) Calcular IMC;
// b) Encontrar o artilheiro;
// c) Encontrar o atleta mais novo;
// d) Ordenar por número de gols;
// e) Alterar os dados de um atleta usando ponteiros.
#include <stdio.h>
#include <math.h>
#define jogadores 3


//Criacao da variavel tipo atleta
typedef struct{
    char nome [50];
    int idade ;
    float altura ;
    float peso ;
    int gols ;
} Atleta;

//Função para calcular IMC
float IMC(float peso, float altura){
    float imc = 0;
    imc = peso / pow(altura, 2); 
    return imc; 
}

//Procedimerto para encontrar artilheiro
void artilheiro(Atleta atletas[jogadores]){
    int i, maior = 0, indice = 0;
    for(i=0; i<jogadores; i++){
        if(atletas[i].gols >= maior){
            maior = atletas[i].gols; 
            indice = i; 

        }
    }
    printf("O artilheiro é: %s com %d\n", atletas[indice].nome, atletas[indice].gols);
}

//Procedimento para encontrar jogador mais novo
void maisNovo(Atleta atletas[jogadores]){
    int i, menor = atletas[0].idade, indice = 0;
    for(i=1; i<jogadores; i++){
        if(atletas[i].idade <= menor){
            menor = atletas[i].idade; 
            indice = i; 

        }
    }
    printf("O atleta mais novo é: %s com %d\n", atletas[indice].nome, atletas[indice].idade);
}

//Procedimento para ordenar em ordem descrescente os jogadores pelo numero de gols
void ordenarGols(Atleta atletas[jogadores]){
    int i;
    Atleta aux; 
    for(i=jogadores-1; i>0; i--){
        if(atletas[i].gols > atletas[i-1].gols){
            aux = atletas[i-1]; 
            atletas[i-1] = atletas[i];
            atletas[i] = aux; 
            i= jogadores; // Volta o laco para o incio, garantindo que todos os elementos estejam ordenados
        }
    }
    for(i=0; i<jogadores; i++){
        printf("Os jpogadores ordenados por gols sao %s / %d gols\n", atletas[i].nome, atletas[i].gols);
    }
}

void alterarDados(Atleta *atleta){
    scanf("%s", atleta->nome); //Posso usar essa outra sintaxe tambem, aqui o * do ponteiro esta embutido na seta
    scanf("%d", &(*atleta).idade); //Aqui eu faco manualmente, entao o & esta sendo usado para pegar o endereco de memoria do campo idade da struct atleta atraves do ponteiro
    scanf("%f", &(*atleta).altura);
    scanf("%f", &(*atleta).peso);
    scanf("%d", &(*atleta).gols);
}

int main(){
    int i;
    Atleta atletas[jogadores]; //Crio um vetor do tipo atleta
    for(i=0; i<jogadores; i++){ //Preencho o vetor com as informações de 8 atletas
        scanf("%s", atletas[i].nome);
        scanf("%d", &atletas[i].idade);
        scanf("%f", &atletas[i].altura);
        scanf("%f", &atletas[i].peso);
        scanf("%d", &atletas[i].gols);
    }

    //Chama o procedimento  de alterar dados de um atleta (Usei um atleta fixo de exemplo)
    alterarDados(&atletas[0]);

    //Chama a função de IMC e calcula para cada jogador
    for(i=0; i<jogadores; i++){
        printf("O IMC do jogador %s é: %f\n", atletas[i].nome, IMC(atletas[i].peso, atletas[i].altura));
    }

    //Chama o procedimento de verificar artilheiro
    artilheiro(atletas); 
    //Chama o procedimento de verificar mais novo
    maisNovo(atletas); 
    //Chama o procedimento de ordenar por gols (decrescente)
    ordenarGols(atletas);


    printf("=====Lista depois das chamadas de função======\n");
    for(i=0; i<jogadores; i++){
        printf("Nome: %s\n Idade: %d\n Altura: %f\n Peso: %f\n Gols: %d\n ", 
            atletas[i].nome, 
            atletas[i].idade,
            atletas[i].altura, 
            atletas[i].peso, 
            atletas[i].gols
        );
    }
    return 0; 
}