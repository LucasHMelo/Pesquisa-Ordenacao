#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

lista* cria_lista(){
    lista *l;
    l=(lista*)malloc(sizeof(lista));
    l->inicio=NULL;
    l->fim=NULL;
    return l;
}

int lista_vazia(lista *l)
{
    if (l->inicio==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void insere_inicio(lista *l, int valor)
{
    no *novo;
    novo=(no*)malloc(sizeof(no));
    novo->valor=valor;
    novo->ant=novo->prox=NULL;
    novo->prox=l->inicio;
    if (l->fim == NULL)
    {
        l->fim=l->inicio;
    }
    else
    {
        l->inicio->ant = novo;
        l->inicio=novo;
    }
}

void insere_ordenado(lista *l, int valor)
{
   /* no *novo;
    novo=(no*)malloc(sizeof(no));
    novo->valor=valor;
    novo->ant=novo->prox=NULL;
    int i;
    for(i=0; i<= no.qtdeChaves;i++){


    }
    novo->prox=l->inicio;
    if (l->fim == NULL)
    {
        l->fim=l->inicio;
    }
    else
    {
        l->inicio->ant = novo;
        l->inicio=novo;
    }
}

void insere_fim(lista *l, int valor)
{
    no *novo;
    novo=(no*)malloc(sizeof(no));
    novo->valor=valor;
    novo->ant=novo->prox=NULL;
    novo->ant=l->fim;//
    if (l->inicio == NULL)
    {
        l->inicio=l->fim;
    }
    else
    {
        l->fim->prox=novo;
        l->fim=novo;
    }*/
}

int remove_inicio_lista(lista *l)
{
    no *aux;
    int guardaval;
    if(lista_vazia(l) == 1)
    {
        return -1;
    }
    else
    {
        if(l->inicio == l->fim)
        {
            aux=l->inicio;
            guardaval=l->inicio->valor;
            l->inicio=NULL;
            l->fim=NULL;
            free(aux);
            return(guardaval);
        }
        else
        {
            aux = l->inicio;
            guardaval=aux->valor;
            l->inicio=l->inicio->prox;
            l->inicio->ant = NULL;
            free(aux);
            return(guardaval);
        }
    }
}

int remove_fim_lista(lista *l)
{
    no *aux;
    int guardaval;
    if(lista_vazia(l)==1)
    {
        return -1;
    }
    else
    {
        if(l->inicio==l->fim)
        {
            aux=l->fim;
            guardaval=l->fim->valor;
            l->inicio=NULL;
            l->fim=NULL;
            free(aux);
            return(guardaval);
        }
        else
        {
            aux=l->fim;
            guardaval=aux->valor;
            l->fim=l->fim->ant;
            l->fim->prox=NULL;
            free(aux);
            return(guardaval);
        }
    }
}

void quebrar_meio(lista *l){
    no *aux,*aux2;
    lista *laux,*laux2;
    int guardaval;
    if(lista_vazia(l)==1)
    {
        printf("A lista está vazia.");
    }
    else
    {
        if(l->inicio==l->fim)
        {
            printf("Nao ha como quebrar a lista ha somente um elemento.");
        }
        else
        {
            int i=0;
            int length=sizeof(l);
            for(i=0;i<=length;i++){
                if(length%2==0 && i==length/2){
                    laux2->inicio = laux->fim->prox;
                    laux->fim->prox=NULL;

                }else if(length%2!=0 && i==length/2){
                    laux2->inicio = laux->fim->prox;
                    laux->fim->prox=NULL;
                }
            }
        }
    }
}

void mostrar_lista_op(lista *l)
{
    no *x;
    x=l->inicio;
    if (l->inicio == NULL)
    {
        printf("Lista vazia.");
        return;
    }else
    {
        while (x->prox != NULL)
        {
            if (x->valor != NULL)
            {
                printf("%d\t", x->valor);
                x=x->prox;
            }
            else
                return;
        }
    }
}

void mostrar_lista_of(lista *l)
{
    no *x;
    x=l->fim;
    if (l->inicio == NULL)
    {
        printf("Lista vazia.");
        return;
    }else
    {
        while (x->ant != NULL)
        {
            if (x->valor != NULL)
            {
                printf("%d\t", x->valor);
                x=x->ant;
            }
            else
                return;
        }
    }
}
