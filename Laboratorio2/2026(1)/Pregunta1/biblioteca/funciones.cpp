#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "estructuras/elementoCarta.h"
#include "estructuras/carta.h"
#include "estructuras/baraja.h"
#include "funciones.h"

void crearBaraja(struct Baraja &baraja) {

    struct Carta *nuevaCarta;

    int numero;
    char palo;

    ifstream arch("CarpetaDeDatos/cartas.txt",ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo acceder al archivo cartas.txt" << endl;
        exit(1);
    }

    struct ElementoCarta elemento {};

    while (true) {
        arch >> elemento.numero;
        if (arch.eof()) break;
        arch >> elemento.palo;
        cargarCartasBaraja(baraja,elemento);
        baraja.longitud++;
    }

}

void cargarCartasBaraja(struct Baraja &baraja, struct ElementoCarta elemento) {

    struct Carta *nuevaCarta, *recorrido;

    nuevaCarta = new struct Carta;
    nuevaCarta->elemento = elemento;
    nuevaCarta->siguiente = nullptr;
    if (!baraja.inicio) {
        baraja.inicio = nuevaCarta;
        baraja.final = nuevaCarta;
    }else {
        baraja.final->siguiente = nuevaCarta;
        baraja.final = nuevaCarta;
    }

}

struct Carta *extraerCarta(struct Baraja &baraja, int posicion) {

    struct Carta *recorrido, *encontrado, *anterior;

    int i = 1;

    recorrido = baraja.inicio;
    anterior = nullptr;
    encontrado = nullptr;
    while (recorrido) {
        if (i == posicion) {
            encontrado = recorrido;
            break;
        }
        anterior = recorrido;
        recorrido = recorrido->siguiente;
        i++;
    }
    if (!encontrado) return nullptr;
    if (!anterior) baraja.inicio = recorrido->siguiente;
    else anterior->siguiente = encontrado->siguiente;
    encontrado->siguiente = nullptr;

    return encontrado;

}

void barajar(struct Baraja &baraja) {

    static int numCartas = baraja.longitud;
    int posicion;

    struct Carta *cartaEncontrada;

    posicion = 1 + rand() % numCartas;
    cartaEncontrada = extraerCarta(baraja,posicion);
    insertarAlFinal(baraja,cartaEncontrada);
    numCartas--;

}

void insertarAlFinal(struct Baraja &baraja, struct Carta *cartaEncontrada) {

    if (!baraja.inicio) {
        baraja.inicio = cartaEncontrada;
        baraja.final = cartaEncontrada;
    }else {
        baraja.final->siguiente = cartaEncontrada;
        baraja.final = cartaEncontrada;
    }

}

void destruirBaraja(struct Baraja &baraja) {

    struct Carta *recorrido, *siguiente;

    recorrido = baraja.inicio;
    siguiente = nullptr;
    while (recorrido) {
        siguiente = recorrido->siguiente;
        delete recorrido;
        recorrido = siguiente;
    }
    baraja.inicio = nullptr;
    baraja.final = nullptr;
    baraja.longitud = 0;

}

void mostrarBaraja(struct Baraja &baraja) {

    struct Carta *recorrido;

    cout << setfill('=') << setw(20) << "=" << setfill(' ') << endl;
    cout << "BARAJA ORIGINAL" << endl;
    cout << setfill('=') << setw(20) << "=" << setfill(' ') << endl;

    recorrido = baraja.inicio;
    while (recorrido) {
        cout << recorrido->elemento.numero << recorrido->elemento.palo << " ";
        recorrido = recorrido->siguiente;
    }

    cout << endl << endl;
    cout << setfill('=') << setw(20) << "=" << setfill(' ') << endl;
    cout << "BARAJADO" << endl;
    cout << setfill('=') << setw(20) << "=" << setfill(' ') << endl;

    for (int i = 0; i < baraja.longitud; i++) {
        barajar(baraja);
    }
    recorrido = baraja.inicio;
    while (recorrido) {
        cout << recorrido->elemento.numero << recorrido->elemento.palo << " ";
        recorrido = recorrido->siguiente;
    }

    cout << endl << endl;
    cout << setfill('=') << setw(20) << "=" << setfill(' ') << endl;
    cout << "LIBERAR MEMORIA" << endl;
    cout << setfill('=') << setw(20) << "=" << setfill(' ') << endl;

    destruirBaraja(baraja);
    recorrido = baraja.inicio;
    while (recorrido) {
        cout << recorrido->elemento.numero << recorrido->elemento.palo << " ";
        recorrido = recorrido->siguiente;
    }

}
