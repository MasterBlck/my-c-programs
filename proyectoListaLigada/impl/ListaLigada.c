#include "../include/ListaLigada.h"
#include <stdio.h>
#include <stdlib.h>

void mensaje()
{
	printf("Mesaje prueba..\n");
}

void creaNodo(Nodo *n, int dat)
{
	n->dato = dat;
    n->liga = NULL;
}

void creaLista(ListaLigada *l)
{
	l->iniLista = NULL;
    l->nElementos = 0;
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

int insertaInicio(ListaLigada *l, int dato)
{
	Nodo *nuevo;

    /* Reserva de memoria para el nuevo nodo */
    if((nuevo = (Nodo *) malloc(sizeof(Nodo))) == NULL) //se puedesustituir por funcion creaNodo()
        return -1;

    nuevo->dato = dato;
    nuevo->liga = l->iniLista;
    l->iniLista = nuevo;
    l->nElementos++;

    return 0;
}

int insertaFin(ListaLigada *l, int dato)
{
	Nodo *nuevo;

	/* Reserva de memoria para el nuevo nodo */
    if((nuevo = (Nodo *) malloc(sizeof(Nodo))) == NULL) //se puede sustituir por funcion creaNodo()
        return -1;

    nuevo->dato = dato;
    nuevo->liga = NULL;
    if(l->iniLista == NULL)
    	l->iniLista = nuevo;
    else
    {
    	Nodo *aux = l->iniLista;
    	while(aux->liga != NULL)
    	{
    		aux = aux->liga;
    	}

    	aux->liga = nuevo;
    }

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

int estaVacia(ListaLigada *l)
{
	if(l->iniLista == NULL)
		return 1;
	
	return 0;
}
