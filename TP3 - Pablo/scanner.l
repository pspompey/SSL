%top{
#include <stdio.h>
#include "tokens.h"
}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput
%option noyywrap
%option yylineno

digito [0-9]
constante {digito}+
letra [a-zA-Z]
identificador {letra}({letra}|{digito})*	
caracter_invalido [[:punct:]]{-}[+/*(),.-]
%%
programa {return PROGRAMA;}
variables {return VARIABLES;}
definir {return DEFINIR;}
codigo {return CODIGO;}
leer {return LEER;}
escribir {return ESCRIBIR;}
fin {return FIN;}
\+ {return '+';}
\- {return '-';}
\/ {return '/';}
\* {return '*';}
\( {return '(';}
\) {return ')';}
\, {return ',';}
\. {return '.';}

[[:space:]]+ ;
\/{2}.*\n ;
{identificador} { ids++; return IDENTIFICADOR; }
{constante}     { ctes++; return CONSTANTE; }
\<-              {return ASIGNACION;}

{constante}{identificador}+ {
				printf("Error léxico: constante inválida: %s\n", yytext); 
                        	errores++;
                            }
{identificador}{caracter_invalido}({caracter_invalido}|{identificador}|{constante})* {
				printf("Error léxico: identificador inválido: %s\n", yytext);
                        	errores++;
                            }
{caracter_invalido}+ {	
			printf("Error léxico: cadena desconocida: %s\n", yytext);
                        errores++;
                     }
%%

