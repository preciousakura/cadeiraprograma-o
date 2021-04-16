#include <stdio.h>
#include <stdlib.h>

typedef struct fila_ {
    int num_conta;
    struct fila_ *next;
    struct fila_ *prev;
}Fila_FIFO;


void f_inicializar (Fila_FIFO **f);
int f_inserir (Fila_FIFO **f, int chave);
int f_obter_proxima_chave (Fila_FIFO **f);

typedef struct escalonador_ {
    Fila_FIFO* premium;
    Fila_FIFO* ouro;
    Fila_FIFO* comum;
    int qtd_total;
    int prior_p, prior_o, prior_c;
} Escalonador;

void e_inicializar (Escalonador **e);
int e_inserir_por_fila (Escalonador **e, int classe, int num_conta);
int e_obter_prox_num_conta(Escalonador **e);