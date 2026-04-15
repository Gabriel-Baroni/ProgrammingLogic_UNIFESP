#include <stdio.h>
int main(){
    int n, fatorial, i;
    printf("Digite um número para calcular seu fatorial: ");
    scanf("%d", &n);
    fatorial = 1;
    for (i=2; i<=n; i++){
        fatorial *= i;
    }
    printf("O fatorial é %d", fatorial);
    return 0;
}