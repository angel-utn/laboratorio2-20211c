#include <cstring>
#include <iostream>
using namespace std;
#include "Alumno.h"

Alumno::Alumno()
{
    //ctor
}
void Alumno::setLegajo(int legajo){
    _legajo = legajo;
}
void Alumno::setApenom(char *apenom){
    strcpy(_apenom, apenom);
}
int Alumno::getLegajo(){
    return _legajo;
}
char * Alumno::getApenom(){
    return _apenom;
}
void Alumno::mostrar(){
    cout << _apenom << " (" << _legajo << ")" << endl;
    _inscripcion.mostrar();

}
void Alumno::setFechaInscripcion(Fecha inscripcion){
    _inscripcion = inscripcion;
}
Fecha Alumno::getFechaInscripcion(){
    return _inscripcion;
}


