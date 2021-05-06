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
bool Docente::guardarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("docentes.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, sizeof(Docente)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Docente), 1, p);
    fclose(p);
    return guardo;
}
bool Docente::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("docentes.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, sizeof(Docente)*pos, SEEK_SET);
    lectura = fread(this, sizeof(Docente), 1, p);
    fclose(p);
    return lectura;
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
int contarDocentes(){
    int bytes, cr;
    FILE *p;
    p = fopen("docentes.dat", "rb");
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Docente);
    fclose(p);
    return cr;
}
int buscarDocente(char *dni){
    Docente reg;
    int i = 0;
    while(reg.leerDeDisco(i)){
        if (strcmp(dni, reg.getDni()) == 0){
            return i;
        }
        i++;
    }
    return -1;
}
