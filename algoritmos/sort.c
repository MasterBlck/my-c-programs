/*Programa de Ordenamiento de arreglos por insertion sort*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void obtenerArregloAleatorio(int *arreglo, int n);
void imprimirArreglo(int *arreglo, int n);
void insertSort(int *arreglo, int n);

int main(int argc, char const *argv[]){
    srand(time(NULL));
    int arr[N];
    clock_t t_inicial, t_final;
    double segs;
    printf("Arreglo de números desordenados:\n");
    /*Midiendo tiempo de ejecución*/
    t_inicial = clock();
    obtenerArregloAleatorio(arr, N);
    imprimirArreglo(arr, N);
    t_final = clock();

    segs = (double) t_final - t_inicial / CLOCKS_PER_SEC;
    printf("%.16g milisegundos\n", segs/1000);


    printf("Ordenando e imprimiendo el arreglo:\n");
    insertSort(arr, N);
    printf("Imprimiendo el arreglo ordenado:\n");
    imprimirArreglo(arr, N);


    return 0;
}


void obtenerArregloAleatorio(int *arreglo, int n){
    int i = 0;
    while( i < n ){
        arreglo[i] = rand()%1024;
        i++;
    }
}

void imprimirArreglo(int *arreglo, int n){
    int i = 0;
    while( i < n ){
        printf("%d\t" , arreglo[i]);
        i++;
    }
    printf("\n");
}

void insertSort(int *arreglo, int n){
    int j, i;
    int key;
    for(j = 1; j < n; j++){
        key = arreglo[j];
        //Inserta A[j] dentro de la secuencia ordenada A[1 .. j-1]
        i = j - 1;
        while (i >= 0 && arreglo[i] > key){
            arreglo[ i + 1 ] = arreglo[i];
            i = i - 1;
        }
        
        arreglo[i + 1] = key;
    }
}