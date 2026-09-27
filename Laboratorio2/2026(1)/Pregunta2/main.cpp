#include <iostream>
#include <ctime>

using namespace std;

#include "biblioteca/estructuras/baraja.h"
#include "biblioteca/funciones.h"

int main() {

    srand(time(nullptr));

    struct Baraja baraja {};

    crearBaraja(baraja);
    mostrarBaraja(baraja);

    return 0;
}
