/*Lista genérica
 *
 * compilar para probar con 
 * gcc -o lista lista2.c -std=c99 -Wall --debug -DTEST
 * ./lista 
 * */

//#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
//#include <stdbool.h>

struct nodo{
	void * dato;
	struct nodo * sig;
};

typedef struct nodo * Lista;

void die(char * err){
	//función para imprimir errores graves y terminar
	printf("%s\n", err);
	exit(-1);
}

void l_Crear(Lista * l){
	struct nodo * aux;
	if (NULL == (aux = malloc(sizeof(struct nodo)))){
		die("No se pudo alocar memoria para el nuevo nodo");
	}
	aux->dato = NULL;
	aux->sig = NULL;
	*l = aux;
}

int l_EsVacia(Lista l){
	return (l->dato == NULL);
}


#ifdef TEST
int main(int argc, char ** argv){
	Lista l;
	puts("Inicializo la lista");
	l_Crear(&l);
	puts("Pregunto si la lista sin inicializar es vacía.");
	printf("%s\n", (l_EsVacia(l)?"Es vacía":"No es vacía"));
	puts("No es vacía, así que trato de imprimir el contenido del nodo...");
	printf("%s\n", (char*)l->dato);
	return 0;
}
#endif
