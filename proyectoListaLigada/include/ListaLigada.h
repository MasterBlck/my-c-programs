/* Archivo de cabecera para la Lista Ligada
 * by MasterBlackHack \m/
 *
*/
#ifndef LISTALIGADA_H
#define LISTALIGADA_H

 //definicion de constantes
 #define PI 3.1416

//definición de variables
// int numElementos = 1;

 typedef struct nodo
 {
 	int dato;
 	struct nodo *liga;
 }Nodo;

 typedef struct lista
 {
 	Nodo *iniLista;
 	int nElementos;
 }ListaLigada;

//definición de las funciones y variables a utilizar
void mensaje();
void creaNodo(Nodo *n, int dat);
void creaLista(ListaLigada *l);
void destruir(ListaLigada *l);
void imprimeLista(ListaLigada *l);
int insertaInicio(ListaLigada *l, int dato);
int insertaFin(ListaLigada *l, int dato);
int borraInicio(ListaLigada *l);
int estaVacia(ListaLigada *l);

#endif
