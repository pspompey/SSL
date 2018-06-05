#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main()
{
    int cantIdentificador = 0;
    int cantConstanteEntera = 0;
    int cantError = 0;
    c = 0;
    while(10 != c){
        Valor resultado = detectar();
            if(identificador == resultado){
                printf("Identificador \n");
                cantIdentificador++;
            }
            if(constanteEntero == resultado){
                printf("Constante Entera \n");
                cantConstanteEntera++;
            }
            if(error == resultado){
                    printf("Error \n");
                    cantError++;
            }

   }
    printf("---\n");
    printf("Totales: \n");
    printf("Identificador %i\n" , cantIdentificador);
    printf("Constante Entera  %i\n" , cantConstanteEntera);
    printf("Errores %i\n" , cantError);
    return 0;
}
