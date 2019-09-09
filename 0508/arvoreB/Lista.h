#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int valor;
    struct no *ant, *prox;
}no;

typedef struct
{
   no *inicio;
   no *fim;
   int qtdvetor;
}lista;

lista* cria_lista();

int lista_vazia(lista *l);

void insere_inicio(lista *l, int valor);

void insere_fim(lista *l, int valor);

int remove_inicio_lista(lista *l);

int remove_fim_lista(lista *l);


#endif // PILHA_E_FILA_H_INCLUDED
