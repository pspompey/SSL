/*
 **        | Digito   Letra   Puntuacion   Espacio   fdc
 **   -----+---------------------------------------------
 ** INICIO |  E1       E2         E3          INICIO  -
 **     E1 |  FIN      E1         FIN         E4      -
 **     E2 |  E2       E2         FIN         FIN     -
 **     E3 |  FIN      FIN        E3          FIN     -
 **    FIN |   -        -          -           -      FIN
 **
 **  Letra -> Lowercase || Uppercase
 **  Digito -> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
 **  Puntuacion -> { ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~ }
 **  Espacio -> { tab, newline, vertical tab, form feed, carriage return, space }
 **  Lowercase -> { a b c d e f g h i j k l m n o p q r s t u v w x y z }
 **  Uppercase ->  { A B C D E F G H I J K L M N O P Q R S T U V W X Y Z }
 */


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
