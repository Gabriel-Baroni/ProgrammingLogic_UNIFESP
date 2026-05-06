#include <stdio.h>
#include <math.h>
#define MAX 65536
int main(){
    int N, sequencia[MAX][2], topo=1, i=0, j=0, m=0, k=0;
    scanf("%d", &N);
    //Vou inicializar com as frações 0/1 e 1/1
    sequencia[0][0] = 1;
    sequencia[0][1] = 1;
    sequencia[1][0] = 0;
    sequencia[1][1] = 1; 
    //Vou colocar a fração i+k/j+m quando der
    while(topo>=0){
        i= sequencia[topo][0];
        j = sequencia[topo][1]; 
        if( topo > 0){
            k= sequencia[topo-1][0];
            m = sequencia[topo-1][1];
            if(m+j <=N){
                topo++;
                sequencia[topo][0] = i;
                sequencia[topo][1] = j;
                sequencia[topo-1][0] = i+k;
                sequencia[topo-1][1] = j+m;
            } else {
            printf("%d/%d\n", i, j);
            topo--;
            }
        }else {
            printf("%d/%d\n", i, j);
            topo--;
        }
    }

}
