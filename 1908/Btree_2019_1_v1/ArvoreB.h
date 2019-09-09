#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include "Lista.h"
#include <Math.h>

struct noB
{
    int qtdChaves;
    struct noB *pai;
    struct noB *esquerda;
    lista *listaChaves;
    int folha; //1 se for folha, 0 caso contrario
};
typedef struct noB noB;

struct arv
{
    int m; //ordem da arvore
    int altura;
    noB *raiz;
};

typedef struct arv arv;


noB* divide(noB* noCheio, int m);
void insere_chave_no(int k, noB *folha);
noB* localiza_folha(int k, arv *tree);


#endif // ARVOREB_H_INCLUDED
