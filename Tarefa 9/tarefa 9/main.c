#include "agenda.h"


int main(int argc, char* argv[]){
    struct Agenda agenda[MAXREGISTROS];
    inicio(agenda);
    int tamanho = 0;
    int *ptTam;
    ptTam = &tamanho;

    char dado[255];
    char contato[5][255];
    int i = 0;

    if(argc == 1){
        menu(agenda, ptTam);

    } else {
        FILE *arq;
        arq=fopen(argv[1], "r");
        while(fgets(dado,255,arq)!= NULL) {
            dado[strcspn(dado, "\n")] = '\0';
            strcpy(contato[i], dado);
            i++;

            if(i==5){
                getRegistro(agenda, contato, ptTam);
                i = 0;
            }
        }
        menu(agenda, ptTam);
        fclose(arq);
    }  
    return 0;
}