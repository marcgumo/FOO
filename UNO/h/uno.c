#include "partida.h"


int main(){
    tpartida p;
    
    iniciar_partida(&p);
    
    do
    {
        turno(&p);
    }while(p.final==FALSE);
    mostrar_final(&p);
}

