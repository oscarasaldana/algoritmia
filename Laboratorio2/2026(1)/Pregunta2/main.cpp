#include <iostream>

using namespace std;

#include "biblioteca/recursion.h"

int main() {

    /*==================================================================================================
       1. Cambie los numeros que indican la cantidad de genes que le comparte un ave a otra diferente
          por 1 por comodidad, esto no afecta en nada a la solucion del problema.

       2. Cambie los 100% de genes que le trasmite una ave a otra que es de su misma especie por 5
          por la misma razon que el item 1.
      ===================================================================================================*/

    int aviario[fila][columna] = {
        {5, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 5, 0, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 5, 0, 0, 0, 1, 1, 1, 0},
        {1, 0, 0, 5, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 5, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 5, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 5, 1, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 5, 1},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 5}
    };

    int aveAncestral = 0, aveCandidata = 0;

    aveCandidata = buscarAveCandidata(aviario,0,0,0);
    buscarAveAncestral(aviario,0,aveCandidata,0);

    return 0;
}
