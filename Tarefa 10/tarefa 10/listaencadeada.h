#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOME 100

typedef struct agenda{
    char nome[MAXNOME];
    int matricula;
    int ddd;
    int num_tel;
    char tipo;
} Agenda;

typedef struct list {
    Agenda agenda;
    struct list *next;
} List;

List* create_List();

void inserir(Agenda, List*);
void carregar(char*, List*);
void percorrer(List*);
void salvar(List*, char*);
