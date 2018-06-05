#ifndef SCANNER_INCLUDED
#define SCANNER_INCLUDED
typedef enum Valor {
identificador,
constanteEntero,
error
}Valor;

typedef enum Estado {

INICIO,
E1,
E2,
E3,
FIN

} Estado;

Valor detectar();

int c;
#endif // SCANNER_INCLUDED
