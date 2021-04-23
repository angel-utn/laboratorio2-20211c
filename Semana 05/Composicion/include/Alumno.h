#ifndef ALUMNO_H
#define ALUMNO_H
#include "Fecha.h"

class Alumno
{
    public:
        Alumno();
        int getLegajo();
        char * getApenom();
        void setLegajo(int);
        void setApenom(char *);
        void mostrar();
        void setFechaInscripcion(Fecha);
        Fecha getFechaInscripcion();

    private:
        int _legajo;
        char _apenom[100];
        Fecha _inscripcion;
};

#endif // ALUMNO_H
