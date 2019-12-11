#include "partida.h"


void iniciar_partida(tpartida *p)
{
    char pregJug[NOM]="Cuantos jugadores? ";
    char pregNom[NOM]="Tu nombre? ";
    char pregMode[NOM]="Quieres ejecutar en modo comprobación? ";
    p->final=FALSE;
    
    p->participantes.njugadores=preguntar_n_en_rango(pregJug,MIN,MAX);
    preguntar_cadena(pregNom,p->participantes.jugadores[0].nombre);
    p->comprob=preguntar_si_o_no(pregMode);
    
    iniciar_mazoEntr(&p->mazoEntr);
    desordenar_mazo(&p->mazoEntr);
    
    iniciar_mazoDesc(&p->mazoDesc,&p->mazoEntr,&p->mazoEntr.ncartas);
    
    turno_inicial(&p->turno,&p->participantes.njugadores);
    vaciar_mazo_jug(p);
    repartir_cartas_iniciales(p);
    asignar_nombres_robots(p);
    
    printf("\nMazo:\n");
    mostrar_mazoEntr(&p->comprob,&p->mazoEntr);
    printf("\n");
    mostrar_mazoDesc(&p->mazoDesc);
    mostrar_jugadores(p);
}

void turno(tpartida *p)
{
    int n,i,j;
    tbaraja jugPos;
    char que_carta[NOM]="Que carta tiras? ";
    jugPos.ncartas=0;
    
    inicializar_azar();
    
    cambiar_color_letra(RED);
    printf("\nTurno %s: ",p->participantes.jugadores[p->turno].nombre);
    default_attributes();
    
    if(p->comprob==TRUE)
    {
        if(p->turno==0)
        {
            buscar_jugPos(p,&jugPos);
            if(jugPos.ncartas!=0)
            {
                printf("Jugadas posibles: ");

                for(i=0;i<jugPos.ncartas;i++)
                {
                    printf("%d(",i);
                    mostrar_carta(&jugPos.cartas[i]);
                    printf(") ");
                }
                printf("\n");
                n=preguntar_n_en_rango(que_carta,FALSE,jugPos.ncartas-1);
                printf("Tira: ");
                mostrar_carta(&jugPos.cartas[n]);
                tirar_carta_pos(p,&jugPos,n);
                if(p->participantes.jugadores[p->turno].baraja.ncartas==1)
                {
                    cambiar_color_letra(GREEN);
                    printf(" ** UNO **");
                    default_attributes();
                }
                printf("\n\n");

                esperar();
            }
            else if(jugPos.ncartas==0)
            {
                printf("Coge del mazo: ");
                repartir_carta(p,p->turno);
                mostrar_carta(&p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1]);

                if(p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1].color==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].color || p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1].num==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].num)
                {
                    printf(" Tira: ");
                    mostrar_carta(&p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1]);
                    p->mazoDesc.cartas[p->mazoDesc.ncartas]=p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1];
                    p->mazoDesc.ncartas++;
                    p->participantes.jugadores[p->turno].baraja.ncartas--;
                }
                else
                    printf(" Ha pasado ");
                printf("\n\n");
                esperar();
            }
        }
        else if(p->turno!=0)
        {
            buscar_jugPos(p,&jugPos);
            if(jugPos.ncartas!=0)
            {
                printf("Jugadas posibles: ");

                n=numero_al_azar(jugPos.ncartas);
                for(i=0;i<jugPos.ncartas;i++)
                {
                    printf("%d(",i);
                    mostrar_carta(&jugPos.cartas[i]);
                    printf(") ");
                }
                printf(" Tira: ");
                mostrar_carta(&jugPos.cartas[n]);
                tirar_carta_pos(p,&jugPos,n);
                if(p->participantes.jugadores[p->turno].baraja.ncartas==1)
                {
                    cambiar_color_letra(GREEN);
                    printf(" ** UNO **");
                    default_attributes();
                }
                printf("\n\n");
                esperar();

            }
            else if(jugPos.ncartas==0)
            {
                printf("Coge del mazo: ");
                repartir_carta(p,p->turno);
                mostrar_carta(&p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1]);

                if(p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1].color==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].color || p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1].num==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].num)
                {
                    printf(" Tira: ");
                    mostrar_carta(&p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1]);
                    p->mazoDesc.cartas[p->mazoDesc.ncartas]=p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1];
                    p->mazoDesc.ncartas++;
                    p->participantes.jugadores[p->turno].baraja.ncartas--;
                }
                else
                    printf(" Ha pasado ");
                printf("\n\n");
                esperar();
            }
        }
    }
    else if(p->comprob==FALSE)
    {
        if(p->turno==0)
        {
            buscar_jugPos(p,&jugPos);
            if(jugPos.ncartas!=0)
            {
                printf("Jugadas posibles: ");

                for(i=0;i<jugPos.ncartas;i++)
                {
                    printf("%d(",i);
                    mostrar_carta(&jugPos.cartas[i]);
                    printf(") ");
                }
                printf("\n");
                n=preguntar_n_en_rango(que_carta,FALSE,jugPos.ncartas-1);
                printf("Tira: ");
                mostrar_carta(&jugPos.cartas[n]);
                tirar_carta_pos(p,&jugPos,n);
                if(p->participantes.jugadores[p->turno].baraja.ncartas==1)
                {
                    cambiar_color_letra(GREEN);
                    printf(" ** UNO **");
                    default_attributes();
                }
                printf("\n\n");

                esperar();
            }
            else if(jugPos.ncartas==0)
            {
                printf("Coge del mazo: ");
                repartir_carta(p,p->turno);
                mostrar_carta(&p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1]);

                if(p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1].color==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].color || p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1].num==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].num)
                {
                    printf(" Tira: ");
                    mostrar_carta(&p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1]);
                    p->mazoDesc.cartas[p->mazoDesc.ncartas]=p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1];
                    p->mazoDesc.ncartas++;
                    p->participantes.jugadores[p->turno].baraja.ncartas--;
                }
                else
                    printf(" Ha pasado ");
                printf("\n\n");
                esperar();
            }
        }
        else if(p->turno!=0)
        {
            buscar_jugPos(p,&jugPos);
            if(jugPos.ncartas!=0)
            {
                n=numero_al_azar(jugPos.ncartas);
                
                printf(" Tira: ");
                mostrar_carta(&jugPos.cartas[n]);
                tirar_carta_pos(p,&jugPos,n);
                if(p->participantes.jugadores[p->turno].baraja.ncartas==1)
                {
                    cambiar_color_letra(GREEN);
                    printf(" ** UNO **");
                    default_attributes();
                }
                printf("\n\n");
                esperar();

            }
            else if(jugPos.ncartas==0)
            {
                printf("Coge del mazo: ");
                repartir_carta(p,p->turno);
                mostrar_carta_girada();

                if(p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1].color==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].color || p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1].num==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].num)
                {
                    printf(" Tira: ");
                    mostrar_carta(&p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1]);
                    p->mazoDesc.cartas[p->mazoDesc.ncartas]=p->participantes.jugadores[p->turno].baraja.cartas[p->participantes.jugadores[p->turno].baraja.ncartas-1];
                    p->mazoDesc.ncartas++;
                    p->participantes.jugadores[p->turno].baraja.ncartas--;
                }
                else
                    printf(" Ha pasado ");
                printf("\n\n");
                esperar();
            }
        }
    }
    
    if(p->participantes.jugadores[p->turno].baraja.ncartas==0)
        p->final=TRUE;
    for(i=0;i<85;i++)
        printf("_");
    printf("\n");
    
    if(p->mazoEntr.ncartas==0)
        reiniciar_mazoEntr(p);
    
    printf("Mazo:\n");
    mostrar_mazoEntr(&p->comprob,&p->mazoEntr);
    printf("\n");
    mostrar_mazoDesc(&p->mazoDesc);
    mostrar_jugadores(p);
    
    if(p->turno<p->participantes.njugadores-1)
            p->turno++;
    else
        p->turno=0;
}

void tirar_carta_pos(tpartida *p,tbaraja *jugPos, int n)
{
    int i,j;
    
    for(i=0;i<p->participantes.jugadores[p->turno].baraja.ncartas;i++)
    {
        if(jugPos->cartas[n].color==p->participantes.jugadores[p->turno].baraja.cartas[i].color && jugPos->cartas[n].num==p->participantes.jugadores[p->turno].baraja.cartas[i].num && n!=-1)
        {
            for(j=i;j<p->participantes.jugadores[p->turno].baraja.ncartas;j++)
                p->participantes.jugadores[p->turno].baraja.cartas[j]=p->participantes.jugadores[p->turno].baraja.cartas[j+1];
            p->participantes.jugadores[p->turno].baraja.ncartas--;
            p->mazoDesc.cartas[p->mazoDesc.ncartas]=jugPos->cartas[n];
            p->mazoDesc.ncartas++;
            n=-1;
        }
    }
}

void buscar_jugPos(tpartida *p,tbaraja *jugPos)
{
    int i;
    
    for(i=0;i<p->participantes.jugadores[p->turno].baraja.ncartas;i++)
        {
            if(p->participantes.jugadores[p->turno].baraja.cartas[i].color==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].color || p->participantes.jugadores[p->turno].baraja.cartas[i].num==p->mazoDesc.cartas[p->mazoDesc.ncartas-1].num)
            {
                jugPos->cartas[jugPos->ncartas]=p->participantes.jugadores[p->turno].baraja.cartas[i];
                jugPos->ncartas++;
            }
        }
}

void mostrar_jugadores(tpartida *p)
{
    int i;
    
    if(p->comprob==TRUE)
    {
        printf("\n");
        for(i=0;i<p->participantes.njugadores;i++)
        {
            printf("%s:\n",p->participantes.jugadores[i].nombre);
            mostrar_mazoEntr(&p->comprob,&p->participantes.jugadores[i].baraja);
            if(p->participantes.jugadores[i].baraja.ncartas==1)
            {
                cambiar_color_letra(GREEN);
                printf(" ** UNO **");
                default_attributes();
            }
            printf("\n");
        }
    }
    else if(p->comprob==FALSE)
    {
        printf("\n%s:\n",p->participantes.jugadores[0].nombre);
        mostrar_mazo(&p->participantes.jugadores[0].baraja);
        if(p->participantes.jugadores[0].baraja.ncartas==1)
            {
                cambiar_color_letra(GREEN);
                printf(" ** UNO **");
                default_attributes();
            }
            printf("\n");
        
        for(i=1;i<p->participantes.njugadores;i++)
        {
            printf("%s:\n",p->participantes.jugadores[i].nombre);
            mostrar_mazoEntr(&p->comprob,&p->participantes.jugadores[i].baraja);
            if(p->participantes.jugadores[i].baraja.ncartas==1)
            {
                cambiar_color_letra(GREEN);
                printf(" ** UNO **");
                default_attributes();
            }
            printf("\n");
        }
    }
}

void repartir_carta(tpartida *p,int i)
{
    p->participantes.jugadores[i].baraja.cartas[p->participantes.jugadores[i].baraja.ncartas]=p->mazoEntr.cartas[p->mazoEntr.ncartas-1];
    p->mazoEntr.ncartas--;
    p->participantes.jugadores[i].baraja.ncartas++;
}

void repartir_cartas_iniciales(tpartida *p)
{
    int i,j;
    
    for(i=0;i<p->participantes.njugadores;i++)
        for(j=0;j<NINI;j++)
            repartir_carta(p,i);
}

void vaciar_mazo(tpartida *p,int i)
{
    p->participantes.jugadores[i].baraja.ncartas=0;
}

void vaciar_mazo_jug(tpartida *p)
{
    int i;
    for(i=0;i<p->participantes.njugadores;i++)
        vaciar_mazo(p,i);
}

void asignar_nombres_robots(tpartida *p)
{
    strcpy(p->participantes.jugadores[1].nombre,"Robot1");
    strcpy(p->participantes.jugadores[2].nombre,"Robot2");
    strcpy(p->participantes.jugadores[3].nombre,"Robot3");
    strcpy(p->participantes.jugadores[4].nombre,"Robot4");
}

void reiniciar_mazoEntr(tpartida *p)
{
    p->mazoEntr=p->mazoDesc;
    p->mazoEntr.ncartas--;
    desordenar_mazo(&p->mazoEntr);
    p->mazoDesc.cartas[0]=p->mazoDesc.cartas[p->mazoDesc.ncartas-1];
    p->mazoDesc.ncartas=1;
}

void mostrar_final(tpartida *p)
{
    p->comprob=TRUE;
    
    printf("\n\t\t\t===>>> FIN PARTIDA <<<===\n\nMazo:\n");
    mostrar_mazoEntr(&p->comprob,&p->mazoEntr);
    printf("\n");
    mostrar_mazoDesc(&p->mazoDesc);
    mostrar_jugadores(p);
    p->turno--;
    if(p->turno==-1)
        p->turno=p->turno+p->participantes.njugadores;
    printf("\n\t\t===>>> HA GANADO %s. ¡FELICIDADES! <<<===\n",p->participantes.jugadores[p->turno].nombre);
    esperar();
}