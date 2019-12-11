#include "cartas.h"
#include "partida.h"



void iniciar_mazoEntr(tbaraja *mazo)
{
    int i,j,k,l,m,n;
    
    mazo->ncartas=MAZO;
    
    for(i=0,j=0,k=0,l=0,m=0;i<MAZO;i++)
    {
        if(j<=9)
        {   
            mazo->cartas[i].num=j;
            mazo->cartas[i].color='B';
            j++;
        }
        else if(j>=10 && j<19)
        {   
            mazo->cartas[i].num=j-9;
            mazo->cartas[i].color='B';
            j++;
        }    
        else if (k<=9)
        {
            mazo->cartas[i].num=k;
            mazo->cartas[i].color='G';
            k++;
        }
        else if(k>=10 && k<19)
        {   
            mazo->cartas[i].num=k-9;
            mazo->cartas[i].color='G';
            k++;
        }
        else if (l<=9)
        {
            mazo->cartas[i].num=l;
            mazo->cartas[i].color='R';
            l++;
        }
        else if(l>=10 && l<19)
        {   
            mazo->cartas[i].num=l-9;
            mazo->cartas[i].color='R';
            l++;
        }
        else if (m<=9)
        {
            mazo->cartas[i].num=m;
            mazo->cartas[i].color='Y';
            m++;
        }
        else if(m>=10 && m<19)
        {   
            mazo->cartas[i].num=m-9;
            mazo->cartas[i].color='Y';
            m++;
        }
    }
    
    /*for(i=0,n=0;i<MAZO;i++,n++)
    {
        printf("|(%d,%c)",mazo->cartas[i].num,mazo->cartas[i].color);
        
    }*/
}


void desordenar_mazo(tbaraja *mazo)
{
    int i,n;
    tcarta aux;
    
    inicializar_azar();
    
    for(i=0;i<mazo->ncartas;i++)
    {
        n=numero_al_azar(mazo->ncartas);
        aux=mazo->cartas[i];
        mazo->cartas[i]=mazo->cartas[n];
        mazo->cartas[n]=aux;
    }
    /*for(i=0,n=0;i<MAZO;i++,n++)
    {
        printf("|(%d,%c)",mazo->cartas[i].num,mazo->cartas[i].color);
        
    }*/
}

void mostrar_mazoEntr(int *comprob,tbaraja *mazo)
{
    char color;
    int i,j;
    
    
    if(*comprob==TRUE)
    {
        for(i=0;i<mazo->ncartas;i++)
        {
            default_attributes();
            printf("|");
            color=mazo->cartas[i].color;
            cambiar_color_carta(&color);
            cambiar_color_letra(WHITE);
            printf(" %d ",mazo->cartas[i].num);
            default_attributes();
        
            if(i==19 || i==39 || i==59)
            {
                printf("|\n ");
                for(j=0;j<20;j++)
                    printf("---+");
                printf("\n");
            }
        }
        printf("|");
    }
    else if(*comprob==FALSE)
    {
        default_attributes();
        printf("|");
        cambiar_color_fondo(WHITE);
        cambiar_color_letra(RED);
        printf("UNO");
        default_attributes();
        printf("|(%d)",mazo->ncartas);
    }
}

void iniciar_mazoDesc(tbaraja *mazoDesc,tbaraja *mazoEntr,int *max)
{
    mazoDesc->ncartas=0;
    mazoDesc->cartas[0]=mazoEntr->cartas[mazoEntr->ncartas-1];
    mazoDesc->ncartas++;
    mazoEntr->ncartas--;
}

void mostrar_mazoDesc(tbaraja *mazoDesc)
{
    printf("Mazo Descartes:\n|");
    cambiar_color_letra(WHITE);
    cambiar_color_carta(&mazoDesc->cartas[mazoDesc->ncartas-1].color);
    printf(" %d ",mazoDesc->cartas[mazoDesc->ncartas-1].num);
    default_attributes();
    printf("|(%d)\n",mazoDesc->ncartas);
}

void mostrar_mazo(tbaraja *mazo)
{
    char color;
    int i;
    
    for(i=0;i<mazo->ncartas;i++)
    {
        default_attributes();
        printf("|");
        color=mazo->cartas[i].color;
        cambiar_color_carta(&color);
        cambiar_color_letra(WHITE);
        printf(" %d ",mazo->cartas[i].num);
        default_attributes();
    }
    printf("|");
}

void mostrar_carta(tcarta *carta)
{
    int i;
    char color;
    
    default_attributes();
    printf("|");
    color=carta->color;
    cambiar_color_carta(&color);
    cambiar_color_letra(WHITE);
    printf(" %d ",carta->num);
    default_attributes();
    printf("|");
}
void mostrar_carta_girada()
{
    default_attributes();
        printf("|");
        cambiar_color_fondo(WHITE);
        cambiar_color_letra(RED);
        printf("UNO");
        default_attributes();
        printf("|");
}