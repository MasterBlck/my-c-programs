/*
 * Archivo de cabecera para la operación de matriz
 */
#ifndef MATRICES_H
#define MATRICES_H
#define N_ROWS 20
#define N_COLS 20

void mensaje();
void llenarMatrizConCeros(int matriz[N_ROWS][N_COLS], int n, int m);
void print(int matriz[N_ROWS][N_COLS], int n, int m);
void iniciarTablero(int matriz[N_ROWS][N_COLS], int n, int m);

#endif
