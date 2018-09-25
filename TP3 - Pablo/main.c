#include <stdio.h>
#include "scanner.h"

int main() {
	errores = 0;
	ids = 0;
	ctes = 0;

	enum token t;
	while ((t = yylex())){
	switch(t){
            case IDENTIFICADOR:
                printf("Token: Identificador	lexema: %s\n", yytext);
                break;
            case CONSTANTE:
                printf("Token: Constante	lexema: %s\n", yytext);
                break;
            default:
                printf("Token: %s\n", yytext);
                break;
	}
	}
	puts("-------totales-------");
	printf("Identificadores: %d\nConstantes: %d\nErrores: %d\n", ids, ctes, errores);
	return 0;
}
