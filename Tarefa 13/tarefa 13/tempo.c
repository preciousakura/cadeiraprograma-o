#include "arquivo.h"
// retorna o tempo inicial
int marcar_tempo(){ 
    struct timeval  inicio;
    gettimeofday(&inicio,NULL);
    int tempo_inicial = inicio.tv_sec;
    return tempo_inicial;
}
// retorna o tempo total
int tempo_final(int t_init){
    struct timeval fim;
    gettimeofday(&fim,NULL);
    int tempo_final = fim.tv_sec - t_init;
    return tempo_final; 
}