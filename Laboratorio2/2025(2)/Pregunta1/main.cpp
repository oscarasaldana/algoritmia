#include <iostream>

using namespace std;

#include "biblioteca/funciones.h"
#include "biblioteca/estructuras/lista.h"

int main() {

    struct Lista lista {};

    cargarLista(lista);

    cout << "Lista de entrada: " << endl;
    imprimirLista(lista);
    cout << endl;
    cout << "Lista de salida: " << endl;
    ordenarLista(lista);
    imprimirLista(lista);


    return 0;
}
