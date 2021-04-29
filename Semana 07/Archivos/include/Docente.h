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

    protected:
        char _titulo[100];
        float _sueldo;

};



#endif // DOCENTE_H
