#ifndef SCANNER_H_
#define SCANNER_H_

typedef enum Token{
	ERROR,
	INDENTIFICADOR,
	CONSTANTE,
	FDT
}Token;

Token scanner ();

#endif /* SCANNER_H_ */
