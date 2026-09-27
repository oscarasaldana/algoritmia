#include <iostream>
#include <fstream>
#include <cstring>

#include "estructuras/lista.h"

using namespace std;

#include "estructuras/elementoNodo.h"
#include "estructuras/nodo.h"
#include "funciones.h"

void cargarLista(struct Lista &lista) {

    ifstream arch("CarpetaDeDatos/jugadores.txt",ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo acceder al archivo jugadores.txt" << endl;
        exit(1);
    }

    struct ElementoNodo elemento {};

    while (true) {
        arch >> elemento.numero;
        if (arch.eof()) break;
        arch.get();
        elemento.nombre = leerCadenaCaracteres(arch,',');
        elemento.posicion = leerCadenaCaracteres(arch,'\n');
        cargarDatosJugadores(lista,elemento);
    }

}

char *leerCadenaCaracteres(ifstream &arch, char delim) {

    char cadena[30], *ptrCadena;

    arch.getline(cadena,30,delim);
    if (arch.eof()) return nullptr;
    ptrCadena = new char [strlen(cadena) + 1];
    strcpy(ptrCadena,cadena);

    return ptrCadena;

}

void cargarDatosJugadores(struct Lista &lista, struct ElementoNodo elemento) {

    struct Nodo *nuevoNodo {};

    nuevoNodo = new Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = nullptr;
    if (!lista.inicio) {
        lista.inicio = nuevoNodo;
        lista.final = nuevoNodo;
    }else {
        lista.final->siguiente = nuevoNodo;
        lista.final = nuevoNodo;
    }

}

void imprimirLista(struct Lista lista) {

    struct Nodo *recorrido {};

    recorrido = lista.inicio;
    while (recorrido) {
        cout << recorrido->elemento.numero << " " << recorrido->elemento.nombre << " "
             << recorrido->elemento.posicion<< endl
        ;
        recorrido = recorrido->siguiente;
    }

}

void ordenarLista(struct Lista &lista) {

    struct Nodo *nodoPorteroInicio {}, *nodoPorteroFinal {};
    struct Nodo *nodoDefensaInicio {}, *nodoDefensaFinal {};
    struct Nodo *nodoMedioCampoInicio {}, *nodoMedioCampoFinal {};
    struct Nodo *nodoDelanteroInicio {}, *nodoDelanteroFinal {};

    for (struct Nodo *nuevoNodo = lista.inicio; nuevoNodo; nuevoNodo = nuevoNodo->siguiente) {
        if (strcmp(nuevoNodo->elemento.posicion,"Portero") == 0) {
            if (!nodoPorteroInicio) nodoPorteroInicio = nuevoNodo;
            else nodoPorteroFinal->siguiente = nuevoNodo;
            nodoPorteroFinal = nuevoNodo;
        }
        if (strcmp(nuevoNodo->elemento.posicion,"Defensa") == 0) {
            if (!nodoDefensaInicio) nodoDefensaInicio = nuevoNodo;
            else nodoDefensaFinal->siguiente = nuevoNodo;
            nodoDefensaFinal = nuevoNodo;
        }
        if (strcmp(nuevoNodo->elemento.posicion,"Mediocampo") == 0) {
            if (!nodoMedioCampoInicio) nodoMedioCampoInicio = nuevoNodo;
            else nodoMedioCampoFinal->siguiente = nuevoNodo;
            nodoMedioCampoFinal = nuevoNodo;
        }
        if (strcmp(nuevoNodo->elemento.posicion,"Delantero") == 0) {
            if (!nodoDelanteroInicio) nodoDelanteroInicio = nuevoNodo;
            else nodoDelanteroFinal->siguiente = nuevoNodo;
            nodoDelanteroFinal = nuevoNodo;
        }
    }
    lista.inicio = nodoPorteroInicio;
    nodoPorteroFinal->siguiente = nodoDefensaInicio;
    nodoDefensaFinal->siguiente = nodoMedioCampoInicio;
    nodoMedioCampoFinal->siguiente = nodoDelanteroInicio;
    nodoDelanteroFinal->siguiente = nullptr;

}
