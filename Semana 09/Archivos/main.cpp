#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include "Docente.h"
#include "persona.h"
#include "rlutil.h"

int main(){
    int opc;
    do{
        rlutil::resetColor();
        rlutil::cls();
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "Menú Docentes" << endl;
        cout << "-------------" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "1 - Agregar docente" << endl;
        cout << "2 - Listar por DNI" << endl;
        cout << "3 - Listado mayores al promedio" << endl;
        cout << "4 - Listado ordenado por sueldo" << endl;
        cout << "------------------------------------" << endl;
        cout << "0 - Salir" << endl;
        cin >> opc;

        switch(opc){
            case 1:
                if (nuevoDocente() == true){
                    cout << "Docente cargado correctamente.";
                }
                else{
                    cout << "No se pudo cargar el docente correctamente";
                }
            break;
            case 2:
                listarDocentexDNI();
            break;
            case 3:
                reporteDocentePromedio();
            break;
            case 4:
                reporteSueldosOrdenado();
            break;
            case 5:
                rlutil::cls();
                listarDocentes();
            break;
            case 0:
            break;
            default:
                rlutil::locate(1, 20);
                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                cout << ">> Opción incorrecta <<";
            break;

        }
        cin.ignore();
        rlutil::anykey();

    }while(opc != 0);

    return 0;
}
