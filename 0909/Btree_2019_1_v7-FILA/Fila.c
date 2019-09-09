#include "Fila.h"

fila* cria_fila()
{
    return cria_lista();
}

void adicionar(void* elem, fila *f, int nivel)
{
    no* novo = cria_no_vazio();
    novo->valor = nivel;
    novo->filho = elem;
    insere_fim(f,novo);
}

void* remover(fila *f)
{
    no* aux = remove_inicio_lista(f);
    return aux;
}

int fila_vazia(fila *f)
{
   return lista_vazia(f);
}
