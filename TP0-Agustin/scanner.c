#include "scanner.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

Valor detectar()
{
    Valor resultado;
    Estado estado = INICIO;
while(estado != FIN && EOF != (c=getchar())){
        switch(estado){
        case INICIO :

            if(ispunct(c))
            {
                resultado = error;
                estado = E3;
            }
            else
            {
                if(isdigit(c))
                {
                    resultado = constanteEntero;
                    estado = E1;
                }
                else
                {
                    if(isalpha(c))
                    {
                        resultado = identificador;
                        estado = E2;
                    }
                }

            }
            break;
        case E1:
            if(isdigit(c))
            {
                estado = E1;
            }
            else
            {
                estado = FIN;
            }
            break;
        case E2:
            if(isalnum(c))
            {
                estado = E2;
            }
            else
            {
                estado = FIN;
            }
            break;
        case E3:
            if(isspace(c) || isalnum(c))
            {
                estado = FIN;
            }
            else
            {
                estado = E3;
            }
        case FIN:
            estado = FIN;
            break;
        default:
            printf("fallo");
            break;
        }
    }

        return resultado;


    }
