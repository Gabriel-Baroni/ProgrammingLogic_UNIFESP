#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char titulo [80];
    char autor [50];
    int ano ;
    int emprestado; //Boolean
} Livro ;

//Procedimento que busca livro por autor
void buscarLivro(Livro lista[MAX], int tam){
    int i, indice=0;
    int temlivro = 0; 
    char busca [50]; 
    getchar(); //Serve para limpar o buffer e permitir a leitura da string, pois o fgets le ENTER como um caracter
    fgets(busca, 50, stdin); 
    for(i=0; i<tam; i++){
        if(strcmp(busca, lista[i].autor) == 0){ //Usa a funcao  "strcmp" da biblioteca string.h para comparar duas strings
            printf("O livro %s foi encontrado!", lista[i].titulo);  
            temlivro=1;
        }
    }
    if(!temlivro){
        printf("O autor não possui livros registrados"); 
    }
}

//Função para listar os livros disponíveis e retornar quantos, ela mexe no vetor disponiveis no main
int listarDisponiveis(Livro lista[MAX], int tam, Livro disponiveis[MAX]){
    int i, j=0;
    for(i=0; i<tam; i++){
        if(lista[i].emprestado == 0){
            disponiveis[j] = lista[i]; 
            j++; 
        }
    }
    return j; 
}
//Procedimento para emprestimo de livro
void emprestimo(Livro lista[MAX], int tam){
    int i;
    char livroEmprestado [50];
    int temLivro=0;  
    fgets(livroEmprestado, 50, stdin); 
    for(i=0; i<tam; i++){
        if(strcmp(livroEmprestado, lista[i].titulo) == 0){
            if(lista[i].emprestado == 0){
                lista[i].emprestado = 1; 
                printf("O livro foi emprestado com sucesso!");
                temLivro=1; 
            } 
        }
    }
    if(!temLivro){
        printf("Esse livro não esta catalogado ou já foi emprestado");
    }
}

//Procedimento para emprestimo de livro
void devolucao(Livro lista[MAX], int tam){
    int i;
    char livroDevolvido [50];
    int temLivro=0;  
    fgets(livroDevolvido, 50, stdin); 
    for(i=0; i<tam; i++){
        if(strcmp(livroDevolvido, lista[i].titulo) == 0){
            if(lista[i].emprestado == 1){
                lista[i].emprestado = 0; 
                printf("O livro foi devolvido com sucesso!");
                temLivro=1; 
            } 
        }
    }
    if(!temLivro){
        printf("Esse livro não esta catalogado ou nao foi emprestado");
    }
}

//Procedimento para apontar o livro mais antigo por data de publicacao
void maisAntigo(Livro lista[MAX], int tam){
    int i, maior = lista[0].ano, indice=0;
    for(i=0; i<tam; i++){
        if(lista[i].ano < maior){
            maior = lista[i].ano; 
            indice = i; 
        }
    }
    printf("O livro %s é o mais antigo, tendo sido publicado em: %d", lista[indice].titulo, lista[indice].ano); 
}


int main(){
    Livro livros[MAX], livroBusca, disponiveis[MAX];
    int i, n, nDisponivel=0; 
    printf("Digite quantos livros quer adicionar na lista:");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){ //Preenche o vetor de livros com livros 
        getchar(); //Serve para limpar o buffer e permitir a leitura da string, pois o fgets le ENTER como um caracter
        fgets(livros[i].titulo, 50, stdin); //Nao usa o & porque string é um vetor
        fgets(livros[i].autor, 50, stdin);
        scanf("%d", &livros[i].ano); 
        scanf("%d", &livros[i].emprestado); 
        
    }
    buscarLivro(livros, n);
    nDisponivel=listarDisponiveis(livros, n, disponiveis);
    for(i=0; i<nDisponivel; i++){
        printf("\n%s está disponível", disponiveis[i].titulo); 
    }
    emprestimo(livros, n); 
    devolucao(livros, n); 
    maisAntigo(livros, n); 
    return 0; 
}