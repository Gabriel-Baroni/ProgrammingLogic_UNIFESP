#include <stdio.h> 
#include <string.h>
#define MAX 100
int main (){
    char x[MAX], y[MAX];
    gets(x);
    gets(y);
    if(strcmp(x, y) == 0){
        printf("sim");
    } else {
        printf("nao\n");
        printf("%s",strcat(x,y));
    }
    return 0; 

}