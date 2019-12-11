#include "colores.h"
#include "azar.h"
#include "preguntas.h"


int main()
{
    char nombre[MAX_CAD];
    int n, num_aleatorio;
    
    preguntar_cadena("Nombre? ", nombre);
    cambiar_color_fondo(YELLOW);
    printf("%s ", nombre);
    cambiar_color_fondo(RED);
    printf("%s ", nombre);
    cambiar_color_fondo(GREEN);
    printf("%s ", nombre);
    cambiar_color_fondo(BLUE);
    printf("%s ", nombre);
    
    default_attributes();
    n=preguntar_n_en_rango("\nIntroduce un valor:", 1, 100);
    
    inicializar_azar();
    do {
        num_aleatorio=numero_al_azar(n)+1;
        printf("He generado un numero aleatorio entre 1 y el valor que has introducido: ");
        cambiar_color_letra(RED);
        printf("%d\n", num_aleatorio);
        default_attributes();
    } while (!preguntar_si_o_no("Te gusta este número?"));
    esperar();

}
