#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <string.h>
#include "colores.h"
#include "azar.h"
#include "preguntas.h"
#define MAZO 76
#define TRUE 1
#define FALSE 0

typedef struct {
	int num;
	char color; /*B(blue)  G(green)  R(red)  Y(yellow)*/
}tcarta;

typedef struct {
	int ncartas;
	tcarta cartas[MAZO];
}tbaraja;

void iniciar_mazoEntr(tbaraja *mazo);
void desordenar_mazo(tbaraja *mazo);
void mostrar_mazoEntr(int *comprob,tbaraja *mazo);
void iniciar_mazoDesc(tbaraja *mazoDesc,tbaraja *mazoEntr,int *max);
void mostrar_mazoDesc(tbaraja *mazoDesc);
void mostrar_mazo(tbaraja *mazo);
void mostrar_carta(tcarta *carta);
void mostrar_carta_girada();


#endif /* CARTAS_H */