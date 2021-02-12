#include <stdio.h>
#include <stdlib.h>
#include "cadeia.h"

int str_tamanho (char *s){
    int tamanho = 0;
    while(s[tamanho] != '\0' && s[tamanho] != '\n'){
        tamanho++;
    }
    return tamanho;
}

void str_copia (char *s, char *d){
    int tamanho_d = 0;
    int tamanho_s = str_tamanho(s);
    

    while(tamanho_d != tamanho_s){
        d[tamanho_d] = s[tamanho_d];
        tamanho_d++; 
    }
}

void str_concatena (char *s, char *d){
    int tamanho_d = str_tamanho(d);
    int contador = 0;
    if(tamanho_d==1){
        d[0] = s[contador];
        contador++;
    }
    while(s[contador] != '\0'){
        d[tamanho_d] = s[contador];
        tamanho_d++;
        contador++;
    }
}

void *extenso(char *numero, char *numero_extenso){
    int tamanho = str_tamanho(numero);
    if(tamanho > 3){
        printf("Soh numeros de 1 a 999.");
    } else {
        char *numeral[4][10] =  { {"", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"},  
                                  {"","Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa" },   
                                  {"","Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos" },
                                  {"","Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove" }     
                                };
        char *jun[3] = {" e "};
        int posicao;

        if(tamanho == 1) {
            posicao = numero[0] - '0';
            str_copia(numeral[0][posicao], numero_extenso);

        } else if((tamanho == 2) && (numero[0] == '1') && (numero[1] != '0')) {  
            posicao = numero[1] - '0';
            str_copia(numeral[3][posicao], numero_extenso);
        } else {
            int i;
            for(i = 0; i<tamanho; i++){
                posicao = numero[i] - '0';
                if(numero[i] != '0' && i != 0){
                    str_concatena(jun[0], numero_extenso);
                }
                str_concatena(numeral[(tamanho-i)-1][posicao], numero_extenso);
            } 
        } 
    }
}