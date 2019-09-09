#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

struct noB{
    int qtdChaves;
    struct noB *pai;
    struct noB *esq;
    Lista *listaChaves;
};

typedef struct noB NoB;

NoB* localizaFolha(int k, NoB *tree);

struct arv{
    int m; //ordem arvore
    NOB *raiz;
};

typedef arv Arv;

#endif // ARVOREB_H_INCLUDED
