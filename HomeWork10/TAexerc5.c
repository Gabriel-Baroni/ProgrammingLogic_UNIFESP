#include <stdio.h>
void LeABC ( int *a, int *b, int *c ){
    scanf("%d %d %d", a, b, c); //Leitura das variaveis
}

void Calcula_XY ( int b, int c, int *x, int *y ){
    *x = b + 1; //Atribui ao conteudo do endereco de memoria apontado por x o valor b + 1
    *y = c + 1; //Atribui ao conteudo do endereco de memoria apontado por y o valor c + 1
    int mdc =0 , num1 =*x, num2=*y, resto;

    while(mdc!=1){ //Procura o numero que tem o mdc entre ele e *x igual a 1
        num1 = *x; 
        num2= *y; 
        while( num2 != 0){
            resto =  num1%num2; 
            num1 = num2;
            num2 = resto; 
        }

        mdc = num1; 
        if(mdc!=1){ //Se o mdc nao for 1, passa para o proximo número
            (*y)++; 
        }
    }
}

void Calcula_QR ( int a, int b, int *q, int *r ){
    if(a>b){ //Se a > b aplica regra do item d
        *q = a/b;
        *r = 1 + (a%b);
    } else if (a < b){ //Se a < b, aplica regra do item e
        *q = b/a;
        *r = 1 + (b%a); 
    } else { //Se a = b, aplica regra do item f
        *q = 20 * a;
        *r = 5;
    }
}
int Calcula_Z ( int q, int r ){
    int minimo, z;
    int ePrimo = 1; 
    if( q > r){ //Averigua qual dos dois e o menor
        minimo = r;
    } else {
        minimo = q; 
    }
    for(int i=minimo; i>=2; i--){ //Testa, a partir do proprio minimo até 2, qual é o primeiro primo que aparece
        for(int j=2; j<i; j++){ //Laco para validar se o numero e primo
            if(i%j == 0){
                ePrimo = 0; 
            }
        }
        if(ePrimo){
            z = i; 
            return z; //Se o numero i for primo, a funcao retorna ele (z) e acaba
        } else {
            ePrimo = 1; 
        }
    }
    return 1; //Evita que a funcao fique sem retornar nada se o numero for menor que 2

}
int Calcula_P ( int x, int y, int z ){
    int p;
    p = x + (z-1) * y; //Formula da PA com os valores fornecidos
    return p; //Retorna p
}

int Calcula_S ( int m, int p, int q, int r, int x, int y ){
    int s, max, min;

    if( x > y){ //Verfica o maior entre eles
        max =x;
    } else {
        max =y;
    }

    if(q < r){ //Verifica o menor entre eles
        min = q;
    } else {
        min = r;
    }

    s = ((m*p)/max) + min; //Calcula s com a formula dada

    return s; 
}

int main(){
    int m, a, b, c, x, y, q, r, z, p, s; 
    scanf("%d", &m);
    //Chamada dos valores
    LeABC(&a, &b, &c); 
    Calcula_XY(b, c, &x, &y);
    Calcula_QR(a, b, &q, &r); 
    z = Calcula_Z(q, r);
    p = Calcula_P(x, y, z);
    s = Calcula_S(m, p, q, r, x, y);
    printf("%d\n", s); 
    
    return 0; 
}