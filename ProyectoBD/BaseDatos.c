#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TAM 15
#define MAX_TAM 20
#define N_ARCHIVOS 5

/* Usaremos unistd.h para la funcion getpass() para leer contraseñas
 * y string.h para comparar cadenas*/
 
 /*se definen las estructuras*/
 struct usuario{
	 char nom[TAM];
	 char passwd[MAX_TAM];
 };
 
 /*se definen variables globales*/
 FILE *usuarios, *contra, *archivos[N_ARCHIVOS];
 char comando[TAM];
 
 /*se definen prototipos de funciones*/
 int existeUsuario(struct usuario *u);
 void ejecutaComandos(char *usr, char *cmd);

int main(int argc, char **argv)
{
	struct usuario login;
	
	/*empezando desde el login de cualquier usuario registrado*/
	system("reset");
	printf("BASE DE DATOS MUSIC\nBienvenido\n User: ");
	scanf("%s", login.nom);
	getchar();
	
	while(!existeUsuario(&login))
	{
		system("reset");
		printf("ERROR!! EL USUARIO %s NO EXISTE! INTENTE DE NUEVO\n User: ", login.nom);
	    scanf("%s", login.nom);
	    getchar();
	    
	}
	while(strcmp(login.passwd, getpass( "Ingrese la contraseña: ")) != 0) /*consultar ayuda*/
	{
		printf("ERROR!! LA CONTRASEÑA DEL USUARIO %s INCORRECTA! INTENTE DE NUEVO\n", login.nom);
	}
	
	printf("%s  %s\n", login.nom, login.passwd);
	
	/*despues de validar cualquier usuario, empezamos a trabajar, ya sea
	 * con el admin o con el resto de usuarios*/
	if((strcmp(login.nom, "admin") == 0) && (strcmp(login.passwd, "admin") == 0)) /*manejo del usuario administrador*/
	{
		printf("BIENVENIDO ADMINISTRADOR\n");
	}
	else
	{
		printf("%s@login:~$", login.nom);
		scanf("%s", comando);
		getchar();
		
		while(strcmp("salir", comando) != 0)
		{
			
			switch(login.nom[0])
			{
				/*usuario esther*/
				case 'e': ejecutaComandos(login.nom, comando);
						  break;
					  
				/*usuario luis*/		  
				case 'l': ejecutaComandos(login.nom, comando);
						  break;
					  
				/*caso flor*/
				case 'f': ejecutaComandos(login.nom, comando);
					      break;
			
				/*caso saul*/		  
				case 's': ejecutaComandos(login.nom, comando);
					      break;
					  
				/*caso miranda*/
				case 'm': ejecutaComandos(login.nom, comando);
					      break;
			}
			
			printf("%s@login:~$", login.nom);
			scanf("%s", comando);
			getchar();
			
		}
		
	}
	
	
	
	return 0;
}

/*AYUDA CON FUNCIONES
 * int system(char* _cmd) sirve para enviar órdenes al shell del sistema operativo.
 * 
 * En la linea donde tiene escrrito
 * strcpy(login.passwd, getpass( "Ingrese la contraseña: "));
 * sirve para copiar la cadena capturada hacia la estructura login.passwd, es equivalente a:
 * 
 * char *pass;
 * pass = getpass("Ingrese la contraseña: "); //peticion de contraseña
 * strcpy(login.passwd, pass); //copiar contraseña capturada hacia la estructura
 * 
 */

int existeUsuario(struct usuario *u)
{
	FILE *fp;
	struct usuario leido;
	if((fp = fopen("usuarios.dat", "rb")) == NULL)
	{
		printf("No se pudo abrir archivo\n");
		exit(1);
	}
	
	while(!feof(fp))
	{
		fread(&leido, sizeof(leido), 1, fp);
		
		if(strcmp(leido.nom, u->nom) == 0)
		{
			strcpy(u->passwd, leido.passwd); //truco
			return 1;
		}
	}
	
	fclose(fp);
	return 0;
}

void ejecutaComandos(char *usr, char *cmd)
{
	printf("Comando %s para usuario %s\n", cmd, usr);
}
