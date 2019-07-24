#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

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

typedef struct
{
   no *inicio;
   no *fim;
}fila;

/*
struct no{
    struct no *ant, *prox;
    int valor;

};
    typedef struct no NO;

struct lista {
    struct no *ini, *fim;
};
    typedef struct lista L;
*/
#endif // MAIN_H_INCLUDED

