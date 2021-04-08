#include <iostream>
using namespace std;

class Auto{
    private:
        float velocidad;
    public:
        void acelerar(float);
        void desacelerar(float);
        void frenar();
        //Getters
        float getVelocidad();
        //Setters
};

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
    Auto coche, autito;

    coche.acelerar(10);
    coche.acelerar(30);

    coche.desacelerar(15);
    coche.desacelerar(15);
    coche.desacelerar(15);

    autito.acelerar(100);


    cout << coche.getVelocidad() << endl;
    cout << autito.getVelocidad() <<endl;
}
