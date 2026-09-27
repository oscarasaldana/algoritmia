
#ifndef PREGUNTA1_CARTA_H
#define PREGUNTA1_CARTA_H

#include "elementoCarta.h"

struct Carta {
    struct ElementoCarta elemento;
    struct Carta *siguiente;
};

#endif //PREGUNTA1_CARTA_H
