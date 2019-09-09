#include <stdio.h>
#include <stdlib.h>
#include "ArvoreB.h"


int main()
{
    arv* tree;
    // int vet[] = {5, 4, 6, 7, 8, 2, 9, 10, 11, 20, 30, 29, 25, 40,26,28,22,21};

    int vet[] = {50, 30, 40, 44, 88, 95, 25, 91, 31, 52, 20, 60, 35, 70, 74, 78, 79, 22, 28, 33, 39, 80, 85, 86, 87, 90, 92, 93, 94};
    int i=0;
    int tam=27;

    tree = cria_arvore(5);


    for (i=0; i<tam; i++)
    {
        insere_chave_arvore(tree,vet[i]);
    }

    insere_chave_arvore(tree,vet[i]);
    mostraArvore(tree);
    printf("\n\n\n\n");
 percursoEmNivelOtimizado(tree);
    percursoEmOrdem(tree->raiz);
    return 0;
}
