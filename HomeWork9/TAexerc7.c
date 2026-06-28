#include <stdio.h>
// Retorna a quantidade ideal de materia prima a ser adquirida.
// Os parametros a serem informados s~ao a capacidade maxima de
// armazenamento do balcao, a quantidade atual de
// materia-prima do balcao e a quantidade atual de produtos no
// galpao.
int CompraMateriaPrima( int balcao, int mat_prima, int produtos ){
    int compra = balcao - (mat_prima + produtos); //o que deve ser comprado e a capacidade do balcao - a quantidade de produto mais materia prima
    if(compra <= 0){
        return 0;
    } else {
        return compra; 
    }
};


// Retorna a quantidade de produtos produzidos durante a semana.
// Os parametros a serem informados s~ao a capacidade maxima de
// armazenamento do galpao, a quantidade atual de
// materia-prima do balcao e a quantidade atual de produtos no
// galpao e a producao maxima do maquinario.
int ProducaoSemanal( int galpao, int mat_prima, int produtos, int producao ){
    int espacoGalpao = galpao - produtos; 
    int limite = producao; //Começamos assumindo que a capacidade de produzir do maquinario e o limitante
    if(limite > mat_prima){ //Se tiver menos materia prima do que a maquina consegue produzir, materia prima é o limite
        limite = mat_prima; 
    }
    if(limite > espacoGalpao){ //Se tiver menos espaço no galpao do que o que conseguimos produzir, o espaco no galpao e o limite
        limite = espacoGalpao; 
    }
    return limite; 
}


// Imprime o relatorio de producao da industria.
// Os parametros a serem informados s~ao a semana analisada, a
// quantidade atual de materia-prima do balcao e a quantidade atual de
// produtos no galpao, a producao da semana, o total comprado, o total
// vendido e os pedidos pendentes para a pr´oxima semana.
void ImprimeRelatorio( int semana, int mat_prima, int produtos, int producao, int comprado, int vendido, int pendentes){
    printf("Semana %d:\n", semana); 
    printf("Estoque do balcao: %d\n", mat_prima);
    printf("Estoque do galpao: %d\n", produtos);
    printf("Producao da semana: %d\n", producao);
    printf("Compras da semana: %d\n", comprado);
    printf("Vendas da semana: %d\n", vendido);
    printf("Pedidos pendentes: %d\n", pendentes);
      
}

int main(){
    int semana, cap_matPrima, cap_Produto, producao, matPrima_ini, produtos_ini, pendentes;  
    int pedido_venda=0, comprado=0, produzido=0, demanda=0, vendido=0; 
    scanf("%d %d %d %d %d %d %d", &semana, &cap_matPrima, & cap_Produto, &producao, &matPrima_ini, &produtos_ini, &pendentes);

    for(int i = 1; i<=semana; i++){
        scanf("%d", &pedido_venda); 
        comprado = CompraMateriaPrima(cap_matPrima, matPrima_ini, produtos_ini); //Chama a funcao para calcular a compra necessaria de materia prima
        matPrima_ini+=comprado; 

        produzido = ProducaoSemanal(cap_Produto, matPrima_ini, produtos_ini, producao); //Chama a funcao para mostrar o quanto sera produzido
        matPrima_ini -= produzido; //desconta da materia prima
        produtos_ini += produzido; //soma nos produtos

        demanda = pedido_venda + pendentes; //Demanda e o pedido da venda + as pendencias
        vendido = 0; 

        if(demanda <=produtos_ini){ //Se a demanda for menor ou igual a quantidade de produto
            vendido = demanda; //O que foi vendido sera a demanda
            produtos_ini -= vendido; //Subtrai dos produtos os vendidos
            pendentes = 0; // e pendentes fica zero
        } else { //Se a demanda for maior
            vendido = produtos_ini;//Vende todos os produtos
            produtos_ini = 0; 
            pendentes = demanda - vendido; //Os pendentes sera o que sobrou da demanda depois de vender todos os produtos
        }

        ImprimeRelatorio(i, matPrima_ini, produtos_ini, produzido, comprado, vendido, pendentes); //Chama o procedimento para imprimir o relatorio dessa semana
    }
    return 0; 
}