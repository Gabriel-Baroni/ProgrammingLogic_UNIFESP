/*Escreva um programa utilizando a linguagem C para ler uma lista de 100 valores inteiros, armazená-los em um
vetor, calcular e mostrar a quantidade de números pares, a lista dos números pares, a quantidade de números 
ímpares e a lista dos números ímpares*/

#include <stdio.h>
#define MAX 100

int main()
{
    int NUM[MAX], IMPAR[MAX], PAR[MAX], qtaP, qtaI, i;
    qtaI=0;
    qtaP = 0;
    for (i=0; i < MAX; i++){
        printf("Digite um número: ");
        scanf("%d", &NUM[i]);
        if (NUM[i] % 2 != 0){
            IMPAR[qtaI] = NUM[i];
            qtaI ++;
        }
        else{
            PAR[qtaP] = NUM[i];
            qtaP ++;
        }
        
    }
    printf("Lista dos impares:\n");
    for (i=0; i < qtaI; i++){
        printf("%d\n", IMPAR[i]);
    }
    printf("Quantidae de Impares: ");
    printf("%d\n", qtaI);
    
    printf("Lista dos pares:\n");
    for (i=0; i < qtaP; i++){
        printf("%d\n", PAR[i]);
    }
    
    printf("Quantidade de pares: ");
    printf("%d\n", qtaP);
    
    return 0;
}