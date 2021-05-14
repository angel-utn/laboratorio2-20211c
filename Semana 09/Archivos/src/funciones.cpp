#include "funciones.h"

bool soloNumeros(const char *cadena){
    int i=0;
    while(cadena[i] != '\0'){
        if(!(cadena[i] >= '0' && cadena[i] <= '9')){
            return false;
        }
        i++;
    }
    return true;
}
