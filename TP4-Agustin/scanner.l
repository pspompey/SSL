%top{
#include <stdio.h>
#include <strings.h>
#include "parser.h"
}
%{

char buffer[100];

%}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option yylineno
%option noinput
%option nounput
%option noyywrap

digito [0-9]
constante {digito}+
letra [a-zA-Z]
opAditivo \+|-
opMultiplicativo \*|\/
caracterPuntuacion \(|\)|,|;
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
{opAditivo}                         {return OPADITIVO;}              
{opMultiplicativo}                  {return OPMULTIPLICATIVO;}        
{caracterPuntuacion}                {return PUNTUACION;}
[[:space:]]+ ;
\/{2}.*\n ;
{identificador} { yylval = strdup(yytext); return IDENTIFICADOR;}
{constante}     { yylval = strdup(yytext); return CONSTANTE;}
\<-              {return ASIGNACION;}

{constante}{identificador}+ { yylexerrs++; 
                                      strcpy(buffer, "Error léxico: Constante con Sufijo Invalido: ");
                                      strcat(buffer, yytext);
                                      yyerror(buffer); }
{identificador}{caracter_invalido}({caracter_invalido}|({letra}({letra}|{digito})*)|{constante})* { yylexerrs++; 
                                                                       strcpy(buffer, "Error léxico: Identificador Invalido: ");
                                      								   strcat(buffer, yytext);
                                                                       yyerror(buffer); }
{caracter_invalido}+ { yylexerrs++; 
               strcpy(buffer, "Error léxico: Cadena Desconocida: ");
               strcat(buffer, yytext);
               yyerror(buffer); }
%%