#include "fila.h"

void f_inicializar (Fila_FIFO **f) { // inicializa
    *f = NULL;
}

int f_inserir (Fila_FIFO **f, int chave) { // insere na fila
    if(*f == NULL) {
        (*f) = (Fila_FIFO*)malloc(sizeof(Fila_FIFO));
        (*f)->num_conta = chave;
        (*f)->next = NULL;
        (*f)->prev = NULL;
        return 1;
    } if((*f)->next == NULL) {
        (*f)->next = (Fila_FIFO*) malloc(sizeof(Fila_FIFO));
        (*f)->next->num_conta = chave;
        (*f)->next->next = NULL;
        (*f)->next->prev = (*f)->next;
        return 1;
    } else {
        f_inserir(&(*f)->next, chave); 
    } return 0;
}

int f_obter_proxima_chave (Fila_FIFO **f) { // remove o primeiro elemento da fila e retorna o valor do elemento
    if((*f)->next != NULL) {
        int valor = (*f)->num_conta;
        *f = (*f)->next;
        (*f)->prev = NULL;
        return valor; // retorna valor
    } else {
        int valor = (*f)->num_conta;
        *f = NULL;
        return valor;
    }
}

void e_inicializar (Escalonador **e) {
    *e = malloc(sizeof(Escalonador));
    f_inicializar(&(*e)->premium);
    f_inicializar(&(*e)->ouro);
    f_inicializar(&(*e)->comum);
    (*e)->prior_p = 3, (*e)->prior_o = 2, (*e)->prior_c = 1;
}

int e_inserir_por_fila (Escalonador **e, int classe, int num_conta) {
    if(classe == 0){
        f_inserir(&(*e)->premium, num_conta);
        return 1;
    } else if(classe == 1){
        f_inserir(&(*e)->ouro, num_conta);
        return 1;
    } else {
        f_inserir(&(*e)->comum, num_conta);
        return 1;
    }
}

void e_reiniciar_contagem (Escalonador **e) {
    (*e)->prior_p = 3, (*e)->prior_o = 2, (*e)->prior_c = 1;
}

int e_obter_prox_num_conta(Escalonador **e) {
    if((*e)->prior_p > 0 && (*e)->premium != NULL) {
        (*e)->prior_p--;
        return f_obter_proxima_chave(&(*e)->premium);
    }else if((*e)->prior_o > 0 && (*e)->ouro != NULL) {
        (*e)->prior_o--;
        return f_obter_proxima_chave(&(*e)->ouro);
    }else if((*e)->prior_c > 0 && (*e)->comum != NULL) {
        (*e)->prior_c--;
        e_reiniciar_contagem(e);
        return f_obter_proxima_chave(&(*e)->comum);
    } return -1;
}