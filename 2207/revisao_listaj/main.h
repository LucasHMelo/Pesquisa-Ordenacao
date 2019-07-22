#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

struct no{
    struct no *ant, *prox;
    int valor;

};
    typedef struct no NO;

struct lista {
    struct no *ini, *fim;
};
    typedef struct lista L;

#endif // MAIN_H_INCLUDED
