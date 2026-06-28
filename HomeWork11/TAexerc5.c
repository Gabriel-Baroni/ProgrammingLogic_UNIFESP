#include <stdio.h>
#define MAX 10000



int main(){
    int M, N, i, medalhas[MAX];
    scanf("%d %d", &M, &N); 
    for(i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &medalhas[j]); 
        }
    }
}