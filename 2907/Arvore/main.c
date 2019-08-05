#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#include <locale.h>
#include <conio.h>

int main()
{
    no *raiz;
    raiz = NULL;
    setlocale(LC_ALL, "Portuguese");
    int escolha;

    while (escolha!=0){
        printf("\n Revisão de Estrutura de Dados - Arvores");
        printf("\n\n ----------------------- ");
        printf("\n 1 - Inserir Arvore ");
        printf("\n 2 - Mostrar Arvore ");
        printf("\n 0 - Fechar Programa ");
        printf("\n\n Escolha uma opcao: ");
        scanf("%d",&escolha);
        // estrutura switch
        switch (escolha){

        case 1:
        {
                system("cls");
                int valor;
                printf("Digite um numero: ");
                scanf("%d",&valor);
                raiz = inserir_arvore(raiz,valor);
                break;

        }
        case 2:
            {
                system("cls");
            em_ordem(raiz);
            printf("%\n\n\n");
            system("pause");
                break;
            }
        default:
        {
            system("cls");
            if( escolha==0)
            {
                continue;
            }
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
