#include <stdio.h>
#include <stdlib.h>
#include "cadeia.h"

int main(int argc, char *argv[]){
    char *s, *d; // ponteiros
    char numero[5]; // número a ser convertido em extenso
    char numero_extenso[1000][1024]; // string onde será guardado os números em extenso
    int linha = 0; // linha do numero_extenso[linha] 

    s = numero; 

    int i;

    for(i = 0; i < 1000; i++){
        for(int j = 0; j<1024; j++){
            numero_extenso[i][j]= 0; // limpando memória 
        }
    } 

    int num; // valor a ser recebido em inteiro

    if(argc == 1){
        scanf("%d", &num); 
        sprintf(numero, "%d", num); // tranformação int para string
        d = numero_extenso[linha];
        extenso(s, d);
        linha++;

    } else {
        FILE *arq;
        arq=fopen(argv[1], "r");
        while(fgets(numero,5,arq)!= NULL) {
            // essa parte converte para inteiro e depois converte para string, para evitar problemas como 003
            num = atoi(numero);
            sprintf(numero, "%d", num);
            //fim
            d = numero_extenso[linha];
            extenso(s, d);
            linha++;
        }
        fclose(arq);
    }  

    for(i = 0; i < linha; i++){
        printf("%s\n", numero_extenso[i]); // mostrando valores
    }  

    return 0;
}