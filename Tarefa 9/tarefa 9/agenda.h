#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXNOME 100
#define MAXREGISTROS 1000

struct Agenda{
    char nome[MAXNOME];
    int matricula;
    int ddd;
    int num_tel;
    char tipo;
};

void inicio(struct Agenda*);
void flush_in();
int contar_Caractere(char *);
void getString(char *, int);
int verifica_posicao(struct Agenda *, int);
void getNome(char *);
int getMatricula(int);
int getDDD(int);
int getNum(int);
char getType(char);
void setRegistro(struct Agenda *, int *);
void verRegistro(struct Agenda *, int);
int buscarRegistro(struct Agenda *, int);
int apagarRegistro(struct Agenda *, int);
void menu(struct Agenda *, int *);

// funções para compilação com arquivo.txt passado como parametro

int matricula(char *);
int ddd(char *);
int tel(char *);
void getRegistro(struct Agenda *, char [][255], int *);
