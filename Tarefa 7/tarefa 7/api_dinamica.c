#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "api_dinamica.h"

void *criar_vetor(int tamanho){
    return malloc(tamanho*sizeof(double));
}

double obter_vetor(void *mem, int x){
    return ((double*)mem)[x];
}

int atribuir_vetor(void *mem, int x, double valor){
    ((double*)mem)[x] = valor;
}

void liberar_vetor(void *mem){
    free(mem);
}

void *criar_matriz(int tamanho_x, int tamanho_y){
    double *matriz = (double*)malloc((tamanho_x * tamanho_y + 2) * sizeof(double));
    matriz[0] = tamanho_x;
    matriz[1] = tamanho_y;
    return matriz;
}

double obter_matriz(void *mem, int x, int y){
    double valor;
    int pos = ((x * ((double*)mem)[1]) + y);
    valor = ((double*)mem)[pos];
    return valor;
}

int atribuir_matriz(void *mem, int x, int y, double valor){
    int pos = ((x * ((double*)mem)[1]) + y);
    ((double*)mem)[pos] = valor;
}

void liberar_matriz(void *mem){
    free(mem);
}
