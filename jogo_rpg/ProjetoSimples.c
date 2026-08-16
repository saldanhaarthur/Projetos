#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Projeto: Sistema da Guilda de Aventureiros (RPG)
Objetivo: Guardar as informacoes pessoais de cada aventureiro e seus atributos
Dia: 15/08/2026
Autor: Arthur Rocha Saldanha
*/

//structs

typedef struct{
    int forca ;
    int destreza;
    int constituicao;
    int inteligencia;
    int sabedoria;
    int carisma;
}Tstatus;

typedef struct{
    Tstatus habilidades;
    char nome[60];
    char classe[60];
    char raca[60];
}Taventureiro;

//prototipos
Taventureiro criacao_personagem();
Taventureiro imprimir_aventureiro();


//main
int main(){
    int max=0;
    Taventureiro aventureiros[50];
    int i, quant=0, p;
    int pass=0;
    char nome[60];

    do{
        printf("\t\t-------GUILDA DE AVENTUREIROS-------\n\n");
        printf("Seja bem-vindo a guilda de aventureiros, selecione uma das opcoes abaixo!! \n\n");
        printf("\t1. Inscricao de aventureiro(s)\n\t2. verificacao de aventureiro\n\t3. Sair\n\n Digite o numero da opcao que deseja: ");
        scanf("%d", &p);
        getchar();
    
        //opcao para inscrever novos aventureiros
        if(p == 1){
            while(quant<0 || quant==0){
                printf("Quantos aventureiros deseja inscrever em nossa guilda, ja temos %d aventureiros inscritos em nossa guilda: ", pass);
                scanf("%d", &quant);
                getchar();
                if(quant < 0 || quant == 0 || quant > 50){
                    printf("Digite uma quantidade valida!!");
                }
            }
            pass=max;
            max+=quant;
            if(max <= 0){
                printf("O numero maximo de aventureiros ja foi atingido!!\n");
            }
            if(p == 1 ){
                for(i = pass; i < max; i++){
                    aventureiros[i] = criacao_personagem();
                }
    
            }
        }

        //opcao para procurar aventureiros ja existentes
        if(p == 2 ){
            if(max == 0){
                printf("Nao existe ainda nenhum registro de aventureiro na Guilda, faca registro de novos!!");
            }
            if(max > 0){
                printf("Digite o nome do Aventureiro que deseja encontrar: ");
                fgets(nome, 60, stdin);

                int encontrado=0;
                for(i= 0; i < max; i++){

                    //Caso tiver vai imprimir todas as informacoes
                    if(strcmp(aventureiros[i].nome, nome) == 0){
                        printf("\t\t------- INFORMACOES DE AVENTUREIRO -------\n\n");
                        printf("NOME: %s\n", aventureiros[i].nome);
                        printf("CLASSE: %s\n", aventureiros[i].classe);
                        printf("RACA: %s\n", aventureiros[i].raca);
                        printf("\t\t------- STATUS -------\n\n");
                        printf("FORCA: %d\n", aventureiros[i].habilidades.forca);
                        printf("DESTREZA: %d\n", aventureiros[i].habilidades.destreza);
                        printf("CONSTITUICAO: %d\n", aventureiros[i].habilidades.constituicao);
                        printf("INTELIGENCIA: %d\n", aventureiros[i].habilidades.inteligencia);
                        printf("SABEDORIA: %d\n", aventureiros[i].habilidades.sabedoria);
                        printf("CARISMA: %d\n", aventureiros[i].habilidades.carisma);
                        encontrado=1;
                        break;
                    }
                    if(encontrado == 0){
                        printf("Nao existe nenhum aventureiro com esse nome!!");
                    }

                }
            }
        }
    }while(p != 3);//termina todo o programa assim que o usario apertar o 3

    return 0;

}


//funcao criacao do personagem
Taventureiro criacao_personagem(){
    Taventureiro aventureiros;
    int c, r, s, d;
    int i=7;

    //Zerando status para evitar lixo de memoria
    aventureiros.habilidades.forca = 0;
    aventureiros.habilidades.destreza = 0;
    aventureiros.habilidades.constituicao = 0;
    aventureiros.habilidades.inteligencia = 0;
    aventureiros.habilidades.sabedoria = 0;
    aventureiros.habilidades.carisma = 0;

    
    //informacoes basicas
    printf("Digite o nome: ");
    fgets(aventureiros.nome, 60, stdin);

    //selecao das classes
    do{
        printf("\t\t-----CLASSES-----\n\n");
        printf("\n 1. Guerreiro\n 2. Bandido\n 3. Mago\n 4.Clerigo\n Digite o numero correspondente a classe que deseja: ");
        scanf("%d", &c);
        getchar();
    }while(c<1 || c>4);


    //strcpy(aventureiros.classe, 'Guerreiro');
    if(c==1){
        strcpy(aventureiros.classe, "Guerreiro");
    }
    if(c==2){
        strcpy(aventureiros.classe, "Bandido");
    }
    if(c==3){
        strcpy(aventureiros.classe, "Mago");
    }
    if(c==4){
        strcpy(aventureiros.classe, "Clerigo");
    }
    
    //selecao de raca
    do{
        printf("\t\t-----RACAS-----\n\n");
        printf("\n 1. Humanos\n 2. Anoes\n 3. Elfos\n 4. Gigantes\n 5. Goblins\n Digite o numero correspondente a raca que deseja:");
        scanf("%d", &r);
        getchar();
    }while(r<1 || r>5);

    if(r==1){
        strcpy(aventureiros.raca, "Humano");
    }
    if(r==2){
         strcpy(aventureiros.raca, "Anao");
    }
    if(r==3){
         strcpy(aventureiros.raca, "Elfos");
    }
    if(r==4){
         strcpy(aventureiros.raca, "Gigante");
    }
    if(r==5){
         strcpy(aventureiros.raca, "Goblin");
    }

    //Distribuicao de Status

    
    printf("\t\t-----DISTRIBUICAO DE STATUS-----\n\n");
    do{
        printf("Voce possui %d para serem distribuidos nos Status abaixo: \n", i);
        printf("\n 1. Forca(STR)\n 2. Destreza(DEX)\n 3. Constituicao(CON)\n 4. Inteligencia(INT)\n 5. Sabedoria\n 6. Carisma(CHA)\n Digite o numero que deseja correspondente ao status que deseja aumentar: ");
        scanf("%d", &s);
        getchar();
        do {
            printf("Quantos pontos deseja colocar nesse Status (Max: %d): ", i);
            scanf("%d", &d);
    
            if(d < 0 || d > i) {
            printf("Você não possui pontos suficientes ou digitou um valor inválido!!\n");
            }

        } while(d < 0 || d > i);

        if(s==1){
            aventureiros.habilidades.forca = d;
        }
        if(s==2){
            aventureiros.habilidades.destreza = d;
        }
        if(s==3){
            aventureiros.habilidades.constituicao = d;
        }
        if(s==4){
            aventureiros.habilidades.inteligencia = d;
        }
        if(s==5){
            aventureiros.habilidades.sabedoria = d;
        }
        if(s==6){
            aventureiros.habilidades.carisma = d;
        }
        i-=d;

    }while(i!=0 );
    return aventureiros;
}
