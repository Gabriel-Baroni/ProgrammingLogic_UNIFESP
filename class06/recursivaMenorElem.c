#include <stdio.h>
#define MAX 10

int menorValor(int vet[], int n){ // Função recursiva
    if(n==0){  //Caso simples, o vetor é de tamanho 1, retorna o próprio valor
        return(vet[n]); 
    }
    int menorResto = menorValor(vet, n-1); // o menor Resto pes o vetor de tamanho n-1
    if(vet[n] < menorResto){
        return vet[n];
    } else {
        return menorResto;
    }

}



int main(){
    int vetor[MAX], i, num;
    for (i=0; i<MAX; i++){ //Inicializo o vetor com valores
        printf("Digite um numero para compor o vetor: ");
        scanf("%d", &num);
        vetor[i] = num; 
    }
    printf("O menor valor e: %d", menorValor(vetor, i-1)); //Faço a chama da função recursiva


    return 0;
}