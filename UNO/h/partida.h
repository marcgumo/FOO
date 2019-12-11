#ifndef PARTIDA_H
#define PARTIDA_H

#include "jugadores.h"
#define TRUE 1
#define FALSE 0
#define NOM 50
#define MIN 3
#define MAX 5
#define NINI 7


typedef struct {
	tjugadores participantes;
	tbaraja mazoDesc;
	tbaraja mazoEntr;
	int turno;
	int comprob;
        int sentido;
        int final;
}tpartida;

void iniciar_partida(tpartida *p);
void mostrar_jugadores(tpartida *p);
void repartir_carta(tpartida *p,int i);
void repartir_cartas_iniciales(tpartida *p);
void vaciar_mazo_jug(tpartida *p);
void vaciar_mazo(tpartida *p,int i);
void asignar_nombres_robots(tpartida *p);
void turno(tpartida *p);
void buscar_jugPos(tpartida *p,tbaraja *jugPos);
void tirar_carta_pos(tpartida *p,tbaraja *jugPos, int n);
void mostrar_final(tpartida *p);
void reiniciar_mazoEntr(tpartida *p);

#endif /* PARTIDA_H */

