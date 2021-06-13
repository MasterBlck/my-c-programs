#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int x;
	FILE *fp;
	if((fp = fopen("datos.dat", "rb")) == NULL)
	{
		printf("No se pudo abrir archivo\n");
		exit(1);
	}
	
	do{
		fread(&x, sizeof(x), 1, fp);
		printf("%d\n", x);
    }while(!feof(fp));
    
    printf("\n\n%d\n\n",(int) ftell(fp));
    fclose(fp);
	return 0;
}

