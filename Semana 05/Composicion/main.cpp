#include <iostream>
using namespace std;
#include "Alumno.h"

int main()
{
    Fecha f;
    f.setDia(15);
    f.setMes(4);
    f.setAnio(2020);

    Alumno brian;
    brian.setLegajo(1000);
    brian.setApenom("Lara, Brian");
    brian.setFechaInscripcion(f);

    brian.mostrar();
    cout << endl;

    return 0;
}
