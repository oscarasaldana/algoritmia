#include <iostream>

using namespace std;

#include "recursion.h"

#define NoEncontrado (-1)

int buscarAveCandidata(int (*aviario)[columna], int posFila, int posColumna, int contador) {

    if (posFila > fila or posColumna > columna) return NoEncontrado;

    if (contador == 10) return posColumna;

    if (aviario[posFila][posColumna] != 0) {
        if (posFila < fila) return buscarAveCandidata(aviario,posFila + 1,posColumna,contador + 1);
        else return buscarAveCandidata(aviario,0,posColumna + 1,0);
    }else {
        return buscarAveCandidata(aviario,0,posColumna + 1,0);
    }

}

void buscarAveAncestral(int (*aviario)[columna], int posColumna, int aveCandidata, int contador) {

    if (posColumna >= columna) {
        if (contador != 9) cout << "No existe ave ancestral en este aviario" << endl;
        else cout << "El ave ancestral se encuentra en la posicion " << aveCandidata << endl;
        return;
    }

    if (aviario[aveCandidata][posColumna] == 0) contador++;
    buscarAveAncestral(aviario,posColumna + 1,aveCandidata,contador);

}
