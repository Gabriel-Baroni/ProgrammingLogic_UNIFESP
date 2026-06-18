// Escreva uma função que receba um vetor de inteiros e remova todos os valores iguais a zero,
// compactando os demais elementos para o início do vetor.
// O tamanho lógico do vetor deve ser atualizado por referência.

#include <stdio.h>
#define MAX 100
void compactarVetor(int v[MAX], int *n){
    int i, posicaoNova=0;
    for(i=0; i<*n; i++){ //Percorre o vetor atual e atribui uma posição apenas se o elemento não for zero
        if(v[i] != 0){
            v[posicaoNova] = v[i];
            posicaoNova++;  
        }
    }
    *n = posicaoNova; 
}

int main(){
    int v[MAX], i, n=0; // Declaração de variáveis
    scanf("%d", &n);
    for(i=0; i<n; i++){ //Preenchimento do vetor
        scanf("%d", &v[i]); 
    }
    compactarVetor(v, &n); //Chama a função passando o vetor e o endereço de memoria da variavel que guarda seu tamanho
    for(i=0; i<n; i++){ //Percorre o vetor, mostrando que seus elementos e indice foram alterados
        printf("%d", v[i]); 
    }
    printf("\n novo indice %d", n); 
    return 0; 
}