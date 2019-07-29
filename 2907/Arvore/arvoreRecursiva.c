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
}*/

arvore_vazia(NO *l)
{
    if ((l->esq && l->dir)== NULL)
        return 0;
    else
        return 1;
}

NO* insereElementos(NO *l, int chave)
{
    if(!arvore_vazia(l)){
    l->chave=(NO*)malloc(sizeof(NO));
    l->chave=chave;
    l->esq= NULL;
    l->dir = NULL;
    return l;
    }else{
        if(chave > l->chave){
          insereElementos(&l->esq,chave);
    }else{
          insereElementos(&l->dir,chave);
    }
    return l;
    }

/*
    if (l->fim == NULL)
        l->fim=l->inicio;
    else
        l->inicio->ant = novo;
    l->inicio=novo;*/

}

NO* mostrarArvore(NO *l)
{
    if(!arvore_vazia(l)){
        printf("%d", l->chave);
        mostrarArvore(l->esq);
        mostrarArvore(l->dir);
        return l;
    }else{
        printf("Arvore Vazia");
    }

}
/*
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

