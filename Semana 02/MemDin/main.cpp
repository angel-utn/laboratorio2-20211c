#include <iostream>
using namespace std;

int main()
{
    int tam;
    cout << "Ingrese el tamaño del vector: ";
    cin >> tam;

    int *vec = NULL;
    vec = new int[tam]; // Pidiendo memoria para un vec de TAM elementos
    if (vec == NULL){
        cout << "No hay memoria. Andá a comprar.";
        return 666;
    }

    int i;
    for(i=0; i<tam; i++){
        vec[i] = 0;
    }
    delete vec;

    return 0;
}
