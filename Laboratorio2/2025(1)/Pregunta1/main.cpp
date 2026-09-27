#include <iostream>

using namespace std;

#include "biblioteca/funciones.h"
#include "biblioteca/estructuras/lista.h"

int main() {

    struct Lista lista {};

    insertarElemento(lista);
    insertarElemento(lista);
    insertarElemento(lista);
    insertarElemento(lista);

    cout << "Lista Inicial: " << endl;
    imprimirLista(lista);
    ordenarLista(lista);
    cout << "\nLista Inicial: " << endl;
    imprimirLista(lista);

    return 0;
}
