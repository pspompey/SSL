%{
#include <stdio.h>
#include "scanner.h"
#include "semantic.h"
%}

%defines "parser.h"
%output "parser.c"
%define parse.error verbose


%code provides {
	extern int yynerrs;
	extern int lexem_error_count;
	extern int semantic_error_count;
	void yyerror(const char *);
}
%define api.value.type {char *}

%token PROGRAMA VARIABLES DEFINIR CODIGO LEER ESCRIBIR FIN IDENTIFICADOR CONSTANTE ASIGNACION

%left '-' '+'
%left '*' '/'
%precedence NEG

%%

programa : PROGRAMA { inicioPrograma(); } cuerpoPrograma FIN { finPrograma(); if (yynerrs > 0 || lexem_error_count > 0 || semantic_error_count > 0) YYABORT; }
         ;

cuerpoPrograma : VARIABLES listaDeclaraciones CODIGO listaSentencias
               ;

listaDeclaraciones : listaDeclaraciones declaracion
                   | declaracion
                   ;

declaracion : DEFINIR IDENTIFICADOR '.' { if (!declararIdentificador($2)) YYERROR; }
            | error '.'
            ;

listaSentencias : listaSentencias sentencia
                | sentencia
                ;

sentencia : identificador ASIGNACION expresion '.' { asignar($1, $3); }
          | LEER '(' listaIdentificadores ')'  '.'
          | ESCRIBIR '(' listaExpresiones ')'  '.'  
          | error '.'
          ;

listaIdentificadores : listaIdentificadores ',' identificador { leerIdentificador($3); }
                     | identificador { leerIdentificador($1); }
                     ;

listaExpresiones : listaExpresiones ',' expresion { escribirIdentificador($3); }
                 | expresion { escribirIdentificador($1); }
                 ;

expresion :	expresion '+' expresion { $$ = sumar($1, $3); }
		      | expresion '-' expresion { $$ = restar($1, $3); }
		      | expresion '/' expresion { $$ = dividir($1, $3); }
		      | expresion '*' expresion { $$ = multiplicar($1, $3); }
		      | '-' expresion           { $$ = invertir($2); } %prec NEG
		      | '(' expresion ')'       { $$ = $2; }
		      | identificador           
		      | CONSTANTE              
		      ;

identificador : IDENTIFICADOR { $$ = $1; if (validarIdentificadorDeclarado($1)) YYERROR; } 

%%
int lexem_error_count = 0;
int semantic_error_count = 0;
void yyerror(const char *msg) {
	printf("línea #%d: %s\n", yylineno, msg);
}
