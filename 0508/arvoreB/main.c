#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    lista *lista=NULL;
    lista = cria_lista();
    int op,valor;
    do{
    system("cls");
    printf("1-insere inicio\n2-insere fim\n3-insere ordenado\n4-remove inicio\n5-remove fim\n6-quebrar metade\n7-altura\nopcao: ");
    scanf("%d",&op);
    switch(op){
    case 1:{
        printf("Digite o valor: ");
        scanf("%d",&valor);
        insere_inicio(lista,valor);
    }break;
    case 2:
        printf("Digite o valor: ");
        scanf("%d",&valor);
       //insere_fim(lista,valor);
        break;
    case 3:
        printf("Digite o valor: ");
        scanf("%d",&valor);
        insere_ordenado(lista,valor);
        break;
    case 4:
        printf(" Removendo inicio... ");
        break;
    case 5:{
        printf(" Removendo fim... ");
    }break;
    case 6:
    {
        mostrar_lista_of(lista);

    }
        break;
    case 7:
        {
        mostrar_lista_op(lista);
    }
        break;
    }
    printf("\n");
    system("pause");
    }while(op!=0);
    return 0;
}
