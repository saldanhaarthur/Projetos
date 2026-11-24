/*
Projeto: Sistema de gestão de lojas
Objetivo: Controlar catálogo de produto, registrar vendas e analisar o desempenho do negócio ao longo do tempo
Autor: Arthur Rocha Saldanha 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//criação de um novo tipo para o registro ou mudança de produto 
typedef struct{
    char nome[50];
    float preco;
    int quantidade;
    char ID[50];

}Testoque;

// Protótipos das funções
Testoque* adicionar_produto(Testoque *produto, int *total, int quant_prod);
Testoque* editar_produto();
Testoque* remover_produto();
void catalogo_produtos(Testoque *produto, int total);
void limpar_buffer(void);



//Função Main
int main(){
    int opcao = 0;
    int quant_prod;
    Testoque *produto= NULL;//Crio meu ponteiro já vazio para que eu possa manipular seus espaços depois com o realloc
    int total = 0;

    //Menu de escolha 
    while (1){
        printf("\t\t-----GESTÃO DE PRODUTOS-----\n");
        printf("Escolha qual das opções abaixo deseja realizar no momento:\n");
        printf("1.Adicionar Produtos\n2.Editar Produto\n3.Remover Produto\n4.Acessar Cátalogo de Produtos\n5.Sair\n Digite o número da opção: ");
        scanf("%d", &opcao);
        limpar_buffer();

        if(opcao == 5){
            free(produto);
            break;
            //quando digitado limpo a memória que foi utilizado e encerro meu programa 

        }else if(opcao == 1){
            printf("Digite a quantidade de produtos que deseja digitar: ");
            scanf("%d", &quant_prod);
            limpar_buffer();

            if (quant_prod > 0){
                produto = adicionar_produto(produto, &total, quant_prod); //passo o endereço de total já que e o que eu quero receber
                //faço o processo de adicionar mais um produto pela função e volto o valor 
            }else{
                printf("Digite uma quantidade válida! um número positivo maior que zero!\n");
            }
        }else if(opcao == 2){
            
        }else if(opcao == 3){
            
        }else if(opcao == 4){
            if (total > 0){
                catalogo_produtos(produto, total);
            }else{
                printf("O seu estoque de produtos ainda está vazio, por favor adicione algum produto primeiro se deseja acessar o catálogo!\n");
            }
        }else{
            printf("Escolha um número válido !!\n");
        }
    }
    return 0;
    
}

Testoque* adicionar_produto(Testoque *produto, int *total, int quant_prod){
    Testoque *temp = realloc(produto, (quant_prod + *total) * sizeof(Testoque)); //armazeno em uma variável temporária para verificar a memória

    if (temp == NULL){
        printf("Erro: memória insuficiente! não e possível adicionar mais produtos!\n");
        return produto;
        // se eu não tiver espaço suficiente, meu programa fala que não tem mais mémoria dispónivel e retorna o que já tinha antes para o menu sem fechar sozinho
    }else{
        produto = temp;
    }

    for(int i = *total; i < (quant_prod + *total); i++){

        printf("Digite o nome do produto: ");
        fgets(produto[i].nome, 50, stdin);//Ler o nome sem risco de estouro de buffer com o fgets
        produto[i].nome[strcspn(produto[i].nome, "\n")] = '\0'; //com essa função contamos quantos caracteres vamos ter até achar o \n e depois usamos isso para substituir pelo \0 que é o final da string
        limpar_buffer();

        printf("Digite a quantidade desse produto: ");
        scanf("%d", &produto[i].quantidade);//lendo a quantidade de produtos que vou ter em estoque
        limpar_buffer();

        printf("Digite o preço: ");
        scanf("%f", &produto[i].preco);// lendo o preço do produto, lembrando que e do tipo float em minha struct
        limpar_buffer();

        sprintf(produto[i].ID, "PROD-%03d", i); // gravo um texto formatado dentro da minha string, criando sempre um ID novo para cada um
        // o %03d preenche o inteiro com zeros a esquerda ate completer 3 casas

        printf("O ID do produto %s é: \n %s \n", produto[i].nome, produto[i].ID);
    }

    *total += quant_prod;
    return produto;
}

void catalogo_produtos(Testoque *produto, int total){
    int n = 0;
    char comp_prod[50];
    int verdade = 0;
    printf("\t-----Catálogo de Produtos-----\n\n");
    while(1){

        printf("1.Acessar Catálogo completo\n2.Busca por um produto\n3.qualquer número diferente\nEscolha a opção: ");
        scanf("%d", &n);
        limpar_buffer();

        if (n== 1){
            for(int i = 0; i < total; i++){
                printf("\t---Produto--- %d\n", i);
                printf("NOME: %s\n", produto[i].nome);
                printf("ID: %s\n", produto[i].ID);
                printf("PREÇO: %.2f\n", produto[i].preco);
                printf("QUANTIDADE EM ESTOQUE: %d\n\n", produto[i].quantidade);
            }
        }else if(n == 2){

            verdade = 0;
            printf("Digite o nome ou o ID do produto que está procurando: ");
            fgets(comp_prod, 50, stdin);
            comp_prod[strcspn(comp_prod, "\n")] = '\0';
            limpar_buffer();

            for (int i = 0; i < total; i++){
                if (strcmp(produto[i].nome, comp_prod) == 0 || strcmp(produto[i].ID, comp_prod) == 0){//faço a verificação de cada produto até achar 
                    printf("\t---Produto--- %d\n", i);
                    printf("NOME: %s\n", produto[i].nome);
                    printf("ID: %s\n", produto[i].ID);
                    printf("PREÇO: %.2f\n", produto[i].preco);
                    printf("QUANTIDADE EM ESTOQUE: %d\n\n", produto[i].quantidade);
                    verdade = 1;
                    break;
                }
            }
            if (verdade == 0){
                printf("O nome ou ID digitado está errado ou não pertence ao estoque!\n");
            }
        }else{
            break;
        }
    }
}

void limpar_buffer(void){
    int c; /*variável temporária para segurar um caractere por vez. Declarada como int pois o getchar() pode devolver
            um código especial de erro/fim chamado de EOF, que geralmente vale -1, e nem todo char consegue gardar inteiros
            negativos*/
            

    while((c = getchar()) != '\n' && c != EOF);
    /*Função criada para limpeza de buffer sem falhas, tirando um caractere da fila e colocando em c,
    assim descartando caractere até encontrar o \n ou o EOF(fim da entrada)*/
}