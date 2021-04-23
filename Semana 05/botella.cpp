/*
    Inconcluso.
*/
#include <iostream>
using namespace std;

class Botella{
    public:
        Botella(float = 100);
        ~Botella();
        float getCapacidad();

    private:
        float _capacidad;
};

Botella::Botella(float capacidad){
    if (capacidad <= 0){
        _capacidad = 100;
    }
    else{
        _capacidad = capacidad;
    }
}
Botella::~Botella(){
    cout << "Dirección: " << this << " Crash: " << _capacidad << endl;
}

float Botella::getCapacidad(){
    return _capacidad;
}

int main(){
    Botella *b=nullptr;
    /*Botella c;
    cout << c.getCapacidad() << endl;
    c = Botella(500);
    cout << c.getCapacidad() << endl;
    return 0;*/
    char opcion;
    float dato;
    cout << "Desea suministrar la capacidad de la botella: ";
    cin >> opcion;

    if (opcion == 'S'){
        cout << "Ingresar capacidad: ";
        cin >> dato;
        b = new Botella[2]{Botella(),Botella(dato*2)};
        if (b == nullptr)
            return 1;
    }
    else{
        b = new Botella[2];
    }
    cout << b[0].getCapacidad() << endl;
    cout << b[1].getCapacidad() << endl;
    delete b;
    return 0;
}
