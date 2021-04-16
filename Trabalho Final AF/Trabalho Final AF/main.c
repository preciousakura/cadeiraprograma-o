#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int string_to_int(char *dado){ // transforma string pra int
    int num = 0;
    while(*dado != '\n' && *dado != '\0'){
        num = num*10 + (int)(*dado - '0');
        dado++;
    }
    return num;
}

void ler_arquivo(Escalonador** e, char* file) { // ler o arquivo txt
	FILE* arquivo = fopen(file, "r");
	char guardar[100];
	fscanf(arquivo, "%s", guardar);
	int quantidade = string_to_int(guardar);
    (*e)->qtd_total = quantidade;
	for(int i = 0; i < quantidade; i++) {
		fscanf(arquivo, "%s", guardar);
		int classe = guardar[0];
		int conta  = string_to_int(&guardar[2]);
		e_inserir_por_fila(e, classe-'0', conta); // insere na fila
	}
	fclose(arquivo);
}

int main(int argc, char* argv[]){
    Escalonador* e;
    e_inicializar(&e);
    char dado[255];
    int num;

    if(argc == 1){
        printf("passe o nome do arquivo txt como parametro");

    } else {
        ler_arquivo(&e, argv[1]);
        for(int i = 0; i < e->qtd_total; i++) {
            printf("%d\n", e_obter_prox_num_conta(&e));
        }
    }  
    return 0;
}