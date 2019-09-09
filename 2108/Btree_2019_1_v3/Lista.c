#include "Lista.h"

lista* cria_lista()
{
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
    novo->filho = NULL;
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
    }
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
    if(lista_vazia(l)==0)
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


lista* quebra_lista(lista *l,int aux)
{
    lista* l2;
    no* auxlista;
    l2 = cria_lista();
    int teste = 1;
    int t = aux;
    int a,b,c;
    if(l->inicio == NULL)
    {
        teste = 0;
        return NULL;
    }
    else
    {
        auxlista = l->inicio;
        while(aux != 0){
            auxlista = auxlista->prox;
            aux--;
        }

        l2->inicio = auxlista;
        l2->fim = l->fim;
        l->fim = auxlista->ant;
        l->fim->prox = NULL;
        l2->inicio->ant = NULL;
        auxlista->ant = NULL;
        return(l2);
    }
}

void insere_ordenado(int valor,lista *l)
{
    no *novo=(no*)malloc(sizeof(no));
    no* aux1;
    no* aux2;
    novo->valor=valor;
    novo->prox=NULL;
    novo->ant=NULL;
    aux1=l->inicio;
    if(l->inicio==NULL)
    {
        l->inicio=novo;
        l->fim=novo;
    }
    else
    {
        if(novo->valor<l->inicio->valor)
        {
            l->inicio->ant=novo;
            novo->prox=l->inicio;
            l->inicio=novo;
        }
        else
        {
            if(novo->valor>l->fim->valor)
            {
                l->fim->prox=novo;
                novo->ant= l->fim;
                l->fim=novo;
            }
            else
            {
                while(novo->valor>aux1->valor)
                {
                    aux1=aux1->prox;
                }
                novo->prox=aux1;
                aux2=aux1->ant;
                novo->ant= aux1->ant;
                aux1->ant=novo;
                aux2->prox=novo;
            }
        }
    }
}
