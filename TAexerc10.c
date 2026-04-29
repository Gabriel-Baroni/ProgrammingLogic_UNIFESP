/*Escreva um programa que leia a quantidade de fitas que uma locadora de vídeo possui
e o valor que ela cobra por cada aluguel, e mostre as informações pedidas a seguir:
– Sabendo que um terço das fitas são alugadas por mês, exiba o faturamento da
locadora;
– Quando o cliente atrasa a entrega, é cobrada uma multa de 10% sobre o valor do
aluguel. Sabendo que um décimo das fitas alugadas no mês são devolvidas com
atraso, calcule o valor ganho com multas por mês;
– Sabendo ainda que 2% das fitas se estragam ao longo do ano, e um décimo desse
total é comprado para reposição, exiba a quantidade de fitas que a locadora terá no
final do ano.*/

#include <stdio.h>  
 
int main(){
    int Nfitas;
    double valorFita;
    scanf("%d %lf", &Nfitas, &valorFita);
    // Faturamento da locadora
    printf("%lf\n", (Nfitas/3) * valorFita);
    // Valor ganho com multas por mês
    printf("%lf\n", ((Nfitas/3)/10.0) * (valorFita*0.1));
    // Quantidades de fitas no final do ano
    Nfitas -= (Nfitas*0.02) - (Nfitas*0.02)/10;
    printf("%d\n", Nfitas); 
    return 0;
}