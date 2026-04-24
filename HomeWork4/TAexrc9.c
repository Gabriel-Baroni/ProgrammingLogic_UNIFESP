/*Escreva um programa que leia um número inteiro de 3 díıgitos que representa o número
de uma conta corrente e imprima seu o dígito verificador, o qual é calculado da seguinte
forma:
– Número: 235
– Somar o número da conta com seu inverso: 235 + 532 = 767
– Multiplicar cada dígito pela sua ordem posicional e somar esses resultados: 7*1 +
6*2 + 7* 3 = 40
– O último dígito desse resultado é o dígito verificador da conta: 0*/

/* O código está MEDONHO, mas eu fiz sozinho, tem com otimizar muito...*/
#include <stdio.h>

int main (){
    int num, alg1, alg2, alg3, alg4, inverso, soma, i;
    scanf("%d", &num);
    alg1 = num/100;
    alg2 = (num/10) %10;
    alg3 = num %10;
    inverso = (alg3*100) + (alg2*10) + alg1;
    soma = num + inverso;
    if (soma/1000 != 0){
        alg1 = soma/1000;
        alg2 = (soma/100) %10;
        alg3 = (soma/10) %10;
        alg4 = soma %10;
        num = (alg1 *1) + (alg2 *2) + (alg3 *3) + (alg4 *4);
    } else{
        alg1 = soma/100;
        alg2 = (soma/10) %10;
        alg3 = soma %10;
        num = (alg1 *1) + (alg2 *2) + (alg3 *3);
    }
    num %= 10;
    printf("%d", num);
    return 0;
}