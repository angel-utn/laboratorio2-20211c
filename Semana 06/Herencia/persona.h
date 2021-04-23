#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
    protected:
        int _edad;
        char _apenom[50];
        char _dni[11];
    public:
        Persona();
        int getEdad();
        char * getApenom();
        char * getDni();
        void setEdad(int);
        void setApenom(char *);
        void setDni(char *);
        void cargar();
        void mostrar();
};

#endif // PERSONA_H_INCLUDED
