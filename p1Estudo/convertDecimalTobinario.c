#include <stdio.h>
int main(){
    int num, binario[1000], i=0, k; 
    scanf("%d", &num);
    while(num/2 != 0){
        binario[i] = num%2;
        num /=2;
        i++;
    }
    binario[i] = 1;
    for(k=i; k>=0; k--){
        printf("%d", binario[k]);
    }
    return 0;
}