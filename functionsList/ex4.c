// Leia duas matrizes quadradas 3 × 3.
// Crie uma terceira matriz contendo o produto matricial:
// C = A × B

#include <stdio.h>

//Procedimento para ler matriz
void lerMatriz ( int m [3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d", &m[i][j]); 
        }
    }
}
//Procedimento para imprimir matriz
void imprimirMatriz ( int m [3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", m[i][j]); 
        }
    }

}
//Procedimento para multiplicar as matrizes
void multiplicarMatrizes (int A [3][3], int B [3][3], int C [3][3]){
    int i, j, k, soma=0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            C[i][j] = 0; // inicializa a matriz C com 0

            for(k=0; k<3; k++){
                C[i][j] += A[i][k] * B[k][j]; //Para cada elemento da linha de A multiplica com o elemento da coluna de B e atribui a um elemento de C
            }
        }
    }
    imprimirMatriz(C); 

}



int main(){
    int matrizA[3][3], matrizB[3][3], matrizC[3][3];
    //Chamada dos procedimentos
    lerMatriz(matrizA);
    lerMatriz(matrizB); 
    multiplicarMatrizes(matrizA, matrizB, matrizC); 
    return 0; 

}