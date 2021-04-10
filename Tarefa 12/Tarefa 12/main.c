#include "lista_polimorfica.h"

void menu(List **list){
    char opcao, *caractere, *string;
    int valor, chave;
    double p_float;

    printf("MENU\n");

    while(0 == 0){
        printf("\n(I) Inserir numero decimal\n");
        printf("(B) Inserir inteiro\n");
        printf("(F) Inserir caractere\n");
        printf("(O) Inserir string\n");
        printf("(R) Obter valor inteiro\n");
        printf("(P) Obter valor decimal\n");
        printf("(C) Obter caractere\n");
        printf("(S) Obter string\n");
        printf("(V) Listar valores\n");
        printf("(E) Encerrar programa\n\n");

        printf("Digite sua opcao: ");
        scanf("%c", &opcao);
        getchar();
        opcao = toupper(opcao);

        if(opcao == 'I'){
          printf("Digite um valor decimal: ");
          scanf("%lf", &p_float);
          printf("Digite uma chave para o valor: ");
          scanf("%d", &chave);
          getchar();
          if(inserir_float(list, p_float, chave)){
            printf("\nValor adicionado com sucesso!\n\n");
          } else {
            printf("Nao foi possivel adicionar o valor.\n");
          }
        } else if(opcao == 'B'){
            printf("Digite um valor inteiro: ");
            scanf("%d", &valor);
            printf("Digite uma chave para o valor: ");
            scanf("%d", &chave);
            getchar();
            if(inserir_inteiro(list, valor, chave)){
              printf("\nValor adicionado com sucesso!\n\n");
            } else {
              printf("Nao foi possivel adicionar o valor.\n");
            }
        } else if(opcao == 'F'){
            printf("Digite um caractere: ");
            caractere = getString(caractere);
            while(strlen(caractere) > 1){
              printf("Caractere invalido! Digite novamente: ");
              caractere = getString(caractere);
            }
            printf("Digite uma chave para o valor: ");
            scanf("%d", &chave); 

            if(inserir_char(list, caractere, chave)){
              printf("\nValor adicionado com sucesso!\n\n");
            } else {
              printf("Nao foi possivel adicionar o valor.\n");
            }  
            getchar(); 
        } else if(opcao == 'O'){
            printf("Digite uma string: ");
            string = getString(string);
            printf("Digite uma chave para o valor: ");
            scanf("%d", &chave);
            if(inserir_string(list, string, chave)){
              printf("\nValor adicionado com sucesso!\n\n");
            } else {
              printf("Nao foi possivel adicionar o valor.\n");
            } 
            getchar(); 
        } else if(opcao == 'R'){
            printf("Digite a chave do valor inteiro desejado: ");
            scanf("%d", &chave);
            getchar();
            obter_inteiro(*list, chave);
        } else if(opcao == 'P'){
            printf("Digite a chave do valor decimal desejado: ");
            scanf("%d", &chave);
            getchar();
            obter_p_flutuante(*list, chave); 
        } else if(opcao == 'C'){
            printf("Digite a chave do caractere desejado: ");
            scanf("%d", &chave);
            getchar();
            obter_caractere(*list, chave); 
        } else if(opcao == 'S'){
            printf("Digite a chave da string desejada: ");
            scanf("%d", &chave);
            getchar();
            obter_c_caracteres(*list, chave);
        } else if(opcao == 'V'){
            printf("LISTA\n\n");
            listar_elementos(*list);
        } else if(opcao == 'E'){
            printf("Encerrando Programa...\n");
            break;
        } else {
            printf("\nOpcao Invalida!\n\n");
        }
        
    }
}

int main() {
    List **list = inicializar(list);    
    menu(list);

    return 0;
}