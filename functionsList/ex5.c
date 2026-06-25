// Implemente uma função que realize a transposição de uma matriz quadrada 4 × 4 sem utilizar
// matriz auxiliar.
#include <stdio.h>
void transpor ( int m [4][4]){ //Passar a matriz como parametro é o mesmo que passar um ponterio, ou seja, nao preciso de uma mariz auxiliar
    int i, j, aux=0; //Declaracao de variavel auxiliar para servir como memoria temporaria
    for(i=0; i<4; i++){
        for(j=i+1; j<4; j++){ //j inicia com i+1, para conseguir trocar de lugar com o elemento da linha com o uso de uma variável auxiliar 
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
           
        }
    }
    for(i=0; i<4; i++){ //Percorro os dados com a ordem correta de linha e coluna para mostrar que realmente fiz a transposta 
        printf("\n");
        for(j=0; j<4; j++){
            printf("%d ", m[i][j]); 
           
        }
    }
}

int main(){
    int m[4][4], i, j;
    for(i=0;i<4; i++){
        for(j=0; j<4; j++){
            scanf("%d", &m[i][j]); //Preenche a matriz
        }
    }
    transpor(m); //Chamada do procedimento
    return 0; 
}