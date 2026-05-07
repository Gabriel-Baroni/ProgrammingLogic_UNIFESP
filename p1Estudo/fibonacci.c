#include <stdio.h>
int main(){
    int f0=0, f1=1, fn, i, n;
    scanf("%d", &n);
    if(n == 0){
        printf("%d", n);
    } else if(n==1){
        printf("%d", n);
    } else {
        for (i=2; i<=n; i++){
            fn = f1 + f0;
            f0 = f1;
            f1= fn;
        }
        printf("%d", fn); 
    }
    return 0; 
    
}