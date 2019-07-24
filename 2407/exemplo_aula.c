#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int valor;
    struct no *ant, *prox;
}no;

typedef struct
{
   no *inicio;
   no *fim;
}lista;

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

int removeFim(lista *L){
    if(listaVazia(aux)){
        printf("Essa lista está vazia!\n");
   }
   if(L->ini == L->fim){
    NO *aux;
    int salvaValor;
    aux = L->fim;
    free(aux);
    L->ini = L->fim = NULL;
    return salvaValor;

   }else{
       int valor = L->fim->valor;
       NO *aux = L->fim;
       L->fim = aux->ant;
       L->ini->prox = NULL;
       free(aux);
       return valor;

   }
}

int main()
{
    //pt-br
    setlocale(LC_ALL, "Portuguese");
    //vars
    lista *l;
    //inicio
    l=cria_lista();
    return 0;
}
