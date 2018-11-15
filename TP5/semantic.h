#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

extern int semantic_error_count;

void inicioPrograma();
void finPrograma();

int declararIdentificador(char *identificador);

void leerIdentificador(char *identificador);
void escribirIdentificador(char *identificador);

char * generarVariableTemporal();

int validarIdentificadorDeclarado(char *identificador);

char * invertir(char *identificador);
char * multiplicar(char *factorUno, char *factorDos);
char * dividir(char* dividendo, char* divisor);
char * restar(char* minuendo, char* sustraendo);
char * sumar(char* sumandoUno, char* sumandoDos);
void asignar(char* identificador, char* valor);

#endif
