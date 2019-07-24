#include "main.h"
//#include "fila.c"
//#include "biblio.c"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int main()
{
    //pt-br
    setlocale(LC_ALL, "Portuguese");
    //vars
    lista *l,*f,*p;
    //inicio
    l=cria_lista();
    f=cria_fila();
    p=cria_pilha();
    int escolha=1,valor;

// se a escolha for diferente de 5, ele continua... o que inicialmente é verdade
// pois escolha é igual a 1
    while (escolha!=0){
        printf("\n Revisão de Estrutura de Dados ");
        printf("\n\n ----------------------- ");
        printf("\n 1 - Lista ");
        printf("\n 2 - Fila");
        printf("\n 3 - Pilha ");
        printf("\n 0 - Fechar Programa ");
        printf("\n\n Escolha uma opcao: ");
        scanf("%d",&escolha);
        // estrutura switch
        switch (escolha){

        case 1:
        {
// a função clrscr(); é para limpar a tela
            system("cls");
            printf("\n\n Opcao escolhida: 1 ");
            while (escolha!=0){
                printf("\n Revisão de Estrutura de Dados ");
                printf("\n\n ----------------------- ");
                printf("\n 1 - Inserir Inicio ");
                printf("\n 2 - Inserir Fim");
                printf("\n 3 - Remover Inicio");
                printf("\n 4 - Remover Fim ");
                printf("\n 5 - Mostrar Lista ");
                printf("\n 0 - Voltar ");
                printf("\n\n Escolha uma opcao: ");
                scanf("%d",&escolha);
                    switch (escolha){
                        case 1:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 1 ");
                            printf("\n\n Digite um valor:  ");
                            scanf("%d",&valor);
                            break;
                        }
                        case 2:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 2 ");
                            printf("\n\n Digite um valor:  ");
                            scanf("%d",&valor);
                            break;
                        }
                        case 3:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 3 ");
                            printf("\n\n Removendo do inicio ");
                            break;
                        }
                        case 4:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 4 ");
                            printf("\n\n Removendo do inicio ");
                            break;
                        }
                        case 5:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 4 ");
                            printf("\n\n Removendo do inicio ");
                            break;
                        }
                    }
            break;
            }
        }
        case 2:
        {
            system("cls");
            printf("\n\n Opcao escolhida: 2 ");
            while (escolha!=0){
                printf("\n Revisão de Estrutura de Dados ");
                printf("\n\n ----------------------- ");
                printf("\n 1 - Inserir Fila ");
                printf("\n 2 - Remover Fila");
                printf("\n 3 - Mostrar Fila");
                printf("\n 0 - Voltar ");
                printf("\n\n Escolha uma opcao: ");
                scanf("%d",&escolha);
                    switch (escolha){
                        case 1:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 1 ");
                            printf("\n\n Digite um valor:  ");
                            scanf("%d",&valor);
                            break;
                        }
                        case 2:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 2 ");
                            printf("\n\n Digite um valor:  ");
                            scanf("%d",&valor);
                            break;
                        }
                        case 3:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 3 ");
                            printf("\n\n Removendo do inicio ");
                            break;
                        }
                        case 4:{
                            return;
                        }
                    }
            break;
            }
        }
        case 3:
        {
            system("cls");
            printf("\n\n Opcao escolhida: 3 ");
            while (escolha!=0){
                printf("\n Revisão de Estrutura de Dados ");
                printf("\n\n ----------------------- ");
                printf("\n 1 - Inserir Pilha ");
                printf("\n 2 - Remover Pilha");
                printf("\n 3 - Mostrar Pilha");
                printf("\n 0 - Voltar ");
                printf("\n\n Escolha uma opcao: ");
                scanf("%d",&escolha);
                    switch (escolha){
                        case 1:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 1 ");
                            printf("\n\n Digite um valor:  ");
                            scanf("%d",&valor);
                            break;
                        }
                        case 2:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 2 ");
                            printf("\n\n Digite um valor:  ");
                            scanf("%d",&valor);
                            break;
                        }
                        case 3:{
                            system("cls");
                            printf("\n\n Opcao escolhida: 3 ");
                            printf("\n\n Removendo do inicio ");
                            break;
                        }
                        case 4:{
                            system("cls");
                            return;
                        }
                    }
            break;
            }
        }
// opção padrão
        default:
        {
            system("cls");
// se for escolhida a opção 5, ele pula o while utilizando continue para isso
            if( escolha==0)
            {
                continue;
            }
// caso o usuário digite um numero acima de 5, ele irá informar que nao existe essa opção
            printf("\n\n Nenhuma opcao foi escolhida ");
            break;
        }
        }
    }
    if( escolha==0)
        printf("\n\n O Programa foi fechado! Até Logo...");
    getch();
    return 0;
}
