#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

typedef struct value_ {
  int key;
  double num;
} Value;

typedef struct no_arvore {
  Value dado;
  struct no_arvore *left; // menor numero
  struct no_arvore *right; // maior ou igual
}No_tree;

typedef struct no_ {
  Value dado;
  struct no_ *prev;
  struct no_ *next;
} No;


// funções da árvore binária de busca

No_tree* inicializar_arvore();
No_tree* inserir_abb(No_tree*, Value);
int buscar_arvore(No_tree *, int);

// funções da lista duplamente encadeada

No* inicializar(No*);
No* inserir_list_encadeada(No*, Value);
int busca_lista_encadeada(No*, int);

// funções dos vetores

int *inicializar_vetor(int);
void insere_chave_vetor(No_tree*, int*, int *);
int busca_sequencial(int*, int, int);
int busca_binaria(int*, int, int, int);

// funções de marcar tempo

int marcar_tempo();
int tempo_final(int);

// funções de gerar tupla

double sortear_double(int );
int sortear_int(int);
Value gerar_tupla_list_encad(No_tree*, int);
    

