#include <stdio.h>
double pesoIdeal (double h, char sexo){
    double peso = 0.0; 
    if(sexo == 'M'){
        peso = 72.7 * h - 58; 
    } else {
        peso = 62.1 * h - 44.7; 
    }
    return (peso);
}

int main (){
    char sexo;
    double h; 
    scanf("%c", &sexo);
    scanf("%lf", &h);
    printf("o peso ideal %lf:", pesoIdeal(h, sexo));
}