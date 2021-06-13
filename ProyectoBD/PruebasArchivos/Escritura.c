#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int x = 0;
	int n = 0;
	FILE *fp;
	if((fp = fopen("datos.dat", "wb")) == NULL)
	{
		printf("No se pudo abrir archivo\n");
		exit(1);
	}
	
	while(feof(fp))
	{
		n++;
		printf("%d\n", n);
	}
	fseek(fp, sizeof(int)*n, SEEK_SET);
	
	do{
		printf("Escribe un entero: (-1 para terminar) ");
		scanf("%d", &x);
		fseek(fp, 0, SEEK_END);
		fwrite(&x, sizeof(x), 1, fp);
		n++;
		
    }while(x != -1);
    
    x=1024;
    fseek(fp, sizeof(int)*3, SEEK_SET);
    fwrite(&x, sizeof(x), 1, fp);
    fclose(fp);
	return 0;
}

