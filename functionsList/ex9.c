#include <stdio.h>

void diagonal(int matriz[4][4]){
    int i, j; 
    int eDiagonal = 1; //boolean
    for(i=0; i<4; i++){
        for(j=i+1; j<4; j++){
            if(matriz[i][j] !=0 && i!=j){
                eDiagonal = 0;
            }
        }
    }
    if(eDiagonal){
        printf("A matriz é diagonal");
    } else{
        printf("A matriz não é diagonal"); 
    }
}

void simetrica(int matriz[4][4]){
    int i, j;
    int eSimetrica=1; //boolean
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(matriz[i][j] != matriz[j][i]){
                eSimetrica = 0; 
            }
        }
    }
    if(eSimetrica){
        printf("A matriz é simetrica");
    } else {
        printf("A matriz nao é simetrica"); 
    }
}

void triangularSuperior (int matriz[4][4]){
    int i, j;
    int eTS =1; //BOOLEAN
    for(i=1; i<4; i++){
        for(j=0; j<i; j++){
            if(matriz[i][j]!=0){
                eTS=0;
            }
        }
    }
    if(eTS){
        printf("A matriz e triangular superior");
    } else {
        printf("A matriz não é triangular superior"); 
    }
}

void triangularInferior(int matriz[4][4]){
    int i, j;
    int eTI =1; //BOOLEAN
    for(i=0; i<4; i++){
        for(j=i+1; j<4; j++){
            if(matriz[i][j]!=0){
                eTI=0;
            }
        }
    }
    if(eTI){
        printf("A matriz e triangular inferior");
    } else {
        printf("A matriz não é triangular superior"); 
    }
}

int main(){
    int matriz[4][4], i, j; 
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%d", &matriz[i][j]); 
        }
    }
    //Chamada dos procedimentos
    diagonal(matriz); 
    simetrica(matriz);
    triangularSuperior(matriz);
    triangularInferior(matriz);
    return 0; 
}

