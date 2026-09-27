#include <iostream>

using namespace std;

#include "biblioteca/recursion.h"

int main() {

    int mina[fila][columna] = {
        {0, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 2, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0}
    };

    int combustible = 4;

    recursion(mina,3,2,combustible,1);

    return 0;
}
