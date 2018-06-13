/*
 **        |	Letra    Digito	 			Error				Espacio     EOF
 **   -----+-----------------------------------------------------
 **      0 |   	1        2          	3            0        100
 **      1 |   	1        1          	4            4         4
 **      2 |   	5        2          	5            5         5
 **     3+ |   	6        6          	3            6         6
 **     4+ |   	-        -          	-            -         -
 **     5+ |   	-        -          	-            -         -
 **     6+ |   	-        -          	-            -         -
 **   100+ |   	-        -          	-            -         -
 **
 **  Letra -> Lowercase | Uppercase
 **  Digito -> 0..9
 **  Error -> ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
 **  Espacio -> tab | newline | vertical tab | form feed | carriage return | space
 **  Lowercase -> a..z
 **  Uppercase ->  A..Z
 */
#include "scanner.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int input;

int columna(int c){
	if(isalpha(c)) return 0;
	else if(isdigit(c))return 1;
	else if(isspace(c))return 3;
	else if (c == EOF) return 4;
	else return 2;
}

int estadoFinal(int e){
	switch(e){
		case 0: case 1: case 2: case 3:
			return 0;
	}
	return 1;
}

Token scanner (){
	Token token;
	int estadoActual = 0;
	static int tablaTT[4][5] = {{1, 2, 3, 0, 100},
															{1, 1, 4, 4, 4},
															{5, 2, 5, 5, 5},
															{6, 6, 3, 6, 6}};

	do{
		input = getchar();
		estadoActual = tablaTT[estadoActual][columna(input)];
	}while(!estadoFinal(estadoActual));

	switch(estadoActual){
		case 4:
			token = INDENTIFICADOR;
			break;
 		case 5:
			token = CONSTANTE;
			break;
		case 6:
			token = ERROR;
			break;
		case 100:
    	token = FDT;
     	break;
		default:
			break;
	}
	ungetc(input, stdin);

	return token;
}
