#include "arvoreB.h"

NoB* localizaFolha(int k, NoB *tree){
    NoB *aux = tree;
    No *auxL;
    NoB *resp;
    if(tree->raiz ==NULL) //arvore vazia mas que tem ordem definida
        resp = NULL; //indica que deve ser criada uma folha
    else{
        while(aux->folha != 1){
            if(k < aux->ini->valorChave)
                aux = aux->esq;
            else
                auxL = aux->ini;
                while (auxL != NULL && k > auxL->valorChave){
                    auxL = auxL->prox;
                }
                if(aux == NULL)
                    aux = aux->fim->filho;
                else
                    aux = auxL->ant->filho;
        } //criar funcao pra ver se é folha
        resp = aux;
    }
    return resp;
}

void insereChaveNo(int k, NoB *folha){
    insere_ordenado(k,folha->listaChaves);
    folha->qtdchaves++;
}

NoB* divide(NoB* noCheio, int m){
    int meio = ceil(m/2.0);

    Lista *listaNova;

    NoB* novoNo = (NoB*)malloc(sizeof(NoB));

    listaNova = separa_lista(meio, noCheio->listaChaves);

    novoNo->pai = noCheio->pai;
    novoNo->esq = NULL;
    novoNo->folha = noCheio->folha;
    novoNo->listaChaves = listaNova;
    novoNo->qtdChaves = m - meio;

    noCheio->qtdChaves = meio;

}
