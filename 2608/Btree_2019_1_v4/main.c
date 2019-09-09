#include <stdio.h>
#include <stdlib.h>
#include "ArvoreB.h"


int main()
{
    arv* tree;



    tree = cria_arvore(3);
    insere_chave_arvore(tree,5);
    insere_chave_arvore(tree,3);
    insere_chave_arvore(tree,6);
    printf("%d", tree->raiz->listaChaves->inicio->valor);

    percursoEmOrdem(tree->raiz);
    return 0;
}
