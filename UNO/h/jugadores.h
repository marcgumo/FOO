#ifndef JUGADORES_H
#define JUGADORES_H

#include "cartas.h"
#define NOM 50
#define TRUE 1
#define FALSE 0
#define MIN 3
#define MAX 5

typedef struct {
	char nombre[NOM];
	tbaraja baraja;
}tjugador;

typedef struct {
	tjugador jugadores[MAX];
	int njugadores;
}tjugadores;

void turno_inicial(int *turno,int *njugadores);

#endif /* JUGADORES_H */

