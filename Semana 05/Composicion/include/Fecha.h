#ifndef FECHA_H
#define FECHA_H

class Fecha
{
    public:
        Fecha();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        int getDia();
        int getMes();
        int getAnio();
        void mostrar();

    private:
        int _dia, _mes, _anio;
};

#endif // FECHA_H
