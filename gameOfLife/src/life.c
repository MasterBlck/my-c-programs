#include "../include/life.h"
#include "../include/matrices.h"
#include <stdio.h>
#include <stdlib.h>

#define N_ROWS 20
#define N_COLS 20

void startTheLife(){
	 printf("Juego de la vida\n");
        //definiendo la matriz
        mensaje();
        int tablero[N_ROWS][N_COLS];

        //Inicializando tablero
	llenarMatrizConCeros(tablero, N_ROWS, N_COLS);

        //Imprimiendo el tablero
        print(tablero, N_ROWS, N_COLS);
}
