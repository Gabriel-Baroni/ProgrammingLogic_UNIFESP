#include <stdio.h>
void pesoIdeal (double h, char sexo, double *p){
    if(sexo == 'M'){
        *p= 72.7 * h - 58; 
    } else {
        *p= 62.1 * h - 44.7; 
    }
}

int main (){
    char sexo;
    double h, peso=0.0; 
    scanf("%c", &sexo);
    scanf("%lf", &h);
    pesoIdeal(h, sexo, &peso);
    printf("o peso ideal %lf", peso);
}