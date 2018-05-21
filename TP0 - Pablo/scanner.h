#ifndef SCANNER_H_
#define SCANNER_H_

#include <ctype.h>
#include <stdio.h>

typedef enum Token{
	ERROR,
	INDENTIFICADOR,
	CONSTANTE
}Token;

typedef enum Estado{
	E0,
	E1,
	E2,
	E3,
	FDC
}Estado;

int pos;

Token scanner (char*);

#endif /* SCANNER_H_ */
