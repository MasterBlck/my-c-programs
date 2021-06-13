#include <stdio.h>
#include <stdlib.h>

/*definicion del tipo 'Nodo'*/
typedef struct nodo{
	int dato;
	struct nodo *liga;
}Nodo;

/*definicion del tipo 'Lista'*/
typedef struct lista{
	Nodo *iniLista;
	int nElementos;
}ListaLigada;

void creaNodo(Nodo *n, int dat);
void creaLista(ListaLigada *l);
int insertaInicio(ListaLigada *l, int dato);
int insertaFin(ListaLigada *l, int dato);
int borraInicio(ListaLigada *l);
int estaVacia(ListaLigada l);
void destruir(ListaLigada *l);
void imprimeLista(ListaLigada *l);

int main()
{
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

void creaLista(ListaLigada *l)
{
	l->iniLista = NULL;
	l->nElementos = 0;
}

void creaNodo(Nodo *n, int dat)
{
	n->dato = dat;
	n->liga = NULL;
}

int insertaInicio(ListaLigada *l, int dato)
{
	Nodo *nuevo;
	/* Reserva de memoria para el nuevo nodo */
	if((nuevo = (Nodo *) malloc(sizeof(Nodo))) == NULL)
		return -1;

	nuevo->dato = dato;
	nuevo->liga = l->iniLista;
        l->iniLista = nuevo;
	l->nElementos++;

	return 0;
}

int borraInicio(ListaLigada *l)
{
	if(l->iniLista == NULL)
		return -1;

	Nodo *viejo = l->iniLista;
	l->iniLista = viejo->liga;
	viejo->liga = NULL;
	free(viejo); /* importante para liberar memoria */
	l->nElementos--;

	return 0;
}

void destruir(ListaLigada *l)
{
	while(l->nElementos > 0)
		borraInicio(l);
}

void imprimeLista(ListaLigada *l)
{
	Nodo *aux = l->iniLista;
	while(aux != NULL)
	{
		printf("%d->", aux->dato);
		aux = aux->liga;
	}
}

int insertaFin(ListaLigada *l, int dato){
	return 0;
}
