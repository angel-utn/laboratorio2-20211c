#include <iostream>
using namespace std;
#include <cstring>

class Auto{
    private:
        float velocidad;
        char color[30];
    public:
        Auto();
        Auto(float, char *);
        ~Auto();
        void acelerar(float);
        void desacelerar(float);
        void frenar();
        void mostrar();
        //Getters
        float getVelocidad();
};

Auto::Auto(){
    velocidad = 0;
    strcpy(color, "FUCSIA");
}
Auto::Auto(float valor, char *nombre){
    velocidad = valor;
    if (valor < 0){
        velocidad = 0;
    }
    strcpy(color, nombre);
}
Auto::~Auto(){
    cout << "Elimino el auto a " << velocidad << "km/h" << endl;
}
void Auto::mostrar(){
    cout << "Velocidad: " << velocidad << endl;
    cout << "Color    : " << color << endl;
}
void Auto::acelerar(float valor){
    if (valor > 0){
        velocidad += valor;
    }
}
void Auto::desacelerar(float valor){
    if (valor > 0){
        velocidad -= valor;

        if (velocidad < 0){
            velocidad = 0;
        }
    }
}
void Auto::frenar(){
    velocidad = 0;
}

float Auto::getVelocidad(){
    return velocidad;
}

int main(){
    Auto a;
    Auto b(100, "Negro");
    a.mostrar();
    cout << endl;
    b.mostrar();
    cout << endl;
}
