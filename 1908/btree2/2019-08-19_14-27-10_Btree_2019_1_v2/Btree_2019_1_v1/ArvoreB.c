#include "arvoreB.h"

arv* cria_arvore(int m){
    arv* tree = (arv*)malloc(sizeof(arv));
    tree->m = m;
    tree->altura = 0;
    tree->raiz = NULL;
    return tree;

}

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

    if (noCheio->folha == 0)//não é folha
    {
        novoNo->esquerda = noCheio->listaChaves->fim->filho;
        if (novoNo->esquerda   != NULL)
            novoNo->esquerda->pai = novoNo;
    }


    return novoNo;
}
noB* ajusta_raiz(noB* folha, noB* novo)
{
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

    novaRaiz->listaChaves->inicio->filho = (void*)  novo;

    return novaRaiz;
}


noB* cria_no_arvore()
{
    noB* novoNo = (noB*) malloc(sizeof(noB));
    novoNo->esquerda = NULL;
    novoNo->pai = NULL;
    novoNo->folha = 1;
    novoNo->qtdChaves =0;
    novoNo->listaChaves = (lista*)malloc(sizeof(lista));
    novoNo->listaChaves->inicio = NULL;
    novoNo->listaChaves->fim = NULL;

    return novoNo;

}



/*
inicio
     encontre uma folha para inserir a chave  K
 enquanto (não sair)
  insira K na folha encontrada
  se (nó não está cheio) entao
        sair = verdadeiro;
  senão
            divida o nó em nó1 e nó2; //nó1 == nó, nó2 é novo
            distribua as chaves e os ponteiros igualmente entre nó1 e nó2
            K = ultima chave de nó1; //a qual é retirada de nó1
            se (nó era a raiz) entao
                crie uma nova raiz como ascendente de nó1 e nó2;
                coloque K e ponteiros para nó1 e nó2 na raiz e
                sair = verdadeiro;
            senao
                folha = seu pai;
            fimse
    fimse
fimenquanto
fim
*/


void  insere_chave_arvore(arv* tree, int k)
{
    int chave=0;
    noB* aux;
    noB* novo;
    noB* folha = localiza_folha(k, tree);
    int continuar = 1;
    if (folha == NULL)
    {
        aux = cria_no_arvore();
        aux->qtdChaves++;
        insere_ordenado(aux->listaChaves, k);
        tree->raiz = aux;
    }

else{
        while (continuar) //continuar ==1
        {
         insere_chave_no(k,folha);

         if (folha->qtdChaves < tree->m)
            {
                continuar = 0;
            }
            else
            {
                novo = divide(folha, tree->m);

               // chave = folha->listaChaves->fim;

                if (folha->pai == NULL)//dividimos a raiz
                {
                    tree->raiz= ajusta_raiz(folha,novo);
                    continuar = 0;
                }
                else{
                    chave = remove_fim_lista(folha->listaChaves);
                    folha->qtdChaves--;
                    folha = folha->pai;
                }
            }

        }
}
}

void ordem(noB* arv){
    int i;
    no* auxl;
    if(arv != NULL ){
        ordem(arv->esquerda);
        auxl=arv->listaChaves->inicio;
        for(i=0;i<arv->qtdChaves;i++){
            printf("%d",auxl->valor);
            ordem((noB*)auxl->filho);
        }
    }
}





