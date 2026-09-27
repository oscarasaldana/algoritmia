
#ifndef PREGUNTA1_BARAJA_H
#define PREGUNTA1_BARAJA_H

#include "carta.h"

struct Baraja {
    struct Carta *inicio;
    struct Carta *final;
    int longitud;
};

#endif //PREGUNTA1_BARAJA_H
