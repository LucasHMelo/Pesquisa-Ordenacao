/*lista*criaLista(){
        lista *L = (lista*)malloc(sizeof(lista));
        L->ini = NULL;
        L->fim = NULL;
        return L;
};

int listaVazia(lista *L){
    if(L->ini == NULL)
        return 1;
    else
        return 0;
};

void insereInicio(lista *L, int valorNovo){
    NO *novo = (NO*)malloc(sizeof(NO));
    novo->valor = valorNovo;
    novo->ant   = novo->prox = NULL;
    novo->prox  = L->ini;
    L->ini      = novo;
    if(L->fim == NULL)
        L->fim  = novo
    if(L->ini != NULL)
        novo->prox = L->ini;
    L->ini = novo;
};

void insereFim(lista *L, int valorNovo){
    NO *novo = (NO*)malloc(sizeof(NO));
    novo->valor = valorNovo;
    novo->ant   = novo->prox = NULL;
    novo->ant  = L->fim;
    if(listaVazia(L)==0){
        L->fim->prox = novo;
    }
    else{
        L->ini = novo;
    }
    L->fim = novo;
};
/*
void removeInicio(lista *L){
  lista *aux = no;
  if(listaVazia(aux)){
        printf("Essa lista está vazia!\n");
    }else{
    if(aux->prox != NULL){
      aux->prox->ant = NULL;
    }
    L = aux->prox;
    aux->prox = NULL;
    printf("\nValor: %d\n", L->valor);
    return list;
  }
}

int removerInicio(lista *L){
   if(listaVazia(aux)){
        printf("Essa lista está vazia!\n");
   }
   if(L->ini == L->fim){
    NO *aux;
    int salvaValor;
    aux = L->ini;
    free(aux);
    L->ini = L->fim = NULL;
    return salvaValor;

   }else{
       int valor = L->ini->valor;
       NO *aux = L->ini;
       L->ini = aux->prox;
       L->ini->ant = NULL;
       free(aux);
       return valor;

   }
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "main.h"

lista* cria_lista()
{
    lista *l;
    l=(lista*)malloc(sizeof(lista));
    l->inicio=NULL;
    l->fim=NULL;
  return l;
}

lista_vazia(lista *l)
{
    if (l->inicio == NULL)
        return 0;
    else
        return 1;
}

void insere_inicio(lista *l, int valor)
{
    no *novo;
    novo->valor=(no*)malloc(sizeof(no));
    novo->valor=novo;
    novo->ant=novo->prox=NULL;
    novo->prox=l->inicio;

    if (l->fim == NULL)
        l->fim=l->inicio;
    else
        l->inicio->ant = novo;
    l->inicio=novo;

}

void insere_fim(lista *l, int valor)
{
    no *novo;
    novo->valor=(no*)malloc(sizeof(no));
    novo->valor=novo;
    novo->ant=novo->prox=NULL;
    novo->ant=l->fim;//
    if (l->inicio == NULL)
        l->inicio=l->fim;
    else
        l->fim->prox=novo;

    l->fim=novo;

}

int removerinicio(lista *L){
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
}
