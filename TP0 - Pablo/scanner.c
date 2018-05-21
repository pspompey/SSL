/*
 * scanner.c
 *
 *  Created on: 20/5/2018
 *      Author: Pablo
 */
#include "scanner.h"

Token scanner (char* cadena){
	Token token;
	Estado estado = E0;

	while(estado != FDC && cadena[pos] != '\0'){
		switch(estado){
		case E0:
			if(isalpha(cadena[pos])){
				token = INDENTIFICADOR;
				estado = E1;
			}
			else{
				if(isdigit(cadena[pos])){
					token = CONSTANTE;
					estado = E2;
				}
				else{
					if(!isspace(cadena[pos])){
						token = ERROR;
						estado = E3;
					}
				}
			}
            pos++;
			break;
		case E1:
			if(isalpha(cadena[pos]) || isdigit(cadena[pos])){
				estado = E1;
				pos++;
			}
			else{
				estado = FDC;
			}
			break;
		case E2:
			if(isdigit(cadena[pos])){
				estado = E2;
				pos++;
			}
			else{
				estado = FDC;
			}
			break;
		case E3:
			if(isalpha(cadena[pos]) || isdigit(cadena[pos]) || isspace(cadena[pos])){
				estado = FDC;
			}
			else{
				estado = E3;
				pos++;
			}
			break;
		default:
			printf("No funcionó el scanner\n");
			break;
		}
	}
	return token;
}
