#include <stdio.h>
int main(){
    int num, i;
    int primo = 1; //Variável booleana
    scanf("%d", &num);
    for(i=2; i<num; i++){
        if(num%i == 0){
            primo = 0;
        }
    }
    if(primo==1){
        printf("Numero Primo");
    } else {
        printf("Nao e um numero primo");
    }
    return 0; 
}