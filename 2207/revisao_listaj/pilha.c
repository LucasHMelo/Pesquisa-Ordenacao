#include "main.h"
#include <stdio.h>
#include <stdlib.h>

lista* cria_pilha(){
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    l->inicio = NULL;
    l->fim = NULL;
  return l;
}

int pilhaVazia(lista *l){
    if (l->inicio == NULL)
        return 0;
    else
        return 1;
}

void Push(lista *l, int valor){
    no *novo;
    novo->valor=(no*)malloc(sizeof(no));
    novo->valor=novo;
    novo->ant=novo->prox=NULL;
    novo->ant=l->fim;

    if (l->inicio == NULL)
        l->inicio=l->fim;
    else
        l->fim->prox=novo;

    l->fim=novo;

}

int Pop(lista *L){
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

