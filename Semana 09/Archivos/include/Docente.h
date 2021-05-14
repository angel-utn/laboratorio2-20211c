#ifndef DOCENTE_H
#define DOCENTE_H
#include "persona.h"

class Docente:public Persona
{
    public:
        Docente();
        char *getTitulo();
        float getSueldo();
        void setTitulo(char *);
        void setSueldo(float);
        void cargar();
        void mostrar();
        bool guardarEnDisco();
        bool guardarEnDisco(int);
        bool leerDeDisco(int);

    protected:
        char _titulo[100];
        float _sueldo;

};

int contarDocentes();
int buscarDocente(char *);
bool nuevoDocente();
void listarDocentexDNI();
void reporteDocentePromedio();
float promedioSueldos();
void reporteSueldosOrdenado();

#endif // DOCENTE_H
