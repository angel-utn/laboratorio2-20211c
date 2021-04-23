#include <iostream>
using namespace std;
#include "Docente.h"
#include "persona.h"
#include "alumno.h"

int main()
{
    /*Alumno obj;
    obj.cargar();
    cout << endl;
    obj.mostrar();*/
    Docente obj;
    obj.cargar();
    cout << endl << endl;
    obj.mostrar();

    return 0;
}
