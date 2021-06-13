/*Programa del servidor de socket*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>

#define LONGITUD_MENSAJE 1024 //Máximo número de datos a transferir
#define PUERTO 5000 // número de puerto
#define SA struct sockaddr // Creando macro para socketaddr como SA

struct sockaddr_in serveraddress, client;
socklen_t length;

int sockert_file_descriptor, connection, bind_status, connection_status;
char message[LONGITUD_MENSAJE];

int main(int argc, char *argv[]){

    //creando el socket
    sockert_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(sockert_file_descriptor == -1){
        printf("Falló la creación del socket.!\n");
        exit(1);
    } 

    //Limpiando la memoria
    bzero(&serveraddress, sizeof(serveraddress));

    //Propiedades del servidor
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);

    //Estableciendo el número de puerto
    serveraddress.sin_port = htons(PUERTO);

    //Familia de protocolos
    serveraddress.sin_family = AF_INET;

    // Binding the newly created socket with the given Ip Address
    bind_status = bind(sockert_file_descriptor, (SA*)&serveraddress, sizeof(serveraddress));

    if(bind_status == -1){
        printf("Socket binding failed.!\n");
        exit(1);
    }

    //Server escuchando para nueva conexión
    connection_status = listen(sockert_file_descriptor, 5);
    if(connection_status == -1){
        printf("Socket no está disponible para nuevas conexiones!\n");
        exit(1);
    }else{
        printf("Servidor escuchando para nuevas conexiones \n");
    }

    length = sizeof(client);
    connection = accept(sockert_file_descriptor, (SA*)&client, &length);

    if(connection == -1){
        printf("Servidor no disponible para aceptar datos del cliente.!\n");
        exit(1);
    }

    //Cuando la comunicación está establecida
    while(1){
        bzero(message, LONGITUD_MENSAJE);
        read(connection, message, sizeof(message));

        if (strncmp("end", message, 3) == 0){
            printf("Client Exited.\n");
            printf("Server is Exiting..!\n");
            break;
        }

        printf("Datos recibidos del cliente: %s\n", message);

        bzero(message, LONGITUD_MENSAJE);

        printf("Escribe el mensaje que quieres enviar al cliente: ");
        scanf("%[^\n]%*c", message);

        // Sending the data to the server by storing the number of bytes transferred in bytes variable
        ssize_t bytes = write(connection, message, sizeof(message));
        
        // If the number of bytes is >= 0 then the data is sent successfully
        if(bytes >= 0){
            printf("Datos enviados al cliente exitosamente!\n");
        }
    }

    // Cerrando la conexión del socket
    close(sockert_file_descriptor);
    return 0;
}
