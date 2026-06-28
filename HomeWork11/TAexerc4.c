#include <stdio.h>
#include <string.h>

int palindrome (char cadeia [2000], int inicio, int fim){
   
    if(inicio >= fim){ //Se o inico e maio ou igual ao fim, os indices se curzaram e retorna 1
        return 1;
    }
   
    if(cadeia[inicio] != cadeia[fim]){ //Se a cadeia no indice inicio for diferente da cadeia no indice final retorna 0
        return 0; 
    }

    return palindrome(cadeia, inicio+1, fim-1);  //Chamada recursiva passando o indice inicio 1 para direita e o inidice fim um para esquerda
}

int main(){
    char cadeia[20001]; //Pega uma cadeia de caracteres de no maximo 2001 pore conta do \0
    int i, tamanho;
    scanf("%s", cadeia); 
    tamanho = strlen(cadeia); //Pega o tamanho da cadeia com a funcao strlen

    if(palindrome(cadeia, 0, tamanho -1) == 1){
        printf("sim"); 
    } else {
        printf("nao");
    }
    return 0; 
    
}