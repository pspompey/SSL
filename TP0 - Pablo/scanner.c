/*
 **        | Letra   Digito   Puntuacion     Espacio    fdc
 **   -----+------------------------------------------------
 **     E0 |  E1       E2         E3           E0       E99
 **     E1 |  E1       E1         E99          E99      E99
 **     E2 |  E99      E2         E99          E99      E99
 **     E3 |  E99      E99        E3           E99      E99
 **
 **  Letra -> Lowercase | Uppercase
 **  Digito -> 0..9
 **  Puntuacion -> ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
 **  Lowercase -> a..z
 **  Uppercase ->  A..Z
 */

#include "scanner.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum Estado{
	E0,
	E1,
	E2,
	E3,
	E99
}Estado;

int input;

int columna(int c){
	if(isalpha(c)) return 0;
	else if(isdigit(c))return 1;
	else if(isspace(c))return 3;
	else if (c == EOF) return 4;
	else return 2;
}

Token scanner (){
    Token token;
	Estado estadoActual = E0;
	static Estado tablaTT[4][5] = {{E1, E2, E3, E0, E99},
								   {E1, E1, E99, E99, E99},
								   {E99, E2, E99, E99, E99},
								   {E99, E99, E3, E99, E99}};

	do{
    input = getchar();
    estadoActual = tablaTT[estadoActual][columna(input)];
    switch(estadoActual){
        case E1:
            token = INDENTIFICADOR;
			break;
        case E2:
			token = CONSTANTE;
			break;
		case E3:
			token = ERROR;
			break;
		default:
			break;
		}

	}while(estadoActual != E99);

    ungetc(input, stdin);
	if(input == EOF){
		token = FDT;
    }

    return token;
}
