#include <iostream>
using namespace std;
#include "alumno.h"

    Alumno::Alumno(){
        _legajo = 0;
    }
    void Alumno::setLegajo(int l){
        _legajo = l;
    }
    int Alumno::getLegajo(){
        return _legajo;
    }


    void Alumno::cargar(){
        Persona::cargar();
        cout << "Legajo : ";
        cin >> _legajo;
    }
    void Alumno::mostrar(){
        Persona::mostrar();
        cout << "Legajo : " << _legajo << endl;
    }
