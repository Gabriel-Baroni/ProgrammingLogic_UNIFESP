// Implemente funções recursivas para calcular:
// a) Soma dos elementos;
// b) Maior elemento;
// c) Quantidade de números pares;
// d) Quantidade de ocorrências de um valor informado.

#include <stdio.h>
#define MAX 100
// a) Soma dos elementos;
int somaRec ( int v[MAX] , int n ){
    if(n==0){ //Condicao de parada da recursividade 
        return v[0]; //retorna o unico elemento do vetor
    } 
    return v[n] + somaRec(v, n-1); //Soma os returns de cada chamada da funcao
}

// b) Maior elemento;
int maiorRec ( int v [MAX] , int n ){
    if(n==0){ //Condicao de parada de recursividade
        return v[0]; //retorna o unico elemento do vetor
    } else {
        if(v[n] > maiorRec(v, n-1)){ //Se o elemento for maior que o resto do vetor
            return v[n]; //retorna ele
        } 
    }
}

// c) Quantidade de números pares;
int contaParesRec ( int v [MAX] , int n ){
    if(n==0){ //Condicao de parada da recursividade
        if(v[0]%2 == 0){ //Se o numero é par retorna 1
            return 1; 
        } else {
            return 0; //Se e impar retorna 0
        }
    }
    if(v[n]%2 == 0){
        return 1 + contaParesRec(v, n-1); //Se for par soma 1 aos outros returns 
    } else {
        return 0 + contaParesRec(v, n-1); //Se for impar soma 0 aos outros returns 
    }
}

// d) Quantidade de ocorrências de um valor informado.
int contaValorRec ( int v [MAX] , int n , int x ){
    if(n==0){ //Condicao de parada da recursividade
        if(v[0] == x){
            return 1; 
        } else {
            return 0; 
        }
    } else {
        if(v[n] == x){
            return 1 + contaValorRec(v, n-1, x);
        } else {
            return 0 + contaValorRec(v, n-1, x); 
        }
    }

}
int main(){
    int i, v[MAX], n, t;
    scanf("%d",&n);
    scanf("%d", &t); 
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    //Chama cada função e printa seus resultados
    printf("Funcao soma: %d\n", somaRec(v, n-1));
    printf("Funcao Maior: %d\n", maiorRec(v, n-1));
    printf("Funcao pares:  %d\n", contaParesRec(v, n-1));
    printf("Funcao quantidade de valor: %d\n", contaValorRec(v, n-1, t)); 
    return 0; 
}