#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T_INT 0
#define T_FLOAT 1
#define T_CHAR 2
#define T_STRING 3

typedef struct info {
    int chave;
    int tipo;
    void *info;
}Info;

typedef struct list{
    Info data;
    struct list* next;
    struct list* prev;
}List;

List** inicializar(List **);
int inserir_no(List **, List*, int);
int inserir_float(List **, double, int);
int inserir_inteiro(List **, int, int);
int inserir_char(List **, char*, int);
int inserir_string(List **, char*, int);
void listar_elementos (List*);
int obter_tipo (List*, int);
int obter_inteiro (List *, int);
int obter_p_flutuante (List *, int);
int obter_caractere (List *, int);
int obter_c_caracteres (List *, int);
char *getString(char *);
