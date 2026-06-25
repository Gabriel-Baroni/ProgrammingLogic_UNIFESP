// Considere uma matriz 5 × 5 contendo 0 para caminho livre e 1 para obstáculo.
// Escreva uma função recursiva que determine se existe um caminho da posição (0, 0) até (4, 4).
// Movimentos permitidos: direita e baixo.
#include <stdio.h>
int existeCaminho (int lab [5][5], int i, int j){
    int temCaminho=0; 
    if(i>4 || j>4 ||lab[i][j] == 1 ){ //Valida se a coordenada esta dentro dos limites da matriz e se a posicao testada e igual a 1
        return 0; 
    }

    if(j==4 && i==4){ // Se chegou na posicao (4,4) significa que tem caminho
        return 1; 

    } else{
        if(existeCaminho(lab, i, j+1)==1){ //Tenta ir para a direita, se o return for 1, tambem retorna 1 
            return 1; 
        } else if(existeCaminho(lab, i+1, j)==1){// Tenta ir para a baixo, se o return for 1, tambem retorna 1 
            return 1; 
        } else{
            return 0; //Se não deu para ir para direita nem baixo, retorna 0 
        }
       

    }

}

int main(){
    int lab[5][5], i, j;
    for(i=0; i<5; i++){ //Preenchendo a matriz 
        for(j=0; j<5; j++){
            scanf("%d", &lab[i][j]); 
        }
    }
    if(existeCaminho(lab, 0, 0) == 1){ // Chamando a funcao
        printf("existe caminho"); 
    } else {
        printf("Não existe caminho"); 
    }
    return 0; 
}