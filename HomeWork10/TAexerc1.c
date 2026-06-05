// Escreva um procedimento que receba como parˆametros um nu´mero inteiro N, um conjunto de N nu´meros inteiros e os endere¸cos de duas vari´aveis inteiras, por exemplo, min
// e max, e deposite nessas vari´aveis o valor do menor e do maior elemento desse conjunto,
// respectivamente. Escreva um programa que leia um nu´mero inteiro N (1 ≤ N ≤ 100)
// indicando o tamanho de um conjunto e, em seguida, leia e armazene um conjunto de N
// nu´meros inteiros e, utilizando esse procedimento, encontre e imprima o menor e o maior
// elemento desse conjunto, separando-os com um espa¸co em branco.

#include <stdio.h>
#define MAX 100
void menorMaior(int N, int vet[], int *min, int *max ){ //Recebe como parametro endereços de memoria, e um procedimento por referencia
    int i;
    *min=vet[0];
    *max=vet[0];
    for(i=1; i<N; i++){ 
        if(vet[i] < *min){ //Verifica o menor elemento
            *min = vet[i]; 
        }
        if(vet[i] > *max){ //Verifica o maior elemento 
            *max = vet[i];
        }
        
    }
}

int main(){
    int N, vet[MAX], i, maior=0, menor=0;
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &vet[i]);
    }
    menorMaior(N, vet, &menor, &maior); //Passa como parametro os edereços de memória das variaveis menor e maior
    printf("%d %d", menor, maior);
    return 0; 
}