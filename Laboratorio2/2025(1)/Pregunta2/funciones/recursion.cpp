#include <iostream>

using namespace std;

#include "recursion.h"

void recursion(int (*mina)[columna], int posFila, int posColumna, int combustible, int i) {

    if (combustible < 0 or posColumna < 0) return;

    if (mina[posFila][posColumna] == 2) {
        i = -1;
    }else {
        for (int a = posFila; a < fila; a++) {
            if (mina[a][posColumna] == 1) {
                cout << "Oro " << a << " " << posColumna << endl;
                break;
            }
        }
        for (int a = posFila; a >= 0; a--) {
            if (mina[a][posColumna] == 1) {
                cout << "Oro " << a << " " << posColumna << endl;
                break;
            }
        }
        for (int a = posColumna; a >= 0; a--) {
            if (mina[posFila][a] == 1) {
                mina[posFila][a] = 0;
                cout << "Oro " << posFila << " " << a << endl;
                break;
            }
        }
    }
    recursion(mina,posFila,posColumna + i,combustible - 1,i);

}
