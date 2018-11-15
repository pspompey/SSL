#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"
#include "parser.h"

char buffer_error[100];
int semantic_error_count;
static int indice_variable_temporal = 0;

void inicioPrograma() {
	printf("Load rtlib,\n");
}

void finPrograma() {
	printf("Stop ,\n");
}

int declararIdentificador(char *identificador) {
	if (existeIdentificador(identificador)) {
		semantic_error_count++;
		sprintf(buffer_error, "Error semántico: identificador %s ya declarado", identificador);
		yyerror(buffer_error);
		return 0;
	} else {
		registrarIdentificador(identificador);
		printf("Declare %s,Integer\n", identificador);
		return 1;
	}
}

void leerIdentificador(char *identificador) {
	printf("Read %s,Integer\n", identificador);
}

void escribirIdentificador(char *identificador) {
	printf("Write %s,Integer\n", identificador);
}

char * generarVariableTemporal() {
	indice_variable_temporal++;
	char * temp = malloc(sizeof(char) * 10);
	sprintf(temp, "Temp#%d", indice_variable_temporal);
	declararIdentificador(temp);
	return temp;
}

int validarIdentificadorDeclarado(char *identificador) {
	if (!existeIdentificador(identificador)) {
		semantic_error_count++;
		sprintf(buffer_error, "Error semántico: identificador %s NO declarado", identificador);
		yyerror(buffer_error);
		return 1;
	}
	return 0;
}

char * realizarOperacion(char* instruccion, char* variableUno, char* variableDos){
	char * temp = generarVariableTemporal();
	printf("%s %s,%s,%s\n", instruccion, variableUno, variableDos, temp);
	return temp;
}

char * invertir(char *identificador) {
	return realizarOperacion("INV", identificador, "");
}

char * multiplicar(char *factorUno, char *factorDos) {
	return realizarOperacion("MULT", factorUno, factorDos);
}

char * dividir(char* dividendo, char* divisor){
	return realizarOperacion("DIV", dividendo, divisor);
}

char * restar(char* minuendo, char* sustraendo){
	return realizarOperacion("SUBS",minuendo,sustraendo);
}

char * sumar(char* sumandoUno, char* sumandoDos){
	return realizarOperacion("ADD", sumandoUno, sumandoDos);
}

void asignar(char* identificador, char* valor){
	printf("Store %s,%s\n", valor, identificador);
}
