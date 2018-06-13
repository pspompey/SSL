/*
TP0  –  2018

Título: Un escáner elemental

Grupo N° 03

Apellido y Nombre               E-mail                      Legajo 
-----------------------------------------------------------------------
MARIÑO AUGUSTO                  augusto.8121@gmail.com      159.754-1
MIRABILE VIOLA FERNANDO PABLO   fpmirabile@gmail.com        153.689-8
POMPEY PABLO SEBASTIAN          pompeypablo@hotmail.com     157.181-3
YAÑEZ AGUSTIN EMANUEL           agustin.y@outlook.com       160.039-4

*/

#include "scanner.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct contadorToken{
    int identificador;
    int constante;
    int error;
}contadorToken;

int main () {
    Token token;

    contadorToken.identificador = 0;
    contadorToken.constante = 0;
    contadorToken.error = 0;

    while((token = scanner()) != FDT){
        switch(token){
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
