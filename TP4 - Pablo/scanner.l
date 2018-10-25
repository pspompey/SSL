%top{
#include <stdio.h>
#include "parser.h"
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
{identificador} { yylval = strdup(yytext); return IDENTIFICADOR; }
{constante}     { yylval = strdup(yytext); return CONSTANTE; }
\<-              {return ASIGNACION;}

{constante}{identificador}+ {
                               char* errorMsg = malloc(sizeof(yytext) + 100); 
                               strcpy(errorMsg,"Error léxico: constante con sufijo inválido: "); 
                               strcat(errorMsg, yytext);
                               yyerror(errorMsg); 
                               lexem_error_count++;
                            }

{identificador}{caracter_invalido}({caracter_invalido}|{letra}|{digito})* {
                               char *errorMsg = malloc(sizeof(yytext) + 100); 
                               strcpy(errorMsg,"Error léxico: identificador inválido: "); 	
                               strcat(errorMsg, yytext);
                               yyerror(errorMsg); 
                               lexem_error_count++;
                            }
{caracter_invalido}+ {	
                        char *errorMsg= malloc(sizeof(yytext) + 100);
                        strcpy(errorMsg,"Error léxico: cadena desconocida: "); 
                        strcat(errorMsg, yytext);
                        yyerror(errorMsg); 
                        lexem_error_count++;
                     }
%%

