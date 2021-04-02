#include "arquivo.h"

// sorteia um valor double
double sortear_double(int range){
  float num = rand() % range; 
  return num;
}

// sorteia valor inteiro
int sortear_int(int range){
  int num = rand() % range; 
  return num;
}

// gera uma tupla [chave, float]
Value gerar_tupla_list_encad(No_tree* arvore,int N){
  Value dado;
  int numero;
  numero = sortear_int(N);
  while(buscar_arvore(arvore, numero)) { // verifica se valor sorteado já existe na arvore
    numero = sortear_int(N);
  }
    
  dado.num = sortear_double(2500)/sortear_double(500);
  dado.key = numero; 
  return dado; // retorna a tupla
} 
