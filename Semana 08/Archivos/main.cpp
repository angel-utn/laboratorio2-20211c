#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include "Docente.h"
#include "persona.h"

int main(){
    char dni[11];
    cout << "DNI a buscar: ";
    cin >> dni;

    int pos = buscarDocente(dni);
    if (pos >= 0){
        Docente reg;
        reg.leerDeDisco(pos);
        float sueldo;
        cout << "Ingresar nuevo sueldo: $";
        cin >> sueldo;
        reg.setSueldo(sueldo);
        reg.guardarEnDisco(pos);
        //reg.mostrar();
    }
    else{
        cout << "No existe docente";
    }

    cout << endl << endl;
    listarDocentes();
    return 0;
}
