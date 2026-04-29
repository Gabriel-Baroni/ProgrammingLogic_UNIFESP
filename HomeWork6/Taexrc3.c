/*Um número natural é triangular se ele é produto de três nuúmeros naturais consecutivos
(por exemplo, 120 é triangular, pois 4 × 5 × 6 = 120. Escreva um programa que leia
um número inteiro e imprima “sim” caso esse número seja triangular ou “nao” caso
contrário*/

#include <stdio.h>

int main(){
    int num, i, x, z;
    int boolean = 0; // Variável booleana
    scanf("%d", &num);
    for(i=1, x=2, z=3; z<num; i++, x++, z++){
        if(i*x*z == num){
            boolean = 1; 
            break;
        } else {
            boolean = 0; 
        }
    }
    if(boolean == 1){
        printf("sim");
    } else {
        printf("nao");
    }
    return 0; 


}