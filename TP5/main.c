/*
TP5  –  2018
Título: Compilador Completo
Grupo N° 03
Apellido y Nombre               E-mail                      	Legajo 
--------------------------------------------------------------------------
POMPEY PABLO SEBASTIAN          pompeypablo@hotmail.com     	157.181-3
YAÑEZ AGUSTIN EMANUEL           agustin.y@outlook.com      	160.039-4
MONTI PABLO SEBASTIAN		pmonti@est.frba.utn.edu.ar  	158.826-6
MARIÑO AUGUSTO                  augusto.8121@gmail.com      	159.754-1
*/

#include <stdio.h>
#include "parser.h"

int main(void){
	switch( yyparse() ){
	case 0:
		printf("Compilación terminada con éxito\n");
		printf("Errores sintácticos: 0 - Errores léxicos: 0 - Errores semánticos: 0\n");
		return 0;
	case 1:
		printf("Errores de compilación\n");
		printf("Errores sintácticos: %d - Errores léxicos: %d - Errores semánticos: %d\n", yynerrs, lexem_error_count, semantic_error_count);
		return 1;
	case 2:
		printf("Memoria insuficiente\n"); 
		return 2;
	}
}
