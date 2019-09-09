#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct
{
    int valorChave;
    struct noB *filho;
    struct no *ant, *prox;
}no;
*/
struct no
{
    int valor;
    void *filho; // struct noB*
    struct no *ant, *prox;
};

typedef struct no no;

struct lista
{
    no *inicio;
    no *fim;
};

typedef struct lista lista;

lista* cria_lista();

int lista_vazia(lista *l);

void insere_inicio(lista *l, no* valor);

void insere_fim(lista *l, no* valor);

no* remove_inicio_lista(lista *l);

no* remove_fim_lista(lista *l);

lista* quebra_lista(lista *l,int aux);

void insere_ordenado(no* valor,lista *l);

no* cria_no(int valor);

no* cria_no_vazio();
#endif // PILHA_E_FILA_H_INCLUDED
