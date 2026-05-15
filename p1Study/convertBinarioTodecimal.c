#include <stdio.h>
#include <math.h>
#define MAX 100
int main(){
    int binario[MAX], bit=0, c=0, i, soma=0, j=0;
    while(bit != 2){
        scanf("%d", &bit);
        if(bit != 2){
            binario[c] = bit;
            c++;
        }
    }
    j=c-1;
    for(i=0; i<c; i++){
        if(binario[i] == 1){
            soma+= 1 * pow(2, j);
        }
        j--;
    }
    printf("%d", soma); 
    return 0; 
}