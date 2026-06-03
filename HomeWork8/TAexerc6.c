#include <stdio.h>
#define MAX 100
int main(){
    int N, matriz[MAX][MAX], i, j, soma=0, aux=0;
    int equadrado = 1; //boolean
    scanf("%d", &N);
    //Preenchendo a matriz
    for(i=0; i<N; i++){ //Laco para as linhas
        for(j=0; j<N; j++ ){
            scanf("%d", &matriz[i][j]); //Laco para as colunas
        }
    }
    //verificando a soma das linhas
    for(i=0; i<N; i++){ 
        soma=0; 
        for(j=0; j<N; j++ ){
            soma+=matriz[i][j]; //Laco para as colunas
        }
        if(i==0){
            aux=soma;
            soma=0;
        } else{
            if(soma != aux){
                equadrado=0;
            } else{
                aux=soma;
                soma=0;
            }
        } 
        
    }

    //verificando a soma das colunas
    for(i=0; i<N; i++){ 
        soma=0;
        for(j=0; j<N; j++ ){
            soma+=matriz[j][i]; //Laco para as linhas
        }
        if(soma != aux){
            equadrado = 0; 
        }
    }

    //Verficando a diagonal principal
    soma=0;
    for(i=0; i<N; i++){
        soma+= matriz[i][i];
    }
    if(soma != aux){
        equadrado = 0; 
    }

    //Verificando diagonal secundaria
    soma=0;
    for(i=N-1; i>=0; i--){
        soma += matriz[i][i];
    }
    if(soma != aux){
        equadrado = 0; 
    }

    if(equadrado == 1){
        printf("%d", aux);
    } else{
        printf("%d", 0);
    }
    return 0; 
}