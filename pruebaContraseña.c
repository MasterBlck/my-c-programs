#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 8//donde N pon la longitud máxima de la cadena

int main(int argc, char **argv)
{
    char *contra;
    system("reset");
	contra = getpass("Ingrese la contrasena:" );

	if( strcmp(contra,"hola") == 0 ){
		system("reset");
		printf("\nContrasena correcta\n");
	}
	else{
		printf("\nContrasena incorrecta\n");
	}
	return 0;
}

