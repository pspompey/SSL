#include "scanner.h"
#include <stdlib.h>

struct contadorToken{
    int identificador;
    int constante;
    int error;
}contadorToken;

int main () {
    char *cadena = "total  123  Mesa34  @?¡<>@89640  SILLA56  *+%\n,	bien";
    contadorToken.identificador = 0;
    contadorToken.constante = 0;
    contadorToken.error = 0;
    pos = 0;

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
    printf("Constantes  enteras %d\n", contadorToken.constante);
    printf("Errores %d\n", contadorToken.error);

    return(0);
}
