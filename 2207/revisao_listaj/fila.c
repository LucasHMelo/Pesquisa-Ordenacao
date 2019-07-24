#include "main.h"
#include <stdio.h>
#include <stdlib.h>

lista* cria_fila(){
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    l->inicio = NULL;
    l->fim = NULL;
  return l;
}

int filaVazia(lista *l){
    if (l->inicio == NULL)
        return 0;
    else
        return 1;
}

void insereFila(lista *l, int valor){
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

int removeFila(lista *L){
  if(filaVazia(L->inicio->prox)){
       printf("Essa lista está vazia!\n");
   }
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
