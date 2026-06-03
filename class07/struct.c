#include <stdio.h>
#define MAX 100


struct TAluno {
    char Nome[60];
    int RA;
    double nota;
    double frequencia;
};

int main(){
    int opcao = 0;
    char resposta = 's';
    int total_alunos = 0; // Controla quantos alunos já foram cadastrados
    
    struct TAluno alunos[MAX]; // Cria o vetor de alunos

    while(resposta == 's' || resposta == 'S'){
        printf("\n----Menu de Escolha----\n");
        printf("1 - Inserir Aluno\n");
        printf("2 - Remover Aluno\n");
        printf("3 - Visualizar Alunos\n");
        printf("4 - Buscar Aluno(a) por RA\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao){    
            case 1: {
                int continuar = 1; //boolean
                // Loop para inserir enquanto o usuário quiser e houver espaço no vetor
                while(continuar == 1 && total_alunos < MAX){
                    // Pega o índice atual disponível
                    int i = total_alunos; 
                    
                    printf("\nDigite o nome do Aluno(a): ");
                    // o [^\n] permite ler nomes com espaço
                    scanf(" %[^\n]", alunos[i].Nome); 
                    
                    printf("Digite o RA do Aluno(a): ");
                    scanf("%d", &alunos[i].RA);
                    
                    printf("Digite a nota do Aluno(a): ");
                    scanf("%lf", &alunos[i].nota);
                    
                    printf("Digite a frequencia do Aluno(a): ");
                    scanf("%lf", &alunos[i].frequencia);
                    
                    total_alunos++; // Aumenta a contagem para o próximo aluno ir para a posição seguinte
                    
                    printf("\nDeseja inserir mais um aluno(a)? Digite 0 para NÃO e 1 para SIM: ");
                    scanf("%d", &continuar);
                }
                break;
            }
            case 2:
            int continuar = 1, encontrado=1;
            int  RA, i, j;
                while (continuar == 1){
                    printf("Digite o RA do aluno para ser removido");
                    scanf("%d", &RA);
                    for (i=0; i<total_alunos; i++){
                        if(alunos[i].RA = RA){
                            encontrado = 1;
                        }
                        for(j=i, j<total_alunos-1; j++){
                            alunos[j] = alunos[j+1];
                        }
                        total_alunos --; 
                    }
                    printf("aluno removido com sucesso! Deseja remover mais algum? Digite 0 para NÃO e 1 para SIM: ");
                    scanf("%d", &continuar);

                }
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }
        
        printf("\nDeseja voltar ao menu principal? Digite 's' para sim ou 'n' para sair: ");
        scanf(" %c", &resposta); 
    }
    
    printf("\nPrograma encerrado. Ate logo!\n");
    return 0;
}