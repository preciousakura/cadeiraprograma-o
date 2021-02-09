#include <stdio.h>
#include <stdlib.h>
#include "api_dinamica.h"

int main(){
    printf("VETOR\n");
    void *p_m, *p_v;
    p_v = criar_vetor(16);
    atribuir_vetor(p_v, 8, 456.0); 
    printf("A pos. 8 do vetor contem %.1f.\n", obter_vetor(p_v, 8));
    liberar_vetor(p_v);
    printf("\nMATRIZ\n");

    p_m = criar_matriz(10, 10);
    atribuir_matriz(p_m, 5, 4, 12.0); // Atribui o valor 12 na posição (5,4)
    printf("A pos. (5,4) da matriz = %.1f.\n", obter_matriz(p_m, 5, 4));
    liberar_matriz(p_m);

    return 0;
}