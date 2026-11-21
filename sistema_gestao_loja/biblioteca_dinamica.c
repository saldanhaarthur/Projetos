#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char produto;
    double preco;
    int quantidade;
    char ID;

}Testoque;


void adicionar_produto(int quant_prod);
int editar_produto();
int remover_produto();
void catalogo_completo();




int main(){
    int opcao;
    int quant_prod;
    while (1){
        printf("\t\t-----GESTÃO DE PRODUTOS-----\n");
        printf("Escolha qual das opções abaixo deseja realizar no momento:\n");
        printf("1.Adicionar Produtos\n2.Editar Produto\n3.Remover Produto\n4.Acessar Cátalogo de Produtos\n5.Sair\n Digite o número da opção: ");
        scanf("%d", &opcao);

        if(opcao == 5){
            break;
        }else if(opcao == 1){
            printf("Digite a quantidade de números que deseja digitar: ");
            scanf("%d", &quant_prod);
            adicionar_produto(quant_prod);
        }else if(opcao == 2){
            
        }else if(opcao == 3){
            
        }else if(opcao == 4){
            
        }else{
            printf("Escolha um número válido !!\n");
        }
        
    }
    
}