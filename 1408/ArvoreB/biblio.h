#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED

typedef struct{
    int valorChave;
    struct noB *filho;
    struct no *ant,*prox;
}no;

typedef struct{
    no *inicio, *fim;
}lista;

lista* cria_lista();

int lista_vazia(lista *l);

void insere_inicio(lista *l, int valor);

void insere_fim(lista *l, int valor);

int remove_inicio_lista(lista *l);

int remove_fim_lista(lista *l);



#endif // BIBLIO_H_INCLUDED
