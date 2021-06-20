/*
    Programa para sacar 2 arrays subsecuentes
*/
#include <stdio.h>
#include <stdlib.h>

void obtenerSubarrays(int* arr, int n);

int main(int argc, char const *argv[]){
    int array[9] = {0, 4, 7, 3, 2, -1, 10,10, 20};
    
    obtenerSubarrays(array, 9);

    printf("\n");
    return 0;
}

void obtenerSubarrays(int* arr, int n){
    int i = 1;
    int *pilas_int[n], i_pila = -1, c_element=0;    

    while ( i < n ){
        if( arr[i] >= arr[i-1] ){
            //printf("%d ", arr[i]);

            if(i_pila == -1 || c_element == 0){  //hará falta un or preguntando por count_elements
                //reservar memoria dinámica para esa pila
                i_pila++;
                pilas_int[i_pila] = (int*) malloc(n*sizeof(int));    
            }

            //poner el elemento arr[i] en la pila[i]
            pilas_int[i_pila][c_element] = arr[i];
            c_element++;        
        }else{
            c_element = 0;
        }
            
        i++;
    }

    printf("tope de pila: %d\n", i_pila);

    int tope_pila = i_pila, j = 0;
    c_element = i_pila = 0;
    
    //Imprimiendo el resultado de la pila
    while ( i_pila <= tope_pila ){
        printf("[%d] : ", i_pila);
        j=0;
        while ( j < n ) {
            printf("%d  ", pilas_int[i_pila][j]);
            j++;
        }

        printf("\n");
        i_pila++;
    }

    i=0;
    //liberando memorias
    while ( i <= tope_pila ){
        free(pilas_int[i]);
        i++;
    }
    
}   
