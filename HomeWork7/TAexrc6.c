/*
 * ENUNCIADO:
 * Escreva um programa que leia um número inteiro N (1 <= N <= 100) indicando o tamanho 
 * de uma sequência e, em seguida, leia e armazene duas sequências de N números 
 * inteiros entre 0 e 9, interpretadas como dois números inteiros de N algarismos 
 * e calcule a sequência de números que representa a soma desses dois inteiros.
 */

#include <stdio.h>
#define MAX 100
int main(){
    int N, seq1[MAX], seq2[MAX], res[MAX], n, i, aux=0, c=0, j;
    scanf("%d", &N);
    for (i=0; i<N; i++){
        scanf("%d", &n);
        seq1[i] = n; 
    }
    for (i=0; i<N; i++){
        scanf("%d", &n);
        seq2[i] = n; 
    }
    for (i=N-1; i>=0; i--){
        if((seq1[i] + seq2[i])>=10 && aux !=1){
            aux = 1; 
            res[i] = (seq1[i] + seq2[i])%10; 
            c+=1;
        } else if (((seq1[i] + seq2[i])>=9 && aux == 1)){
            res[i] = ((seq1[i] + seq2[i])+1)%10;
            aux = 1; 
            c+=1;
        } else if((seq1[i] + seq2[i])<10 && aux ==1){
            res[i] =(seq1[i] + seq2[i]) +1;
            aux = 0;
            c+=1;
        }
        else{
            aux=0;
             res[i] =  seq1[i] + seq2[i];
             c+=1;
        }
        if(i == 0 && ((seq1[i] + seq2[i])>=10 || aux == 1)){
            c++; 
            for (j = c - 1; j > 0; j--) {
                res[j] = res[j - 1]; 
            }
            res[0] = 1;
        }
    }
    for (i=0; i<c; i++){
        printf("%d ", res[i]);
    }
    return 0;
}