#include "arvoreB.h"

noB* localiza_folha(int k, arv *tree)
{
    noB *aux = tree->raiz;
    no *auxL;
    noB *resp;
   // int a,b,c,d,e,f,g,h,m;
    if (tree->raiz == NULL)//arvore vazia mas que tem ordem definida
        resp = NULL; //indica que deve ser criada uma folha, a raiz
    else{
        //d = aux->folha;
        while (aux->folha != 1) //criar funcao para verificar se � folha
        {
            //a = aux->listaChaves->inicio->valor;
            //b=k;
          if (k < aux->listaChaves->inicio->valor){
            aux = aux->esquerda;

          }
          else
          {


             auxL = aux->listaChaves->inicio;
             //e = auxL->valor;
             while (auxL != NULL && k > auxL->valor)
             {
              auxL = auxL->prox;
             }

             if(auxL == NULL){
                aux = aux->listaChaves->fim->filho;
             }
             else{
                //c = auxL->valor;
                //g = (noB
                //h = g = (noB*)auxL->prox->filho;
                //f = (noB*)auxL->ant->filho;
                //if(auxL->ant == NULL)
                    aux = (noB*)auxL->ant->filho;
                //d = aux->folha;
             }
          }
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

    noB* novoNo = (noB*)malloc(sizeof(noB));

    listaNova = quebra_lista(noCheio->listaChaves, meio);

    novoNo->pai = noCheio->pai;
    novoNo->esquerda = NULL;
    novoNo->folha = noCheio->folha;
    novoNo->listaChaves = listaNova;
    novoNo->qtdChaves = m - meio;

    noCheio->qtdChaves = meio;
//e se o no que est� sendo dividido n�o for folha?

    if (noCheio->folha == 0)//n�o � folha
    {
        novoNo->esquerda = noCheio->listaChaves->fim->filho;
        if (novoNo->esquerda   != NULL)//VERIFICAR
            novoNo->esquerda->pai = novoNo;
    }
    else
    {
        noCheio->listaChaves->fim->filho = (void*) novoNo;
        novoNo-> pai = noCheio;
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
 enquanto (n�o sair)
  insira K na folha encontrada
  se (n� n�o est� cheio) entao
        sair = verdadeiro;
  sen�o
            divida o n� em n�1 e n�2; //n�1 == n�, n�2 � novo
            distribua as chaves e os ponteiros igualmente entre n�1 e n�2
            K = ultima chave de n�1; //a qual � retirada de n�1
            se (n� era a raiz) entao
                crie uma nova raiz como ascendente de n�1 e n�2;
                coloque K e ponteiros para n�1 e n�2 na raiz e
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

    noB* aux;
    noB* novo;
    noB* folha = localiza_folha(k, tree);
    int continuar = 1;
    if (folha == NULL)
    {
        aux = cria_no_arvore();
        aux->qtdChaves++;
        insere_ordenado(k,aux->listaChaves);
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
                    tree->altura++;
                    continuar = 0;
                }
                else{
                    k = remove_fim_lista(folha->listaChaves);
                    folha->qtdChaves--;
                    folha = folha->pai;
                }
            }

        }
}
}
 void percursoEmOrdem(noB *raiz) {
     no* aux;
     noB* auxb=raiz;
        if (auxb != NULL) {
            percursoEmOrdem(auxb->esquerda);
            aux = auxb->listaChaves->inicio;
            while (aux != NULL)
            {
                printf("%d ",aux->valor);
                aux = aux->prox;
                if(aux!=NULL)
                    percursoEmOrdem((noB*)aux->filho);
            }
        }
    /* no* aux;
     noB* auxb=raiz;
        if (auxb != NULL) {
            percursoEmOrdem(auxb->esquerda);
            aux = auxb->listaChaves->inicio;
            while (aux != NULL)
            {
                printf("%d ",aux->valor);
                //auxb=(noB*)aux->filho;
                aux = aux->prox;
                percursoEmOrdem(auxb);
            }
        }*/
    }

arv* cria_arvore(int m)
{
    arv* tree= (arv*)malloc(sizeof(arv));
    tree->m = m;
    tree->altura=0;
    tree->raiz = NULL;
    return tree;
}





