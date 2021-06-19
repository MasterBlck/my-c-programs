/*Programa para contar las veces en que se repite una palabra en un string*/
#include <stdio.h>
#include <string.h>

void count_letters(char* str, int tam);
int exists(char leter, char* str, int tam);
int get_index(char letter, char* str, int tam);
void inicializa_arr(char* arr, int tam);
void inicializa_conteos(int* arr, int n);

int main(int argc, char const *argv[]){
    char* str = "Hola mundo";
    int length = strlen(str);

    count_letters(str, length);
    return 0;
}

void count_letters(char* str, int tam){
    //Inicializar 2 arreglos para almacenar la letra y el conteo correspondiente
    char letras[tam], i_letras=0;  //arreglo pseudodinámico
    int conteos[tam];

    inicializa_arr(letras, tam);
    inicializa_conteos(conteos, tam);

    int i = 0;
    while ( i < tam ){
        /*checar si cadena str[i] está en el arreglo de letras*/
        if ( exists(str[i], letras, tam) ){
            conteos[get_index(str[i], letras, tam)]++;
        }else if(i_letras < tam) {  // <------------------- se proteje para que i_letras no sobrepase el tamanio máximo
            //apilar la letra nueva en el arreglo letras[]
            letras[i_letras] = str[i];
            conteos[i_letras]++;

            i_letras++;
        }
        i++;
    }

    //rellenando los conteos
    while (i_letras < tam){
        letras[i_letras] = '-';
        conteos[i_letras] = -1;
        i_letras++;
    }
    
    
    //imprimiendo el resultado
    i=0;
    while ( letras[i] != '-' && i < tam ){  //Warning!!! operación muy delicada
        printf("%c\t%d\n", letras[i], conteos[i]);
        i++;
    }

}

int exists(char letter, char* str, int tam){
    int  i=0;

    while (i < tam){
        if(letter == str[i])
            return 1;
        i++;
    }
    
    return 0;
}

int get_index(char letter, char* str, int tam){
    int i=0;

    while (i < tam){
        if(letter == str[i]) return i;
        i++;
    }

    return -1;
}

void inicializa_arr(char* arr, int tam){
    int  i=0;

    while (i < tam){
        *(arr+i) = 0;
        i++;
    }
}

void inicializa_conteos(int* arr, int n){
    int  i=0;
    while (i < n){
        *(arr+i) = 0;
        i++;
    }
}