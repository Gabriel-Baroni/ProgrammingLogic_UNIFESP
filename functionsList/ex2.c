// Um vetor contém números inteiros em ordem crescente.
// Implemente uma função que insira um novo valor mantendo a ordenação do vetor.
#include <stdio.h>
#define MAX 100 
void inserirOrdenado (int v[MAX], int *n, int capacidade, int valor){
    int i;  
    if(*n+1 <= MAX){
        for(i=*n-1; i>=0 && v[i]>valor; i--){ //Verifica se o elemento é maior que o valor a ser inserido
            v[i+1] = v[i]; //Empurra o elemento um indice para cima
        }
        //Quando sai do laço, achamos um valor menor do que o quer ser inserido, ou seja, ele adiciona o valor no indice posteior 
        v[i+1] = valor; 
        *n = *n + 1;
    } else {
        printf("Vetor cheio"); //Se for maior que a capacidade pre definida, não deica inserir
    }

}
int main(){
    int v[MAX], n, i, valor;
    scanf("%d", &n);
    scanf("%d", &valor);
    for(i=0; i<n; i++){ //Preenche o vetor
        scanf("%d", &v[i]); 
    }
    inserirOrdenado(v, &n, MAX, valor); 
    for(i=0; i<n; i++){ //Percorre o vetor com o valor inserido
        printf("%d ", v[i]); 
    }
}