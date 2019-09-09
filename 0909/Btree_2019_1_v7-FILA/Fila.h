#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "Lista.h"

typedef lista fila;

fila* cria_fila();
void adicionar(void* novo, fila *f,int nivel);
void* remover(fila *f);
int fila_vazia(fila *f);


#endif // FILA_H_INCLUDED
