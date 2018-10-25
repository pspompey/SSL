%code top{
#include <stdio.h>
#include "scanner.h"
}

%code provides{

void yyerror(const char *msg);

extern int yylexerrs;
extern int yynerrs;

}

// -- Declaraciones --

%defines "parser.h"
%output "parser.c"

%token PROGRAMA VARIABLES DEFINIR CODIGO LEER ESCRIBIR FIN OPADITIVO OPMULTIPLICATIVO PUNTUACION IDENTIFICADOR CONSTANTE ASIGNACION
%define parse.error verbose
%define api.value.type {char*}

%start inicio
%left '+' '-'
%left '/' '*'
%precedence NEG

%%// -- Reglas gramaticales --

inicio : programa { if (yynerrs || yylexerrs) YYABORT; }

programa : PROGRAMA listaSentencias FIN
        ;

listaSentencias : VARIABLES declaraciones CODIGO sentencias
                ;

declaraciones : DEFINIR IDENTIFICADOR '.' restoDeclaraciones 
              | error '.'
              ;

restoDeclaraciones : DEFINIR IDENTIFICADOR '.' restoDeclaraciones {printf("%s\n", "asignacion");}
                   | %empty
		   ;

sentencias : sentencia '.' restoSentencias
           ;

restoSentencias : sentencia '.' restoSentencias
			    | %empty
				;

sentencia : IDENTIFICADOR ASIGNACION expresion '.' {printf("%s\n", "asignacion");}
		  | LEER '(' listaIDENTIFICADORes ')' '.' {printf("%s\n", "leer");}
		  | ESCRIBIR '(' listaExpresiones ')' '.' {printf("%s\n", "escribir");}
		  |error '.'
		  ;

listaIDENTIFICADORes : IDENTIFICADOR bucleId
					 ;

bucleId : ',' IDENTIFICADOR bucleId
	     | %empty
		 ;

listaExpresiones : expresion bucleExp
				 ;

bucleExp : ',' expresion bucleExp 
		 | %empty
		 ;

expresion : termino 
		  | expresion OPADITIVO termino
		  ;

termino : factor
        | termino OPMULTIPLICATIVO factor
		|  '-'  factor
		;

factor : IDENTIFICADOR
       | CONSTANTE 
	   | '(' expresion ')'
	   ;

%%