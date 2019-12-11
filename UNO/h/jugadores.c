#include "jugadores.h"

void turno_inicial(int *turno,int *njugadores)
{
    inicializar_azar();
    *turno=numero_al_azar(*njugadores);
}