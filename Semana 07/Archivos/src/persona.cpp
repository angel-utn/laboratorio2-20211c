#include <iostream>
using namespace std;
#include <cstring>
#include "persona.h"

        Persona::Persona(){
            _edad = 0;
            strcpy(_apenom, "NN");
        }
        int Persona::getEdad(){
            return _edad;
        }
        char * Persona::getApenom(){
            return _apenom;
        }
        char * Persona::getDni(){
            return _dni;
        }
        void Persona::setDni(char *dni){
            strcpy(_dni, dni);
        }
        void Persona::setEdad(int e){
            _edad = e;
        }
        void Persona::setApenom(char *ap){
            strcpy(_apenom, ap);
        }
        void Persona::cargar(){
            cout << "DNI: ";
            cin >> _dni;
            cout << "Edad: ";
            cin >> _edad;
            cin.ignore();
            cout << "Apellido y nombres: ";
            cin.getline(_apenom, 50);

        }
        void Persona::mostrar(){
            cout << "DNI    : " << _dni << endl;
            cout << "Edad: " << _edad << endl;
            cout << "Apellido y nombres: " << _apenom << endl;
       }
