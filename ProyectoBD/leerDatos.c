#include <stdlib.h>
#include <stdio.h>
#define TAM 15
#define MAX_TAM 20
FILE *fp;

 struct usuario{
	 char nom[TAM];
	 char passwd[MAX_TAM];
 };
 
int main(int argc, char **argv)
{
	struct usuario buffer;
	
	if((fp = fopen("usuarios.dat", "rb")) == NULL)
	{
		printf("No se pudo abrir archivo\n");
		exit(1);
	}
	
	while(!feof(fp))
	{
		fread(&buffer, sizeof(buffer), 1, fp);
		//fscanf(fp, "%s", buffer);
		printf("%s  %s\n", buffer.nom, buffer.passwd);
	}
	
	fclose(fp);
	return 0;
}

