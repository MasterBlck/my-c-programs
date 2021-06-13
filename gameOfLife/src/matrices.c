#include "../include/matrices.h"
#include <stdio.h>
#define N_ROWS 20
#define N_COLS 20

void mensaje(){
	printf("Hola este es un programa de matrices\n");
}

void llenarMatrizConCeros(int matriz[N_ROWS][N_COLS], int n, int m){
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			matriz[i][j] = 0;
		}		
	}
}
	
void print(int matriz[N_ROWS][N_COLS], int n, int m){
	 for(int i=0; i < n; i++){
                for(int j=0; j < m; j++){
                        printf("%d ", matriz[i][j]);
                }
		printf("\n");
        }
}
void iniciarTablero(int matriz[N_ROWS][N_COLS], int n, int m){
}

