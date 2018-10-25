%{
#include <stdio.h>
#include "scanner.h"
%}

%defines "parser.h"
%output "parser.c"
%define parse.error verbose


%code provides {
	extern int yynerrs;
	extern int lexem_error_count;
	void yyerror(const char *);
}
%define api.value.type {char *}

%token PROGRAMA VARIABLES DEFINIR CODIGO LEER ESCRIBIR FIN IDENTIFICADOR CONSTANTE ASIGNACION

%left '-' '+'
%left '*' '/'
%precedence NEG

%%

programa : PROGRAMA cuerpoPrograma FIN { if (yynerrs > 0 || lexem_error_count > 0) YYABORT; }
   ;

cuerpoPrograma : VARIABLES listaDeclaraciones CODIGO listaSentencias
               ;

listaDeclaraciones : listaDeclaraciones declaracion
                   | declaracion
                   ;

declaracion : DEFINIR IDENTIFICADOR '.' { printf("definir %s\n", $2); }
	    | error '.'
      ;

listaSentencias : listaSentencias sentencia
                | sentencia
                ;

sentencia : IDENTIFICADOR ASIGNACION expresion '.' { printf("asignación\n"); }
          | LEER '(' listaIdentificadores ')'  '.' { printf("leer\n"); }
          | ESCRIBIR '(' listaExpresiones ')'  '.' { printf("escribir\n"); } 
	  			| error '.'
          ;

listaIdentificadores : listaIdentificadores ',' IDENTIFICADOR
		     						 | IDENTIFICADOR
                     ;

listaExpresiones : listaExpresiones ',' expresion
		 						 | expresion
                 ;

expresion :	  expresion '+' expresion	{ printf("suma\n"); }
		| expresion '-' expresion	{ printf("resta\n"); }
		| expresion '/' expresion	{ printf("división\n"); }
		| expresion '*' expresion	{ printf("multiplicación\n"); }
		| '-' expresion			{ printf("inversión\n"); } %prec NEG
		| '(' expresion ')' 		{ printf("paréntesis\n"); }
		| IDENTIFICADOR
		| CONSTANTE
		;

%%
int lexem_error_count = 0;
void yyerror(const char *msg) {
	printf("línea #%d: %s\n", yylineno, msg);
}
