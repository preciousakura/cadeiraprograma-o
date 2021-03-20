#ifndef AGENDA_H
#define AGENDA_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
    char *nome;
    int matricula;
    int ddd;
    int num_tel;
    char tipo;
} Agenda;

typedef struct list {
    Agenda contato;
    struct list *next;
    struct list *prev;
} List;

// funções da lista

List* create_list();
void agd_ordenar(List *);
void agd_remover(char*, List *);
void agd_inserir_inicio(Agenda, List*);
void agd_inserir_final(Agenda, List *);
void agd_inserir(Agenda , List*);
void percorrer(List*);
void carregar(char *, List*);
void salvar(List*, char *);

// funcoes da agenda

void flush_in();
int contar_Caractere(char *);
char *getString(char *);
char* getNome(char *);
int getMatricula();
int getDDD();
int getNum();
char getType();

// funções para tratamento de arquivo.txt

int string_to_int(char *);
char *getString_arquivo(char *, FILE *);

// MENU

void menu(List *);

#endif