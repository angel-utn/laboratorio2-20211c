#include <iostream>
using namespace std;
#include <cstring>
#include "Docente.h"

Docente::Docente()
{
    //ctor
}

char * Docente::getTitulo(){
    return _titulo;
}
float Docente::getSueldo(){
    return _sueldo;
}
void Docente::setTitulo(char *titulo){
    strcpy(_titulo, titulo);
}
void Docente::setSueldo(float sueldo){
    _sueldo = sueldo;
}
void Docente::cargar(){
    Persona::cargar();
    cout << "Sueldo : $";
    cin >> _sueldo;
    cout << "Título: ";
    cin.ignore();
    cin.getline(_titulo, 50);
}
void Docente::mostrar(){
    Persona::mostrar();
    cout << "Sueldo : $ " << _sueldo << endl;
    cout << "Título: " << _titulo << endl;
}
bool Docente::guardarEnDisco(){
    bool guardo;
    FILE *p;
    p = fopen("docentes.dat", "ab");
    if (p == NULL){
        return false;
    }
    guardo = fwrite(this, sizeof(Docente), 1, p);
    fclose(p);
    return guardo;
}

void listarDocentes(){
    Docente obj;
    FILE *p;
    p = fopen("docentes.dat", "rb");
    if (p == NULL){
        cout << "No pude abrir el archivo.";
        return;
    }

    while(fread(&obj, sizeof(Docente), 1, p) == 1){
        obj.mostrar();
        cout << endl;
    }
    fclose(p);
}

