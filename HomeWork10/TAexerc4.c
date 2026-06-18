#include <stdio.h>
#define MAX 100
void interseccao (int M, int A[MAX], int N, int B[MAX], int *P, int *C){
    int i, j;
    int jatem = 0, nosDois=0; //boolean
    for(i=0; i<M; i++){ 
        for(j=0; j<*P; j++){ //Esse laco serve para verificar se o elemento i do vetor A ja foi adicionado no C
            if(A[i] == C[j]){
                jatem = 1; 
            }
        }
        for(j=0; j<N; j++){ //Esse laco verifica se o elemento i do vetor A existe no vetor B
            if(A[i] == B[j]){
                nosDois = 1; 
            }
        }
        if(jatem==0 && nosDois==1){ //Se o elemento ainda nao esta no C e possui no A e no B, adiciona no C
            *(C+*P) = A[i];
            //C[*P]=A[i];
            *P+=1; 
        }
        jatem=0; 
        nosDois = 0; 


    }
}

int main(){
    int M, A[MAX], N, B[MAX], soma=0, i, C[MAX], P=0; 
    scanf("%d", &M);
    for(i=0; i<M; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &B[i]);
    }
    interseccao(M, A, N, B, &P, C);
    for(i=0; i<P; i++){
        soma+= C[i]; 
    }
    printf("%d", soma); 
    return 0; 
}