#include "arvoreB.h"

noB* localiza_folha(int k, arv *tree)
{
    noB *aux = tree->raiz;
    no *auxL;
    noB *resp;

    if (tree->raiz == NULL)//arvore vazia mas que tem ordem definida
        resp = NULL; //indica que deve ser criada uma folha, a raiz
    else
    {

        while (aux->folha != 1) //criar funcao para verificar se é folha
        {
            if (k < aux->listaChaves->inicio->valor)
                aux = aux->esquerda;
            else
            {


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
        }
        resp = aux;
    }
    return resp;
}

void insere_chave_no(no* k, noB *folha)
{
    insere_ordenado(k,folha->listaChaves);
    folha->qtdChaves++;
}

noB* divide(noB* noCheio, int m)
{
    int meio=ceil(m/2.0);

    lista *listaNova;

    noB* novoNo= cria_no_arvore();
    no* aux = NULL;
    listaNova = quebra_lista(noCheio->listaChaves, meio);
    //alterar o pai de todos nós que são do novo agora
    aux = listaNova->inicio;

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
        if (novoNo->esquerda   != NULL)//VERIFICAR
            novoNo->esquerda->pai = novoNo;
        while (aux != NULL)
        {
            if (aux->filho != NULL)
                ((noB*)aux->filho)->pai = novoNo;
            aux = aux->prox;
        }
    }

        noCheio->listaChaves->fim->filho = (void*) novoNo;



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
    no* chave=NULL;
    noB* aux;
    noB* novo;
    noB* folha = localiza_folha(k, tree);
    int continuar = 1;

    if (folha == NULL)
    {
        aux = cria_no_arvore();
        insere_chave_no(cria_chave(k),aux);
        tree->raiz = aux;
        tree->altura++;
    }

    else
    {
        while (continuar) //continuar ==1
        {
            if (chave == NULL)
                insere_chave_no(cria_chave(k),folha);
            else
                insere_chave_no(chave,folha);

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
                else
                {
                    chave = remove_fim_lista(folha->listaChaves);
                    folha->qtdChaves--;

                    folha = folha->pai;
                }
            }

        }
    }
}
void percursoEmOrdem(noB *raiz)
{
    no* aux;
    noB* auxb=raiz;
    if (auxb != NULL)
    {
        percursoEmOrdem(auxb->esquerda);
        aux = auxb->listaChaves->inicio;
        while (aux != NULL)
        {
            printf("%d ",aux->valor);
            auxb=(noB*)aux->filho;
            aux = aux->prox;
            percursoEmOrdem(auxb);
        }
    }
}

arv* cria_arvore(int m)
{
    arv* tree= (arv*)malloc(sizeof(arv));
    tree->m = m;
    tree->altura=0;
    tree->raiz = NULL;
    return tree;
}

void mostraNo(noB* raiz)
{
    no* aux=raiz->listaChaves->inicio;

    if (raiz->pai == NULL)
        printf("pai: nulo-");
    else
        printf("pai:%d-",raiz->pai->listaChaves->inicio->valor);

    printf("[");
    while (aux != NULL)
    {

        printf("%d ",aux->valor);
        aux = aux->prox;
    }
    printf("]");
}
void percursoEmNivel(noB *raiz, int nivel, int altura)
{
    no* aux;
    noB* auxb = raiz;
    if (raiz != NULL)
    {
        if (altura == nivel)
        {
            mostraNo(raiz);
        }
        percursoEmNivel(raiz->esquerda, nivel + 1,altura);
        aux = auxb->listaChaves->inicio;
        while (aux != NULL)
        {
            auxb=(noB*)aux->filho;
            aux = aux->prox;
            percursoEmNivel(auxb, nivel+1,altura);
        }
    }

}

void mostraArvore(arv* tree)
{

    int nivel = 0;

    while (nivel <= tree->altura)
    {

        percursoEmNivel(tree->raiz, nivel, tree->altura);
        printf("\n");
        nivel++;

    }
}





