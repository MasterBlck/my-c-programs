#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

//Máximo número de caracteres para ser transmitido
#define LONGITUD_MAX 1024
#define PUERTO 5000 //Puerto de comunicación del socket, debe ser el mismo que el del servidor

//Creando una macro para socketaddr
#define SA struct sockaddr

//Datos globales
int sock_f_descriptor, 
    connection;

struct sockaddr_in serveraddress,
                   client;

char mensaje[LONGITUD_MAX];

int main(int argc, char *argv[]){
    //Creación del socket del lado del cliente
    sock_f_descriptor = socket(AF_INET, SOCK_STREAM, 0);  //checar el último parámetro
    if(sock_f_descriptor == -1){
        printf("Error al intentar crear el socket\n");
        exit(1);
    }

    //Lmpia la memoria
    bzero(&serveraddress, sizeof(serveraddress));

    //Establece las propiedades del servidor
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1"); //conexión IP del servidor, verificar si funciona con IPv6

    //Estableciendo el puerto
    serveraddress.sin_port = htons(PUERTO);

    //Familia de protocolos
    serveraddress.sin_family = AF_INET;

    //Estableciendo la conexión con el servidor
    connection = connect(sock_f_descriptor, (SA*)&serveraddress, sizeof(serveraddress));
    if (connection == -1){
        printf("No se ha podido conectar al servidor.\n");
        exit(1);
    }
    
    //Interactuando con el servidor
    while (1){
        bzero(mensaje, sizeof(mensaje));

        printf("Escribe el mensaje que quieres enviar al servidor: ");
        scanf("%[^\n]%*c", mensaje);

        if( strncmp(mensaje, "end", 3) == 0) {
            write(sock_f_descriptor, mensaje, sizeof(mensaje));
            printf("Cliente saliendo.\n");
            break;
        }

        //Enviando datos al servidor almacenando el número de bytes transferidos 
        ssize_t bytes = write(sock_f_descriptor, mensaje, sizeof(mensaje));

        //Si el número de bytes >= 0 entonces los datos se enviaron exitosamente
        if(bytes >= 0){
            printf("Datos enviados al servidor exitósamente.!\n");
        }

        bzero(mensaje, sizeof(mensaje));

        //Leyendo la respuesta desde el servidor
        read(sock_f_descriptor, mensaje, sizeof(mensaje));

        printf("Datos recibidos desde el servidor:\n%s", mensaje);
    }

    //Cerrando la conexión del socket
    close(sock_f_descriptor);

    return 0;
    
}