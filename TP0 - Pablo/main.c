/*
TP0  –  2018

Título: Un escáner elemental

Grupo N° 03

Apellido y Nombre	            E-mail	                    Legajo 
-----------------------------------------------------------------------
MARIÑO AUGUSTO 	                augusto.8121@gmail.com	    159.754-1
MIRABILE VIOLA FERNANDO PABLO	fpmirabile@gmail.com	    153.689-8
POMPEY PABLO SEBASTIAN          pompeypablo@hotmail.com 	157.181-3
YAÑEZ AGUSTIN EMANUEL 	        agustin.y@outlook.com 	    160.039-4

*/

#include "scanner.h"
#include <stdlib.h>
#include <string.h>

// Tamaño máximo de buffer.
#define STRING_MAXSIZE 1024
#define STRING_1024 malloc(STRING_MAXSIZE*sizeof(char))

struct contadorToken{
    int identificador;
    int constante;
    int error;
}contadorToken;

void string_append(char** original, char* string_to_add) {
	*original = realloc(*original, strlen(*original) + strlen(string_to_add) + 1);
	strcat(*original, string_to_add);
}

int main () {
    char *input = STRING_1024;
    char *cadena = strdup("");

    contadorToken.identificador = 0;
    contadorToken.constante = 0;
    contadorToken.error = 0;
    pos = 0;


    while(scanf("%s", input) != EOF){
        string_append(&cadena, input);
        string_append(&cadena, "\n");
    }
    printf("\n");

    while(cadena[pos] != '\0'){
        switch(scanner(cadena)){
            case INDENTIFICADOR:
                printf("Identificador\n");
                contadorToken.identificador++;
                break;
            case CONSTANTE:
                printf("Constante Entera\n");
                contadorToken.constante++;
                break;
            case ERROR:
                printf("Error\n");
                contadorToken.error++;
                break;
            default:
                break;
        }
    }

    printf("----\nTotales:\n");
    printf("Identificadores %d\n", contadorToken.identificador);
    printf("Constantes enteras %d\n", contadorToken.constante);
    printf("Errores %d\n", contadorToken.error);

    return(0);
}
