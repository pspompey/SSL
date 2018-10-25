#include <stdio.h>
#include "parser.h"

int main() {

	switch( yyparse() ){
	case 0:
		printf("Compilación terminada con éxito\n");
		printf("Errors sintácticos: 0 - Errores léxicos: 0\n");
		return 0;
	case 1:
		printf("Errores de compilación\n");
		printf("Errors sintácticos: %d - Errores léxicos: %d\n", yynerrs, lexem_error_count);
		return 1;
	case 2:
		printf("Memoria insuficiente\n"); 
		return 2;
	}
	return 0;
}
