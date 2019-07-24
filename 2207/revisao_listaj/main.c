#include "main.h"
//#include "fila.c"
//#include "biblio.c"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
    //pt-br
    setlocale(LC_ALL, "Portuguese");
    //vars
    lista *l,*f;
    //inicio
    l=cria_lista();
    f=cria_fila();

    return 0;
}
