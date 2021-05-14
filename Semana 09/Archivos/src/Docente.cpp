#include <iostream>
using namespace std;
#include <cstring>
#include "Docente.h"
#include "rlutil.h"
#include "funciones.h"

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

/* Funciones globales */

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
bool nuevoDocente(){
    rlutil::cls();
    int edad;
    char apenom[50];
    char dni[11];
    char titulo[100];
    float sueldo;

    cout << "DNI: ";
    cin >> dni;
    if (buscarDocente(dni) >= 0){
        return false;
    }
    if (soloNumeros(dni) == false){
        return false;
    }
    cout << "Apellido y nombres: ";
    cin.ignore();
    cin.getline(apenom, 50);

    cout << "Edad: ";
    cin >> edad;

    cout << "Título: ";
    cin.ignore();
    cin.getline(titulo, 100);

    cout << "Sueldo: $";
    cin >> sueldo;

    Docente reg;
    reg.setDni(dni);
    reg.setApenom(apenom);
    reg.setEdad(edad);
    reg.setTitulo(titulo);
    reg.setSueldo(sueldo);

    return reg.guardarEnDisco();
}

void listarDocentexDNI(){
    rlutil::cls();
    int pos;
    char dni[11];

    cout << "DNI: ";
    cin >> dni;
    if (soloNumeros(dni) == false){
        cout << "DNI con formato incorrecto";
        return;
    }
    pos = buscarDocente(dni);
    if (pos == -1){
        cout << "DNI inexistente";
        return;
    }
    Docente reg;
    reg.leerDeDisco(pos);
    cout << endl << endl;
    reg.mostrar();
}

float promedioSueldos(Docente *vec, int tam){
    int i;
    float suma = 0;
    for(i=0; i<tam; i++){
        suma += vec[i].getSueldo();
    }
    return suma/tam;
}
void leerDocentes(Docente *vec, int tam){
    for(int i=0; i<tam; i++){
        vec[i].leerDeDisco(i);
    }
}
void reporteDocentePromedio(){
    rlutil::cls();

    int cant = contarDocentes();
    Docente *vec;

    if (cant == 0)
        return;
    vec = new Docente[cant];
    if (vec == NULL)
        return;

    leerDocentes(vec, cant);

    float promedio = promedioSueldos(vec, cant);
    int i;
    cout << "Sueldo promedio: $" << promedio << endl << endl;
    cout << "Docentes con sueldo mayor al promedio" << endl;
    for(i=0; i<cant; i++){
        if (vec[i].getSueldo() > promedio){
            cout << vec[i].getApenom() << endl;
        }
    }

    delete vec;
}

void ordenarDocentes(Docente *vec, int tam){
    int i, j, posMax;

    for(i=0; i<tam-1; i++){
        posMax = i;
        for(j=i+1; j<tam; j++){
            if (vec[j].getSueldo() > vec[posMax].getSueldo()){
                posMax = j;
            }
        }
        Docente aux = vec[i];
        vec[i] = vec[posMax];
        vec[posMax] = aux;
    }
}

void reporteSueldosOrdenado(){
    rlutil::cls();
    Docente *vec;
    int cant = contarDocentes(), i;
    vec = new Docente[cant];
    if (vec == NULL)
        return;
    leerDocentes(vec, cant);
    ordenarDocentes(vec, cant);
    cout << "Docentes ordenados por sueldo" << endl;
    cout << "-----------------------------" << endl;
    for(i=0; i<cant; i++){
        rlutil::locate(1, 3+i);
        cout << vec[i].getApenom() << " ";
        rlutil::locate(20, 3+i);
        cout << "$ " << vec[i].getSueldo() << endl;
    }

    delete vec;
}

