#include <stdio.h>
#include <stdlib.h>

void *criar_vetor(int tamanho);
double obter_vetor(void *mem, int x);
int atribuir_vetor(void *mem, int x, double valor);
void liberar_vetor(void *mem);

void *criar_matriz(int tamanho_x, int tamanho_y);
double obter_matriz(void *mem, int x, int y);
int atribuir_matriz(void *mem, int x, int y, double valor);
void liberar_matriz(void *mem);
