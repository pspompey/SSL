#include <string.h>

static char *diccionario[1000];
static int indice_diccionario = 0;

void registrarIdentificador(char *identificador) {
	diccionario[indice_diccionario] = identificador;
	indice_diccionario++;
}

int existeIdentificador(char *identificador) {
	int i;
	for (i = 0; i < indice_diccionario; i++) {
		if (strcmp(diccionario[i], identificador) == 0) {
			return 1;
		}
	}
	return 0;
}
