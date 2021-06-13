#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 15
#define MAX_TAM 20
FILE *fp;
int numUsuarios = 0;
 struct usuario{
	 char nom[TAM];
	 char passwd[MAX_TAM];
 };

/*programa para registrar usuarios en un archivo*/
int existeUsuario(char *usr, FILE *file);

int main(int argc, char **argv)
{
	char resp;
	struct usuario user;
	system("rm usuarios.dat");
	printf("REGISTRO DE USUARIOS\n");
	if((fp = fopen("usuarios.dat", "wrb")) == NULL)
	{
		printf("No se pudo abrir archivo\n");
		exit(1);
	}
	
	
	
	do{
		printf("Teclee un nuevo usuario: ");
		scanf("%s", user.nom);
		getchar();
		
		printf("Teclee contraseña para %s: ", user.nom);
		scanf("%s", user.passwd);
		getchar();
		numUsuarios++;
		
		fwrite(&user, sizeof(user), 1, fp);
		
		printf("Registrado %s con éxito\nDesea registrar otro usuario?(s/n) ", user.nom);
		scanf("%c", &resp);
		getchar();
		
	}while(resp == 's');
	
	fclose(fp);

	return 0;
}

