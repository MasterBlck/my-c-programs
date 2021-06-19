/*Programa para checar si una palabra clave está dentro de una cadena*/
#include <stdio.h>

int str_include(char* input, char* key);
int length(char* str);

int main(int argc, char const *argv[]){
    //inputs
    char *entrada = "Hola esto es una cadena para comparar";
    char *clave = "cadena";

    printf("%d\n", str_include(entrada, clave));
    if ( str_include(entrada, clave) ){
        printf("La palabra %s está dentro de la entrada\n", clave);
    }else{
        printf("La palabra %s NO está dentro de la entrada\n", clave);
    }
    
    return 0;
}

int str_include(char* input, char* key){
    int length_input = length(input);
    int length_key = length(key);
    int i=0, j=0;
    
    while (i < length_input){
        if( input[i] == key[j] && j < length_key ){
            j++;
            if( key[j] == '\0' && (input[i+1] == ' ' || input[i+1] == '\0'))
                return 1; //la palabra key es igual
        } else {
            j = 0;
        }

        i++;
    }
    return 0;
}

int length(char* str){
    int i=0;

    while (*(str+i) != '\0') i++;
    return i;
}
