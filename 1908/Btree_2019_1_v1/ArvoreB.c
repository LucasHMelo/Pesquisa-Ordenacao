#include "arvoreB.h"

noB* localiza_folha(int k, arv *tree)
{
    noB *aux = tree->raiz;
    no *auxL;
    noB *resp;

    if (tree->raiz == NULL)//arvore vazia mas que tem ordem definida
        resp = NULL; //indica que deve ser criada uma folha, a raiz
    else{

        while (aux->folha != 1) //criar funcao para verificar se é folha
        {
          if (k < aux->listaChaves->inicio->valor)
            aux = aux->esquerda;
          else
             auxL = aux->listaChaves->inicio;
             while (auxL != NULL && k > auxL->valor)
             {
              auxL = auxL->prox;
             }

             if(auxL == NULL)
                aux = aux->listaChaves->fim->filho;
             else
                aux = (noB*)auxL->ant->filho;
        }
        resp = aux;
    }
    return resp;
}

void insere_chave_no(int k, noB *folha)
{
    insere_ordenado(k,folha->listaChaves);
    folha->qtdChaves++;
}

noB* divide(noB* noCheio, int m)
{
    int meio=ceil(m/2.0);

    lista *listaNova;

    noB* novoNo= (noB*)malloc(sizeof(noB));

    listaNova = quebra_lista(noCheio->listaChaves, meio);

    novoNo->pai = noCheio->pai;
    novoNo->esquerda = NULL;
    novoNo->folha = noCheio->folha;
    novoNo->listaChaves = listaNova;
    novoNo->qtdChaves = m - meio;

    noCheio->qtdChaves = meio;
//e se o no que está sendo dividido não for folha?



    return novoNo;
}

noB* ajusta_raiz(noB* folha, noB* novo){

    noB* novaRaiz = cria_no_arvore();

    novaRaiz->folha = 0;
    novaRaiz->esquerda = folha;
    novaRaiz->pai = NULL;
    novaRaiz->qtdChaves = 1;

    novaRaiz->listaChaves->inicio =
    novaRaiz->listaChaves->fim =
    folha->listaChaves->fim;

    folha->listaChaves->fim =
    folha->listaChaves->fim->ant;

    folha->listaChaves->fim->prox = NULL;

    novaRaiz->listaChaves->inicio->ant = NULL;

    folha->qtdChaves--;

    folha->pai = novaRaiz;

    novo->pai = novaRaiz;

    novaRaiz->listaChaves->inicio->filho = (void*) novo;

    return novaRaiz;

}

noB* cria_no_arvore(){
    noB* novoNo = (noB*) malloc(sizeof(noB));
    novoNo->esquerda = NULL;
    novoNo->pai = NULL;
    novoNo->folha = 1;
    novoNo->qtdChaves = 0;
    novoNo->listaChaves = (lista*)malloc(sizeof(no));
    novoNo->listaChaves->inicio = NULL;
    novoNo->listaChaves->fim = NULL;

    return novoNo;
}

arv* insere_chave_arvore(arv* tree, int k){

    noB* aux;
    noB* folha = localiza_folha(k,tree);
    int continuar,chave;
    if(folha == NULL){
        aux = cria_no_arvore();
        aux->qtdChaves++;
        insere_inicio(aux->listaChaves, k);
        arv->raiz = aux;
    }else{
        while(continuar){
            insere_chave_no(k, folha);
            if(folha->qtdChaves < arv->m){
                continuar = 0;
            }else{
                novo = divide(folha, arv->m);

                chave = folha->listaChaves->fim;

                if(folha->pai == NULL){
                    arv->raiz = ajusta_raiz(folha, novo);
                    continuar = 0;
                }else{
                    chave = remove_fim_lista(folha->listaChaves->fim);
                    folha->qtdChaves--;

            }
        }
    }


}

void ordem(no* arv){
    int i;

    if(arv != NULL ){
        ordem(arv->esq);
        for(i=0;i<aux->qtdChaves;i++){
            printf("%d",aux->info);
            ordem(aux->dir);
        }
    }
}





