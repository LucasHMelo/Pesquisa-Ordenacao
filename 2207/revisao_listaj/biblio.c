lista*criaLista(){
        lista *L = (lista*)malloc(sizeof(lista));
        L->ini = NULL;
        L->fim = NULL;
        return L;
};

int listaVazia(lista *L){
    if(L->ini == NULL)
        return 1;
    else
        return 0;
};

void insereInicio(lista *L, int valorNovo){
    NO *novo = (NO*)malloc(sizeof(NO));
    novo->valor = valorNovo;
    novo->ant   = novo->prox = NULL;
    novo->prox  = L->ini;
    L->ini      = novo;
    if(L->fim == NULL)
        L->fim  = novo
    if(L->ini != NULL)
        novo->prox = L->ini;
    L->ini = novo;
};

void insereFim(lista *L, int valorNovo){
    NO *novo = (NO*)malloc(sizeof(NO));
    novo->valor = valorNovo;
    novo->ant   = novo->prox = NULL;
    novo->ant  = L->fim;
    if(listaVazia(L)==0){
        L->fim->prox = novo;
    }
    else{
        L->ini = novo;
    }
    L->fim = novo;
};
/*
void removeInicio(lista *L){
  lista *aux = no;
  if(listaVazia(aux)){
        printf("Essa lista está vazia!\n");
    }else{
    if(aux->prox != NULL){
      aux->prox->ant = NULL;
    }
    L = aux->prox;
    aux->prox = NULL;
    printf("\nValor: %d\n", L->valor);
    return list;
  }
}
*/
int removerInicio(lista *L){
   if(listaVazia(aux)){
        printf("Essa lista está vazia!\n");
   }
   if(L->ini == L->fim){
    NO *aux;
    int salvaValor;
    aux = L->ini;
    free(aux);
    L->ini = L->fim = NULL;
    return salvaValor;

   }else{
       int valor = L->ini->valor;
       NO *aux = L->ini;
       L->ini = aux->prox;
       L->ini->ant = NULL;
       free(aux);
       return valor;

   }
}

