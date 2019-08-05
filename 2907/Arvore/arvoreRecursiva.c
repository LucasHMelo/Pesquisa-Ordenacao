#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "biblio.h"
/*
NO* cria_arvore()
{
    NO *l;
    l=(NO*)malloc(sizeof(NO));
    l->inicio=NULL;
    l->fim=NULL;
  return l;
}

arvore_vazia(NO *l)
{
    if ((l->esq && l->dir)== NULL)
        return 0;
    else
        return 1;
}

NO* insereElementos(NO *l, int chave)
{
    NO *novo;
    novo = (NO*)malloc(sizeof(NO));
    novo->chave = chave;
    novo->esq= NULL;
    novo->dir = NULL;
    if(!arvore_vazia(l)){
        l = novo;
        return l;
    }else{
        if(chave > l->chave){
          insereElementos(&l->esq,chave);
          return l;
    }else{
          insereElementos(&l->dir,chave);
          return l;
    }
}


    if (l->fim == NULL)
        l->fim=l->inicio;
    else
        l->inicio->ant = novo;
    l->inicio=novo;

}

void mostrarArvore(NO *l)
{
    if(!arvore_vazia(l)){
        printf("%d", l->chave);
        mostrarArvore(l->esq);
        mostrarArvore(l->dir);

    }else{
        printf("Arvore Vazia");
    }

}

int removerinicio(NO *L){
   //if(lista_vazia(aux)){
   //     printf("Essa lista está vazia!\n");
  // }
   if(L->inicio == L->fim){
    no *aux;
    int salvaValor;
    aux = L->inicio;
    free(aux);
    L->inicio = L->fim = NULL;
    return salvaValor;

   }else{
       int valor = L->inicio->valor;
       no *aux = L->inicio;
       L->inicio = aux->prox;
       L->inicio->ant = NULL;
       free(aux);
       return valor;

   }
}

int removeFim(lista *L){
  //  if(listaVazia(aux)){
   //     printf("Essa lista está vazia!\n");
  // }
   if(L->inicio == L->fim){
    no *aux;
    int salvaValor;
    aux = L->fim;
    free(aux);
    L->inicio = L->fim = NULL;
    return salvaValor;

   }else{
       int valor = L->fim->valor;
       no *aux = L->fim;
       L->fim = aux->ant;
       L->inicio->prox = NULL;
       free(aux);
       return valor;

   }
}*/

no* inserir_arvore(no *raiz, int dado)
{
    no *novo, *aux;
    novo=(no*)malloc(sizeof(no));
    novo->dado=dado;
    novo->dir=NULL;
    novo->esq=NULL;
    if (raiz == NULL)
    {
        raiz=novo;
    }
    else
    {
        aux=raiz;
        no* ant;
        while (aux != NULL)
        {
            if (dado < aux->dado)
            {
                ant=aux;
                aux=aux->esq;
            }
            else
            {
                ant=aux;
                aux=aux->dir;
            }

        }
        if (dado < ant->dado)
            ant->esq=novo;
        else
            ant->dir=novo;


    }
    return raiz;
}

void em_ordem (no *raiz)
{
    if (raiz != NULL)
    {
        em_ordem(raiz->esq);
        printf("%d\n", raiz->dado);
        em_ordem(raiz->dir);
    }

}

void pre_ordem (no *raiz)
{
    if (raiz != NULL)
    {
        printf("%d\n", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

