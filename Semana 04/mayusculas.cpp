#include <iostream>
using namespace std;
#include <cstring>

void funcion(char *texto){
    int tam = strlen(texto), pos=0;
    char *nuevaCadena = NULL;
    nuevaCadena = new char[tam+1];
    if (nuevaCadena == NULL){
        return;
    }

    strcpy(nuevaCadena, texto);
    while(nuevaCadena[pos] != '\0'){
        nuevaCadena[pos] = toupper(nuevaCadena[pos]);
        pos++;
    }
    cout << nuevaCadena << endl;
    delete nuevaCadena;
}


int main(){
    char texto[100];

    cin.getline(texto, 100);

    funcion(texto);

    cout << endl << texto;
    return 0;
}
