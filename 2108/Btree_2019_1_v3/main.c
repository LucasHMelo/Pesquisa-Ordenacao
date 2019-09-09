#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "ArvoreB.h"
#include <locale.h>
#include <conio.h>

int main()
{
    arv* tr = cria_arvore(3);
    setlocale(LC_ALL, "Portuguese");
    int escolha;

    while (escolha!=0){
        printf("\n B-TREE");
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
                insere_chave_arvore(tr, valor);
               // printf("%d",tr->raiz->listaChaves->inicio->valor);
                break;

        }
        case 2:
            {
            system("cls");
            percursoEmOrdem(tr->raiz);
            printf("\n\n\n");
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
