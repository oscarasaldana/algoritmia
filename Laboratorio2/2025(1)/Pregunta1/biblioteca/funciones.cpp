#include <iostream>
#include <cstring>

using namespace std;

#include "funciones.h"
#include "estructuras/lista.h"
#include "estructuras/nodo.h"
#include "estructuras/elementoNodo.h"

void insertarElemento(struct Lista &lista) {

    struct Elemento elemento;

    cargarDatos(elemento);

    struct Nodo *nuevoNodo;

    nuevoNodo = new Nodo;
    nuevoNodo->elemento = elemento;
    if (!lista.inicio) {
        nuevoNodo->siguiente = lista.inicio;
        lista.inicio = nuevoNodo;
    }else {
        nuevoNodo->siguiente = lista.inicio;
        lista.inicio = nuevoNodo;
    }
    lista.longitud++;

}

void cargarDatos(struct Elemento &elemento) {

    char nombre[15], color[15];

    cout << "Ingresa el id del competidor: ";
    cin >> elemento.id;

    cout << "Ingresa el nombre del competidor: ";
    cin >> nombre;
    elemento.nombre = leerCadenaCaracteres(nombre);

    cout << "Ingresa el color del competidor: ";
    cin >> color;
    elemento.color = leerCadenaCaracteres(color);

}

char *leerCadenaCaracteres(char *cadena) {

    char *ptrCadena;

    ptrCadena = new char[strlen(cadena) + 1];
    strcpy(ptrCadena,cadena);

    return ptrCadena;

}

void imprimirLista(struct Lista &lista) {

    struct Nodo *recorrido;

    recorrido = lista.inicio;
    while (recorrido) {
        cout << "[ID: " << recorrido->elemento.id << ", Nombre: " << recorrido->elemento.nombre
             << ", Equipo: " << recorrido->elemento.color << "]" <<endl
        ;
        recorrido = recorrido->siguiente;
    }

}

void ordenarLista(struct Lista &lista) {

    struct Nodo *anterior, *siguiente;
    struct Elemento aux;

    anterior = lista.inicio;
    siguiente = anterior->siguiente;
    while (anterior and siguiente) {
        if (anterior->elemento.id % 2 != 0 and siguiente->elemento.id % 2 == 0) {
            aux = anterior->elemento;
            anterior->elemento = siguiente->elemento;
            siguiente->elemento = aux;
        }
        anterior = anterior->siguiente;
        siguiente = anterior->siguiente;
    }

}
