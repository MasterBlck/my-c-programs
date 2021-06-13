#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 15
FILE *fp;

int main(int argc, char **argv)
{
	char leido[TAM], nom[TAM];
	
	if((fp = fopen("usuarios.dat", "rb")) == NULL)
	{
		printf("No se pudo abrir archivo\n");
		exit(1);
	}
	
	printf("Teclee el nombre que desea buscar: ");
	scanf("%s", nom);
	
	while(!feof(fp))
	{
		fread(leido, sizeof(leido), 1, fp);
		
		if(strcmp(leido, nom) == 0)
		{
			printf("Encontrado %s\n", leido);
		}
	}
	return 0;
}

