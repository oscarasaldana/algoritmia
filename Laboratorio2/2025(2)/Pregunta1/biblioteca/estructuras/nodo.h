
#ifndef PREGUNTA1_NODO_H
#define PREGUNTA1_NODO_H

#include "elementoNodo.h"

struct Nodo {
    struct ElementoNodo elemento;
    struct Nodo *siguiente;
};

#endif //PREGUNTA1_NODO_H
