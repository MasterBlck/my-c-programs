#include "../include/ListaLigada.h"
#include <stdio.h>

int main()
{
	mensaje();
	ListaLigada listita;
    creaLista(&listita); /* importante a la hora de crear */

    printf("ListaLigada:\n");
    insertaInicio(&listita, 14);
    insertaInicio(&listita, 8);
    insertaInicio(&listita, 9);

    imprimeLista(&listita);
    borraInicio(&listita);
    borraInicio(&listita);
    imprimeLista(&listita);

    destruir(&listita);

	return 0;
}
