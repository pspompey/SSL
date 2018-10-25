/*
TP3  –  2018
Título: Escáner Flex
Grupo N° 03

Apellido y Nombre               E-mail                      	Legajo 
--------------------------------------------------------------------------
POMPEY PABLO SEBASTIAN          pompeypablo@hotmail.com     	157.181-3
YAÑEZ AGUSTIN EMANUEL           agustin.y@outlook.com      	160.039-4
MONTI PABLO SEBASTIAN		pmonti@est.frba.utn.edu.ar  	158.826-6
MARIÑO AUGUSTO                  augusto.8121@gmail.com      	159.754-1

*/
#include "scanner.h"
#include "parser.h"

int yylexerrs = 0;

int main(void)
{
	switch( (yyparse()) ){
	case 0:
		puts("Compilacion terminada con exito"); 
		printf("Errores sintácticos: %d - Errores léxicos: %d\n", yynerrs, yylexerrs);
		return 0;
	case 1:
		puts("Errores de compilacion"); 
		printf("Errores sintácticos: %d - Errores léxicos: %d\n", yynerrs, yylexerrs);
		return 1;
	case 2:
		puts("Memoria insuficiente"); 
		return 2;
	}

	return 0;
}

void yyerror(const char *msg){
	printf("línea #%d: %s\n", yylineno, msg);
	return;
}
