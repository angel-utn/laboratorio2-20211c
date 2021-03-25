#include <iostream>
using namespace std;

void cargar_datos(float m[][3]){
    int pais, dia;
    float importe;

    cout << "País: ";
    cin >> pais;
    while (pais < 1 || pais > 3){
        cout << "Reingrese país:";
        cin >> pais;
    }
    while(pais != -1){
        cout << "Día: ";
        cin >> dia;
        cout << "Importe: $";
        cin >> importe;
        m[dia-1][pais-1] += importe;
        cout << "País: ";
        cin >> pais;
    }
}
void puntoA(float m[][3], const int F, const int C){
    int i, j;
    for(i=0; i<C; i++){
        cout << "País " << i+1 << endl;
        for(j=0; j<F; j++){
            if (m[j][i] != 0){
                cout << "\tDía " << j+1 << ": $ " << m[j][i] << endl;
            }
        }
        cout << endl;
    }
}
void puntoB(float m[][3], const int F, const int C){
    int i, j, no_rec;
    for(i=0; i<C; i++){
        cout << "País " << i+1 << ": ";
        no_rec = 0;
        for(j=0; j<F; j++){
            if (m[j][i] == 0){
                no_rec++;
            }
        }
        cout << no_rec << endl;
    }
}
void puntoC(float m[][3], const int F, const int C){
    int i, j, cont;
    cout << "Días sin ventas en ningún país:" << endl;
    for(i=0; i<F; i++){
        cont = 0;
        for(j=0; j<C; j++){
            if (m[i][j] == 0){
                cont++;
            }
        }

        if (cont == C){
            cout << i+1 << ", ";
        }
    }
}

int main(){
    const int PAISES = 3;
    const int DIAS = 31;

    float mVentas[DIAS][PAISES] = {};
    cargar_datos(mVentas);
    cout << endl << "PUNTO A: " << endl;
    puntoA(mVentas, DIAS, PAISES);
    cout << endl << "PUNTO B: " << endl;
    puntoB(mVentas, DIAS, PAISES);
    cout << endl << "PUNTO C: " << endl;
    puntoC(mVentas, DIAS, PAISES);
    return 0;
}
