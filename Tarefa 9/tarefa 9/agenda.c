#include "agenda.h"

void inicio(struct Agenda *agenda){
    for(int i = 0; i<MAXREGISTROS; i++){
        agenda[i].ddd = -1;
    }
}

void flush_in(){ // limpar buffer
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int contar_Caractere(char *word) { // conta o número de caracteres
	int tamanho = 0;
	while (word[tamanho] != '\0') {
		tamanho++;
	}
	return tamanho;
}

void getString(char *string, int tamanho){
	fgets(string, tamanho, stdin);
	string[strcspn(string, "\n")] = '\0';
}

int verifica_posicao(struct Agenda *agenda, int tamanho){
    int index = 0;
    for(int i = 0; i < MAXREGISTROS; i++){
        if(agenda[i].ddd == -1){
            index = i;
            return index;
        }
    } return index;
}


void getNome(char *nome) { 
	printf("Digite o nome do contato: ");
	getString(nome, 255);

	while ((contar_Caractere(nome) > 100) || (contar_Caractere(nome) == 0)) {
		printf("Nome invalido! Digite novamente: ");
		getString(nome, 255);
	}
}

int getMatricula(int matricula) { 
	printf("Digite a matricula do contato: ");
	scanf("%d", &matricula);
    flush_in();
    return matricula;
}

int getDDD(int ddd) { 
	printf("Digite o DDD do contato: ");
    scanf("%d", &ddd);
    flush_in();
    while(ddd > 99) {
        printf("DDD invalido! Digite novamente: ");
        scanf("%d", &ddd);
    }
    return ddd;
}

int getNum(int telefone) { 
	printf("Digite o telefone do contato: ");
	scanf("%d", &telefone);
  flush_in();
    return telefone;
}

char getType(char tipo) { 
    char tipo_contato[255];
	printf("Digite o tipo do contato: ");
	getString(tipo_contato, 255);

	while ((contar_Caractere(tipo_contato) > 1) || (contar_Caractere(tipo_contato) == 0)) {
		printf("Tipo invalido! Digite novamente: ");
		getString(tipo_contato, 255);
	}

    tipo = tipo_contato[0];
    return toupper(tipo);
}


void setRegistro(struct Agenda *agenda, int *tamanho) {
    int index = verifica_posicao(agenda, *tamanho);
    if(index > MAXREGISTROS) {
        printf("Agenda lotada!");
    }

    else {
        agenda[index].matricula = getMatricula(agenda[index].matricula);
        getNome(agenda[index].nome);
        agenda[index].ddd = getDDD(agenda[index].ddd);
        agenda[index].num_tel = getNum(agenda[index].num_tel);
        agenda[index].tipo = getType(agenda[index].tipo);
        
        *tamanho = *tamanho + 1;
    }
}

void verRegistro(struct Agenda *agenda, int tamanho){
    int num_contatos = 1;
    if(tamanho == 0){
        printf("Agenda vazia!");
        
    } else {
        printf("\n\n --- LISTANDO CONTATOS --- \n\n");
        for(int i = 0; i < tamanho; i++){
            if(agenda[i].ddd != -1){
                printf("%d. %s\n", num_contatos, agenda[i].nome);
                num_contatos++;
            }
        }
    }
}

int buscarRegistro(struct Agenda *agenda, int tamanho) {
    if(tamanho == 0){
        printf("Agenda vazia!");
        
    } else {
        char nome[255];
        printf("Digite o nome do contato desejado: ");
        getString(nome, 255);

        for(int i = 0; i < tamanho; i++){
            if(!strcmp(nome, agenda[i].nome) && agenda[i].ddd != -1){
                printf("\n%s - (%d) %d", agenda[i].nome, agenda[i].ddd, agenda[i].num_tel);
                return 0;
            }
        } printf("Contato nao encontrado.");
    }
    return 1;
}

int apagarRegistro(struct Agenda *agenda, int tamanho) {
    if(tamanho == 0){
        printf("Agenda vazia!");
        
    } else {
        char nome[255];
        printf("Digite o nome do contato que deseja apagar: ");
        getString(nome, 255);

        for(int i = 0; i < tamanho; i++){
            if(!strcmp(nome, agenda[i].nome) && agenda[i].ddd != -1){
                agenda[i].ddd = -1;
                printf("\nContato excluido!\n");
                return 0;
            }
        } printf("Contato nao encontrado.");
    }
    return 1;
}

void menu(struct Agenda *agenda, int *tamanho){
    char opcao[50];

    printf("--- AGENDA TELEFONICA ---\n\n");
    printf(
        "B. Buscar telefone pelo nome\nI. Inserir novo registro\nA. Apagar registro pelo nome\nL. Listar nomes na agenda\n0. Sair"
    );
    printf("\n\nEscolha uma opcao: ");
    getString(opcao, 50);

    while(toupper(opcao[0]) != '0'){
        if(toupper(opcao[0]) == 'B'){
            buscarRegistro(agenda, *tamanho);
        } else if(toupper(opcao[0]) == 'I') {
            setRegistro(agenda, tamanho);
        } else if(toupper(opcao[0]) == 'A') {
            apagarRegistro(agenda, *tamanho);
        } else if(toupper(opcao[0]) == 'L') {
            verRegistro(agenda, *tamanho);
        } else {
            printf("Opção invalida! Digite novamente: ");
            getString(opcao, 50);
        }

        printf(
            "\nB. Buscar telefone pelo nome\nI. Inserir novo registro\nA. Apagar registro pelo nome\nL. Listar nomes na agenda\n0. Sair"
        );
        printf("\n\nEscolha uma opcao: ");
        getString(opcao, 50);
    }
    
}

int matricula(char *matricula){
    int num = atoi(matricula);
    return num;
}

int ddd(char *ddd){
    int num = atoi(ddd);
    return num;
}

int tel(char *tel) {
    int num = atoi(tel);
    return num;
}

void getRegistro(struct Agenda *agenda, char contato[][255], int *tamanho){
    agenda[*tamanho].matricula = matricula(contato[0]);
    strcpy(agenda[*tamanho].nome, contato[1]);
    agenda[*tamanho].ddd = ddd(contato[2]);
    agenda[*tamanho].num_tel = tel(contato[3]);
    agenda[*tamanho].tipo = contato[4][0];
    *tamanho = *tamanho + 1;
}
