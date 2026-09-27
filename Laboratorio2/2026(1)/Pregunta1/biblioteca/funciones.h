
#ifndef PREGUNTA1_FUNCIONES_H
#define PREGUNTA1_FUNCIONES_H

void crearBaraja(struct Baraja &);
void cargarCartasBaraja(struct Baraja &, struct ElementoCarta );
struct Carta *extraerCarta(struct Baraja &, int );
void barajar(struct Baraja &);
void insertarAlFinal(struct Baraja &, struct Carta *);
void destruirBaraja(struct Baraja &);
void mostrarBaraja(struct Baraja &);

#endif //PREGUNTA1_FUNCIONES_H
