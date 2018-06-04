#include "scanner.h"

/*
 **        | Letra   Digito   Puntuacion   Espacio   fdc
 **   -----+---------------------------------------------
 **     E0 |  E1       E2         E3          E0      -
 **     E1 |  E1       E1         E4          E4      -
 **     E2 |  E4       E2         E4          E4      -
 **     E3 |  E4       E4         E3          E4      -
 **     E4 |  --       --         --          --      E5
 **
 **  Letra -> Lowercase || Uppercase
 **  Digito -> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
 **  Puntuacion -> { ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~ }
 **  Espacio -> { tab, newline, vertical tab, form feed, carriage return, space }
 **  Lowercase -> { a b c d e f g h i j k l m n o p q r s t u v w x y z }
 **  Uppercase ->  { A B C D E F G H I J K L M N O P Q R S T U V W X Y Z }
 */

Token scanner (char* cadena){
    Token token;
    Estado estado = E0;

    while(estado != E5 && cadena[pos] != '\0'){
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
                    if(ispunct(cadena[pos])){
                        token = ERROR;
                        estado = E3;
                    }
                }
            }
            pos++;
            break;
        case E1:
            if(isalnum(cadena[pos])){
                estado = E1;
                pos++;
            }
            else{
                estado = E4;
            }
            break;
        case E2:
            if(isdigit(cadena[pos])){
                estado = E2;
                pos++;
            }
            else{
                estado = E4;
            }
            break;
        case E3:
            if(isalnum(cadena[pos]) || isspace(cadena[pos])){
                estado = E4;
            }
            else{
                estado = E3;
                pos++;
            }
            break;
        case E4:
            estado = E5;
            break;
        default:
            printf("No funcionó el scanner\n");
            break;
        }
    }
    return token;
}
