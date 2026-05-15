#include <stdio.h>

int fatorial(int num){
    int fatorial=1, i;
    for (i=2; i<= num; i++){
        fatorial *= i ;
    }
    return (fatorial);
    
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fatorial(n));

    return 0;
}