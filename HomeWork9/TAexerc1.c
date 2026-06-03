#include <stdio.h>
int primo (int num){
    int i=0;
    int primo = 1;
    for(i=2; i<num; i++){
        if(num%i == 0 ){
            primo = 0;
        }    
    }
    return primo;
}
int main(){
    int n;
    scanf("%d", &n);
    if(primo(n) == 1){
        printf("sim");
    }else{
        printf("nao");
    }
}