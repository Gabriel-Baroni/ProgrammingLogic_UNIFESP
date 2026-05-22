#include <stdio.h> 
# define MAX 10

int somarValores (int vet[], int tam){
    if(tam == 0){
        return (vet[tam]);
    }
    else{
        return (vet[tam] + somarValores(vet, tam-1));
    }
}


int main(){
    int vetor[MAX], i, num;
    for (i=0; i<MAX; i++){ //Inicializo o vetor com valores
        printf("Digite um numero para compor o vetor: ");
        scanf("%d", &num);
        vetor[i] = num; 
    }
    printf("A soma dos elementos e: %d", somarValores(vetor, i-1)); //Faço a chama da função recursiva


    return 0;
}