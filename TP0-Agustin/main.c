/*
TP0  –  2018

Título: Un escáner elemental

Grupo N° 03

Apellido y Nombre	            E-mail	     		        Legajo 
-----------------------------------------------------------------------
MARIÑO AUGUSTO			        augusto.8121@gmail.com	    159.754-1
MIRABILE VIOLA FERNANDO PABLO	fpmirabile@gmail.com	    153.689-8
POMPEY PABLO SEBASTIAN		    pompeypablo@hotmail.com     157.181-3
YAÑEZ AGUSTIN EMANUEL		    agustin.y@outlook.com 	    160.039-4

*/
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main()
{
    int cantIdentificador = 0;
    int cantConstanteEntera = 0;
    int cantError = 0;
    c = 0;
    while(EOF != c){
        Valor resultado = detectar();
            if(identificador == resultado){
                printf("Identificador \n");
                cantIdentificador++;
            }
            if(constanteEntero == resultado){
                printf("Constante Entera \n");
                cantConstanteEntera++;
            }
            if(error == resultado){
                    printf("Error \n");
                    cantError++;
            }

   }
    printf("---\n");
    printf("Totales: \n");
    printf("Identificador %i\n" , cantIdentificador);
    printf("Constante Entera  %i\n" , cantConstanteEntera);
    printf("Errores %i\n" , cantError);
    return 0;
}
