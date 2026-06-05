#include <stdio.h>
#define MAX 100
void uniao(int M, int N, int vetM[MAX], int vetN[MAX], int *P, int *c){
    int i, j;
    int jatem = 0; //Boolean

    for(i=0; i<M; i++){ 
         for(j=0; j<*P; j++){ //Verfica se no proprio vetM ja tem elementos repetidos
            if(vetM[i] == c[j]){
                jatem = 1; 
            }
        }
        if(jatem ==0){
            c[*P] = vetM[i];
            *P+=1; 
        }
        jatem =0; 
    }
    for(i=0; i<N; i++){ //verifica os elementos repetidos entre o c e o vetN
        for(j=0; j<*P; j++){
            if(vetN[i] == c[j]){
                jatem = 1; 
            }
        }
        if(jatem ==0){
            c[*P] = vetN[i];
            *P+=1; 
        }
        jatem =0; 
    }

}

int main(){
    int M, N, soma=0, vetM[MAX], vetN[MAX], c[MAX], P=0, i;
    scanf("%d", &M);
    for(i=0; i<M; i++){
        scanf("%d", &vetM[i]);
    }
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &vetN[i]);
    }
    uniao(M, N, vetM, vetN, &P, c); 
    for(i=0; i<P; i++){ //Percorre o vetor c e soma os elementos
        soma+= c[i];
    }
    printf("%d", soma);
    return 0; 
}