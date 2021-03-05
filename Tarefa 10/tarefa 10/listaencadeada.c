#include "listaencadeada.h"

List* create_List() {
    List* list = (List*) malloc(sizeof(List));
    list->agenda.ddd = -1;
    list->next = NULL;
    return list;     
}

void inserir(Agenda contato, List* list) {
    if(list->agenda.ddd == -1){
        list->agenda = contato;
        return;

    } if(strcmp(contato.nome, list->agenda.nome) < 0) {
        Agenda aux = contato;
        contato = list->agenda;
        list->agenda = aux;
    }

    if(list->next == NULL) {
        list->next = malloc(sizeof(struct list));
        list->next->agenda = contato;
        list->next->next = NULL;

    } else
        inserir(contato, list->next);
}

void carregar(char *arquivo, List* list) {
    FILE *arq = fopen(arquivo, "r");
    Agenda contato;
    char dado[100];
    while(fgets(dado, 100, arq) != NULL) {
        sscanf(dado, "%d", &contato.matricula);
        fgets(dado, 100, arq);
        sscanf(dado, "%s", contato.nome);
        fgets(dado, 100, arq);
        sscanf(dado, "%d", &contato.ddd);
        fgets(dado, 100, arq);
        sscanf(dado, "%d", &contato.num_tel);
        fgets(dado, 100, arq);
        sscanf(dado, " %c", &contato.tipo);
        inserir(contato, list);
    } fclose(arq);
}

void percorrer(List* list) {
    if(list->next == NULL)return;

    if(list->agenda.ddd != -1) {
        printf("Contato: %s\n", list->agenda.nome);
        printf("%c: (%d) %d\n\n", list->agenda.tipo, list->agenda.ddd, list->agenda.num_tel);
    } percorrer(list->next);
}

void salvar(List* list, char *arquivo) {
    if(list->next == NULL)return;
    FILE* arq = fopen(arquivo, "w");
    while(list->next != NULL){
        fprintf(arq, "%d\n", list->agenda.matricula);
        fprintf(arq, "%s\n", list->agenda.nome);
        fprintf(arq, "%d\n", list->agenda.ddd);
        fprintf(arq, "%d\n", list->agenda.num_tel);
        fprintf(arq, "%c\n", list->agenda.tipo);
        list = list->next;
    }
    fclose(arq);
}
