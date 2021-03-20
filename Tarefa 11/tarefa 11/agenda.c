#include "agenda.h"

// funções da lista

List* inicio = NULL; // inicio da lista
List* fim = NULL; // fim da lista
int tam = 0; // tamanho da lista

List* create_list() { // cria a lista dinamicamente
    List* list = malloc(sizeof(List));
    list->contato.ddd = -1;
    list->next = NULL; // inicia os ponteiros
    list->prev = NULL; // inicia os ponteiros
    return list;
} 

void agd_ordenar(List *list){ // ordena a lista com o algoritmo insertion sort
    if(!list)return;

    List *key, *prev;
    Agenda aux;
    
    for (List *i = list->next; i; i = i->next) {
        key = i;
        prev = i->prev;
        
        aux = i->contato;

        while(prev != NULL && (strcmp(aux.nome, prev->contato.nome) < 0)){
            prev->next->contato = prev->contato;
            prev = prev->prev;
        }
        if(prev) // se for o primeiro elemento da lista
            prev->next->contato = aux;
        else 
            list->contato = aux;  
    }  
}

void agd_remover(char* nome, List *no){ // remove o contato pelo nome
    if(!no){ 
        printf("Contato nao encontrado!\n\n");
        return;
    } if(!strcmp(nome, no->contato.nome)) { // verifica se existe o contato na lista
        printf("O contato %s foi deletado.\n\n", no->contato.nome);
        if(no == inicio){ // remove o primeiro elemento da lista
            inicio = no->next;
            inicio->prev = NULL;
        } else if(no == fim) { // remove o ultimo elemento da lista
            fim = no->prev;
            fim->next = NULL;
        } else { // remove um elemento no meio da lista
            no->next->prev = no->prev;
            no->prev->next = no->next;
        }
        tam--;
        return;
    } agd_remover(nome, no->next);
}

void agd_inserir_inicio(Agenda contato, List* list){ // insere no inicio da lista
    if(inicio == NULL){ // caso a lista esteja vazia
        list->contato = contato;
        inicio = list;
        fim = list;
        tam++;
        return;
    } 

    inicio->prev = create_list();
    inicio->prev->contato = contato;
    inicio->prev->next = inicio;
    inicio = inicio->prev;
    tam++;
}

void agd_inserir_final(Agenda contato, List *list){ // insere no fim da lista
    if(inicio == NULL){ // caso a lista esteja vazia
        list->contato = contato;
        inicio = list;
        fim = list;
        tam++;
        return;
    } 

    fim->next = create_list();
    fim->next->contato = contato;
    fim->next->prev = fim;
    fim = fim->next;
    tam++;
}

void agd_inserir(Agenda contato, List* list){ // insere na lista por ordem alfabética 
    if(inicio == NULL){ // caso a lista esteja vazia
        list->contato = contato;
        inicio = list;
        fim = list;
        tam++;
        return;
    } 
    
    if(strcmp(contato.nome, list->contato.nome) < 0) {
        Agenda aux = contato;
        contato = list->contato;
        list->contato = aux;

    } if(list == fim) 
        agd_inserir_final(contato, inicio);
    else 
        agd_inserir(contato, list->next);
}

void percorrer(List* list) { // percorre e mostra os elementos da lista
    if(!list) return;

    if(list){
        printf("Contato: %s\n", list->contato.nome);
        printf("%c: (%d) %d\n\n", list->contato.tipo, list->contato.ddd, list->contato.num_tel);
    } percorrer(list->next);
}


void carregar(char *arquivo, List* list) {
    FILE *arq = fopen(arquivo, "r");
    char *dado = (char*)malloc(1);
    
    while((dado = getString_arquivo(dado, arq)) != NULL){
      Agenda contato;
      contato.nome = (char*)malloc(1);
      contato.matricula = string_to_int(dado);
      contato.nome = getString_arquivo(contato.nome, arq);
      dado = getString_arquivo(dado, arq);
      contato.ddd = string_to_int(dado);
      dado = getString_arquivo(dado, arq);
      contato.num_tel = string_to_int(dado);
      dado = getString_arquivo(dado, arq);
      contato.tipo = dado[0];
      agd_inserir(contato, list);
    } 
    fclose(arq);
}

void salvar(List* list, char *arquivo) { // salva a lista em um outro arquivo txt
    if(inicio == NULL){
        printf("Agenda vazia!\n");
        return;
    }
    FILE* arq = fopen(arquivo, "w");
    while(list){
        fprintf(arq, "%d\n", list->contato.matricula);
        fprintf(arq, "%s\n", list->contato.nome);
        fprintf(arq, "%d\n", list->contato.ddd);
        fprintf(arq, "%d\n", list->contato.num_tel);
        fprintf(arq, "%c\n", list->contato.tipo);
        list = list->next;
    }
    fclose(arq);
}

// funções para tratar agenda

void flush_in() { // limpa o buffer
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}


int contar_Caractere(char *word) { // conta o número de caracteres
	int tamanho = 0;
	while (word[tamanho] != '\0') {
		tamanho++;
	}
	return tamanho;
}

char *getString(char *nome) { // le uma string com tamanho dinamico
    int i = 0;
    char letra;

    nome = malloc(sizeof(char));

    while(letra != '\n') {
        letra = getchar(); // pega o getchar
        if(letra != '\n')
        {
            nome[i] = letra;
            i++;
            nome = realloc(nome, sizeof(char) * i+1);
        }
    }

    nome[i] = '\0';
    return nome;
}

char* getNome(char *nome) { // ler o nome do contato
	printf("\nDigite o nome do contato: ");
	nome = getString(nome);

	while ((contar_Caractere(nome) > 100) || (contar_Caractere(nome) == 0)) {
		printf("Nome invalido! Digite novamente: ");
		nome = getString(nome);
	} return nome; 
}

int getMatricula() { // ler a matricula
    int matricula;
	printf("Digite a matricula do contato: ");
	scanf("%d", &matricula);
  flush_in();
    return matricula;
}

int getDDD() { // ler o ddd do contato
    int ddd; 
	printf("Digite o DDD do contato: ");
    scanf("%d", &ddd);
    flush_in();

    while(ddd > 99) {
        printf("DDD invalido! Digite novamente: ");
        scanf("%d", &ddd);
        flush_in();
    }
    return ddd;
}

int getNum() { // ler o numero de telefone do contato
    int telefone;
	printf("Digite o telefone do contato: ");
	scanf("%d", &telefone);
  flush_in();

    while(telefone > 999999999) {
        printf("telefone invalido! Digite novamente: ");
        scanf("%d", &telefone);
        flush_in();
    }
    return telefone;
}

char getType() { // ler o tipo do contato 
    char tipo;
	printf("Digite o tipo do contato: ");
    scanf("%c", &tipo);
    flush_in();

	while(0 == 0) {
        if(toupper(tipo) == 'C' || toupper(tipo) == 'T'){
            break;
        } else {
		    printf("Tipo invalido! Digite novamente (C ou T): ");
		    scanf("%c", &tipo);
        flush_in();
        }
	}
    return toupper(tipo);
}

// funções para tratamento de arquivo.txt

int string_to_int(char *dado){ // transforma string pra int
    int num = 0;
    while(*dado != '\n' && *dado != '\0'){
        num = num*10 + (int)(*dado - '0');
        dado++;
    }
    return num;
}

char *getString_arquivo(char *dado, FILE *arq) { // le uma string com tamanho dinamico de um arquivo.txt

    int i = 0;
    char letra;
    
    while(fscanf(arq, "%c", &letra) != EOF && letra != '\n') {
        dado[i] = letra;
        i++;
        dado = realloc(dado, sizeof(char) * i+1);
    } if(i == 0) return NULL;
    dado[i] = '\0';
    return dado;
}

// MENU

void menu(List *list){
    char opcao, *nome_apagar, *nome_arquivo, *arquivo_salvar;
    Agenda contato;

    printf("MENU\n\n");

    while(0 == 0){
        printf("(I) Inserir novo registro\n");
        printf("(B) Inserir novo registro no inicio\n");
        printf("(F) Inserir novo registro no fim\n");
        printf("(O) Ordenar lista\n");
        printf("(R) Remover contato\n");
        printf("(P) Mostrar lista\n");
        printf("(C) Carregar arquivo\n");
        printf("(S) Salvar arquivo\n");
        printf("(E) Encerrar programa\n\n");

        printf("Digite sua opcao: ");
        scanf("%c", &opcao);
        flush_in();
        opcao = toupper(opcao);

        if(opcao == 'I'){
            contato.matricula = getMatricula();
            contato.nome = contato.nome = getNome(contato.nome);
            contato.ddd = getDDD();
            contato.num_tel = getNum();
            contato.tipo = getType();
            printf("\nContato adicionado com sucesso!\n\n");
            agd_inserir(contato, list);
        } else if(opcao == 'B'){
            contato.matricula = getMatricula();
            contato.nome = getNome(contato.nome);
            contato.ddd = getDDD();
            contato.num_tel = getNum();
            contato.tipo = getType();
            printf("\nContato adicionado no inicio com sucesso!\n\n");
            agd_inserir_inicio(contato, list);
        } else if(opcao == 'F'){
            contato.matricula = getMatricula();
            contato.nome = getNome(contato.nome);
            contato.ddd = getDDD();
            contato.num_tel = getNum();
            contato.tipo = getType();
            printf("\nContato adicionado no fim com sucesso!\n\n");
            agd_inserir_final(contato, list);
        } else if(opcao == 'O'){
            if(tam == 0) {
                printf("Lista vazia!\n\n");
            } else {
                printf("\nLista ordenada com sucesso!\n\n");
                agd_ordenar(inicio);
            }
        } else if(opcao == 'R'){
            if(tam == 0) {
                printf("Lista vazia!\n\n");
            } else {
                printf("Digite o nome que voce quer apagar: ");
                nome_apagar = getString(nome_apagar);
                agd_remover(nome_apagar, inicio);
            }
        } else if(opcao == 'P'){
            if(tam == 0) {
                printf("Lista vazia!\n\n");
            } else {
                percorrer(inicio);
            }
        } else if(opcao == 'C'){
            printf("Digite o nome do arquivo: ");
            nome_arquivo = getString(nome_arquivo);
            carregar(nome_arquivo, list);
            if(tam==0)
                printf("\nNão foi possível carregar o arquivo.\n\n");
        } else if(opcao == 'S'){
            printf("Digite o nome do arquivo onde deseja salvar a agenda: ");
            arquivo_salvar = getString(arquivo_salvar);
            printf("\nAgenda salva!\n\n");
        } else if(opcao == 'E'){
            printf("Encerrando Programa...\n");
            break;
        } else {
            printf("\nOpcao Invalida!\n\n");
        }
        
    }
}