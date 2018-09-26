%top{
/* TP03 - 2018
*  Scanner Flex
*  
*  Grupo 03
*Pompey Pablo Sebastián	157.181-3
*Yañez Agustín Emanuel	160.039-4
*Mariño Augusto			159.754-1
*Monti Pablo Sebastián	158.826-6
*/
}
%{
#include <stdio.h>
#include "tokens.h"
%}

%option header-file="scanner.h"

%option outfile="scanner.c"
%option noinput
%option nounput
%option noyywrap

letra [a-zA-Z]
digito [0-9]
espacios [[:space:]]
invalidos [[:punct:]]{-}[:=)(,;+*/-]
comentario \/\/

%%

programa                            {return programa;}
fin                                 {return fin;}
variables                           {return variables;}
codigo                              {return codigo;}
definir                             {return definir;}
leer                                {return leer;}
escribir                            {return escribir;}
{espacios} ;
{letra}({letra}|{digito})*          {return identificador;}
{digito}+                           {return constante;}
\+ {return '+';}
\- {return '-';}
\/ {return '/';}
\* {return '*';}
\( {return '(';}
\) {return ')';}
\, {return ',';}
\. {return '.';}           
\<-                                  {return asignacion;}     
{digito}+{letra}({digito}|{letra})* {printf("Error léxico: %s: %s\n", "Constante con Sufijo Invalido",yytext); return constanteSufInvalido;}
{letra}({letra}|{digito})*{invalidos}({letra}|{digito}|{invalidos})* {printf("Error léxico: %s: %s\n", "Identificador Invalido",yytext); return identificadorInvalido;}
{comentario}.* ;
{invalidos}+ {printf("Error léxico: %s: %s\n","cadena Desconocida" ,yytext); return cadenaDesconocida;}

%%


