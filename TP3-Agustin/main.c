char *token_names[] = {"Fin de Archivo",
                       "Identificador",
                       "Constante", 
                       "Programa",
	               "Fin",
                       "Variables",
	               "Codigo",
                       "Definir",
                       "Leer",
                       "Escribir", 
                       "operadorAditivo", 
                       "Asignacion", 
                       "Caracter Puntuacion", 
                       "Operador Multiplicativo", 
                       "constante con sufijo invalido", 
                       "identificador invalido", 
                       "cadena desconocida"};

int main() {
    enum TOKEN t;
    while((t = yylex())){
        switch(t){
            case programa:
            case fin:
            case variables:
            case codigo:
            case definir:
            case leer:
            case escribir:
                printf("Token: %s \n",yytext);
                break;
            case asignacion:
                printf("Token: %s \n",token_names[t]);
                break;
            case identificador:
            case constante:
                printf("Token: %s \tlexema: %s\n", token_names[t],yytext);
                break;
            default:
                break;
        }
    }
    printf("Token: %s\n",token_names[t]);
    return 0;
}